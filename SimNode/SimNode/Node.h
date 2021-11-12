#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include "SimLAN.h"

class Node
{
public:
	int AddEvent();
	void SubEvent(Node *node);
	void UnSubEvent(Node *node);
	void SCreate(int index);
	void GetSubscriptions();
	void GetFollowers();
	
private:
	//SimLAN _simLAN;
	bool EnabledSub;
	std::list<int> Subscriptions = { };
	std::list<int> Followers = {  };
};

