#include "Slime.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Slime::Slime() : Monster("녹색 슬라임", 30, 5, 2, 10)
{
	cout << "녹색 슬라임이 나타났다." << endl;
}

Slime::~Slime()
{
	if (int hp=0)
	{
		cout << "녹색 슬라임을 처치했다!" << endl;
	}
}

