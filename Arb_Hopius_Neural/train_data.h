#ifndef __TRAIN_DATA_H__
#define __TRAIN_DATA_H__

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

class TrainData
{
	public:
		TrainData(const std::string filename);
		bool isEOF(void) { return m_trainingDatum.eof(); }
		void getTopology(std::vector<unsigned> &topology);

		unsigned retrieveNextInputs(std::vector<double> &inputVals);
		unsigned retrieveTargetOutputs(std::vector<double> &targetOutputVals);

	private:
		std::ifstream m_trainingDatum;
}

#endif	// __TRAIN_DATA_H__