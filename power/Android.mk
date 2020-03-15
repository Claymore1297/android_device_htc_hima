ifeq ($(TARGET_DEVICE),$(filter $(TARGET_DEVICE),hima))
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    power.c \
    metadata-parser.c \
    utils.c \
    list.c \
    hint-data.c \
    power-8994.c

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    liblog \
    libdl

LOCAL_MODULE_RELATIVE_PATH := hw

LOCAL_CFLAGS += \
    -DINTERACTION_BOOST

LOCAL_MODULE := power.qcom
LOCAL_MODULE_TAGS := optional
LOCAL_VENDOR_MODULE := true

include $(BUILD_SHARED_LIBRARY)
endif
