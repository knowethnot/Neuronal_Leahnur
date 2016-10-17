#include "frequencieum.hpp"

#include <iostream>
#include <fstream>

Frequencieum::Frequencieum(const char* filepath);
{
	std::ifstream file(filepath, std::ios::in | std::ios::binary);

	file.seekg(22);
	file.read((char*)&_num_channels, 2);
	file.read((char*)&_sampling_rate, 4);

	file.seekg(34);
	file.read((char*)&_bits_per_sample, 2);

	file.seekg(34);
	file.read((char*)&_bits_per_sample, 2);

	u32 length;
	file.seekg(40);
	file.read((char*)&length, 4);

	_n_count = (length >> 1);	// essentially (|L| / 2)
	_data = new pcm16[_n_count];

	file.read((char*)_data, length);
}

Frequencieum::~Frequencieum()
{
	delete [] _data;
}