#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>




class Node
{
public:
	int AddEvent(Node* node);
	void SubEvent(Node *node);
	void UnSubEvent(Node *node);
	void SCreate(int index);
	Node GetSubscriptions();
	int GetFollowers();
	void SetNode(Node* node);
	int GetSumSub();
	
private:
	Node* _nodeSub; 
	
	int sumSub = 0;
	int _followers = 0;
};

