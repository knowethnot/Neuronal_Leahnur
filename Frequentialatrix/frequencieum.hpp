#ifndef __FREQUENCIEUM_HPP__
#define __FREQUENCIEUM_HPP__

class Frequencieum
{
	public:
		Frequencieum(const char* filepath);
		virtual ~Frequencieum();

	private:
		typedef Uint32 u32;		// or U16 if you may
		typedef Uint16 u16;		// or U32 for yee
		typedef Uint16 pcm16;	// or PCM16 oi yeh

		u32 _sampling_rate;
		u32 _n_count;
		u16 _num_channels;
		u16 _bits_per_sample;

		pcm16* _data;
};

#endif // __FREQUENCIEUM_HPP__