/*
 * Linked_List.cpp
 *
 *  Created on: Dec. 2, 2020
 *      Author: Raksha
 */
#include <iostream>

#include "Linked_List.hpp"

/// Struct node definitions
node::node(long int m){
	index=m;

	p_nxt =nullptr;
	parent =nullptr;
}

node::~node(){}

/// Linked_List class definitions
Linked_list::Linked_list(){
	list_size = 0;
	head = nullptr;
	tail = nullptr;
}

Linked_list::~Linked_list(){
	delete head;
	head=nullptr;

}

node* Linked_list::getHead(){
	return head;
}


void Linked_list::setHead(node* block){
	head = block;
}

long int Linked_list::getListSize(){
	return list_size;
}

void Linked_list::setListSize(long int newSize){
	list_size = newSize;
}

void Linked_list::setTail(node* block){
	tail = block;
}

node* Linked_list::getTail(){
	return tail;
}

void Linked_list::insert(node *Node) {
	if(head == NULL) {
		head = Node;
		tail = Node;
		list_size++;
	}
	else {
		tail->p_nxt = Node;
		tail = tail->p_nxt;
	}

	Node->parent=head;
}



