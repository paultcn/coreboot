/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

/* Intel Gigabit Ethernet Controller 0:1f.6 */

Device (GLAN)
{
	Name (_ADR, 0x001f0006)

	Name (_S0W, 3)

	Name (_PRW, Package() {GPE0_PME_B0, 4})

	Method (_DSW, 3) {}
}
