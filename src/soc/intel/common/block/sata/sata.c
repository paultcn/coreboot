/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <device/mmio.h>
#include <device/device.h>
#include <device/pci.h>
#include <device/pci_ops.h>
#include <device/pci_def.h>
#include <device/pci_ids.h>
#include <soc/pci_devs.h>

#define SATA_ABAR_PORT_IMPLEMENTED	0x0c
#define SATA_PCI_CFG_PORT_CTL_STS	0x92

static void *sata_get_ahci_bar(struct device *dev)
{
	uintptr_t bar;

	bar = pci_read_config32(dev, PCI_BASE_ADDRESS_5);
	return (void *)(bar & ~PCI_BASE_ADDRESS_MEM_ATTR_MASK);
}

/*
 * SATA Port control and Status. By default, the SATA ports are set (by HW)
 * to the disabled state (e.g. bits[3:0] == '0') as a result of an initial
 * power on reset. When enabled by software as per SATA port mapping,
 * the ports can transition between the on, partial and slumber states
 * and can detect devices. When disabled, the port is in the off state and
 * can't detect any devices.
 */
static void sata_final(struct device *dev)
{
	void *ahcibar = sata_get_ahci_bar(dev);
	u8 port_impl, temp;

	/* Set Bus Master */
	temp = pci_read_config32(dev, PCI_COMMAND);
	pci_write_config32(dev, PCI_COMMAND, temp | PCI_COMMAND_MASTER);

	/* Read Ports Implemented (GHC_PI) */
	port_impl = read8(ahcibar + SATA_ABAR_PORT_IMPLEMENTED);

	if (CONFIG(SOC_AHCI_PORT_IMPLEMENTED_INVERT))
		port_impl = ~port_impl;

	port_impl &= 0x07; /* bit 0-2 */

	/* Port enable */
	temp = pci_read_config8(dev, SATA_PCI_CFG_PORT_CTL_STS);
	temp |= port_impl;
	pci_write_config8(dev, SATA_PCI_CFG_PORT_CTL_STS, temp);
}

static struct device_operations sata_ops = {
	.read_resources		= pci_dev_read_resources,
	.set_resources		= pci_dev_set_resources,
	.enable_resources	= pci_dev_enable_resources,
	.final			= sata_final,
	.ops_pci		= &pci_dev_ops_pci,
};

static const unsigned short pci_device_ids[] = {
	PCI_DEVICE_ID_INTEL_SPT_U_SATA,
	PCI_DEVICE_ID_INTEL_SPT_U_Y_PREMIUM_SATA,
	PCI_DEVICE_ID_INTEL_SPT_KBL_SATA,
	PCI_DEVICE_ID_INTEL_LWB_SATA_AHCI,
	PCI_DEVICE_ID_INTEL_LWB_SSATA_AHCI,
	PCI_DEVICE_ID_INTEL_LWB_SATA_RAID,
	PCI_DEVICE_ID_INTEL_LWB_SSATA_RAID,
	PCI_DEVICE_ID_INTEL_LWB_SATA_AHCI_SUPER,
	PCI_DEVICE_ID_INTEL_LWB_SSATA_AHCI_SUPER,
	PCI_DEVICE_ID_INTEL_LWB_SATA_RAID_SUPER,
	PCI_DEVICE_ID_INTEL_LWB_SSATA_RAID_SUPER,
	PCI_DEVICE_ID_INTEL_LWB_SATA_ALT,
	PCI_DEVICE_ID_INTEL_LWB_SATA_ALT_RST,
	PCI_DEVICE_ID_INTEL_LWB_SSATA_ALT,
	PCI_DEVICE_ID_INTEL_LWB_SSATA_ALT_RST,
	PCI_DEVICE_ID_INTEL_CNL_SATA,
	PCI_DEVICE_ID_INTEL_CNL_PREMIUM_SATA,
	PCI_DEVICE_ID_INTEL_CNP_CMP_COMPAT_SATA,
	PCI_DEVICE_ID_INTEL_CNP_H_SATA,
	PCI_DEVICE_ID_INTEL_CNP_LP_SATA,
	PCI_DEVICE_ID_INTEL_ICP_U_SATA,
	PCI_DEVICE_ID_INTEL_CMP_SATA,
	PCI_DEVICE_ID_INTEL_CMP_PREMIUM_SATA,
	PCI_DEVICE_ID_INTEL_CMP_LP_SATA,
	PCI_DEVICE_ID_INTEL_CMP_H_SATA,
	PCI_DEVICE_ID_INTEL_CMP_H_HALO_SATA,
	PCI_DEVICE_ID_INTEL_CMP_H_PREMIUM_SATA,
	PCI_DEVICE_ID_INTEL_TGP_LP_SATA,
	PCI_DEVICE_ID_INTEL_TGP_SATA,
	PCI_DEVICE_ID_INTEL_TGP_PREMIUM_SATA,
	PCI_DEVICE_ID_INTEL_TGP_COMPAT_SATA,
	PCI_DEVICE_ID_INTEL_MCC_AHCI_SATA,
	PCI_DEVICE_ID_INTEL_JSP_SATA_1,
	PCI_DEVICE_ID_INTEL_JSP_SATA_2,
	0
};

static const struct pci_driver pch_sata __pci_driver = {
	.ops	= &sata_ops,
	.vendor	= PCI_VENDOR_ID_INTEL,
	.devices	= pci_device_ids,
};
