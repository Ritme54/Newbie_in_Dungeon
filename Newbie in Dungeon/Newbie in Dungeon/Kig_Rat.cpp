#include "Kig_Rat.h"
#include <iostream>

using namespace std;

Kig_Rat::Kig_Rat() : BossMonster("��� ��", 80, 25, 15, 100) // ��ġ ������ ��
{
	std::cout << "��� �㰡 ��Ÿ�����ϴ�!" << std::endl;
}


void Kig_Rat::activateSpecialPhase()
{
}

std::string Kig_Rat::getDefeatMessage() const
{
    return "����� ������ �ϰݿ� ��� �㰡 �� �ָ� ���ư���!";
}
