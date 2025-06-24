#include "BossTile.h" // 자신의 헤더 파일 포함
#include <iostream>   // std::cout, std::endl 사용
#include <random>     // std::uniform_int_distribution 사용
#include "Player.h"   // Player::IsAlive(), Player::GetName() 등 호출
#include "Dungeon.h"  // Dungeon::setBossDefeated() 호출

extern std::mt19937 rng;

BossTile::BossTile(const std::vector<std::function<std::unique_ptr<Monster>()>>& generators, Dungeon& dungeon) : bossGenerators(generators), dungeonRef(dungeon)
{
	std::cout << "보스 방에 진입했습니다." << std::endl;
}

void BossTile::onEnter(Player& player)
{
	std::cout << "방 중앙에 무언가 보입니다..." << std::endl;
	if (bossGenerators.empty()) {
		std::cout << "하지만 보스 몬스터가 나타나지 않았습니다. (보스 풀이 비어있음)" << std::endl;
		return;
	}
	std::unique_ptr<Monster> boss = bossGenerators[0]();

	if (boss)
	{
	//보스와 전투 시작
		startcombat(player, *boss);

	}

}

std::string BossTile::getDescription() const
{
	return std::string();
}
