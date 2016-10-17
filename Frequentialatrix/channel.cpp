#include "channel.hpp"

// TODO: Improve Upon Set Math Functions Cos & Sin

Channel::Channel() : _audiom(0), _position(0)
{
	// Ctor Quick Initialization	
}

void Channel::EmitAudiom(Frequencieum* audio)
{
	_audiom = audio;
	_position = 0;
}

void Channel::HaltAudiom()
{
	_audiom = 0;
}

void Channel::RecordAudioDatum(pcm16* data, int count)
{
	if (_audiom == 0 || _paused) return;

	for (int i = 0; i < count; i += 2)
	{
		if (_position >= _audiom->count)
		{
			if (_loop) _position = 0;
			else
			{
				HaltAudiom();
				return;
			}
		}

		float value = (pcm16)(_audiom->data[(int)_f_position] * _volume);

		data[i] = (pcm16)(value * _left_gain + data[i]);
		data[i+1] = (pcm16)(value * _right_gain + data[i+1]);

		_f_position += _pitch;
	}
}

void Channel::SetVolume(float val)
{
	if (val < 0.0f) _volume = 0.0f;
	else if (val > 1.0f) _volume = 1.0f;
	else { _volume = val; }
}

void Channel::SetPitch(float val)
{
	if (val < 0.25f) _pitch = 0.25f;
	else if (val > 4.0f) _pitch = 4.0f;
	else { _pitch = val; }
}

void Channel::SetPan(float val)
{
	if (val < -1.0f) _pan = -1.0f;
	else if (val > 1.0f) _pan = 1.0f;
	else { _pan = val; }
}

void Channel::U_LinearPan()
{
	float pos = _pan * 0.5f;
	_left_gain = 0.5f - pos;
	_right_gain = pos + 0.5f;
}

void Channel::U_ConstPowerPan()
{
	double theta = _pan * _pi_4;
	_left_gain = (float)(_sqrt_2 * (cos(theta) - sin(theta)));
	_right_gain = (float)(_sqrt_2 * (cos(theta) + sin(theta)));
}