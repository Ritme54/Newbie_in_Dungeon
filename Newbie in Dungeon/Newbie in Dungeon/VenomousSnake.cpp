#include "VenomousSnake.h"
#include <iostream>

using namespace std;

VenomousSnake::VenomousSnake() : BossMonster("����", 80, 25, 15, 100) // ��ġ ������ ��
{
	cout << "���簡 ��Ÿ�����ϴ�!" << endl;
}


void VenomousSnake::activateSpecialPhase()
{
}

std::string VenomousSnake::getDefeatMessage() const
{
    return "����� ������ �ϰݿ� ���簡 ������ �߷�������!";
}
