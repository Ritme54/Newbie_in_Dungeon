#include "Big_Rat.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Big_Rat::Big_Rat() : Monster("ŭ������ ��", 30, 6, 3, 10)
{
	cout << "ŭ������ �㰡 Ƣ��Դ�!" << endl;
}

Big_Rat::~Big_Rat()
{
	if (int hp = 0)
	{
		cout << "ŭ������ �㸦 óġ�ߴ�!" << endl;
	}
}
