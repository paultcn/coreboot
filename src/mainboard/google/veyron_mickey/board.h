/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#ifndef __MAINBOARD_GOOGLE_VEYRON_MICKEY_BOARD_H
#define __MAINBOARD_GOOGLE_VEYRON_MICKEY_BOARD_H

#include <boardid.h>
#include <gpio.h>

#define GPIO_RESET	GPIO(0, B, 5)

void setup_chromeos_gpios(void);

#endif	/* __MAINBOARD_GOOGLE_VEYRON_MICKEY_BOARD_H */
