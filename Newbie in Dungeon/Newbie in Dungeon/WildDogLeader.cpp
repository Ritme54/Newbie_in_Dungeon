#include "WildDogLeader.h"
#include <iostream>

using namespace std;


WildDogLeader::WildDogLeader() : BossMonster("��θӸ� �鰳", 100, 20, 12, 50) // ��ġ ������ ��
{
	std::cout << "��θӸ� �鰳�� ��Ÿ�����ϴ�!" << std::endl;


}
void WildDogLeader::activateSpecialPhase()
{
}

std::string WildDogLeader::getDefeatMessage() const
{
	return "����� ������ �ϰݿ� ��θӸ� �鰳�� ����� ������ ��������!";
}
