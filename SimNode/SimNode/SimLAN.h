#pragma once
#include <iostream>
#include "Node.h"
#include <cstdlib>
#include <vector>
class SimLAN
{
public:
	void StartSim();
	void Destroy();
	void Create();
	void SimLogic();
	void Update();
	//std::vector<Node> Field = {  };
private:
	Node _node;
	//std::vector<Node> _field;
	float _randCountNode;
	float _randSub;
	float _speedIteration;
	
};

