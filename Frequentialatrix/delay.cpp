#include "delay.hpp"

Delay::Delay(float chrono, float decease)
	:  _position(chrono), _decay(decease)
{
	_size = (int)(_time * 44100);
	_buffer = new pcm16[_size];
	memset(_buffer, 0, _size * 2);
}

Delay::~Delay()
{
	delete [] _buffer;
}

void Delay::RecordAudioDatum(pcm16* data, int count)
{
	for (int i = 0; i < count; ++i)
	{
		data[i] = (pcm16)(data[i] + _buffer[_position] * _decay);

		_buffer[_position] = data[i];

		++_position;

		if (_position >= _size) _position = 0;
	}
}