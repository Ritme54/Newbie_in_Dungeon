#pragma once
#include "Tile.h" // Tile 클래스를 상속받으므로 포함
#include "Monster.h"   // 몬스터 객체를 사용하므로 포함
#include <memory>      // std::unique_ptr
#include <vector>      // std::vector
#include <functional>  // std::function
#include <random>      // 몬스터 생성 시 랜덤 사용

class Player;

extern void startcombat(Player& player, Monster& monster);

class MonsterTile : public Tile
{
private:
    // 이 칸에서 생성될 몬스터의 종류를 결정하는 람다 함수 풀
    // Dungeon 클래스에서 이 MonsterTile을 생성할 때 전달받습니다.
    std::vector<std::function<std::unique_ptr<Monster>()>> monsterGenerators;

public:
    MonsterTile(const std::vector<std::function<std::unique_ptr<Monster>()>>& generators);

    // Tile 클래스의 순수 가상 함수 onEnter를 재정의 (override)
    void onEnter(Player& player) override;

    // Tile 클래스의 순수 가상 함수 getDescription을 재정의 (override)
    std::string getDescription() const override;


};

