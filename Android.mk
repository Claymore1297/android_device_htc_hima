#
# Copyright 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)

ifneq ($(filter hima himaul himawl himawhl, $(TARGET_DEVICE)),)

include $(call all-makefiles-under,$(LOCAL_PATH))

include $(CLEAR_VARS)

WCD9320_IMAGES := \
    wcd9320_anc.bin wcd9320_mad_audio.bin wcd9320_mbhc.bin

WCD9320_SYMLINKS := $(addprefix $(TARGET_OUT_ETC)/firmware/wcd9320/,$(WCD9320_IMAGES))
$(WCD9320_SYMLINKS): $(LOCAL_INSTALLED_MODULE)
	@echo "wcd9320 firmware link: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	tf=$(notdir $@); if [ "$$tf" = "wcd9320_mbhc.bin" ]; then tf="mbhc.bin"; fi; ln -sf /data/misc/audio/$$tf $@

ALL_DEFAULT_INSTALLED_MODULES += $(WCD9320_SYMLINKS)


FIRMWARE_SUB_DIRS := \
    adsp cpe radio

FIRMWARE_DIR := $(addprefix $(TARGET_OUT_VENDOR)/firmware_mnt/,$(notdir $(FIRMWARE_SUB_DIRS)))
$(FIRMWARE_DIR): $(LOCAL_INSTALLED_MODULE)
	@echo "Firmware sub dirs: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) mkdir -p $@

ALL_DEFAULT_INSTALLED_MODULES += $(FIRMWARE_DIR)


VENDOR_SUB_DIRS := \
    fwimage

VENDOR_DIRS := $(addprefix $(TARGET_OUT_VENDOR)/,$(notdir $(VENDOR_SUB_DIRS)))
$(VENDOR_DIRS): $(LOCAL_INSTALLED_MODULE)
	@echo "vendor sub dirs: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) mkdir -p $@

ALL_DEFAULT_INSTALLED_MODULES += $(VENDOR_DIRS)

endif
