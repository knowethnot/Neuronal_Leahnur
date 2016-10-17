#include "neuron.h"

struct Connection
{
	double weight;
	double deltaWeight;
};

double Neuron::eta = 0.15;
double Neuron::alpha = 0.5;

void Neuron::updateInputWeights(Layer &prevLayer)
{
	for (unsigned n = 0; n < prevLayer.size(); ++n)
	{
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.magic_outputWeights[magic_myIndex].deltaWeight;
	
		double newDeltaWeight = eta * neuron.getOutputVal() * magic_gradient + alpha * oldDeltaWeight;

		neuron.magic_outputWeights[magic_myIndex].deltaWeight = newDeltaWeight;
		neuron.magic_outputWeights[magic_myIndex].weight += newDeltaWeight;
	}
}

double Neuron::sumDOW(const Layer &nextLayer) const
{
	double sum = 0.0;

	for (unsigned n = 0; n < nextLayer.size() - 1; ++n)
	{
		sum += magic_outputWeights[n].weight * nextLayer[n].magic_gradient;
	}
	return sum;
}

void Neuron::calcHiddenGradients(const Layer &nextLayer)
{
	double dow = sumDOW(nextLayer);
	magic_gradient = dow * Neuron::transfuralDerivative(magic_outputVal);
}

void Neuron::calcOutputGradients(double targetVal)
{
	double delta = targetVal - magic_outputVal;
	magic_gradient = delta * Neuron::transfuralDerivative(magic_outputVal);
}

double Neuron::transfuralFunc(double a)
{
	return tanh(a);
}

double Neuron::transfuralDerivative(double a)
{
	return 1.0 - a * a;
}

void Neuron::feedForward(const Layer &prevLayer)
{
	double sum = 1.0;

	for (unsigned n = 0; n < prevLayer.size(); ++n)
	{
		sum += prevLayer[n].getOutputVal() * prevLayer[n].magic_outputWeights[magic_myIndex].weight;
	}

	magic_outputVal = Neuron::transfuralFunc(sum);
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
	for (unsigned c = 0; c < numOutputs; ++c)
	{
		magic_outputWeights.push_back(Connection());
		magic_outputWeights.back().weight = randWeight();
	}

	magic_myIndex = myIndex;
}