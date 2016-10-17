#ifndef __CHANNEL_HPP__
#define __CHANNEL_HPP__

#include "frequencieum.hpp"

class Channel
{
	public:
		Channel();

		void EmitAudiom(Frequencieum* audio);
		void HaltAudiom();
		void RecordAudioDatum(pcm16* data, int count);

		bool GetPaused() const { return _paused; }
		void SetPaused(bool val) { _paused = val; }

		bool GetLoop() const { return _loop; }
		void SetLoop(bool val) { _loop = val; }

		float GetVolume() const { return _volume; }
		void SetVolume(float val);

		float GetPitch() const { return _pitch; }
		void SetPitch(float val);

		float GetPan() const { return _pan; }
		void SetPan(float val);

	private:
		void U_LinearPan();
		void U_ConstPowerPan();

		Channel* _audiom;

		int _position;

		bool _paused;
		bool _loop;

		float _volume;
		float _f_position;
		float _pitch;
		float _left_gain;
		float _right_gain;
		float _pan;

		static constexpr double _pi_4 	= 0.78539816339;
		static constexpr double _sqrt_2	= 0.70710678118;
};

#endif // __CHANNEL_HPP__