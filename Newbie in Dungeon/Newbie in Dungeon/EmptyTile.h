#pragma once
#include "Tile.h"

class Player;

class EmteyTile : public Tile
{
	void onEnter(Player& player) override;

	std::string getDescription() const override;



};

