/*****************************************************************************
 * Copyright (c) 2014 Ted John
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * This file is part of OpenRCT2.
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "../common.h"
#include "../world/sprite.h"

#define AUDIO_DEVICE_NAME_SIZE 256
#define AUDIO_MAX_RIDE_MUSIC 2
#define AUDIO_MAX_VEHICLE_SOUNDS 14
#define NUM_DEFAULT_MUSIC_TRACKS 46

typedef struct audio_device {
	char name[AUDIO_DEVICE_NAME_SIZE];
} audio_device;

typedef struct rct_ride_music {
	uint8 ride_id;
	uint8 tune_id;
	sint16 volume;
	sint16 pan;
	uint16 frequency;
	void* sound_channel;
} rct_ride_music;

typedef struct rct_ride_music_info {
	uint32 length;
	uint32 offset;
	uint8 path_id;
	uint8 var_9;
} rct_ride_music_info;

typedef struct rct_ride_music_params {
	uint8 ride_id;
	uint8 tune_id;
	sint32 offset;
	sint16 volume;
	sint16 pan;
	uint16 frequency;
} rct_ride_music_params;

typedef struct rct_vehicle_sound {
	uint16 id;
	sint16 volume;
	uint16 sound1_id;
	sint16 sound1_volume;
	sint16 sound1_pan;
	uint16 sound1_freq;
	uint16 sound2_id;
	sint16 sound2_volume;
	sint16 sound2_pan;
	uint16 sound2_freq;
	void* sound1_channel;
	void* sound2_channel;
} rct_vehicle_sound;

typedef struct rct_vehicle_sound_params {
	uint16 id;
	sint16 pan_x;
	sint16 pan_y;
	uint16 frequency;
	sint16 volume;
	uint16 var_A;
} rct_vehicle_sound_params;

typedef enum RCT2_SOUND {
	SOUND_LIFT_1 = 0,
	SOUND_TRACK_FRICTION_1 = 1,
	SOUND_LIFT_2 = 2,
	SOUND_SCREAM_1 = 3,
	SOUND_CLICK_1 = 4,
	SOUND_CLICK_2 = 5,
	SOUND_PLACE_ITEM = 6,
	SOUND_SCREAM_2 = 7,
	SOUND_SCREAM_3 = 8,
	SOUND_SCREAM_4 = 9,
	SOUND_SCREAM_5 = 10,
	SOUND_SCREAM_6 = 11,
	SOUND_LIFT_3 = 12,
	SOUND_PURCHASE = 13,
	SOUND_CRASH = 14,
	SOUND_LAYING_OUT_WATER = 15,
	SOUND_WATER_1 = 16,
	SOUND_WATER_2 = 17,
	SOUND_TRAIN_WHISTLE = 18,
	SOUND_TRAIN_CHUGGING = 19,
	SOUND_WATER_SPLASH = 20,
	SOUND_HAMMERING = 21,
	SOUND_RIDE_LAUNCH_1 = 22,
	SOUND_RIDE_LAUNCH_2 = 23,
	SOUND_COUGH_1 = 24,
	SOUND_COUGH_2 = 25,
	SOUND_COUGH_3 = 26,
	SOUND_COUGH_4 = 27,
	SOUND_RAIN_1 = 28,
	SOUND_THUNDER_1 = 29,
	SOUND_THUNDER_2 = 30,
	SOUND_RAIN_2 = 31,
	SOUND_RAIN_3 = 32,
	SOUND_BALLOON_POP = 33,
	SOUND_MECHANIC_FIX = 34,
	SOUND_SCREAM_7 = 35,
	SOUND_TOILET_FLUSH = 36,
	SOUND_CLICK_3 = 37,
	SOUND_QUACK = 38,
	SOUND_NEWS_ITEM = 39,
	SOUND_WINDOW_OPEN = 40,
	SOUND_LAUGH_1 = 41,
	SOUND_LAUGH_2 = 42,
	SOUND_LAUGH_3 = 43,
	SOUND_APPLAUSE = 44,
	SOUND_HAUNTED_HOUSE_SCARE = 45,
	SOUND_HAUNTED_HOUSE_SCREAM_1 = 46,
	SOUND_HAUNTED_HOUSE_SCREAM_2 = 47,
	SOUND_48 = 48,
	SOUND_49 = 49,
	SOUND_ERROR = 50,
	SOUND_51 = 51,
	SOUND_LIFT_4 = 52,
	SOUND_LIFT_5 = 53,
	SOUND_TRACK_FRICTION_2 = 54,
	SOUND_LIFT_6 = 55,
	SOUND_LIFT_7 = 56,
	SOUND_TRACK_FRICTION_3 = 57,
	SOUND_SCREAM_8 = 58,
	SOUND_TRAM = 59,
	SOUND_DOOR_OPEN = 60,
	SOUND_DOOR_CLOSE = 61,
	SOUND_62 = 62,
	SOUND_MAXID
} RCT2_SOUND;

extern audio_device *gAudioDevices;
extern int gAudioDeviceCount;
extern void *gCrowdSoundChannel;
extern bool gGameSoundsOff;
extern void *gRainSoundChannel;
extern rct_ride_music gRideMusicList[AUDIO_MAX_RIDE_MUSIC];
extern rct_ride_music_info *gRideMusicInfoList[NUM_DEFAULT_MUSIC_TRACKS];
extern rct_ride_music_params gRideMusicParamsList[AUDIO_MAX_RIDE_MUSIC];
extern rct_ride_music_params *gRideMusicParamsListEnd;
extern void *gTitleMusicChannel;
extern rct_vehicle_sound gVehicleSoundList[AUDIO_MAX_VEHICLE_SOUNDS];
extern rct_vehicle_sound_params gVehicleSoundParamsList[AUDIO_MAX_VEHICLE_SOUNDS];
extern rct_vehicle_sound_params *gVehicleSoundParamsListEnd;

/**
* Deregisters the audio device.
*/
void audio_close();
/*
* Initialises the audio subsystem.
*/
void audio_init();
/**
* Loads the ride sounds and info.
*/
void audio_init_ride_sounds_and_info();
/**
Loads the ride sounds.
*/
void audio_init_ride_sounds(int device);
/**
* Temporarily stops playing sounds until audio_unpause_sounds() is called.
*/
void audio_pause_sounds();
/**
* Populates the gAudioDevices array with the available audio devices.
*/
void audio_populate_devices();
/**
* Terminates the audio subsystem.
* This appears to be unused.
*/
void audio_quit();
/** Plays the specified sound effect at the specified virtual location.
* @param soundId The sound effect to play.
* @param mode If set to 0x8001, play the sound at the specified location; if
* set to 0x8000, play the sound at the center of the viewport; if set to
* anything else, use the value of mode as a relative position to the center of
* the viewport.
* @param x The x coordinate of the location.
* @param y The y coordinate of the location.
* @param z The z coordinate of the location.
* @return 0 if the sound was played successfully, otherwise, soundId.
*/
int audio_sound_play_panned(int soundId, int mode, sint16 x, sint16 y, sint16 z);
/**
* Starts playing the title music.
*/
void audio_start_title_music();
/**
* Stops the crowd sound effect from playing.
*/
void audio_stop_crowd_sound();
/**
* Stops the rain sound effect from playing.
*/
void audio_stop_rain_sound();
/**
* Stops ride music from playing.
*/
void audio_stop_ride_music();
/**
* Stops the title music from playing.
*/
void audio_stop_title_music();
/**
* Stops vehicle sounds from playing.
*/
void audio_stop_vehicle_sounds();
/**
* Toggles whether all sounds should be played.
*/
void audio_toggle_all_sounds();
/**
* Resumes playing sounds that had been paused by a call to
* audio_pause_sounds().
*/
void audio_unpause_sounds();

#endif
