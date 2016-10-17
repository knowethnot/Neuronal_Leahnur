#ifndef __NEURO_NET_H__
#define __NEURO_NET_H__

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

class NeuroNet {

	public:
		 NeuroNet(const std::vector<unsigned> &topology);
		 void feedForward(const std::vector<double> &inputVals);
		 void backPropagation(const std::vector<double> &targetVals);
		 void getInitialResults(std::vector<double> &resultVals)const;
		 double getRecentAvgError(void) const { return m_recentAvgError; }

	private:
		std::vector<Layer> m_layers;
		double m_error;
		double m_recentAvgError;
		double m_recentAvgSmoothingFactor;
};

#endif // __NEURO_NET_H__