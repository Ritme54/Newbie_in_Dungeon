#include "Goblin.h"
#include <iostream>
#include "Monster.h"

using namespace std;


Goblin::Goblin() : Monster("���",10,10,10,10)//���� ����
{
	cout << "����� ����Ÿ��� ��Ÿ����!" << endl;

}

std::string Goblin::getDefeatMessage() const 
{
	return GetName() + "(��)�� �����̸� ��ġ�� ����� ������ ���������ϴ�!";
}
