#include "VenomousSnake.h"
#include <iostream>

using namespace std;

VenomousSnake::VenomousSnake() : BossMonster("����", 80, 25, 15, 100) // ��ġ ������ ��
{
	std::cout << "���簡 ��Ÿ�����ϴ�!" << std::endl;
}


void VenomousSnake::activateSpecialPhase()
{
}

std::string VenomousSnake::getDefeatMessage() const
{
    return "����� ������ �ϰݿ� ���簡 ������ �߷�������!";
}
