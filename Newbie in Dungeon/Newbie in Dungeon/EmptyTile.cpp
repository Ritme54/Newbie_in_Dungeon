#include "emptyTile.h"
#include <iostream>

using namespace std;

void EmptyTile::onEnter(Player& player)
{
	std::cout << "아무 일도 일어나지 않았다..." << std::endl;
}

std::string EmptyTile::getDescription() const
{
	return std::string("빈 칸");
}
