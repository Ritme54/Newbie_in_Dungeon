#include "Snake.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Snake::Snake() : Monster("구렁이", 10,10,10,10)//수치 수정할것
{
	cout << "구렁이가 바위틈에서 튀어나왔다!" << endl;
}

Snake::~Snake()
{
	cout << "구렁이를 처치했다!" << endl;
}
