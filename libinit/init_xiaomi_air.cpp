/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_variant.h>
#include <libinit_utils.h>
#include <unistd.h>

#include "vendor_init.h"

// Variant info extracted from actual Xiaomi Air device
// SKU: c3vinl (POCO M6 5G - India variant)
static const variant_info_t air_poco_in_info = {
    .hwc_value = "",
    .sku_value = "c3vinl",

    .brand = "POCO",
    .device = "air",
    .mod_device = "air_in_global",
    .marketname = "POCO M6 5G",
    .model = "23128PC33I",
    .build_fingerprint = "POCO/air_p_in/air:14/UP1A.231005.007/V816.0.5.0.UGQINXM:user/release-keys"
};

// SKU: c3vcn (Redmi 13C - China variant)
static const variant_info_t air_redmi_cn_info = {
    .hwc_value = "",
    .sku_value = "c3vcn",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_global",
    .marketname = "Redmi 13C",
    .model = "23124RN87C",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQCNXM:user/release-keys"
};

// SKU: c3vcnl (Redmi 13C - China Lite variant)
static const variant_info_t air_redmi_cn_lite_info = {
    .hwc_value = "",
    .sku_value = "c3vcnl",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_global",
    .marketname = "Redmi 13C",
    .model = "23122RN86C",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQCNXM:user/release-keys"
};

// SKU: c3vg (Redmi 13C - Global variant)
static const variant_info_t air_redmi_global_info = {
    .hwc_value = "",
    .sku_value = "c3vg",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_global",
    .marketname = "Redmi 13C",
    .model = "23124RN87G",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQINXM:user/release-keys"
};

//SKU: c3vin (Redmi 13C - India variant)
static const variant_info_t air_redmi_in_info = {
    .hwc_value = "",
    .sku_value = "c3vin",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_in_global",
    .marketname = "Redmi 13C",
    .model = "23124RN87I",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQINXM:user/release-keys"
};

// SKU: c3vinl (Redmi 13C - India Lite variant) 
static const variant_info_t air_redmi_in_lite_info = {
    .hwc_value = "",
    .sku_value = "c3vinl",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_in_global",
    .marketname = "Redmi 13C",
    .model = "23122RN86I",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQINXM:user/release-keys"
};

// Single SIM variants
// SKU: c3vcn_ss (Redmi 13C - China Single SIM)
static const variant_info_t air_redmi_cn_ss_info = {
    .hwc_value = "",
    .sku_value = "c3vcn_ss",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_global",  
    .marketname = "Redmi 13C",
    .model = "23124RN87C",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQCNXM:user/release-keys"
};

// SKU: c3vcnl_ss (Redmi 13C - China Lite Single SIM)
static const variant_info_t air_redmi_cn_lite_ss_info = {
    .hwc_value = "",
    .sku_value = "c3vcnl_ss",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_global",
    .marketname = "Redmi 13C",
    .model = "23122RN86C",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQCNXM:user/release-keys"
};

// SKU: c3vg_ss (Redmi 13C - Global Single SIM)  
static const variant_info_t air_redmi_global_ss_info = {
    .hwc_value = "",
    .sku_value = "c3vg_ss",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_global",
    .marketname = "Redmi 13C",
    .model = "23124RN87G",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQINXM:user/release-keys"
};

// SKU: c3vin_ss (Redmi 13C - India Single SIM)
static const variant_info_t air_redmi_in_ss_info = {
    .hwc_value = "",
    .sku_value = "c3vin_ss",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_in_global",
    .marketname = "Redmi 13C",
    .model = "23124RN87I",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQINXM:user/release-keys"
};

// SKU: c3vinl_ss (Redmi 13C - India Lite Single SIM)
static const variant_info_t air_redmi_in_lite_ss_info = {
    .hwc_value = "",
    .sku_value = "c3vinl_ss",

    .brand = "Redmi",
    .device = "air",
    .mod_device = "air_in_global",
    .marketname = "Redmi 13C",
    .model = "23122RN86I",
    .build_fingerprint = "Redmi/air/air:13/TP1A.220624.014/V14.0.10.0.TGQINXM:user/release-keys"
};

static const std::vector<variant_info_t> variants = {
    air_poco_in_info,
    air_redmi_cn_info,
    air_redmi_cn_lite_info,
    air_redmi_global_info,
    air_redmi_in_info,
    air_redmi_in_lite_info,
    air_redmi_cn_ss_info,
    air_redmi_cn_lite_ss_info,
    air_redmi_global_ss_info,
    air_redmi_in_ss_info,
    air_redmi_in_lite_ss_info,
};

void vendor_load_properties() {
    if (access("/system/bin/recovery", F_OK) != 0) {
        search_variant(variants);
    }
}
