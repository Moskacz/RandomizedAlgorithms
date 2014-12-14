//
//  MaxCutAlgorithm.cpp
//  RadomizedAlgorithms
//
//  Created by Michal Moskala on 13/12/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#include "MaxCutAlgorithm.h"
#include <time.h>
#include <iostream>
#define INTERATIONS 10000;

int MaxCutAlgorithm::calculateMaxCut(vector<Vertex *> vertices) {
	int MaxCut = 0;
	int iterations = INTERATIONS;
	srand((unsigned)time(NULL));
	
	while(true) {
		vector<Vertex*> firstSubgraph = vector<Vertex*>();
		vector<Vertex*> secondSubgraph = vector<Vertex*>();
		
		while (true) {
			bool shouldBreak = true;
			for (vector<Vertex*>::iterator it = vertices.begin(); it != vertices.end(); it++) {
				if ((*it)->tag == -1) {
					shouldBreak = false;
					(*it)->tag = rand() % 2;
					if ((*it)->tag == 0) {
						addToSubgraphIfNeighbour(firstSubgraph, *it);
					} else {
						addToSubgraphIfNeighbour(secondSubgraph, *it);
					}
				}
			}
			
			if (shouldBreak) {
				break;
			}
		}
		
	
		int cut = this->maxCut(firstSubgraph, secondSubgraph);		
		if (cut > MaxCut) {
			MaxCut = cut;
			iterations = INTERATIONS;
			printSubgraphs(firstSubgraph, secondSubgraph);
			continue;
		}
		
		iterations -= 1;
		if (iterations == 0) {
			break;
		}
	}
	
	return MaxCut;
}


int MaxCutAlgorithm::maxCut(vector<Vertex *> firstSubgraph, vector<Vertex *> secondSubgraph) {
	int cut = 0;
	for (vector<Vertex*>::iterator it = firstSubgraph.begin(); it != firstSubgraph.end(); it++) {
		for (vector<Vertex*>::iterator it2 = secondSubgraph.begin(); it2 != secondSubgraph.end(); it2++) {
			if ((*it)->isNeighbour(*it2)){
				cut++;
			}
		}
	}
	return cut;
}

void MaxCutAlgorithm::printSubgraphs(vector<Vertex *> firstSubgraph, vector<Vertex *> secondSubgraph) {
	cout << "=======================" << endl;
	cout << "First subgraph: " << endl;
	for (vector<Vertex*>::iterator it = firstSubgraph.begin(); it != firstSubgraph.end(); it++) {
		cout << (*it)->getName() << " ";
	}
	cout << endl << "Second subgraph: " << endl;
	for (vector<Vertex*>::iterator it = secondSubgraph.begin(); it != secondSubgraph.end(); it++) {
		cout << (*it)->getName() << " ";
	}
	cout << endl;
}

void MaxCutAlgorithm::addToSubgraphIfNeighbour(vector<Vertex *> &vertices, Vertex *vertex) {
	if (vertices.empty()) {
		vertices.push_back(vertex);
	} else {
		bool didAddToVector = false;
		for (vector<Vertex*>::iterator it = vertices.begin(); it != vertices.end(); it++) {
			if ((*it)->isNeighbour(vertex)) {
				vertices.push_back(vertex);
				didAddToVector = true;
				break;
			}
		}
		
		if (!didAddToVector) {
			vertex->tag = -1;
		}
	}
}