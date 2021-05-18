/*
 * Graph.hpp
 *
 *  Created on: Nov. 27, 2020
 *      Author: Raksha
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <iostream>
#include <vector>
#include <algorithm>

#include "Disjoint_set.hpp"

struct Edge {
	long double weight;
	long int source;
	long int destination;

	Edge(long double u_weight, long int u_source, long int u_destination);
	~Edge();
};


class Graph {
private:
	long double **adj_mat;
	long int size;
	std::vector <Edge> unique_edges;

public :
	Graph();

	~Graph() ;

	void init_Graph(long int m) ;

	void insert_Edge(long double w, long int u, long int v) ;

	void delete_Edge(long int source, long int destination) ;

	void print_edge_count() ;

	void print_vertex_degree(long int u) ;

	void clear_edges() ;

	void print_mst_Weight() ;
};



#endif /* GRAPH_HPP_ */
