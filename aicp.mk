$(call inherit-product, device/htc/hima/full_hima.mk)

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

PRODUCT_NAME := aicp_hima
BOARD_VENDOR := htc
TARGET_VENDOR := htc
PRODUCT_DEVICE := hima
