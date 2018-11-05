LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
	liblog libutils libtinyalsa

LOCAL_CFLAGS += \
	-DPLATFORM_MSM8994

LOCAL_C_INCLUDES := \
	external/tinyalsa/include \
	hardware/libhardware/include \
	$(call project-path-for,qcom-audio)/hal

LOCAL_HEADER_LIBRARIES := generated_kernel_headers

LOCAL_SRC_FILES := \
	rt5501.c \
	tfa9887.c \
	audio_amplifier.c

LOCAL_MODULE := audio_amplifier.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_VENDOR_MODULE := true

include $(BUILD_SHARED_LIBRARY)
