# Inherit some common AICP stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

$(call inherit-product, device/htc/hima/full_hima.mk)

PRODUCT_NAME := lineage_hima

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_DEVICE="htc_himauhl" \
    PRODUCT_NAME="himauhl_htc_europe" \
    PRIVATE_BUILD_DESC="4.28.401.3 CL869604 release-keys"

BUILD_FINGERPRINT="htc/himauhl_htc_europe/htc_himauhl:7.0/NRD90M/869604.3:user/release-keys"

# AICP Device Maintainers
PRODUCT_BUILD_PROP_OVERRIDES += \
    DEVICE_MAINTAINERS="Julian Veit (Claymore1297), Ali B (eyosen), Joel Stein (k4y0z)"

# Boot animation
TARGET_SCREEN_HEIGHT := 1920
TARGET_SCREEN_WIDTH := 1080
