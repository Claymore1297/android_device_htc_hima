#
# System Properties for HTC One M9 (hima)
#

# Audio
PRODUCT_PROPERTY_OVERRIDES += \
    vendor.audio.offload.buffer.size.kb=1024 \
    vendor.audio.offload.gapless.enabled=true \
    vendor.audio.offload.multiple.enabled=true \
    audio.offload.pcm.16bit.enable=false \
    audio.offload.pcm.24bit.enable=true \
    av.offload.enable=true \
    av.streaming.offload.enable=true

PRODUCT_PROPERTY_OVERRIDES += \
    ro.vendor.audio.sdk.fluencetype=fluence \
    ro.vendor.audio.sdk.ssr=false \
    vendor.use.voice.path.for.pcm.voip=true

PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.audio.camcorder.stereo=true \
    persist.vendor.audio.fluence.voicecall=true \
    persist.vendor.audio.fluence.voicerec=false \
    persist.vendor.audio.fluence.speaker=true

PRODUCT_PROPERTY_OVERRIDES += \
    vendor.audio.dmid=-1286820014 \
    audio.ds1.metainfo.key=273

PRODUCT_PROPERTY_OVERRIDES += \
    vendor.audio.use.dts_eagle=true \
    hpx_send_params=1

PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.audio.spkr.cal.duration=0

PRODUCT_PROPERTY_OVERRIDES += \
    ro.config.media_vol_steps=25 \
    ro.config.vc_call_vol_steps=7
# Bluetooth
PRODUCT_PROPERTY_OVERRIDES += \
   ro.bt.bdaddr_path=/sys/module/htc_bdaddress/parameters/bdaddress \
   ro.bluetooth.hfp.ver=1.6 \
   bluetooth.hfp.client=1 \
   vendor.qcom.bluetooth.soc=rome

# Dalvik heap
PRODUCT_PROPERTY_OVERRIDES += \
    dalvik.vm.heapstartsize=8m \
    dalvik.vm.heapgrowthlimit=192m \
    dalvik.vm.heapsize=512m \
    dalvik.vm.heaptargetutilization=0.75 \
    dalvik.vm.heapminfree=2m \
    dalvik.vm.heapmaxfree=8m

# Display
PRODUCT_PROPERTY_OVERRIDES += \
    persist.hwc.mdpcomp.enable=true \
    ro.opengles.version=196610 \
    ro.qualcomm.cabl=0 \
    ro.sf.lcd_density=420

# Factory Reset Protection
PRODUCT_PROPERTY_OVERRIDES += \
   ro.frp.pst=/dev/block/platform/soc.0/f9824900.sdhci/by-name/frp

# GPS
PRODUCT_PROPERTY_OVERRIDES += \
    persist.gps.qc_nlp_in_use=1 \
    persist.loc.nlp_name=com.qualcomm.services.location \
    ro.gps.agps_provider=1 \
    ro.qc.sdk.izat.premium_enabled=0 \
    ro.qc.sdk.izat.service_mask=0x0

# Media
PRODUCT_PROPERTY_OVERRIDES += \
    media.aac_51_output_enabled=true \
    mm.enable.smoothstreaming=true

#system props for the MM modules
PRODUCT_PROPERTY_OVERRIDES += \
    media.stagefright.enable-player=true \
    media.stagefright.enable-http=true \
    media.stagefright.enable-aac=true \
    media.stagefright.enable-qcp=true \
    media.stagefright.enable-fma2dp=true \
    media.stagefright.enable-scan=true \
    mmp.enable.3g2=true \
    av.debug.disable.pers.cache=true

#3379827: Decimal sum after adding WAV parser flag
#37491 is decimal sum of supported codecs in AAL
#codecs: DivX DivXHD AVI AC3 ASF AAC QCP DTS 3G2 MP2TS
PRODUCT_PROPERTY_OVERRIDES += \
    mm.enable.qcom_parser=3379827

# Print clip name being played
PRODUCT_PROPERTY_OVERRIDES += \
    media.stagefright.log-uri=1

# NFC
PRODUCT_PROPERTY_OVERRIDES += \
    debug.nfc.fw_download=true \
    debug.nfc.fw_boot_download=false

# NITZ
PRODUCT_PROPERTY_OVERRIDES += \
    persist.rild.nitz_plmn="" \
    persist.rild.nitz_long_ons_0="" \
    persist.rild.nitz_long_ons_1="" \
    persist.rild.nitz_long_ons_2="" \
    persist.rild.nitz_long_ons_3="" \
    persist.rild.nitz_short_ons_0="" \
    persist.rild.nitz_short_ons_1="" \
    persist.rild.nitz_short_ons_2="" \
    persist.rild.nitz_short_ons_3=""

# Perf
PRODUCT_PROPERTY_OVERRIDES += \
    ro.vendor.extension_library=libqti-perfd-client.so

PRODUCT_PROPERTY_OVERRIDES += \
    ro.min_freq_0=384000 \
    ro.min_freq_4=384000

# Radio
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
    rild.libpath=/system/vendor/lib64/libril-qc-qmi-1.so \
    ro.ril.telephony.mqanelements=5

PRODUCT_PROPERTY_OVERRIDES += \
    ro.telephony.call_ring.multiple=false

# Vendor security patch level
PRODUCT_PROPERTY_OVERRIDES += \
    ro.lineage.build.vendor_security_patch=2017-04-01

# Wifi
PRODUCT_PROPERTY_OVERRIDES += \
    wifi.interface=wlan0 \
    wifi.direct.interface=p2p-dev-wlan0
