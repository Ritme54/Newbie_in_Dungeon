#include "emptyTile.h"
#include <iostream>

using namespace std;


void EmteyTile::onEnter(Player& player)
{
	cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�..." << endl;

}

std::string EmteyTile::getDescription() const
{
	return std::string("�� ĭ");
}
