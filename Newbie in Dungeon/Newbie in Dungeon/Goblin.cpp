#include "Goblin.h"
#include <iostream>
#include "Monster.h"

using namespace std;


Goblin::Goblin() : Monster("���",10,10,10,10)//���� ����
{
	std::cout << "����� ����Ÿ��� ��Ÿ����!" << std::endl;

}

std::string Goblin::getDefeatMessage() const 
{
	return GetName() + "(��)�� �����̸� ��ġ�� ����� ������ ���������ϴ�!";
}
