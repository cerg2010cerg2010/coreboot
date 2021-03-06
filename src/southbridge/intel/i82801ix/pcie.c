/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2008-2009 coresystems GmbH
 *               2012 secunet Security Networks AG
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of
 * the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <console/console.h>
#include <device/device.h>
#include <device/pci.h>
#include <device/pci_def.h>
#include <device/pci_ops.h>
#include <device/pciexp.h>
#include <device/pci_ids.h>
#include <southbridge/intel/common/pciehp.h>
#include "chip.h"

static void pci_init(struct device *dev)
{
	u16 reg16;
	u32 reg32;
	struct southbridge_intel_i82801ix_config *config = dev->chip_info;

	printk(BIOS_DEBUG, "Initializing ICH9 PCIe root port.\n");

	/* Enable Bus Master */
	reg32 = pci_read_config32(dev, PCI_COMMAND);
	reg32 |= PCI_COMMAND_MASTER;
	pci_write_config32(dev, PCI_COMMAND, reg32);

	/* Set Cache Line Size to 0x10 */
	// This has no effect but the OS might expect it
	pci_write_config8(dev, 0x0c, 0x10);

	reg16 = pci_read_config16(dev, PCI_BRIDGE_CONTROL);
	reg16 &= ~PCI_BRIDGE_CTL_PARITY;
	reg16 |= PCI_BRIDGE_CTL_NO_ISA;
	pci_write_config16(dev, PCI_BRIDGE_CONTROL, reg16);

	/* Enable IO xAPIC on this PCIe port */
	reg32 = pci_read_config32(dev, 0xd8);
	reg32 |= (1 << 7);
	pci_write_config32(dev, 0xd8, reg32);

	/* Enable Backbone Clock Gating */
	reg32 = pci_read_config32(dev, 0xe1);
	reg32 |= (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0);
	pci_write_config32(dev, 0xe1, reg32);

	/* Set VC0 transaction class */
	reg32 = pci_read_config32(dev, 0x114);
	reg32 &= 0xffffff00;
	reg32 |= 1;
	pci_write_config32(dev, 0x114, reg32);

	/* Mask completion timeouts */
	reg32 = pci_read_config32(dev, 0x148);
	reg32 |= (1 << 14);
	pci_write_config32(dev, 0x148, reg32);

	/* Lock R/WO Correctable Error Mask. */
	pci_write_config32(dev, 0x154, pci_read_config32(dev, 0x154));

	/* Clear errors in status registers */
	reg16 = pci_read_config16(dev, 0x06);
	pci_write_config16(dev, 0x06, reg16);
	reg16 = pci_read_config16(dev, 0x1e);
	pci_write_config16(dev, 0x1e, reg16);

	/* Get configured ASPM state */
	const enum aspm_type apmc = pci_read_config32(dev, 0x50) & 3;

	/* If both L0s and L1 enabled then set root port 0xE8[1]=1 */
	if (apmc == PCIE_ASPM_BOTH) {
		reg32 = pci_read_config32(dev, 0xe8);
		reg32 |= (1 << 1);
		pci_write_config32(dev, 0xe8, reg32);
	}

	/* Enable expresscard hotplug events.  */
	if (config->pcie_hotplug_map[PCI_FUNC(dev->path.pci.devfn)]) {
		pci_write_config32(dev, 0xd8,
				   pci_read_config32(dev, 0xd8)
				   | (1 << 30));
		pci_write_config16(dev, 0x42, 0x142);
	}
}

static void pch_pciexp_scan_bridge(struct device *dev)
{
	struct southbridge_intel_i82801ix_config *config = dev->chip_info;

	/* Normal PCIe Scan */
	pciexp_scan_bridge(dev);

	if (config->pcie_hotplug_map[PCI_FUNC(dev->path.pci.devfn)]) {
		intel_acpi_pcie_hotplug_scan_slot(dev->link_list);
	}
}

static struct pci_operations pci_ops = {
	.set_subsystem = pci_dev_set_subsystem,
};

static struct device_operations device_ops = {
	.read_resources		= pci_bus_read_resources,
	.set_resources		= pci_dev_set_resources,
	.enable_resources	= pci_bus_enable_resources,
	.init			= pci_init,
	.scan_bus		= pch_pciexp_scan_bridge,
	.ops_pci		= &pci_ops,
};

/* 82801Ix (ICH9DH/ICH9DO/ICH9R/ICH9/ICH9M-E/ICH9M) */
static const unsigned short pci_device_ids[] = {
	PCI_DEVICE_ID_INTEL_82801IB_PCIE1, /* Port 1 */
	PCI_DEVICE_ID_INTEL_82801IB_PCIE2, /* Port 2 */
	PCI_DEVICE_ID_INTEL_82801IB_PCIE3, /* Port 3 */
	PCI_DEVICE_ID_INTEL_82801IB_PCIE4, /* Port 4 */
	PCI_DEVICE_ID_INTEL_82801IB_PCIE5, /* Port 5 */
	PCI_DEVICE_ID_INTEL_82801IB_PCIE6, /* Port 6 */
	0
};
static const struct pci_driver ich9_pcie __pci_driver = {
	.ops		= &device_ops,
	.vendor		= PCI_VENDOR_ID_INTEL,
	.devices	= pci_device_ids,
};
