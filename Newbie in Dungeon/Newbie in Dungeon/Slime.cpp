#include "Slime.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Slime::Slime() : Monster("��� ������", 20, 7, 3, 10)
{
	std::cout << "��� �������� ��Ÿ����." << std::endl;
}

std::string Slime::getDefeatMessage() const
{
	return GetName() + "(��)�� ����ó�� ��Ƴ����� ���������ϴ�!";
}



