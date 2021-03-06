/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <southbridge/intel/common/gpio.h>

static const struct pch_gpio_set1 pch_gpio_set1_mode = {
	.gpio1 = GPIO_MODE_GPIO,
	.gpio6 = GPIO_MODE_GPIO,
	.gpio7 = GPIO_MODE_GPIO,
	.gpio8 = GPIO_MODE_GPIO,
	.gpio10 = GPIO_MODE_GPIO,
	.gpio12 = GPIO_MODE_GPIO,
	.gpio13 = GPIO_MODE_GPIO,
	.gpio14 = GPIO_MODE_GPIO,
	.gpio16 = GPIO_MODE_GPIO,
	.gpio17 = GPIO_MODE_GPIO,
	.gpio18 = GPIO_MODE_GPIO,
	.gpio19 = GPIO_MODE_GPIO,
	.gpio20 = GPIO_MODE_GPIO,
	.gpio21 = GPIO_MODE_GPIO,
	.gpio22 = GPIO_MODE_GPIO,
	.gpio23 = GPIO_MODE_GPIO,
	.gpio24 = GPIO_MODE_GPIO,
	.gpio27 = GPIO_MODE_GPIO,
	.gpio28 = GPIO_MODE_GPIO,
};

static const struct pch_gpio_set1 pch_gpio_set1_direction = {
	.gpio1 = GPIO_DIR_INPUT,
	.gpio6 = GPIO_DIR_INPUT,
	.gpio7 = GPIO_DIR_INPUT,
	.gpio8 = GPIO_DIR_INPUT,
	.gpio10 = GPIO_DIR_INPUT,
	.gpio12 = GPIO_DIR_INPUT,
	.gpio13 = GPIO_DIR_INPUT,
	.gpio14 = GPIO_DIR_INPUT,
	.gpio16 = GPIO_DIR_INPUT,
	.gpio17 = GPIO_DIR_INPUT,
	.gpio18 = GPIO_DIR_INPUT,
	.gpio19 = GPIO_DIR_INPUT,
	.gpio20 = GPIO_DIR_OUTPUT,
	.gpio21 = GPIO_DIR_OUTPUT,
	.gpio22 = GPIO_DIR_INPUT,
	.gpio23 = GPIO_DIR_OUTPUT,
	.gpio24 = GPIO_DIR_OUTPUT,
	.gpio27 = GPIO_DIR_OUTPUT,
	.gpio28 = GPIO_DIR_OUTPUT,
};

static const struct pch_gpio_set1 pch_gpio_set1_level = {
	.gpio20 = GPIO_LEVEL_HIGH,
	.gpio21 = GPIO_LEVEL_HIGH,
	.gpio23 = GPIO_LEVEL_HIGH,
	.gpio24 = GPIO_LEVEL_LOW,
	.gpio27 = GPIO_LEVEL_LOW,
	.gpio28 = GPIO_LEVEL_LOW,
};

static const struct pch_gpio_set1 pch_gpio_set1_invert = {
	.gpio7 = GPIO_INVERT,
	.gpio10 = GPIO_INVERT,
	.gpio13 = GPIO_INVERT,
};

static const struct pch_gpio_set1 pch_gpio_set1_blink = {
};

static const struct pch_gpio_set2 pch_gpio_set2_mode = {
	.gpio32 = GPIO_MODE_GPIO,
	.gpio33 = GPIO_MODE_GPIO,
	.gpio34 = GPIO_MODE_GPIO,
	.gpio35 = GPIO_MODE_GPIO,
	.gpio36 = GPIO_MODE_GPIO,
	.gpio37 = GPIO_MODE_GPIO,
	.gpio38 = GPIO_MODE_GPIO,
	.gpio39 = GPIO_MODE_GPIO,
	.gpio48 = GPIO_MODE_GPIO,
	.gpio49 = GPIO_MODE_GPIO,
	.gpio56 = GPIO_MODE_GPIO,
	.gpio57 = GPIO_MODE_GPIO,
};

static const struct pch_gpio_set2 pch_gpio_set2_direction = {
	.gpio32 = GPIO_DIR_OUTPUT,
	.gpio33 = GPIO_DIR_OUTPUT,
	.gpio34 = GPIO_DIR_OUTPUT,
	.gpio35 = GPIO_DIR_OUTPUT,
	.gpio36 = GPIO_DIR_INPUT,
	.gpio37 = GPIO_DIR_OUTPUT,
	.gpio38 = GPIO_DIR_INPUT,
	.gpio39 = GPIO_DIR_OUTPUT,
	.gpio48 = GPIO_DIR_OUTPUT,
	.gpio49 = GPIO_DIR_OUTPUT,
	.gpio56 = GPIO_DIR_INPUT,
	.gpio57 = GPIO_DIR_OUTPUT,
};

static const struct pch_gpio_set2 pch_gpio_set2_level = {
	.gpio32 = GPIO_LEVEL_HIGH,
	.gpio33 = GPIO_LEVEL_HIGH,
	.gpio34 = GPIO_LEVEL_LOW,
	.gpio35 = GPIO_LEVEL_LOW,
	.gpio37 = GPIO_LEVEL_LOW,
	.gpio39 = GPIO_LEVEL_HIGH,
	.gpio48 = GPIO_LEVEL_LOW,
	.gpio49 = GPIO_LEVEL_HIGH,
	.gpio57 = GPIO_LEVEL_HIGH,
};

const struct pch_gpio_map mainboard_gpio_map = {
	.set1 = {
		.mode		= &pch_gpio_set1_mode,
		.direction	= &pch_gpio_set1_direction,
		.level		= &pch_gpio_set1_level,
		.blink		= &pch_gpio_set1_blink,
		.invert		= &pch_gpio_set1_invert,
	},
	.set2 = {
		.mode		= &pch_gpio_set2_mode,
		.direction	= &pch_gpio_set2_direction,
		.level		= &pch_gpio_set2_level,
	},
};
