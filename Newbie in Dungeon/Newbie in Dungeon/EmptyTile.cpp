#include "emptyTile.h"
#include <iostream>

using namespace std;

void EmptyTile::onEnter(Player& player)
{
	std::cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�..." << std::endl;
}

std::string EmptyTile::getDescription() const
{
	return std::string("�� ĭ");
}
