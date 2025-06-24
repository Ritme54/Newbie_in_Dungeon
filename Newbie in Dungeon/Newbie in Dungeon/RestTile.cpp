#include "RestTile.h"
#include <iostream>
#include "Player.h"



void RestTile::onEnter(Player& player)
{
	std::cout << "모닥불의 흔적이다." << std::endl;
	std::cout << "모닥불을 피울 수 있을것 같다." << std::endl;
    // TODO: 플레이어 체력 회복 로직
   // 예시: 플레이어 최대 체력의 절반만큼 회복
   // Player 클래스에 Heal(int amount) 함수가 있다고 가정
   // player.Heal(player.GetMaxHP() / 2);
    std::cout << player.GetName() << "의 체력이 회복되었습니다." << std::endl;
    // 회복 후 플레이어 상태를 다시 표시할 수도 있습니다.
    // player.DisplayStatus();
}

std::string RestTile::getDescription() const
{
	return std::string("휴식 칸");
}
