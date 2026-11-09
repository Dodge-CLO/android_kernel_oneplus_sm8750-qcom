# SPDX-License-Identifier: GPL-2.0-only
# OnePlus (oplus) additions to the sun perf config, kept separate from
# configs/sun_perf.bzl so CLO updates rebase cleanly. Restores the vendor
# drivers the 6.6 OnePlus sun kernel enabled.

sun_perf_oplus_config = {
    # keep sorted
    "CONFIG_LEDS_QCOM_FLASH": "m",
    "CONFIG_LEDS_QPNP_VIBRATOR_LDO": "m",
    "CONFIG_QCOM_CPUSS_SLEEP_STATS": "m",
    "CONFIG_QCOM_CPUSS_SLEEP_STATS_V4": "m",
    "CONFIG_QCOM_FSA4480_I2C": "m",
    "CONFIG_QCOM_GLINK": "m",
    "CONFIG_QCOM_LLCC_HEURISTICS": "m",
    "CONFIG_QCOM_MEM_HOOKS": "m",
    "CONFIG_QCOM_PMIC_ECID": "m",
    "CONFIG_QCOM_QFPROM_SYS": "m",
    "CONFIG_QCOM_SPMI_PMIC_ERR_DBG": "m",
    "CONFIG_QTI_CPUFREQ_STATS_SCMI_V2": "m",
    "CONFIG_QTI_MPAM_MSC": "m",
    "CONFIG_QTI_MPAM_MSC_SLC": "m",
    "CONFIG_QTI_SLC_MPAM_INTERFACE": "m",
    "CONFIG_SHOW_SUSPEND_EPOCH": "m",
    "CONFIG_SND_USB_AUDIO_QMI": "m",
    "CONFIG_USB_MSM_EUSB2_PHY": "m",
}
