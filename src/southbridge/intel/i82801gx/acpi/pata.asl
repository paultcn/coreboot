/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

// Intel PATA Controller 0:1f.1

Device (PATA)
{
	Name (_ADR, 0x001f0001)

	Device (PRID)
	{
		Name (_ADR, 0)

		// Get Timing Mode
		Method (_GTM, 0, Serialized)
		{
			Name(PBUF, Buffer(20) {
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00 })

			CreateDwordField (PBUF,  0, PIO0)
			CreateDwordField (PBUF,  4, DMA0)
			CreateDwordField (PBUF,  8, PIO1)
			CreateDwordField (PBUF, 12, DMA1)
			CreateDwordField (PBUF, 16, FLAG)

			// TODO fill return structure

			Return (PBUF)
		}

		// Set Timing Mode
		Method (_STM, 3)
		{
			CreateDwordField (Arg0,  0, PIO0)
			CreateDwordField (Arg0,  4, DMA0)
			CreateDwordField (Arg0,  8, PIO1)
			CreateDwordField (Arg0, 12, DMA1)
			CreateDwordField (Arg0, 16, FLAG)

			// TODO: Do the deed
		}

		Device (DSK0)
		{
			Name (_ADR, 0)
			// TODO: _RMV ?
			// TODO: _GTF ?
		}

		Device (DSK1)
		{
			Name (_ADR, 1)

			// TODO: _RMV ?
			// TODO: _GTF ?
		}

	}
}
