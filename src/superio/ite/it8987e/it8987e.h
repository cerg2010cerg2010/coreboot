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

#ifndef SUPERIO_ITE_IT8987E_H
#define SUPERIO_ITE_IT8987E_H

#define IT8987E_SWUC 0x04 /* System Wake-Up */
#define IT8987E_KBCM 0x05 /* PS/2 mouse */
#define IT8987E_KBCK 0x06 /* PS/2 keyboard */
#define IT8987E_IR   0x0a /* Consumer IR */
#define IT8987E_SMFI 0x0f /* Shared Memory/Flash Interface */
#define IT8987E_RTCT 0x10 /* RTC-like Timer */
#define IT8987E_PMC1 0x11 /* Power Management Channel 1 */
#define IT8987E_PMC2 0x12 /* Power Management Channel 2 */
#define IT8987E_SSPI 0x13 /* Serial Peripheral Interface */
#define IT8987E_PECI 0x14 /* Platform EC Interface */
#define IT8987E_PMC3 0x17 /* Power Management Channel 3 */
#define IT8987E_PMC4 0x18 /* Power Management Channel 4 */
#define IT8987E_PMC5 0x19 /* Power Management Channel 5 */


#endif /* SUPERIO_ITE_IT8987E_H */
