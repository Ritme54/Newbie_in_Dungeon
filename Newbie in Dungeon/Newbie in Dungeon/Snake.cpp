#include "Snake.h"
#include <iostream>
#include "Monster.h"

using namespace std;

Snake::Snake() : Monster("������", 10,10,10,10)//��ġ �����Ұ�
{
	cout << "�����̰� ����ƴ���� Ƣ��Դ�!" << endl;
}

Snake::~Snake()
{
	cout << "�����̸� óġ�ߴ�!" << endl;
}
