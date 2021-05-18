/*
 * Linked_List.h
 *
 *  Created on: Nov. 29, 2020
 *      Author: Raksha
 */

#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <iostream>

struct node{
	node* p_nxt;
	node* parent;
	long int index;

	node(long int m);

	~node();
};


class Linked_list{
private:
	long int list_size;
	node *head;
	node* tail;

public :
	Linked_list();

	~Linked_list();

	node* getHead();

	void setHead(node* block);

	long int getListSize();

	void setListSize(long int newSize);

	void setTail(node* block);

	node* getTail();

	void insert(node *Node) ;


};



#endif /* LINKED_LIST_HPP_ */
