#include "Monster.h"





void Monster::DisplayStatus() const
{
	{
		std::cout << "--- " << name << "�� ���� ---" << std::endl;
		std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
		std::cout << "���ݷ�: " << attack << std::endl;
		std::cout << "����: " << defense << std::endl;
		std::cout << "-------------------------" << std::endl;
	}
}

Monster::~Monster()
{
	if (hp=0)
	{
		cout << "--- �� ����Ʈ�Ƚ��ϴ�." << endl;
		cout << "�������� �¸��߽��ϴ�." << endl;
	}
}
