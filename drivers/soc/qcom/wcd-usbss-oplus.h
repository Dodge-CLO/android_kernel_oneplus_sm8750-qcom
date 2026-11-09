/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * OnePlus hooks for the WCD939x USBSS switch.
 *
 * On 6.6 the oplus boot, feedback and charger code was built in the same tree
 * as this driver. On 6.12 it is built out of tree against this kernel, so the
 * dependencies point the other way: the boot mode is read from the command
 * line here, and the charger <-> switch notifier chain lives in this driver.
 */
#ifndef _WCD_USBSS_OPLUS_H
#define _WCD_USBSS_OPLUS_H

#include <linux/notifier.h>
#include <soc/oplus/system/boot_mode_cmdline.h>

/* oplus mm feedback telemetry is not wired up on 6.12 */
#define mm_fb_audio_kevent_named(...) do { } while (0)

#endif /* _WCD_USBSS_OPLUS_H */
