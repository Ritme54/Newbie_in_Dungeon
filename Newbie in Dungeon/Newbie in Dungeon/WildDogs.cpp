#include "WildDogs.h"
#include <iostream>
#include "Monster.h"

using namespace std;

WildDogs::WildDogs() : Monster("�鰳", 50, 15, 8, 30)//��ġ �����Ұ�
{
	std::cout << "�鰳�� Ƣ��Դ�!" << std::endl;
}

std::string WildDogs::getDefeatMessage() const
{
	return GetName() + "�鰳�� ����� ������ ���������ϴ�!";
}

