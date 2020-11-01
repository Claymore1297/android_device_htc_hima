/*
 * Copyright (C) 2013, The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _TFA9887_H_
#define _TFA9887_H_

#include <stdint.h>

/* ------------------------------------------------------------------------- */
/* From tfa9895.h kernel header */
#define TFA9895_IOCTL_MAGIC 'a'
#define TFA9895_WRITE_CONFIG_NR     0x01
#define TFA9895_READ_CONFIG_NR      0x02
#define TFA9895_ENABLE_DSP_NR       0x03
#define TFA9895_WRITE_L_CONFIG_NR   0x04
#define TFA9895_READ_L_CONFIG_NR    0x05
#define TFA9895_KERNEL_LOCK_NR      0x06
#define TFA9895_KERNEL_INIT_NR      0x07

#define TFA9895_WRITE_CONFIG(size)   _IOW(TFA9895_IOCTL_MAGIC, TFA9895_WRITE_CONFIG_NR, (size))
#define TFA9895_READ_CONFIG(size)    _IOWR(TFA9895_IOCTL_MAGIC, TFA9895_READ_CONFIG_NR, (size))
#define TFA9895_ENABLE_DSP(size)     _IOW(TFA9895_IOCTL_MAGIC, TFA9895_ENABLE_DSP_NR, (size))
#define TFA9895_WRITE_L_CONFIG(size) _IOW(TFA9895_IOCTL_MAGIC, TFA9895_WRITE_L_CONFIG_NR , (size))
#define TFA9895_READ_L_CONFIG(size)  _IOWR(TFA9895_IOCTL_MAGIC, TFA9895_READ_L_CONFIG_NR, (size))
#define TFA9895_KERNEL_LOCK(size)    _IOW(TFA9895_IOCTL_MAGIC, TFA9895_KERNEL_LOCK_NR, (size))
#define TFA9895_KERNEL_LOCK_INIT(size)  _IOW(TFA9895_IOCTL_MAGIC, TFA9895_KERNEL_INIT_NR, (size))

#define I2C_BUFFER_SIZE 255

struct tfa9895_i2c_buffer {
    int size;
    uint8_t buffer[I2C_BUFFER_SIZE];
};

/* ------------------------------------------------------------------------- */

#define TFA9887_DEVICE "/dev/tfa9887"
#define TFA9887L_DEVICE "/dev/tfa9887l"

#define TFA9887_DEFAULT_RATE 48000

#define MAX_PATCH_SIZE 3072
#define MAX_PARAM_SIZE 768

#define PATCH_HEADER_LENGTH 6

typedef struct uint24 {
    uint8_t bytes[3];
} uint24_t;

#define MAX_EQ_ITEM_SIZE (sizeof(uint24_t))
#define MAX_EQ_LINE_SIZE 6
#define MAX_EQ_LINES 10
#define MAX_EQ_SIZE (MAX_EQ_ITEM_SIZE * MAX_EQ_LINE_SIZE * MAX_EQ_LINES)

#define CONFIG_TFA9887 "/vendor/etc/tfa/tfa9895.config"
#define PATCH_TFA9887 "/vendor/etc/tfa/tfa9895.patch"

#define SPKR_R "/vendor/etc/tfa/tfa9895.speaker"
#define SPKR_L "/vendor/etc/tfa/tfa9895_l.speaker"

#define PRESET_PLAYBACK_R "/vendor/etc/tfa/playback.preset"
#define PRESET_PLAYBACK_L "/vendor/etc/tfa/playback_l.preset"
#define PRESET_VOICE_R "/vendor/etc/tfa/voice.preset"
#define PRESET_VOICE_L "/vendor/etc/tfa/voice_l.preset"
#define PRESET_VOIP_R "/vendor/etc/tfa/voip.preset"
#define PRESET_VOIP_L "/vendor/etc/tfa/voip_l.preset"

#define EQ_PLAYBACK_R "/vendor/etc/tfa/playback.eq"
#define EQ_PLAYBACK_L "/vendor/etc/tfa/playback_l.eq"
#define EQ_VOICE_R "/vendor/etc/tfa/voice.eq"
#define EQ_VOICE_L "/vendor/etc/tfa/voice_l.eq"
#define EQ_VOIP_R "/vendor/etc/tfa/voip.eq"
#define EQ_VOIP_L "/vendor/etc/tfa/voip_l.eq"

