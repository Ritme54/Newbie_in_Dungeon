#include "Big_Rat.h"
#include <iostream>


using namespace std;

Big_Rat::Big_Rat() : Monster("ŭ������ ��", 30, 9, 4, 15)
{
	cout << "ŭ������ �㰡 Ƣ��Դ�!" << endl;
}

std::string Big_Rat::getDefeatMessage() const // <-- const Ű���� Ȯ��
{
	return GetName() + " ū �㰡 ����� ������ ��������!"; // ��Ÿ ����: �������� -> ��������
}
