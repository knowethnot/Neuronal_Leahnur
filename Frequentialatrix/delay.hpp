#ifndef __DELAY_HPP__
#define __DELAY_HPP__

#include "frequencieum.hpp"

class Delay
{
	public:
		Delay(float chrono, float decease);
		~Delay();

		void RecordAudioDatum(pcm16* data, int count);

	private:
		pcm16* _buffer;

		int    _size;
		int	   _position;

		float	_decay;
};

#endif // __DELAY_HPP__