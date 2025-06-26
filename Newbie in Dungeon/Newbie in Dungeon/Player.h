#pragma once
#include <string>
#include <memory> 
class Monster;
class SpecialAbility;

class Player//캐릭터 생성 클래스
{
private:
    std::string name;//캐릭터 이름
    int hp;//캐릭터 체력
    int maxHp;//캐릭터 최대 채력-이후 레벨업에 의해 일정하게 증가
    int attack;// 공격력
    int defense;//방어력
    int level;//현 레벨
    int exp;//획득한 경험치
    int requiredExp;//최대 경험치. 최대치가 넘어가면 레벨업하며 일정하게 증가함

    int bandageCount;    // 현재 남아있는 치료 붕대 수
    // int maxBandages;     // <-- 이 줄 제거 (최대치 없이 관리)
    const int bandageHealAmt; // 치료 붕대 사용 시 회복량 (고정값)

    // --- 3번: 포션 관련 멤버 변수 ---
    int potionCount;     // 현재 남아있는 포션 수
    // int maxPotions;      // <-- 이 줄 제거 (최대치 없이 관리)
    const int potionHealAmt; // 포션 사용 시 회복량 (고정값)

    // --- 새로운 전투 행동 관련 멤버 변수 ---
    bool isDefending; // 방어 상태 여부
    int strongAttackCooldown; // 강공격 쿨다운

    std::unique_ptr<SpecialAbility> selectedSpecialAbility;


public:
    Player(std::string initialName, int initialHp, int initialAttack, int initialDefense);

    void Attack(Monster& targetEnemy); // Enemy 클래스가 있다고 가정 몬스터 전체에 적용되도록 해야함. 기본적으로 플레이어 공격력-몬스터 방어력이 되도록 해야함.
    void TakeDamage(int damageAmount); //반대로 몬스터 공격력-플레이어 방어력이 되야함.(방어 효과 적용 예정)
    void GainExperience(int expAmount);//몬스터가 사망했을시 획득하는 경험치
    void DisplayStatus();//화면에 생성될 플레이어 상태창 언제 얼마나 표시될지는 미정
    void Heal(int amount); // 회복
    void LevelUp(); // 레벨업 시 전략적 회복 스택 충전 로직 포함
  
    // --- 새로운 전투 행동 함수 ---
    void StrongAttack(Monster& targetEnemy); // 강공격
    void Defend(); // 방어

    void setSpecialAbility(std::unique_ptr<SpecialAbility> ability); // 특수능력 설정
    void useSpecialAbility(Monster& targetEnemy); // 설정된 특수능력 사용

    // --- 턴 시작 시 상태 초기화 함수 (GameManager에서 호출) ---
    void ResetTurnState(); // 턴 시작 시 방어 상태 해제, 쿨다운 감소 등


    // --- 6번: 치료 붕대 관련 함수 ---
    bool useBandage(); // 치료 붕대 사용
    int getBandageCount() const; // 현재 붕대 개수 조회
    void setBandages(int count); // GameManager에서 붕대를 지급할 때 사용
    void addBandages(int count); // <-- 이 줄 추가: 붕대 스택 추가

    // --- 3번: 포션 관련 함수 ---
    bool usePotion(); // 포션 사용
    int getPotionCount() const; // 현재 포션 개수 조회
    void addPotions(int count); // <-- 이 줄 추가: 포션 스택 추가

    bool IsAlive() const; //생존유무

    int GetHP() const; // 현재 체력을 반환
    int GetMaxHP() const; // 최대 체력을 반환
    int GetAttack() const; // 공격력을 반환
    int GetDefense() const; // 방어력을 반환
    std::string GetName() const; // 플레이어 이름을 반환
  int GetLevel() const; //레벨 함수
    ~Player();



   
  
       
};

