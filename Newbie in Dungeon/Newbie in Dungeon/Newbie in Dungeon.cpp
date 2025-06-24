#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Slime.h"
#include <memory>
#include <vector>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));

void EndCombat(Player& player, Monster& monster)
{
	if (!player.IsAlive()) // Player::IsAlive() 함수 사용
	{
		// 플레이어 패배 처리
		std::cout << "당신은 " << monster.GetName() << "(에게) 쓰러졌습니다..." << std::endl;
		// TODO: 게임 오버 처리 로직 호출 (예: GoToGameOverScreen();)
	}
	// 2. 몬스터가 쓰러졌는지 확인 (플레이어는 살아있다고 가정)
	else if (!monster.IsAlive()) // Monster::IsAlive() 함수 사용
	{
		// 플레이어 승리 처리
		std::cout << monster.GetName() << "(을)를 물리쳤습니다!" << std::endl;

		// 몬스터를 물리쳤을 때의 보상 (경험치 획득)
		int gainedExp = monster.GetEXPValue(); // Monster::GetEXPValue() 함수 사용
		player.GainExperience(gainedExp); // Player::GainExperience() 함수 호출

		std::cout << gainedExp << "의 경험치를 획득했습니다." << std::endl;
	}
}

#pragma region 전투 로직
void startcombat(Player& player, Monster& monster)
{
	std::cout << monster.GetName() << "(과)와 조우했다! " << "   ";
	while (player.IsAlive() && monster.IsAlive())
	{
		player.DisplayStatus();
		monster.DisplayStatus();
		player.Attack(monster);
		if (!monster.IsAlive())
		{
			break;
		}
		monster.Attack(player);
		if (!player.IsAlive())
		{
			break;
		}
		std::cout << "\n --- 턴 종료 --- " << std::endl;
	}
	EndCombat(player, monster);
	
}

// TODO: 몬스터 풀에서 랜덤으로 하나 선택하여 생성하는 함수 추가
// 이전에 설명드린 createRandomMonster 함수를 여기에 정의해야 합니다.
std::unique_ptr<Monster> createRandomMonster(const vector<function<unique_ptr<Monster>()>>& monsterPool)
{if (monsterPool.empty())
{
	return nullptr;

}
uniform_int_distribution<int> dist(0, monsterPool.size() - 1);
int randomindex = dist(rng);
return monsterPool[randomindex]();

}



#pragma endregion




int main()
{
	std::cout << "당신의 이름을 입력하세요." << std::endl;
	std::cout << "'한/영문자만 입력'" << std::endl;
	string name;
	getline(cin, name);
	
	Player user(name, 100, 10, 5);

	user.DisplayStatus();

#pragma region 몬스터 스마트 포인터(생성 및 소멸 담당.)
	vector<vector<function<unique_ptr<Monster>()>>>dungenMonsterPools(5);

	dungenMonsterPools[0] =
	{
	[] {return make_unique<Slime>(); }

	// 추가 몬스터 생성 함수.

	};

	dungenMonsterPools[1] =
	{
	[] {return make_unique<Slime>(); }

	// 추가 몬스터 생성 함수.

	};
	dungenMonsterPools[2] =
	{
	[] {return make_unique<Slime>(); }

	// 추가 몬스터 생성 함수.

	};
	dungenMonsterPools[3] =
	{
	[] {return make_unique<Slime>(); }

	// 추가 몬스터 생성 함수.

	};	
	dungenMonsterPools[4] =
	{
	[] {return make_unique<Slime>(); }

	// 추가 몬스터 생성 함수.

	};

#pragma endregion

#pragma region 던전 진행 루프
	int currentFloor = 1; // 현 플레이어 층
	const int totalFloors = 5; //총 던전 층

	while (user.IsAlive() && currentFloor <= totalFloors)
	{
		std::cout << "\n---던전" << currentFloor << "층 ---" << std::endl;
		const auto& currentFloorPool = dungenMonsterPools[currentFloor - 1];
		if (!currentFloorPool.empty())
		{
			unique_ptr<Monster> currentMonster = createRandomMonster(currentFloorPool);
			if (currentMonster)
			{
				startcombat(user, *currentMonster);
			}

		}

	}
#pragma endregion
	if (user.IsAlive() && currentFloor > totalFloors)
	{
		std::cout << "\n--- 던전 클리어! ---" << std::endl;
		std::cout << "당신은 이 던전을 돌파했습니다." << std::endl;
	}
	else if (!user.IsAlive())
	{
		std::cout << "\n--- 게임 종료 ---" << std::endl;
	}

	
	return 0;


}
