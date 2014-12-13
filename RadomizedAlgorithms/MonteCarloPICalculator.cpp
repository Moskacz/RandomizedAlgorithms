//
//  MonteCarloPICalculator.cpp
//  RadomizedAlgorithms
//
//  Created by Michal Moskala on 13/12/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include "MonteCarloPICalculator.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

float MonteCarloPICalculator::estimatePIValue(int stepsCount) {
	srand((unsigned)time(NULL));
	
	int insidePointCount = 0;
	
	for (int i = 0; i < stepsCount; i++) {
		float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float y = static_cast <float> (rand()) / static_cast<float>(RAND_MAX);		
		if (isPointInsideCircle(x, y, 1.0)) {
			insidePointCount++;
		}
	}
	
	return insidePointCount * 4 / (float) stepsCount;
}


bool MonteCarloPICalculator::isPointInsideCircle(float x, float y, float r) {	
	return (pow(x, 2) + pow(y, 2)) < pow(r, 2);
}