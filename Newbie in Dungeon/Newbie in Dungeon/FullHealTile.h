#pragma once
#include "Tile.h"
#include <iostream>

class FullHealTile : public Tile
{
    // Tile Ŭ������ ���� ���� �Լ� onEnter�� ������ (override)
    void onEnter(Player& player) override;

    // Tile Ŭ������ ���� ���� �Լ� getDescription�� ������ (override)
    std::string getDescription() const override;
};


