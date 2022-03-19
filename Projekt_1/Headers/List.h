#pragma once
#include "../Headers/Node.h"

class List : Node
{
	Node* header, trailer;

	List()
	{
		header = new Node('0', 0, nullptr, nullptr);
		trailer = new Node('0', 0, nullptr, nullptr);
	}



}; //CLASS

