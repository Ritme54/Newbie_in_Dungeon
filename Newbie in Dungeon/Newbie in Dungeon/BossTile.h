#pragma once
#include "Tile.h"
#include "Monster.h"
#include <memory>
#include <vector>
#include <functional>

class Player;
class Dungeon;
class GameManager;

extern void startcombat(Player& player, Monster& monster);

class BossTile : public Tile
{private:
	std::vector<std::function<std::unique_ptr<Monster>()>> bossGenerators;
	Dungeon& dungeonRef;
public:
	BossTile(const std::vector<std::function<std::unique_ptr<Monster>()>>& generators, Dungeon& dungeon);
	void onEnter(Player& player) override;
	std::string getDescription() const override;
	// ~BossTile() override = default;

};

