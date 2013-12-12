static cmd_tbl_t cmd_i2c_exynos_sub[] = {
#if defined(CONFIG_I2C_MUX)
	U_BOOT_CMD_MKENT(bus, 1, 1, do_i2c_add_bus, "", ""),
#endif  /* CONFIG_I2C_MUX */
	U_BOOT_CMD_MKENT(crc32, 3, 1, do_i2c_crc, "", ""),
#if defined(CONFIG_I2C_MULTI_BUS)
	U_BOOT_CMD_MKENT(dev, 1, 1, do_i2c_bus_num, "", ""),
#endif  /* CONFIG_I2C_MULTI_BUS */
	U_BOOT_CMD_MKENT(loop, 3, 1, do_i2c_loop, "", ""),
	U_BOOT_CMD_MKENT(md, 3, 1, do_i2c_md, "", ""),
	U_BOOT_CMD_MKENT(mm, 2, 1, do_i2c_mm, "", ""),
	U_BOOT_CMD_MKENT(mw, 3, 1, do_i2c_mw, "", ""),
	U_BOOT_CMD_MKENT(nm, 2, 1, do_i2c_nm, "", ""),
	U_BOOT_CMD_MKENT(probe, 0, 1, do_i2c_probe, "", ""),
	U_BOOT_CMD_MKENT(read, 5, 1, do_i2c_read, "", ""),
	U_BOOT_CMD_MKENT(reset, 0, 1, do_i2c_reset, "", ""),
#if defined(CONFIG_CMD_SDRAM)
	U_BOOT_CMD_MKENT(sdram, 1, 1, do_sdram, "", ""),
#endif
	U_BOOT_CMD_MKENT(speed, 1, 1, do_i2c_bus_speed, "", ""),
};

static int do_i2c_exynos(cmd_tbl_t * cmdtp, int flag, int argc, char * const argv[])
{
	cmd_tbl_t *c;
	
	if (argc < 2)
		return cmd_usage(cmdtp);
	
	/* Strip off leading 'i2c' command argument */
	argc--;
	argv++;
	
	c = find_cmd_tbl(argv[0], &cmd_i2c_exynos_sub[0], ARRAY_SIZE(cmd_i2c_exynos_sub));
	if (c)
		return  c->cmd(cmdtp, flag, argc, argv);
	else
		return cmd_usage(cmdtp);
}


U_BOOT_CMD(
	i2c, 6, 1, do_i2c_exynos,
	"I2C sub-system",
#if defined(CONFIG_I2C_MUX)
	"bus [muxtype:muxaddr:muxchannel] - add a new bus reached over muxes\ni2c "
#endif  /* CONFIG_I2C_MUX */
	"crc32 chip address[.0, .1, .2] count - compute CRC32 checksum\n"
#if defined(CONFIG_I2C_MULTI_BUS)
	"i2c dev [dev] - show or set current I2C bus\n"
#endif  /* CONFIG_I2C_MULTI_BUS */
	"i2c loop chip address[.0, .1, .2] [# of objects] - looping read of device\n"
	"i2c md chip address[.0, .1, .2] [# of objects] - read from I2C device\n"
	"i2c mm chip address[.0, .1, .2] - write to I2C device (auto-incrementing)\n"
	"i2c mw chip address[.0, .1, .2] value [count] - write to I2C device (fill)\n"
	"i2c nm chip address[.0, .1, .2] - write to I2C device (constant address)\n"
	"i2c probe - show devices on the I2C bus\n"
	"i2c read chip address[.0, .1, .2] length memaddress - read to memory \n"
	"i2c reset - re-init the I2C Controller\n"
#if defined(CONFIG_CMD_SDRAM)
	"i2c sdram chip - print SDRAM configuration information\n"
#endif
	"i2c speed [speed] - show or set I2C bus speed"
);

