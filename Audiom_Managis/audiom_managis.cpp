#include "audiom_managis.hpp"

#include <cstdlib>
#include <stdio.h>

AudiomManagis *AudiomManagis::pr_Instance = 0;

AudiomManagis *AudiomManagis::Instance()
{
	if (AudiomManagis::pr_Instance == 0)
	{
		AudiomManagis::pr_Instance = new AudiomManagis;
	}

	return AudiomManagis::pr_Instance;
}

AudiomManagis::AudiomManagis()
{
	FMOD_RESULT result = FMOD::System_Create(&systema);

	systema->init(512, FMOD_INIT_NORMAL, 0);
	
	if (result != FMOD_OK)
	{
		printf("FMOD_ERROR: (%d) %s", result, FMOD_ErrorString(result));
		exit(-1);
	}

	result = systema->createSound(".mp3", FMOD_LOOP_NORMAL, 0, &tone[0]);
	result = systema->createSound(".mp3", FMOD_LOOP_NORMAL, 0, &tone[1]);

	channel[0] = 0;
	channel[1] = 0;

	halt_sound[0] = false;
	halt_sound[1] = false;
}

AudiomManagis::~AudiomManagis()
{
	FMOD_RESULT result;

	result = tone[0]->release();
	result = tone[1]->release();
	result = systema->close();
	result = systema->release();
}

void AudiomManagis::modFrequency(int numeric)
{
	FMOD_RESULT result;
	channel[numeric]->isPlaying(&halt_sound[numeric]);

	if (halt_sound[numeric] == false)
	{
		result = systema->playSound(FMOD_CHANNEL_FREE, tone[numeric], false, &channel[numeric]);
	}
}

void AudiomManagis::lowFrequency(int numeric)
{
	channel[numeric]->stop();	
}

void AudiomManagis::haltFrequency(int numeric)
{
	channel[numeric]->setPaused(true);
}

void AudiomManagis::highFrequency(int numeric)
{
	channel[numeric]->setPaused(false);
}

void AudiomManagis::Update()
{
	systema->update();
}