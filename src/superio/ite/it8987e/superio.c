/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2019 Sergey Larin <cerg2010cerg2010@mail.ru>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <device/device.h>
#include <device/pnp.h>
#include <superio/conf_mode.h>

#include "it8987e.h"

static void it8987e_init(struct device *dev)
{
}

static struct device_operations ops = {
	.read_resources   = pnp_read_resources,
	.set_resources    = pnp_set_resources,
	.enable_resources = pnp_enable_resources,
	.enable           = pnp_alt_enable,
	.init             = it8987e_init,
	.ops_pnp_mode     = &pnp_conf_mode_870155_aa,
};

static struct pnp_info pnp_dev_info[] = {
	{ NULL, IT8987E_SWUC, PNP_IO0 | PNP_IRQ0, 0xfff0, },
	{ NULL, IT8987E_KBCM, PNP_IRQ0, },
	{ NULL, IT8987E_KBCK, PNP_IO0 | PNP_IO1 | PNP_IRQ0, 0x07ff, 0x07ff, },
	{ NULL, IT8987E_IR, PNP_IO0 | PNP_IRQ0, 0xfff8, },
	{ NULL, IT8987E_SMFI, PNP_IO0 | PNP_IRQ0 | PNP_MSC4, 0xfff0, },
	{ NULL, IT8987E_RTCT, PNP_IO0 | PNP_IO1 | PNP_IO2 | PNP_IO3 | PNP_IRQ0
		| PNP_MSC0 | PNP_MSC1 | PNP_MSC2,
		0xfffe, 0xfffe, 0xfffe, 0xfffe},
	{ NULL, IT8987E_PMC1, PNP_IO0 | PNP_IO1 | PNP_IRQ0, 0x07ff, 0x07ff },
	{ NULL, IT8987E_PMC2, PNP_IO0 | PNP_IO1 | PNP_IO2 | PNP_IRQ0 | PNP_MSC0,
		0x07fc, 0x07fc, 0xfff0 },
	{ NULL, IT8987E_SSPI, PNP_IO0 | PNP_IRQ0, 0xfff8 },
	{ NULL, IT8987E_PECI, PNP_IO0, 0xfff8 },
	{ NULL, IT8987E_PMC3, PNP_IO0 | PNP_IO1 | PNP_IRQ0, 0x07ff, 0x07ff },
	{ NULL, IT8987E_PMC4, PNP_IO0 | PNP_IO1 | PNP_IRQ0 | PNP_MSC0,
		0x07ff, 0x07ff },
	{ NULL, IT8987E_PMC5, PNP_IO0 | PNP_IO1 | PNP_IRQ0 | PNP_MSC0,
		0x07ff, 0x07ff },
};

static void enable_dev(struct device *dev)
{
	pnp_enable_devices(dev, &ops, ARRAY_SIZE(pnp_dev_info), pnp_dev_info);
}

struct chip_operations superio_ite_it8987e_ops = {
	CHIP_NAME("ITE IT8987E Super I/O")
	.enable_dev = enable_dev,
};
