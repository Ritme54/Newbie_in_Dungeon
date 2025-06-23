#pragma once
#include "Tile.h"

class Player;

class RestTile : public Tile
{
    // Tile 클래스의 순수 가상 함수 onEnter를 재정의 (override)
    void onEnter(Player& player) override;

    // Tile 클래스의 순수 가상 함수 getDescription을 재정의 (override)
    std::string getDescription() const override;
};

