##
## This file is part of the coreboot project.
##
## Copyright 2018 Google LLC
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; version 2 of the License.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##

## GPP_F12-F16 indicates mem_id to match specific spd file
SPD_SOURCES = empty_ddr4	# 0b00000
SPD_SOURCES += micron_dimm_MT40A512M16LY-075E	# 0b10100
SPD_SOURCES += micron_dimm_MT40A512M16TB-062EJ	# 0b11100
SPD_SOURCES += micron_dimm_MT40A1G16KNR-075E	# 0b10010
SPD_SOURCES += hynix_dimm_H5AN8G6NCJR-VKC	# 0b10001
SPD_SOURCES += hynix_dimm_H5ANAG6NCMR-VKC	# 0b11001
SPD_SOURCES += samsung_dimm_K4A8G165WC-BCTD	# 0b10011
SPD_SOURCES += samsung_dimm_K4AAG165WB-MCTD	# 0b11011
SPD_SOURCES += micron_dimm_MT40A1G16KD-062EE	# 0b11010

bootblock-y += gpio.c
ramstage-y += gpio.c
romstage-y += gpio.c
verstage-y += gpio.c

romstage-y += memory.c

ramstage-y += sku.c
ramstage-y += smbios.c
