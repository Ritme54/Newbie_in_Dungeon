#include "GoblinWarrior.h"
#include <iostream>

using namespace std;

GoblinWarrior::GoblinWarrior() : BossMonster("��� ����", 80, 15, 8, 40) // ��ġ ������ ��
{
	cout << "��� ���簡 ��Ÿ�����ϴ�!" << endl;

}

void GoblinWarrior::activateSpecialPhase()
{
}

std::string GoblinWarrior::getDefeatMessage() const
{
    return "����� ������ �ϰݿ� ��� ���簡 ������ �ο������� ��������!";std::string();
}
