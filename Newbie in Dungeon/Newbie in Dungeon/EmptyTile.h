#pragma once
#include "Tile.h"

class Player;

class EmptyTile : public Tile
{
	void onEnter(Player& player) override;

	std::string getDescription() const override;



};

