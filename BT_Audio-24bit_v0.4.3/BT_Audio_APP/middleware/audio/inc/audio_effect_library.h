/**
 *************************************************************************************
 * @file	audio_effect_library.h
 * @brief	Audio Effect Library
 *
 * @author	ZHAO Ying (Alfred)
 * @version	@see AUDIO_EFFECT_LIBRARY_VERSION
 *
 * &copy; Shanghai Mountain View Silicon Co.,Ltd. All rights reserved.
 *************************************************************************************
 */

#ifndef __AUDIO_EFFECT_LIBRARY_H__
#define __AUDIO_EFFECT_LIBRARY_H__

// audio effect headers
#include "adpcm_codec.h"
#include "auto_tune.h"
#include "auto_wah.h"
#include "beat_tracker.h"
#include "blue_aec.h"
#include "blue_ns.h"
#include "blue_ns_dual.h"
#include "chorus.h"
#include "chorus2.h"
#include "compander.h"
#include "dc_blocker.h"
#include "distortion_ds1.h"
#include "distortion_exp.h"
#include "drc.h"
#include "echo.h"
#include "engine_sound.h"
#include "eq.h"
#include "eq_drc.h"
#include "exciter.h"
#include "expander.h"
#include "fader.h"
#include "flanger.h"
#include "freqshifter.h"
#include "freqshifter_fine.h"
#include "howling_guard.h"
#include "howling_suppressor.h"
#include "howling_suppressor_fine.h"
#include "low_level_compressor.h"
#include "mixer.h"
#include "noise_gate.h"
#include "overdrive.h"
#include "overdrive_poly.h"
#include "pcm_delay.h"
#include "phase_shifter.h"
#include "pingpong.h"
#include "pitch_detector.h"
#include "pitch_shifter.h"
#include "pitch_shifter_pro.h"
#include "reverb.h"
#include "reverb_plate.h"
#include "reverb_pro.h"
#include "silence_detector.h"
#include "stereo_widener.h"
#include "three_d.h"
#include "three_d_plus.h"
#include "virtual_bass.h"
#include "virtual_bass_td.h"
#include "virtual_bass_classic.h"
#include "virtual_surround.h"
#include "vocal_remover.h"
#include "voice_changer.h"
#include "voice_changer_pro.h"


// audio effect library version
#define AUDIO_EFFECT_LIBRARY_VERSION "2.29.0"

// audio effect versions (Info below is for convenience only. In case of any contradiction, the version info in the respective file header shall prevail.)
#define EFFECT_VERSION_ADPCM_CODEC                  "2.0.1"
#define EFFECT_VERSION_AUTO_TUNE                    "1.3.0"
#define EFFECT_VERSION_AUTO_WAH                     "1.1.1"
#define EFFECT_VERSION_BEAT_TRACKER                 "1.1.1"
#define EFFECT_VERSION_BLUE_AEC                     "6.6.1"
#define EFFECT_VERSION_BLUE_NS                      "2.1.1"
#define EFFECT_VERSION_BLUE_NS_DUAL                 "1.4.1"
#define EFFECT_VERSION_CHORUS                       "1.2.1"
#define EFFECT_VERSION_CHORUS2                      "2.0.0"
#define EFFECT_VERSION_COMPANDER                    "1.0.2"
#define EFFECT_VERSION_DC_BLOCKER                   "1.1.1"
#define EFFECT_VERSION_DISTORTION_DS1				"1.1.2"
#define EFFECT_VERSION_DISTORTION_EXP				"1.0.0"
#define EFFECT_VERSION_DYNAMIC_RANGE_COMPRESSOR     "4.1.0"
#define EFFECT_VERSION_ECHO                         "2.1.0"
#define EFFECT_VERSION_ENGINE_SOUND                 "1.1.0"
#define EFFECT_VERSION_EQ                           "8.3.1"
#define EFFECT_VERSION_EQ_DRC                       "1.1.0"
#define EFFECT_VERSION_EXCITER				        "1.3.0"
#define EFFECT_VERSION_EXPANDER                     "1.2.2"
#define EFFECT_VERSION_FADER						"1.0.1"
#define EFFECT_VERSION_FLANGER				        "1.0.1"
#define EFFECT_VERSION_FREQUENCY_SHIFTER            "1.7.0"
#define EFFECT_VERSION_FREQUENCY_SHIFTER_FINE       "2.1.0"
#define EFFECT_VERSION_HOWLING_GUARD                "1.1.0"
#define EFFECT_VERSION_HOWLING_SUPPRESSOR           "2.0.1"
#define EFFECT_VERSION_HOWLING_SUPPRESSOR_FINE      "3.1.0"
#define EFFECT_VERSION_LOW_LEVEL_COMPRESSOR         "1.0.0"
#define EFFECT_VERSION_MIXER                        "1.0.0"
#define EFFECT_VERSION_NOISE_GATE                   "2.1.0"
#define EFFECT_VERSION_OVERDRIVE					"1.0.0"
#define EFFECT_VERSION_OVERDRIVE_POLY				"2.0.0"
#define EFFECT_VERSION_PCM_DELAY                    "2.1.0"
#define EFFECT_VERSION_PHASE_SHIFTER				"1.1.0"
#define EFFECT_VERSION_PINGPONG						"1.4.1"
#define EFFECT_VERSION_PITCH_DETECTOR               "2.1.1"
#define EFFECT_VERSION_PITCH_SHIFTER                "1.7.7"
#define EFFECT_VERSION_PITCH_SHIFTER_PRO            "2.2.0"
#define EFFECT_VERSION_REVERB                       "1.9.2"
#define EFFECT_VERSION_REVERB_PLATE                 "2.2.0"
#define EFFECT_VERSION_REVERB_PRO                   "1.3.1"
#define EFFECT_VERSION_SILENCE_DETECTOR             "1.2.0"
#define EFFECT_VERSION_STEREO_WIDENER               "1.3.1"
#define EFFECT_VERSION_3D                           "3.4.0"
#define EFFECT_VERSION_3D_PLUS                      "1.0.2"
#define EFFECT_VERSION_VIRTUAL_BASS                 "4.4.2"
#define EFFECT_VERSION_VIRTUAL_BASS_TD              "4.1.6"
#define EFFECT_VERSION_VIRTUAL_BASS_CLASSIC         "3.17.0"
#define EFFECT_VERSION_VIRTUAL_SURROUND             "1.1.1"
#define EFFECT_VERSION_VOCAL_REMOVER                "1.3.2"
#define EFFECT_VERSION_VOICE_CHANGER                "1.6.3"
#define EFFECT_VERSION_VOICE_CHANGER_PRO            "2.5.0"


#endif // __AUDIO_EFFECT_LIBRARY_H__