#define DRC_PLAYBACK_R "/vendor/etc/tfa/playback.drc"
#define DRC_PLAYBACK_L "/vendor/etc/tfa/playback_l.drc"
#define DRC_VOICE_R "/vendor/etc/tfa/voice.drc"
#define DRC_VOICE_L "/vendor/etc/tfa/voice_l.drc"
#define DRC_VOIP_R "/vendor/etc/tfa/voip.drc"
#define DRC_VOIP_L "/vendor/etc/tfa/voip_l.drc"

struct mode_config_t {
    const char *preset;
    const char *eq;
    const char *drc;
};

enum {
    TFA9887_MODE_PLAYBACK = 0,
    TFA9887_MODE_VOICE,
    TFA9887_MODE_VOIP,
    TFA9887_MODE_MAX,
};

enum {
    TFA9887_MUTE_OFF = 0,
    TFA9887_MUTE_DIGITAL,
    TFA9887_MUTE_AMPLIFIER,
};

/* possible memory values for DMEM in CF_CONTROLs */
enum {
    TFA9887_DMEM_PMEM = 0,
    TFA9887_DMEM_XMEM,
    TFA9887_DMEM_YMEM,
    TFA9887_DMEM_IOMEM,
};

struct tfa9887_amp_t {
    int fd;
    bool is_right;
    uint32_t mode;
    bool initializing;
    bool writing;
    pthread_t write_thread;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

#define MIN(a,b) ((a)<(b)?(a):(b))
#define ROUND_DOWN(a,n) (((a)/(n))*(n))

/* modules */
#define MODULE_SPEAKERBOOST  1
#define MODULE_BIQUADFILTERBANK 2
#define MODULE_SETRE 9

#define SPKRBST_TIMECTE_EXP     1
#define SPKRBST_LIMGAIN_EXP     4
#define SPKRBST_AGCGAIN_EXP     7   /* Exponent used for AGC Gain related variables */
#define SPKRBST_TEMP_EXP        9   /* Exponent used for Gain Corection related variables */
#define DSP_MAX_GAIN_EXP        SPKRBST_AGCGAIN_EXP

/* RPC commands */
#define PARAM_SET_LSMODEL        0x06  // Load a full model into SpeakerBoost.
#define PARAM_SET_LSMODEL_SEL    0x07  // Select one of the default models present in Tfa9887 ROM.
#define PARAM_SET_EQ             0x0A  // 2 Equaliser Filters.
#define PARAM_SET_PRESET         0x0D  // Load a preset
#define PARAM_SET_CONFIG         0x0E  // Load a config
#define PARAM_SET_DRC            0x0F  // Load DRC file
#define PARAM_SET_AGC            0x10  /* Load AGC params */
#define PARAM_SET_RE0            0x89  /* sets the speaker calibration impedance (@25 degrees celsius) */

#define PARAM_GET_CONFIG_PRESET  0x80
#define PARAM_GET_RE0            0x85  /* gets the speaker calibration impedance (@25 degrees celsius) */
#define PARAM_GET_LSMODEL        0x86  // Gets current LoudSpeaker Model.
#define PARAM_GET_STATE          0xC0

/* RPC Status results */
#define STATUS_OK                  0
#define STATUS_INVALID_MODULE_ID   2
#define STATUS_INVALID_PARAM_ID    3
#define STATUS_INVALID_INFO_ID     4

/* maximum number of bytes in 1 I2C write transaction */
#define MAX_I2C_LENGTH        254

/* REVISION values */
#define TFA9887_REV_N1C       0x11
#define TFA9887_REV_N1D       0x12

/* I2S_CONTROL bits */
#define TFA9887_I2SCTRL_RATE_SHIFT (12)
#define TFA9887_I2SCTRL_RATE_08000 (0<<TFA9887_I2SCTRL_RATE_SHIFT)
#define TFA9887_I2SCTRL_RATE_11025 (1<<TFA9887_I2SCTRL_RATE_SHIFT)
#define TFA9887_I2SCTRL_RATE_12000 (2<<TFA9887_I2SCTRL_RATE_SHIFT)
#define TFA9887_I2SCTRL_RATE_16000 (3<<TFA9887_I2SCTRL_RATE_SHIFT)
#define TFA9887_I2SCTRL_RATE_22050 (4<<TFA9887_I2SCTRL_RATE_SHIFT)
#define TFA9887_I2SCTRL_RATE_24000 (5<<TFA9887_I2SCTRL_RATE_SHIFT)
#define TFA9887_I2SCTRL_RATE_32000 (6<<TFA9887_I2SCTRL_RATE_SHIFT)
#define TFA9887_I2SCTRL_RATE_44100 (7<<TFA9887_I2SCTRL_RATE_SHIFT)
#define TFA9887_I2SCTRL_RATE_48000 (8<<TFA9887_I2SCTRL_RATE_SHIFT)

#define TFA9887_I2SCTRL_CHANSEL_SHIFT      3
#define TFA9887_I2SCTRL_INPUT_SEL_SHIFT    6

#define TFA9887_I2SCTRL_DATAI2_SHIFT      5

#define TFA9887_I2SSEL_I2SOUT_LEFT_SHIFT  0
#define TFA9887_I2SSEL_I2SOUT_RIGHT_SHIFT 3

/* SYSTEM CONTROL bits */
#define TFA9887_SYSCTRL_POWERDOWN    (1<<0)
#define TFA9887_SYSCTRL_RESETI2C     (1<<1)
#define TFA9887_SYSCTRL_ENBL_AMP     (1<<3)
#define TFA9887_SYSCTRL_CONFIGURED   (1<<5)
#define TFA9887_SYSCTRL_SEL_ENBL_AMP (1<<6)

/* Audio control bits */
#define TFA9887_AUDIOCTRL_MUTE       (1<<5)

/* STATUS bits */
#define TFA9887_STATUS_VDDS       (1<<0) /*  */
#define TFA9887_STATUS_PLLS       (1<<1) /* plls locked */
#define TFA9887_STATUS_OTDS       (1<<2) /*  */
#define TFA9887_STATUS_OVDS       (1<<3) /*  */
#define TFA9887_STATUS_UVDS       (1<<4) /*  */
#define TFA9887_STATUS_OCDS       (1<<5) /*  */
#define TFA9887_STATUS_CLKS       (1<<6) /* clocks stable */
#define TFA9887_STATUS_MTPB       (1<<8) /*MTP busy operation*/
#define TFA9887_STATUS_DCCS       (1<<9) /*  */
#define TFA9887_STATUS_ACS        (1<<11) /* cold started */
#define TFA9887_STATUS_SWS        (1<<12) /* amplifier switching */

/* MTP bits */
#define TFA9887_MTP_MTPOTC        (1<<0)  /* one time calibration */
#define TFA9887_MTP_MTPEX         (1<<1)  /* one time calibration done */

/* CF bits */
#define TFA9887_CF_CONTROLS_RST         (1<<0)
#define TFA9887_CF_CONTROLS_RST_POS      0
#define TFA9887_CF_CONTROLS_RST_LEN      1
#define TFA9887_CF_CONTROLS_RST_MAX      1
#define TFA9887_CF_CONTROLS_RST_MSK      0x1

#define TFA9887_STATUS (0x00)
#define TFA9887_BATTERYVOLTAGE (0x01)
#define TFA9887_TEMPERATURE (0x02)
#define TFA9887_REVISIONNUMBER (0x03)
#define TFA9887_I2S_CONTROL (0x04)
#define TFA9887_BAT_PROT (0x05)
#define TFA9887_AUDIO_CONTROL (0x06)
#define TFA9887_DCDCBOOST (0x07)
#define TFA9887_SPKR_CALIBRATION (0x08)
#define TFA9887_SYSTEM_CONTROL (0x09)
#define TFA9887_I2S_SEL (0x0a)
#define TFA9887_MTPKEY2_REG (0x0b)
#define TFA9887_RESERVE1 (0x0c)
#define TFA9887_RESERVE2 (0x0d)
#define TFA9887_HIDE_UNHIDE_KEY (0x40)
#define TFA9887_PWM_CONTROL (0x41)
#define TFA9887_CURRENTSENSE1 (0x46)
#define TFA9887_CURRENTSENSE2 (0x47)
#define TFA9887_CURRENTSENSE3 (0x48)
#define TFA9887_CURRENTSENSE4 (0x49)
#define TFA9887_ABISTTEST (0x4c)
#define TFA9887_HIDDEN_DFT3 (0x52)
#define TFA9887_MTP_COPY (0x62)
#define TFA9887_CF_CONTROLS (0x70)
#define TFA9887_CF_MAD (0x71)
#define TFA9887_CF_MEM (0x72)
#define TFA9887_CF_STATUS (0x73)
#define TFA9887_MTP (0x80)

#define I2S_MIXER_CTL "QUAT_MI2S_RX Audio Mixer MultiMedia1"

int tfa9887_open(void);
int tfa9887_power(bool on);
int tfa9887_set_mode(audio_mode_t mode);
int tfa9887_set_mute(bool on);
int tfa9887_close(void);

#endif
