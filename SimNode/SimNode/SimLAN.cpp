#include "SimLAN.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void SimLAN::StartSim()
{
	std::cin >> _subChance;

    _numberOfNodes; 
	srand(time(0));
	_numberOfNodes = rand() % 30;
	if (_numberOfNodes == 0) _numberOfNodes++;
	std::cout << _numberOfNodes << std::endl;
	for (int i = 0; i < _numberOfNodes; i++)
	{
		Create();
		std::cout << "   " << _numberOfNodes << Field[i] << std::endl;
	}
	Update();
}

void SimLAN::Destroy() // на мой взгляд, из дестроя должна быть одна из больших причин плохой работы
{
	int i = 0;
		
	for (int i = 0; i < _numberOfNodes; i++)
	{
		if (Field[i]->GetFollowers() <= 0)
		{
			_numberOfNodes--;
			Field.erase(Field.begin() + i);
			//std::cout << "delete" << std::endl;
		}	
	}
	
	Update();
}

void SimLAN::Create()
{
	Field.push_back(new Node);
}

void SimLAN::SimLogic()
{
	int _randInt;
	srand(time(0));
	_randInt = rand() % 100 + 1;
	if (_randInt <= _subChance)
	{
		int _randSub1;
		srand(time(0));
		_randSub1 = rand() % _numberOfNodes;

		Sleep(2000); // пауза т.к. из-за сида, зависящего от времени, нужно время для нового числа
		int _randSub2;
		srand(time(0));
		_randSub2 = rand() % _numberOfNodes;

		if (_randSub1 != _randSub2)
		{
			Field[_randSub1]->SubEvent(Field[_randSub2]); // сам процесс подписки
			std::cout << "Sub::  " << "Node" <<_randSub1 << "->" << 
				"Node"<<_randSub2 << "->Sum: " /*<<Field[_randSub2]->GetSumSub()
											   нет рабочей передачи чисел */ << std::endl;
		}
		else
		{
			std::cout << "Dont Sub:  " << _randSub1 << " " << _randSub2 << std::endl;
		}
	}
	else
	{
		Sleep(1000);
		int _randUnSub1;
		srand(time(0));
		_randUnSub1 = rand() % _numberOfNodes;

		Sleep(1000);
		int _randUnSub2;
		srand(time(0));
		_randUnSub2 = rand() % _numberOfNodes;

		if (Field[_randUnSub2] != NULL) 
		{
			Field[_randUnSub1]->UnSubEvent(Field[_randUnSub2]);
			std::cout << "UnSub::  " << "Node" << _randUnSub1 << "->" << "Node" <<
				_randUnSub2 << std::endl;/*отписка должна была работать по своей идее, задав
			                              рандомные числа и посмотреть подписаны ли они 
										  и если да - отписать, иначе бездействие, но тут 
										  тоже проблемное место*/
		}
	}

}

void SimLAN::Update()
{
	while (Field.size() >= 1)
	{
		std::cout << "New iterate: " << std::endl;
		std::cout << Field.size() - 1 << std::endl;
		for (int i = 0; i < Field.size() - 1; i++)
		{
			SimLogic();
		}
		if(Field.size() <= 1) break;
		Destroy();
	}
}
