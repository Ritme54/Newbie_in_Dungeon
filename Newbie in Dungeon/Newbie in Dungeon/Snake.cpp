#include "Snake.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Snake::Snake() : Monster("������", 35,15,6,25)//��ġ �����Ұ�
{
	std::cout << "�����̰� ����ƴ���� Ƣ��Դ�!" << std::endl;
}

std::string Snake::getDefeatMessage() const 
{
	return GetName() + "�����̰� ���������ϴ�!";
}
