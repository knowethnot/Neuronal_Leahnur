#ifndef __AUDIOM_MANAGIS_HPP__
#define __AUDIOM_MANAGIS_HPP__

#include <fmodex/fmod.h>
#include <fmodex/fmod.hpp>
#include <fmodex/fmod_errors.h>
#include <string>

struct Soundeth_Filus_Datum
{
	int soundID;
	const std::string& file;
	const std::string& descriptor;
};

class AudiomManagis
{
	public:
		static AudiomManagis *Instance();

		void modFrequency(int numeric);
		void lowFrequency(int numeric);
		void haltFrequency(int numeric);
		void highFrequency(int numeric);
		void Update();

	protected:
		AudiomManagis();
		virtual ~AudiomManagis();

	private:
		static AudiomManagis *pr_Instance;

		FMOD::System* systema;
		FMOD::Sound* tone[2];
		FMOD::Channel* channel[2];

		bool halt_sound[2];
};

#endif // __AUDIOM_MANAGIS_HPP__