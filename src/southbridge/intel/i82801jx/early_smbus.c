/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <device/pci_ops.h>
#include <device/pci_def.h>
#include <device/smbus_host.h>
#include "i82801jx.h"

uintptr_t smbus_base(void)
{
	return SMBUS_IO_BASE;
}

int smbus_enable_iobar(uintptr_t base)
{
	/* Set the SMBus device statically. */
	pci_devfn_t dev = PCI_DEV(0x0, 0x1f, 0x3);

	/* Set SMBus I/O base. */
	pci_write_config32(dev, SMB_BASE,
			   base | PCI_BASE_ADDRESS_SPACE_IO);

	/* Set SMBus enable. */
	pci_write_config8(dev, HOSTC, HST_EN);

	/* Set SMBus I/O space enable. */
	pci_write_config16(dev, PCI_COMMAND, PCI_COMMAND_IO);

	return 0;
}

int smbus_read_byte(unsigned int device, unsigned int address)
{
	return do_smbus_read_byte(SMBUS_IO_BASE, device, address);
}

int i2c_eeprom_read(unsigned int device, unsigned int offset, u32 bytes, u8 *buf)
{
	return do_i2c_eeprom_read(SMBUS_IO_BASE, device, offset, bytes, buf);
}

int smbus_block_read(unsigned int device, unsigned int cmd, u8 bytes, u8 *buf)
{
	return do_smbus_block_read(SMBUS_IO_BASE, device, cmd, bytes, buf);
}

int smbus_block_write(unsigned int device, unsigned int cmd, u8 bytes,
		const u8 *buf)
{
	return do_smbus_block_write(SMBUS_IO_BASE, device, cmd, bytes, buf);
}
