##
## This file is part of the coreboot project.
##
## Copyright (C) 2015 Google Inc.
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

subdirs-y += spd

#ramstage-y += mainboard.c
ramstage-y += ramstage.c
ramstage-y += hda_verb.c
ramstage-$(CONFIG_MAINBOARD_USE_LIBGFXINIT) += gma-mainboard.ads

cbfs-files-y += ec.bin
ec.bin-file := $(call strip_quotes,$(CONFIG_MINIBOOK_EC_BIN_PATH))
ec.bin-type := raw
ec.bin-position := 0xffa40000
