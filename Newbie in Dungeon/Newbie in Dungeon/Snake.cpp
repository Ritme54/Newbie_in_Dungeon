#include "Snake.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Snake::Snake() : Monster("������", 35,15,6,25)//��ġ �����Ұ�
{
	cout << "�����̰� ����ƴ���� Ƣ��Դ�!" << endl;
}

std::string Snake::getDefeatMessage() const 
{
	return GetName() + "�����̰� ���������ϴ�!";
}
