/*
 * kruskaltest.cpp
 *
 *  Created on: Dec. 2, 2020
 *      Author: Raksha
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>

#include "Disjoint_set.hpp"
#include "Graph.hpp"
#include "invalid.hpp"

#define TOLERANCE 0.00001

/// struct Edge Definitions
Edge::Edge(long double u_weight, long int u_source, long int u_destination){
	weight = u_weight;
	source = u_source;
	destination = u_destination;
}

Edge::~Edge(){};


//// Graph class definitions
Graph::Graph() {
	size=0;
	adj_mat = nullptr;
}

Graph::~Graph() {
	for(long int i=0; i<size; i++){
		delete[] adj_mat[i];
	}

	if (size != 0){
		delete[] adj_mat;
		unique_edges.clear();
	}
}

void Graph::init_Graph(long int m) {
	if (m <= 0){
		throw Invalid();
		return;
	}

	size=m;
	adj_mat = new long double *[size];

	for(long int i=0; i<size; i++){
		adj_mat[i] = new long double [size];
	}

	for (long int i=0; i<size; i++){
		for (long int j=0; j<size; j++){
			adj_mat[i][j] = -1.0;
		}
	}

	std::cout<<"success"<<std::endl;
}

void Graph::insert_Edge(long double w, long int u, long int v){
	if ( u<0 || v<0 || u >= size || v >= size || (w*(-1)) >= 0 ) {
		throw Invalid();
		return;
	}

	Edge edge(w,u,v);

	if (edge.destination < edge.source){
		std::swap (edge.destination, edge.source);
	}

	if (adj_mat[edge.source][edge.destination] != -1.0){
		// reference - https://www.geeksforgeeks.org/introduction-iterators-c/
		std::vector<Edge>::iterator pos;

		pos = std::find_if(unique_edges.begin(), unique_edges.end(), [edge](Edge& f){ return (edge.source == f.source)&& (edge.destination == f.destination); });
		pos->weight = edge.weight;
	}
	else{
		unique_edges.push_back(edge);
	}

	adj_mat[edge.source][edge.destination] = edge.weight;
	adj_mat[edge.destination][edge.source] = edge.weight;

	std::cout<<"success"<<std::endl;
}

void Graph::delete_Edge(long int source, long int destination){
	if ( source < 0 || destination < 0 || destination >= size || source >= size ) {
		throw Invalid();
		return;
	}

	if (adj_mat[source][destination] == -1.0){
		std::cout<<"failure"<<std::endl;
		return;
	}

	if (destination < source) {
		std::swap (destination, source);
	}

	Edge del_edge = {adj_mat[source][destination], source, destination};
	// reference - https://en.cppreference.com/w/cpp/algorithm/remove
	std::remove_if(unique_edges.begin(), unique_edges.end(), [del_edge](Edge& f){ return (del_edge.source == f.source)&& (del_edge.destination == f.destination); });
	unique_edges.pop_back();

	adj_mat[source][destination] = -1.0;
	adj_mat[destination][source] = -1.0;

	std::cout<<"success"<<std::endl;
}

void Graph::print_edge_count(){
	std::cout<<"edge count is "<<unique_edges.size()<<std::endl;
}

void Graph::print_vertex_degree(long int u){
	if ( u<0 || u >= size ) {
		throw Invalid();
		return;
	}

	long int degree = 0;

	for (long int i=0; i<size; i++) {
		if (adj_mat[u][i] != -1.0) {
			degree ++;
		}
	}

	if (adj_mat[u][u] != -1.0){
		degree++;
	}

	std::cout <<"degree of "<<u<<" is "<<degree<<std::endl;
}

void Graph::clear_edges() {
	for(long int i=0; i<unique_edges.size(); i++){
		adj_mat[unique_edges[i].source][unique_edges[i].destination] = -1.0;

		adj_mat[unique_edges[i].destination][unique_edges[i].source] = -1.0;
	}

	unique_edges.clear();

	std::cout<<"success"<<std::endl;
}

void Graph::print_mst_Weight(){
	if (unique_edges.size() < (size-1) ){
		std::cout<<"not connected"<<std::endl;
		return ;
	}

	long double mst_weight = 0.0;
	long int mst_edges_count = 0;
	Disjoint_Set S(size);

	std::sort (unique_edges.begin(), unique_edges.end(), [](Edge e1, Edge e2){ return ( TOLERANCE < (e2.weight - e1.weight) ); });

	for(long int i=0; i<unique_edges.size(); i++) {
		long int u = unique_edges[i].source;
		long int v = unique_edges[i].destination;

		if (S.findSet(u) != S.findSet(v) ) {
			mst_edges_count++;
			mst_weight += unique_edges[i].weight;

			if(mst_edges_count == (size-1)) {
				break;
			}

			S.setUnion(u,v);
		}
	}

	if (mst_edges_count == (size-1)){
		std::cout<< std::fixed << std::setprecision(2)<<"mst "<<mst_weight<<std::endl;
	}
	else{
		std::cout<<"not connected"<<std::endl;
	}

}


