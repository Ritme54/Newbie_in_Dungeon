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
	cout << monster.GetName() << "(과)와 조우했다! " << "   ";
	while (player.IsAlive() && monster.IsAlive())
	{
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
	}
	EndCombat(player, monster);
	
}

// TODO: 몬스터 풀에서 랜덤으로 하나 선택하여 생성하는 함수 추가
// 이전에 설명드린 createRandomMonster 함수를 여기에 정의해야 합니다.
std::unique_ptr<Monster> createRandomMonster(
	const std::vector<std::function<std::unique_ptr<Monster>()>>& monsterPool);



#pragma endregion




int main()
{
	cout << "당신의 이름을 입력하세요." << endl;
	cout << "'한/영문자만 입력'" << endl;
	string name;
	getline(cin, name);
	
	Player user(name, 100, 10, 5);

	user.DisplayStatus();

	//랜덤시드(던전 N층)
	srand(static_cast<unsigned int>(time(nullptr)));



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
		cout << "\n---던전" << currentFloor << "층 ---" << endl;
		const auto& currentFloorPool = dungenMonsterPools[currentFloor - 1];
		if (!currentFloorPool.empty())
		{
			unique_ptr<Monster> currentMonster = createRandomMonster(currentFloorPool);
			if (currentMonster)
			{
				startcombat(user, *currentMonster);
				if (!user.IsAlive())
				{
					//플레이어 패배
					// 게임오버 루프 탈출
					break;
				}
				else
				{
					//승리
				}
			}

		}

	}
#pragma endregion


	
	return 0;


}

std::unique_ptr<Monster> createRandomMonster(const std::vector<std::function<std::unique_ptr<Monster>()>>& monsterPool)
{
	return std::unique_ptr<Monster>();
}
