#include "FullHealTile.h"
#include <iostream>
#include "Player.h"

void FullHealTile::onEnter(Player& player)
{
    std::cout << "모닥불의 흔적이다." << std::endl;
    std::cout << "모닥불을 피울 수 있을것 같다." << std::endl;

    std::cout << "럭키! 땔감용 장작을 찾았다!" << std::endl;
    std::cout << "깔끔하게 휴식을 취할 수 있었다." << std::endl;
    // TODO: 플레이어 체력 회복 로직
   // 예시: 플레이어 최대 체력 전부 회복
   // Player 클래스에 Heal(int amount) 함수가 있다고 가정
    int healAmount = player.GetMaxHP(); // 예시: 최대 체력 회복
    player.Heal(healAmount); // Player::Heal() 함수 호출
    player.DisplayStatus();
    std::cout << player.GetName() << "의 체력이 전부 회복되었습니다." << std::endl;
    std::cout << player.GetName() << "는 뒷정리를 한 뒤 다시 전진하기 시작했다." << std::endl;
    // 회복 후 플레이어 상태를 다시 표시할 수도 있습니다.
}

std::string FullHealTile::getDescription() const
{
	return std::string("최고의 휴식 칸");
}
