#include "BlackSlime.h"
#include <iostream>

using namespace std;

BlackSlime::BlackSlime() : BossMonster("�� ������",10,10,10,10)//���� ����
{
	std::cout << "�� �������� ����� ��ġü�� �ٰ��ɴϴ�." << std::endl;
}

void BlackSlime::activateSpecialPhase()
{
}

std::string BlackSlime::getDefeatMessage() const
{
	return  "����� ������ �ϰݿ� �� �������� �����������!";
}
