#include "Node.h"
#include <stdlib.h>
#include <time.h>

int Node::AddEvent(Node* node)
{
	int RandInt;
	srand(time(0));
	RandInt = rand() % 10 + 1;
	return RandInt;

	(*node).sumSub += RandInt;
}

void Node::SubEvent(Node* node)
{
	if (_nodeSub != node)
	{
		_nodeSub = node;
		(*node)._followers++;
		//AddEvent(node); возвращает лишь нули в выводе, убрал
	}
	else
		std::cout << "Already subscribed" << std::endl;
}

void Node::UnSubEvent(Node *node)
{             
		_nodeSub = NULL;
		(*node)._followers--;
}
	


void Node::SCreate(int index) // метод, создающий и подписывающий узлы. —делать не получилось
{                              


}

Node Node::GetSubscriptions()
{
	return *_nodeSub;
}

int Node::GetFollowers()
{
	return _followers;
}

void Node::SetNode(Node* node)
{
	_nodeSub = node;
}

int Node::GetSumSub()
{
	return sumSub;
}



