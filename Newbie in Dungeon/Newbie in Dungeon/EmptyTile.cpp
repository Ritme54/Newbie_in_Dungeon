#include "emptyTile.h"
#include <iostream>

using namespace std;


void EmteyTile::onEnter(Player& player)
{
	cout << "아무 일도 일어나지 않았다..." << endl;

}

std::string EmteyTile::getDescription() const
{
	return std::string("빈 칸");
}
