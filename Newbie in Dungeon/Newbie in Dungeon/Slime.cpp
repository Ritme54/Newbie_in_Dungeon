#include "Slime.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Slime::Slime() : Monster("��� ������", 30, 6, 3, 10)
{
	cout << "��� �������� ��Ÿ����." << endl;
}

Slime::~Slime()
{
	if (int hp=0)
	{
		cout << "��� �������� óġ�ߴ�!" << endl;
	}
}

