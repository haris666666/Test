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

private:
	std::vector<Node*> Field = {  };

	SimLAN *_simLan;

	int _numberOfNodes;
	float _randCountNode;
	int _subChance;
};

