/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Read the oplus FTM boot mode from /chosen/bootargs.
 *
 * Mirrors board_ftm_mode_init() in the oplus boot module, for vendor drivers
 * that cannot link against that out-of-tree module on 6.12.
 */
#ifndef _OPLUS_BOOT_MODE_CMDLINE_H
#define _OPLUS_BOOT_MODE_CMDLINE_H

#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/string.h>
#include <soc/oplus/system/boot_mode.h>

static inline int oplus_boot_mode_from_cmdline(void)
{
	static const struct {
		const char *name;
		int mode;
	} modes[] = {
		{ "factory2",	 MSM_BOOT_MODE__FACTORY },
		{ "ftmwifi",	 MSM_BOOT_MODE__WLAN },
		{ "ftmmos",	 MSM_BOOT_MODE__MOS },
		{ "ftmrf",	 MSM_BOOT_MODE__RF },
		{ "ftmrecovery", MSM_BOOT_MODE__RECOVERY },
		{ "ftmsilence",	 MSM_BOOT_MODE__SILENCE },
		{ "ftmsau",	 MSM_BOOT_MODE__SAU },
		{ "ftmaging",	 MSM_BOOT_MODE__AGING },
		{ "ftmsafe",	 MSM_BOOT_MODE__SAFE },
	};
	struct device_node *np = of_find_node_by_path("/chosen");
	const char *args = NULL, *p;
	int i;

	if (np) {
		of_property_read_string(np, "bootargs", &args);
		of_node_put(np);
	}
	if (!args)
		return MSM_BOOT_MODE__NORMAL;

	p = strstr(args, "oplus_ftm_mode=");
	if (!p)
		return MSM_BOOT_MODE__NORMAL;
	p += strlen("oplus_ftm_mode=");

	for (i = 0; i < ARRAY_SIZE(modes); i++) {
		size_t len = strlen(modes[i].name);

		if (!strncmp(p, modes[i].name, len) && (p[len] == ' ' || p[len] == '\0'))
			return modes[i].mode;
	}
	return MSM_BOOT_MODE__NORMAL;
}

#endif /* _OPLUS_BOOT_MODE_CMDLINE_H */
