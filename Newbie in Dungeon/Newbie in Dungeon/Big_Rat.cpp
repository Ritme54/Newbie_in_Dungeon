#include "Big_Rat.h"
#include <iostream>


using namespace std;

Big_Rat::Big_Rat() : Monster("큼지막한 쥐", 30, 9, 4, 15)
{
	cout << "큼지막한 쥐가 튀어나왔다!" << endl;
}

std::string Big_Rat::getDefeatMessage() const // <-- const 키워드 확인
{
	return GetName() + " 큰 쥐가 비명을 지르며 쓰러졌다!"; // 오타 수정: 쓰러젔다 -> 쓰러졌다
}
