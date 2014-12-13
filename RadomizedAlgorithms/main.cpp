//
//  main.cpp
//  RadomizedAlgorithms
//
//  Created by Michal Moskala on 13/12/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include <iostream>
#include "MonteCarloPICalculator.h"
#include "MaxCutAlgorithm.h"
#include "Vertex.h"
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
	MonteCarloPICalculator *piCalculator = new MonteCarloPICalculator();
	cout << piCalculator->estimatePIValue(100000) << endl;
	delete piCalculator;
	
	MaxCutAlgorithm *maxCutAlgorithm = new MaxCutAlgorithm();
	
	Vertex *v1 = new Vertex("v1");
	Vertex *v2 = new Vertex("v2");
	Vertex *v3 = new Vertex("v3");
	Vertex *v4 = new Vertex("v4");
	Vertex *v5 = new Vertex("v5");
	Vertex *v6 = new Vertex("v6");
	
	v1->addNeighbour(v2); v1->addNeighbour(v4);
	v2->addNeighbour(v1); v2->addNeighbour(v4); v2->addNeighbour(v5); v2->addNeighbour(v3);
	v3->addNeighbour(v2); v3->addNeighbour(v6);
	v4->addNeighbour(v1); v4->addNeighbour(v2); v4->addNeighbour(v5);
	v5->addNeighbour(v4); v5->addNeighbour(v2);
	v6->addNeighbour(v3);
	
	vector<Vertex*> vertices = vector<Vertex*>();
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
	vertices.push_back(v4);
	vertices.push_back(v5);
	vertices.push_back(v6);
	
	cout << maxCutAlgorithm->calculateMaxCut(vertices) << endl;
	delete maxCutAlgorithm;

  return 0;
}
