
#pragma once
#include <string>

class Player;

class Tile
{
public:
// 플레이어가 칸에 진입했을 때 호출될 순수 가상 함수
// 모든 파생 클래스는 이 함수를 반드시 구현해야 합니다.
// = 0; 을 붙여 순수 가상 함수로 만들면 Tile 클래스는 추상 클래스가 되어 객체 생성이 불가능해집니다.
    virtual void onEnter(Player& player) = 0;

    // 칸의 종류를 문자열로 반환하는 순수 가상 함수 (디버깅/표시용)
    // 모든 파생 클래스는 이 함수를 반드시 구현해야 합니다.
    virtual std::string getDescription() const = 0;

   // 소멸자는 반드시 virtual로 선언해야 합니다.
    // 다형성을 통해 Tile* 포인터로 파생 클래스 객체를 delete할 때 올바른 소멸자가 호출되도록 합니다.
    // C++11 이후 default 소멸자 사용 가능
    virtual ~Tile() = default;
};

