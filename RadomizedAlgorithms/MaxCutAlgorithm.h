//
//  MaxCutAlgorithm.h
//  RadomizedAlgorithms
//
//  Created by Michal Moskala on 13/12/14.
//  Copyright (c) 2014 Michal Moskala. All rights reserved.
//

#ifndef __RadomizedAlgorithms__MaxCutAlgorithm__
#define __RadomizedAlgorithms__MaxCutAlgorithm__

#include <stdio.h>
#include "Vertex.h"

class MaxCutAlgorithm {
private:
	int maxCut(vector<Vertex*> firstSubgraph, vector<Vertex*> secondSubgraph);
	void printSubgraphs(vector<Vertex*> firstSubgraph, vector<Vertex*> secondSubgraph);
	void addToSubgraphIfNeighbour(vector<Vertex*> &vertices, Vertex* vertex);
	
public:
	int calculateMaxCut(vector<Vertex*> vertices);
};

#endif /* defined(__RadomizedAlgorithms__MaxCutAlgorithm__) */
