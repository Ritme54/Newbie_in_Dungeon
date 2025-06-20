#pragma once
#include <string>
#include <iostream>

class Monster;


using namespace std;

class Player//캐릭터 생성 클래스
{
private:
    string name;//캐릭터 이름
    int hp;//캐릭터 체력
    int maxHp;//캐릭터 최대 채력-이후 레벨업에 의해 일정하게 증가
    int attack;// 공격력
    int defense;//방어력
    int level;//현 레벨
    int exp;//획득한 경험치
    int requiredExp;//최대 경험치. 최대치가 넘어가면 레벨업하며 일정하게 증가함
public:
    Player(string initialName, int initialHp, int initialAttack, int initialDefense);

    void Attack(Monster& targetEnemy); // Enemy 클래스가 있다고 가정 몬스터 전체에 적용되도록 해야함. 기본적으로 플레이어 공격력-몬스터 방어력이 되도록 해야함.
    void TakeDamage(int damageAmount); //반대로 몬스터 공격력-플레이어 방어력이 되야함.
    void GainExperience(int expAmount);//몬스터가 사망했을시 획득하는 경험치
    void LevelUp();//최대치가 넘어가면 레벨업하며 일정하게 증가함
    void DisplayStatus();//화면에 생성될 플레이어 상태창 언제 얼마나 표시될지는 미정

    bool IsAlive() const;

    int GetHP() const; // 현재 체력을 반환
    int GetMaxHP() const; // 최대 체력을 반환
    int GetAttack() const; // 공격력을 반환
    int GetDefense() const; // 방어력을 반환
    std::string GetName() const; // 몬스터 이름을 반환

    ~Player();



   
  
       
};

