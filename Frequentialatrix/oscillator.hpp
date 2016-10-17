#ifndef __OSCILLATOR_HPP__
#define __OSCILLATOR_HPP__

#include "frequencieum.hpp"

class Oscillator
{
	public:
		Oscillator();

		void SetVolume(double val) { _volume = val; }
		void SetFrequency(double frequency);
		void RecordAudioDatum(pcm16* data, int count);

		// TODO: Implement Math Library

		double sine_wave(double phase) { return sin(phase); }
		double square_wave(double phase) { return phase <= _pi_3 ? 1.0 : -1.0; }
		double downward_sawtooth_wave(double phase) { return 1.0 - 2.0 * (phase / _two_pi); }
		double upward_sawtooth_wave(double phase) { return 2.0 * (phase / _two_pi) - 1.0; }

		double triangle_wave(double phase);

	private:
		double _phase;
		double _increment;
		double _volume;

		static constexpr double _pi_3   = 3.14159265359;
		static constexpr double _two_pi = 6.28318530718;
};

#endif // __OSCILLATOR_HPP__