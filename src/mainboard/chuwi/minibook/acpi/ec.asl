/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2019 Johanna Schander <coreboot@mimoja.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

Device (EC)
{
	Name (_HID, EisaId ("PNP0C09"))
	Name (_UID, 0)

	Name (_CRS, ResourceTemplate () {
		IO (Decode16, 0x62, 0x62, 0, 1)
		IO (Decode16, 0x66, 0x66, 0, 1)
	})

	Name (ACEX, 0)

	OperationRegion (ERAM, EmbeddedControl, 0x00, 0xFF)
	Field (ERAM, ByteAcc, NoLock, Preserve)
	{
                XXX0,   8, 
                XXX1,   8, 
                XXX2,   8, 
                Offset (0x11), 
                KBCD,   8, 
                Offset (0x20), 
                RCMD,   8, 
                RCST,   8, 
                TESR,   8, 
                Offset (0x60), 
                TSR1,   8, 
                TSR2,   8, 
                TSR3,   8, 
                TSI,    4, 
                HYST,   4, 
                TSHT,   8, 
                TSLT,   8, 
                TSSR,   8, 
                CHGR,   16, 
                Offset (0x72), 
                CHGT,   8, 
                Offset (0x7F), 
                LSTE,   1, 
                Offset (0x80), 
                ECWR,   8, 
                XX10,   8, 
                XX11,   16, 
                B1DC,   16, 
                B1FV,   16, 
                B1FC,   16, 
                XX15,   16, 
                B1ST,   8, 
                B1CR,   16, 
                B1RC,   16, 
                B1VT,   16, 
                BPCN,   8, 
                Offset (0xC0), 
                VER1,   8, 
                VER2,   8, 
                RSV1,   8, 
                RSV2,   8, 
                CCI0,   8, 
                CCI1,   8, 
                CCI2,   8, 
                CCI3,   8, 
                CTL0,   8, 
                CTL1,   8, 
                CTL2,   8, 
                CTL3,   8, 
                CTL4,   8, 
                CTL5,   8, 
                CTL6,   8, 
                CTL7,   8, 
                MGI0,   8, 
                MGI1,   8, 
                MGI2,   8, 
                MGI3,   8, 
                MGI4,   8, 
                MGI5,   8, 
                MGI6,   8, 
                MGI7,   8, 
                MGI8,   8, 
                MGI9,   8, 
                MGIA,   8, 
                MGIB,   8, 
                MGIC,   8, 
                MGID,   8, 
                MGIE,   8, 
                MGIF,   8, 
                MGO0,   8, 
                MGO1,   8, 
                MGO2,   8, 
                MGO3,   8, 
                MGO4,   8, 
                MGO5,   8, 
                MGO6,   8, 
                MGO7,   8, 
                MGO8,   8, 
                MGO9,   8, 
                MGOA,   8, 
                MGOB,   8, 
                MGOC,   8, 
                MGOD,   8, 
                MGOE,   8, 
                MGOF,   8, 
                    ,   3, 
                TPCC,   1, 
                    ,   2, 
                DRMD,   1, 
                Offset (0xF1)
	}

	Method (_REG, 2, NotSerialized)
	{
	}

	// KEY_RFKILL???
	Method (_Q01, 0, NotSerialized)
	{
	}

	// AC plugged?
	Method (_Q0A, 0, NotSerialized)
	{
	}

	// AC unplugged?
	Method (_Q0B, 0, NotSerialized)
	{
	}

	// Lid open/closed
	Method (_Q0C, 0, NotSerialized)
	{
	}

	// Lid open/closed
	Method (_Q0D, 0, NotSerialized)
	{
	}

	// Brigtness up
	Method (_Q06, 0, NotSerialized)
	{
	}

	// Brigtness down
	Method (_Q07, 0, NotSerialized)
	{
	}

	// Power down event
	Method (_Q54, 0, NotSerialized)
	{
	}

	// ??? USB Type C/UCSI Something?
	Method (_Q79, 0, NotSerialized)
	{
	}

	// ??? DCI (OTG?)
	Method (_QDD, 0, NotSerialized)
	{
	}
}
