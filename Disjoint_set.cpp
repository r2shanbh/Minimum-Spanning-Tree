/*
 * Disjoint_set.cpp
 *
 *  Created on: Dec. 2, 2020
 *      Author: Raksha
 */
#include <iostream>

#include "Disjoint_set.hpp"
#include "Linked_List.hpp"

Disjoint_Set::Disjoint_Set(long int m){
	Set = new Linked_list[m];

	for (long int j=0; j<m; j++){

		node *Node = new node(j);
		Set[j].insert(Node);
	}
}

Disjoint_Set::~Disjoint_Set(){
	delete[] Set;
}

node* Disjoint_Set::findSet(long int m){
	return Set[m].getHead()->parent;
}

void Disjoint_Set::setUnion(long int u, long int v){
	long int max_list = Set[u].getHead()->parent->index;
	long int min_list = Set[v].getHead()->parent->index;

	if (Set[max_list].getListSize() < Set[min_list].getListSize() ) {
		std::swap(max_list,min_list);
	}

	Set[max_list].setListSize(Set[max_list].getListSize() + Set[min_list].getListSize());
	Set[max_list].insert(Set[min_list].getHead());

	while( Set[max_list].getTail()->p_nxt != nullptr ) {
		Set[max_list].getTail()-> parent = Set[max_list].getHead() ;
		Set[max_list].setTail ( Set[max_list].getTail()->p_nxt);
	}

	Set[max_list].getTail()-> parent = Set[max_list].getHead() ;
}



