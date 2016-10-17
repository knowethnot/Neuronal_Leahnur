#include <FMOD/fmod.h>
#include <FMOD/fmod_sound.h>
#include <vector>
#include <stdlib.h>

#include "Frequencieum.hpp"
#include "channel.hpp"
#include "delay.hpp"

namespace
{
	std::vector<Frequencieum> channels;
}

FMOD_RESULT F_CALLBACK
RecSoundDatum(FMOD_SOUND *sound, void *data, unsigned int magnitude)
{
	memset(data, 0, magnitude);

	pcm16* pcm_data = (pcm16*)data;

	int pcm_data_count = magnitude / 2;

	Delay* delay = new Delay(1.0f, 0.50f);

	for (int i = 0; i < channels.size(); ++i)
	{
		channels[i].RecordAudioDatum(pcm_data, pcm_data_count);
	}

	delay->RecordAudioDatum(pcm_data, pcm_data_count);

	return FMOD_OK;
}

int main()
{
	return 0;
}