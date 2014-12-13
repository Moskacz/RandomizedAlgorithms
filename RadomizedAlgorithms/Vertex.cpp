//
//  Vertex.cpp
//  RadomizedAlgorithms
//
//  Created by Michal Moskala on 13/12/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include "Vertex.h"

Vertex::Vertex(string name) {
	this->name = name;
	this->neighbours = vector<Vertex*>();
}

void Vertex::addNeighbour(Vertex *vertex) {
	this->neighbours.push_back(vertex);
}

bool Vertex::isNeighbour(Vertex *vertex) {
	for (vector<Vertex*>::iterator it = neighbours.begin(); it != neighbours.end(); it++) {
		if (vertex == *it) {
			return true;
		}
	}
	return false;
}

string Vertex::getName() {
	return this->name;
}
