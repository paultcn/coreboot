/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <arch/acpi.h>
DefinitionBlock(
	"dsdt.aml",
	"DSDT",
	0x02,		// DSDT revision: ACPI v2.0 and up
	OEM_ID,
	ACPI_TABLE_CREATOR,
	0x00000001	// OEM revision
)
{
	// global NVS and variables
	#include <southbridge/intel/common/acpi/platform.asl>
	#include <southbridge/intel/i82801jx/acpi/globalnvs.asl>

	Scope (\_SB) {
		Device (PCI0)
		{
			#include <northbridge/intel/x4x/acpi/x4x.asl>
			#include <southbridge/intel/i82801jx/acpi/ich10.asl>
			#include <drivers/intel/gma/acpi/default_brightness_levels.asl>
		}
	}

	#include <southbridge/intel/common/acpi/sleepstates.asl>
}
