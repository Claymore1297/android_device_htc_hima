/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/properties.h>
#include <android-base/logging.h>

#include "property_service.h"
#include "vendor_init.h"

using android::base::GetProperty;
using android::init::property_set;

void property_override(char const prop[], char const value[]) {
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[],
    char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void cdma_properties(char const default_cdma_sub[], char const default_network[]) {
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.ril.enable.sdr", "0");
    property_set("ro.telephony.default_cdma_sub", default_cdma_sub);
    property_set("ro.telephony.default_network", default_network);
    property_set("telephony.lteOnCdmaDevice", "1");

    property_set("ro.cdma.home.operator.numeric", "310120");
    property_set("ro.cdma.home.operator.alpha", "Sprint");
    property_set("gsm.sim.operator.alpha", "Sprint");
    property_set("gsm.sim.operator.numeric", "310120");
    property_set("gsm.operator.alpha", "Sprint");
    property_set("gsm.operator.numeric", "310120");
}

void gsm_properties(char const default_network[]) {
    property_set("ro.telephony.default_network", default_network);
    property_set("telephony.lteOnGsmDevice", "1");
}

void vendor_load_properties() {
    std::string platform;
    std::string bootmid;
    std::string device;

    bootmid = GetProperty("ro.boot.mid", "");
    if (bootmid == "2PQ910000") {
        /* himauhl */
        gsm_properties("9");
        property_override("ro.build.description", "1.10.401.7 CL635503 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "htc/hiaeuhl_00401/htc_hiaeuhl:6.0/MRA58K/635503.7:user/release-keys");
        property_override("ro.build.changelist", "635503");
        property_override("ro.build.product", "htc_hiaeuhl");
        property_override("ro.build.sense.version", "8.0");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "htc_hiaeuhl");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "HTC One A9");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "hiaeul_00401");
    } else if (bootmid == "2PQ912000") {
        /* himaul */
        gsm_properties("9");
        property_override("ro.build.description", "2.18.617.30 8.0_g CL861328 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "htc/hiaeul_00617/htc_hiaeul:7.0/NRD90M/861328.30:user/release-keys");
        property_override("ro.build.changelist", "861328");
        property_override("ro.build.product", "htc_hiaeul");
        property_override("ro.build.sense.version", "8.0");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "htc_hiaeul");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "HTC One A9");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "hiaeul_00617");
    } else if (bootmid == "2PQ930000") {
        /* himawhl */
        cdma_properties("1", "8");
        property_override("ro.build.description", "1.57.651.1 CL688951 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "htc/hiaewhl_00651/htc_hiaewhl:6.0.1/MMB29M/688951.1:user/release-keys");
        property_override("ro.build.changelist", "688951");
        property_override("ro.build.product", "htc_hiaewhl");
        property_override("ro.build.sense.version", "8.0");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "htc_hiaewhl");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "HTC One A9");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "hiaeul_00651");
    } else if (bootmid == "2PQ930000") {
        /* himawl */
        cdma_properties("1", "8");
        property_override("ro.build.description", "1.57.651.1 CL688951 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "htc/hiaewhl_00651/htc_hiaewhl:6.0.1/MMB29M/688951.1:user/release-keys");
        property_override("ro.build.changelist", "688951");
        property_override("ro.build.product", "htc_hiaewhl");
        property_override("ro.build.sense.version", "8.0");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "htc_hiaewhl");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "HTC One A9");
        property_override_dual("ro.product.name", "ro.vendor.product.name", "hiaeul_00651");
    }

    device = GetProperty("ro.product.device", "");
    LOG(INFO) << "Found bootmid '" << bootmid.c_str() <<
        "' setting build properties for '" << device.c_str() << "' device\n";
}
