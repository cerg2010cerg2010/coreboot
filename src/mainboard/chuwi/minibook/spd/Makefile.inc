##
## This file is part of the coreboot project.
##
## Copyright (C) 2019 Johanna Schander <coreboot@mimoja.de>
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

romstage-y += spd_util.c

SPD_BIN = $(obj)/spd.bin

# It's probably the same SPD used for 16GB version
SPD_SOURCES += micron # 0b0000  8GB
