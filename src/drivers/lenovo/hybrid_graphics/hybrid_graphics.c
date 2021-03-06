/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <types.h>
#include <option.h>
#include <device/device.h>

#include <southbridge/intel/common/gpio.h>
#include <console/console.h>
#include "chip.h"

/*
 * Switch panel mux or backlight mux to active GPU.
 * In case both GPUs are active switch panel mux to integrated.
 */
static void lenovo_hybrid_graphics_enable(struct device *dev)
{
	const struct drivers_lenovo_hybrid_graphics_config *config;
	enum hybrid_graphics_req mode = HYBRID_GRAPHICS_DEFAULT_GPU;

	/* Don't confuse anyone else and disable the fake device */
	dev->enabled = 0;

	config = dev->chip_info;
	if (!config || (get_gpio(config->detect_gpio) == DGPU_NOT_INSTALLED)) {
		printk(BIOS_DEBUG, "Hybrid graphics: Not installed\n");
		return;
	}

	get_option(&mode, "hybrid_graphics_mode");

	if (mode == HYBRID_GRAPHICS_DISCRETE) {
		printk(BIOS_DEBUG, "Hybrid graphics:"
		       " Switching panel to discrete GPU.\n");

		if (config->has_panel_hybrid_gpio)
			set_gpio(config->panel_hybrid_gpio,
				 !config->panel_integrated_lvl);

		if (config->has_backlight_gpio)
			set_gpio(config->backlight_gpio,
				 !config->backlight_integrated_lvl);
	} else {
		printk(BIOS_DEBUG, "Hybrid graphics:"
		       " Switching panel to integrated GPU.\n");

		if (config->has_panel_hybrid_gpio)
			set_gpio(config->panel_hybrid_gpio,
				 config->panel_integrated_lvl);

		if (config->has_backlight_gpio)
			set_gpio(config->backlight_gpio,
				 config->backlight_integrated_lvl);
	}
}

struct chip_operations drivers_lenovo_hybrid_graphics_ops = {
	CHIP_NAME("Lenovo hybrid graphics driver")
	.enable_dev = lenovo_hybrid_graphics_enable
};
