/*
 * Disjoint_set.hpp
 *
 *  Created on: Nov. 29, 2020
 *      Author: Raksha
 */

#ifndef DISJOINT_SET_HPP_
#define DISJOINT_SET_HPP_

#include <iostream>

#include "Graph.hpp"
#include "Linked_List.hpp"

class Disjoint_Set {
private :
	Linked_list *Set;

public:
	Disjoint_Set(long int m);

	~Disjoint_Set();

	node* findSet(long int m);

	void setUnion(long int u, long int v);
};


#endif /* DISJOINT_SET_HPP_ */
