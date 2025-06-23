#pragma once
#include "Tile.h" // Tile Ŭ������ ��ӹ����Ƿ� ����
#include "Monster.h"   // ���� ��ü�� ����ϹǷ� ����
#include <memory>      // std::unique_ptr
#include <vector>      // std::vector
#include <functional>  // std::function
#include <random>      // ���� ���� �� ���� ���

class Player;

extern void startcombat(Player& player, Monster& monster);

class MonsterTile : public Tile
{
private:
    // �� ĭ���� ������ ������ ������ �����ϴ� ���� �Լ� Ǯ
    // Dungeon Ŭ�������� �� MonsterTile�� ������ �� ���޹޽��ϴ�.
    std::vector<std::function<std::unique_ptr<Monster>()>> monsterGenerators;

public:
    MonsterTile(const std::vector<std::function<std::unique_ptr<Monster>()>>& generators);

    // Tile Ŭ������ ���� ���� �Լ� onEnter�� ������ (override)
    void onEnter(Player& player) override;

    // Tile Ŭ������ ���� ���� �Լ� getDescription�� ������ (override)
    std::string getDescription() const override;


};

