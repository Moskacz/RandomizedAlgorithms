//
//  MonteCarloPICalculator.h
//  RadomizedAlgorithms
//
//  Created by Michal Moskala on 13/12/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#ifndef __RadomizedAlgorithms__MonteCarloPICalculator__
#define __RadomizedAlgorithms__MonteCarloPICalculator__

#include <stdio.h>

class MonteCarloPICalculator {
private:
	bool isPointInsideCircle(float x, float y, float r);
public:
	float estimatePIValue(int stepsCount);
};

#endif /* defined(__RadomizedAlgorithms__MonteCarloPICalculator__) */
