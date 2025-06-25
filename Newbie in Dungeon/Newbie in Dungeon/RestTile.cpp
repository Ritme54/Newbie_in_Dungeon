#include "RestTile.h"
#include <iostream>
#include "Player.h"



void RestTile::onEnter(Player& player)
{
	std::cout << "모닥불의 흔적이다." << std::endl;
	std::cout << "모닥불을 피울 수 있을것 같다." << std::endl;

    std::cout << "주변의 부서진 상자 잔해로 불을 피웠다." << std::endl;
    std::cout << "그닥 좋은 모닥불은 아니지만, 그래도 휴식을 취할 수 있었다." << std::endl;
    // TODO: 플레이어 체력 회복 로직
   // 예시: 플레이어 최대 체력의 절반만큼 회복
   // Player 클래스에 Heal(int amount) 함수가 있다고 가정
    int healAmount = player.GetMaxHP() / 2; // 예시: 최대 체력의 절반 회복
    player.Heal(healAmount); // Player::Heal() 함수 호출
    std::cout << player.GetName() << "의 체력이 절반 회복되었습니다." << std::endl;
    std::cout << player.GetName() << "는 뒷정리를 한 뒤 다시 전진하기 시작했다." << std::endl;
    // 회복 후 플레이어 상태를 다시 표시할 수도 있습니다.
    player.DisplayStatus();
}

std::string RestTile::getDescription() const
{
	return std::string("휴식 칸");
}
