#include "MonsterTile.h"
#include <iostream>

using namespace std;

extern mt19937 rng;

MonsterTile::MonsterTile(const std::vector<std::function<std::unique_ptr<Monster>()>>& generators)
{
	cout << "임시 초기화 메세지" << endl;
}

void MonsterTile::onEnter(Player& player)
{
	cout << "---(와)과 조우했습니다." << endl;


	if (monsterGenerators.empty()) {
		std::cout << "하지만 이 칸에는 몬스터가 없습니다. (몬스터 풀이 비어있음)" << std::endl;
		return;
	}

	uniform_int_distribution<int> dist(0, static_cast<int>(monsterGenerators.size() - 1));
	int randomIndex = dist(rng); // 전역 rng 사용

	unique_ptr<Monster> monster = monsterGenerators[randomIndex]();
	if (monster)
	{ startcombat(player, *monster);//전투 시작 함수 호출
	} 
	else {
	 std::cout << "몬스터 생성에 실패했습니다." << std::endl;
	}
}

std::string MonsterTile::getDescription() const
{
	return std::string("몬스터 칸");
}
