#include "Big_Rat.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Big_Rat::Big_Rat() : Monster("큼지막한 쥐", 30, 6, 3, 10)
{
	cout << "큼지막한 쥐가 튀어나왔다!" << endl;
}

Big_Rat::~Big_Rat()
{
	if (int hp = 0)
	{
		cout << "큼지막한 쥐를 처치했다!" << endl;
	}
}
