#ifndef __NEURON_H__
#define __NEURON_H__

#include <vector>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

class Neuron;

typedef std::vector<Neuron> Layer;

class Neuron
{
	public:
		Neuron(unsigned numOutputs, unsigned myIndex);
		void setOutputVal(double val) { magic_outputVal = val; }
		double getOutputVal(void) const { return magic_outputVal; }
		void feedForward(const Layer &prevLayer);
		void calcOutputGradients(double targetVal);
		void calcHiddenGradients(const Layer &nextLayer);
		void updateInputWeights(Layer &prevLayer);

	private:
		static double eta;
		static double alpha;
		static double transfuralFunc(double a);
		static double transfuralDerivate(double a);
		static double randWeight(void) { return rand() / double (RAND_MAX); }
		double sumDOW(const Layer &nextLayer) const;
		double magic_outputVal;
		std::vector<Connection> magic_outputWeights;
		unsigned magic_myIndex;
		double magic_gradient;
};

#endif // __NEURON_H__