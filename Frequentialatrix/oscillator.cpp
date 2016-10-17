#include "oscillator.hpp"

Oscillator::Oscillator() : _phase(0.0), _volume(0.5)
{
	SetFrequency(440.0);
}

void Oscillator::SetFrequency(double frequency)
{
	_increment = frequency / 44100.0 * _two_pi;
}

void Oscillator::RecordAudioDatum(pcm16* data, int count)
{
	for (int i = 0; i < count; i += 2)
	{
		double value = sine_wave(_phase) * 32767.0 * _volume;

		data[i] = (pcm16)(data[i] + value);
		data[i+1] = (pcm16)(data[i+1] + value);

		_phase += _increment;

		if (_phase >= _two_pi) _phase -= _two_pi;
	}
}

double triangle_wave(double phase)
{
	double result = upward_sawtooth_wave(phase);
	if (result < 0.0) result = -result;
	return 2.0 * (result - 0.5);
}