#include "train_data.h"
#include "neuro_net.h"
#include "neuron.h"

void showVectorVals(std::string label, std::vector<double> &v)
{
	std::cout << label << " ";

	for (unsigned i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}

	std::cout << "\n" << std::endl;
}

int main()
{
	TrainData data("/*directory containing input*/");

	std::vector<unsigned> topology;
	data.getTopology(topology);
	NeuroNet net(topology);

	std::vector<double> inputVals, targetVals, resultVals;
	int trainPass = 0;

	while (!data.isEOF())
	{
		++trainPass;
		std::cout << "\n" << "Pass " << trainPass;

		if (data.retrieveNextInputs(inputVals) != topology[0])
		{
			break;
		}

		showVectorVals("| Inputs:", inputVals);
		net.feedForward(inputVals);

		net.getResults(resultVals);
		showVectorVals("Outputs:", resultVals);

		data.retrieveTargetOutputs(targetVals);
		showVectorVals("Targets:", targetVals);
		std::assert(targetVals.size() == topology.back());
	}
	std::cout << "\nFinish......." << std::endl;
}