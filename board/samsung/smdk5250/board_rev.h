/*
 * (C) Copyright 2012 Samsung Electronics Co. Ltd
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

/* SFR BASE ADDRESS */
#define FIMC_IS_ADC_BASE                0x13150000
#define PMU_ISP_CONFIGURATION	        (ELFIN_POWER_BASE + 0x4020)
#define PMU_ISP_STATUS		        (ELFIN_POWER_BASE + 0x4024)
#define MTCADC_PHY_CONTROL		(ELFIN_POWER_BASE + 0x071C)

#define EXYNOS5_CLKDIV_ISP0		(ELFIN_CLOCK_BASE + 0x0C300)
#define EXYNOS5_CLKDIV_ISP1		(ELFIN_CLOCK_BASE + 0x0C304)
#define EXYNOS5_CLKDIV_ISP2		(ELFIN_CLOCK_BASE + 0x0C308)

#define EXYNOS5_CLKGATE_ISP0		(ELFIN_CLOCK_BASE + 0x0C800)
#define EXYNOS5_CLKGATE_ISP1		(ELFIN_CLOCK_BASE + 0x0C804)

/* ADC CONTROL */
#define ADCCON	   		        0x00
#define ADCDAT0	   		        0x0C
#define ADCMUX				0x1C

#define ADCCON_SELMUX(x)		(((x)&0xF)<<0)
#define ADCCON_MUXMASK		        (0x7<<3)
#define ADCCON_STDBM		        (1<<2)
#define ADCCON_ENABLE_START	        (1<<0)
#define ADCCON_STARTMASK	        (0x3<<0)
#define ADCCON_PRSCEN		        (1<<14)
#define ADCCLRINT	                0x18

/* BOART REVISION INFORMATION */
#define SMDK5250_REV_0_0_ADC_VALUE	0
#define SMDK5250_REV_0_2_ADC_VALUE	500

#define SMDK5250_REV_0_0                0x0
#define SMDK5250_REV_0_1                0x1
#define SMDK5250_REV_0_2                0x2
#define SMDK5250_REV_MASK               0xf

/* BOART REVISION INFORMATION */
#define SMDK5250_REGULATOR_MAX77686     0x0
#define SMDK5250_REGULATOR_MAX8997      0x1
#define SMDK5250_REGULATOR_S5M8767      0x2
#define SMDK5250_REGULATOR_SHIFT        16
#define SMDK5250_REGULATOR_MASK         0xf

