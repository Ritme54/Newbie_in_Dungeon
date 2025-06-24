#include "Snake.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Snake::Snake() : Monster("구렁이", 35,15,6,25)//수치 수정할것
{
	std::cout << "구렁이가 바위틈에서 튀어나왔다!" << std::endl;
}

std::string Snake::getDefeatMessage() const 
{
	return GetName() + "구렁이가 쓰러졌습니다!";
}
