#include "Node.h"
#include <stdlib.h>
#include <time.h>

int Node::AddEvent()
{
	int RandInt;
	srand(time(0));
	RandInt = rand() % 10 + 1;
	return RandInt;
}

void Node::SubEvent(Node *node)
{
	Subscriptions.push_back(1);
	(*node).Followers.push_back(0);
}

void Node::UnSubEvent(Node *node)
{                                   // нужен Field из SimLan, т.к. нужно знать кто именно подписывался ранее
	Subscriptions.pop_back();       // сейчас лишь ансабнется последняя подписка и последний фолловер
	(*node).Followers.pop_back();
}

void Node::SCreate(int index)
{                              // нужен Field из SimLan


}

void Node::GetSubscriptions()
{
	for (auto iter = Subscriptions.begin(); iter != Subscriptions.end(); iter++)
	{
		//system("pause");
		std::cout << *iter << "\t";
	}
}

void Node::GetFollowers()
{
	for (auto iter = Followers.begin(); iter != Followers.end(); iter++)
	{
		std::cout << *iter << "\t";
	}
}


