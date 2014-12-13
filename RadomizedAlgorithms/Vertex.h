//
//  Vertex.h
//  RadomizedAlgorithms
//
//  Created by Michal Moskala on 13/12/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#ifndef __RadomizedAlgorithms__Vertex__
#define __RadomizedAlgorithms__Vertex__

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Vertex {
private:
	vector<Vertex*> neighbours;
	string name;
	
public:
	int tag;
	Vertex(string name);
	void addNeighbour(Vertex *vertex);
	bool isNeighbour(Vertex* vertex);
	string getName();
};

#endif /* defined(__RadomizedAlgorithms__Vertex__) */
