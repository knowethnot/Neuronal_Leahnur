#include "train_data.h"

TrainData::getTopology(std::vector<unsigned> &topology)
{
	std::string line;
	std::stringlabel;

	std::getline(m_trainingDatum, line);
	std::stringstream ss(line);
	ss >> label;

	if (this->isEof() || label.compare("topology:") != 0)
	{
		abort();
	}

	while (!ss.eof())
	{
		unsigned n;
		ss >> n;
		topology.push_back(n);
	}

	return;
}

TrainData::TrainData(const std::string filename)
{
	m_trainingDatum.open(filename.c_str());
}

unsigned TrainData::retrieveNextInputs(std::vector<double> &inputVals)
{
	inputVals.clear();

	std::string line;
	std::getline(m_trainingDatum, line);
	std::stringstream ss(line);

	std::string label;
	ss >> label;

	if (label.compare("in:") == 0)
	{
		double oneVal;

		while (ss >> oneVal)
		{
			inputVals.push_back(oneVal)
		}
	}

	return inputVals.size();
}

unsigned TrainData::retrieve(std::vector<double> &targetOutputVals)
{
	targetOutputVals.clear();

	std::string line;
	std::getline(m_trainingDatum, line);
	std::stringstream ss(line);

	std::string label;
	ss >> label;

	if (label.compare("out:") == 0)
	{
		double oneVal;

		while (ss >> oneVal)
		{
			targetOutputVals.push_back(oneVal);
		}
	}

	return targetOutputVals.size();
}