#include "Player.h"
#include <string>
#include <iostream>
#include "Monster.h"
#include <algorithm> // std::min, std::max 사용 (LevelUp에서)

Player::Player(std::string initialName, int initialHp, int initialAttack, int initialDefense):
	name(initialName),
	hp(initialHp),
	maxHp(initialHp),
	attack(initialAttack),
	defense(initialDefense),
	level(1),
	exp(0),
	requiredExp(100)
	// --- 6번: 치료 붕대 초기화 ---
	bandageCount(0),     // GameManager에서 지급할 것이므로 0으로 시작
	// maxBandages는 Player.h에서 제거되었으므로 여기서는 초기화하지 않습니다.
	bandageHealAmt(20),  // 치료 붕대 사용 시 회복량 (예시: 20)
	// --- 3번: 포션 초기화 ---
	potionCount(0),      // 레벨업 시 충전될 것이므로 0으로 시작
	// maxPotions는 Player.h에서 제거되었으므로 여기서는 초기화하지 않습니다.
	potionHealAmt(50)    // 포션 사용 시 회복량 (예시: 50)
	// --- 새로운 전투 행동 관련 멤버 변수 초기화 ---
	isDefending(false), // 방어 상태 초기화
	strongAttackCooldown(0), // 강공격 쿨다운 초기화
	specialAbilityCooldown(0) // 특수능력 쿨다운 초기화



{
	std::cout << "캐릭터가 생성되었습니다." << std::endl;
}

#pragma region 전투 로직


void Player::Attack(Monster& targetEnemy)
{
	if (!IsAlive()) return;
	std::cout << GetName() << "(이)가" << targetEnemy.GetName() << "(을)를 공격합니다." << std::endl;
	int damage = attack - targetEnemy.GetDefense();
	if (damage < 0) damage = 0;
	targetEnemy.TakeDamage(damage);
}



// --- TakeDamage 함수 수정 (방어 효과 적용) ---
void Player::TakeDamage(int damageAmount) {
	if (!IsAlive()) return;

	int actualDamage = damageAmount;
	if (isDefending) {
		actualDamage = damageAmount / 2; // 방어 시 피해 절반 (예시)
		std::cout << GetName() << "(은)는 방어하여 피해를 " << actualDamage << "로 줄였습니다!" << std::endl;
	}

	hp -= actualDamage;
	std::cout << GetName() << "(은)는 " << actualDamage << "의 피해를 입었습니다." << std::endl;

	if (hp <= 0) {
		hp = 0;
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
		std::cout << GetName() << "(이)가 쓰러졌습니다..." << std::endl;
	}
	else {
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
	}
}

// --- 새로운 전투 행동 함수 구현 ---
void Player::StrongAttack(Monster& targetEnemy) {
	if (strongAttackCooldown > 0) {
		std::cout << "강공격은 아직 쿨다운 중입니다! (" << strongAttackCooldown << "턴 남음)" << std::endl;
		return; // 쿨다운 중이면 공격 불가
	}
	std::cout << GetName() << "(이)가 강력한 일격을 날립니다!" << std::endl;
	int damage = static_cast<int>(attack * 1.5) - targetEnemy.GetDefense(); // 1.5배 공격력 (예시), int로 캐스팅
	if (damage < 0) damage = 0;
	targetEnemy.TakeDamage(damage);
	strongAttackCooldown = 3; // 3턴 쿨다운 (예시)
}

//방어 행동 출력
void Player::Defend() {
	std::cout << GetName() << "(이)가 방어 자세를 취합니다. 다음 공격의 피해가 감소합니다." << std::endl;
	isDefending = true;
}

// --- 턴 시작 시 상태 초기화 함수 구현 ---
void Player::ResetTurnState() {
	isDefending = false; // 방어 상태 해제
	if (strongAttackCooldown > 0) strongAttackCooldown--; // 강공격 쿨다운 감소
	if (specialAbilityCooldown > 0) specialAbilityCooldown--; // 특수능력 쿨다운 감소
}

void Player::GainExperience(int expAmount)
{

	exp += expAmount;
	std::cout << GetName() << "이(가) 경험치 " << expAmount << "을(를) 획득했습니다. (현재 경험치: " << exp << "/" << requiredExp << ")" << std::endl;
	while (exp >= requiredExp) {
		LevelUp();
	}

}

void Player::LevelUp()
{
	level++;
	exp -= requiredExp; // 남은 경험치 처리
	requiredExp = level * 100; // 다음 레벨업 필요 경험치 (예시)

	// 스탯 증가 (예시)
	maxHp += 10;
	hp = (maxHp/2); // 레벨업 시 체력 완전 회복 (또는 절반 회복)
	attack += 2;
	defense += 1;

	std::cout << "\n--- 레벨업! ---" << std::endl;
	std::cout << GetName() << "이(가) 레벨 " << level << "이(가) 되었습니다!" << std::endl;
	DisplayStatus(); // 레벨업 후 상태 표시
	//레벨업시 포션 충전
	potionCount++;
	std::cout << GetName() << "의 레벨업으로 포션사용 횟수가 1증가했습니다! (현재: " << potionCount << ")" << std::endl;
}



void Player::DisplayStatus()
{
	{
		std::cout << "--- " << name << "의 상태 ---" << std::endl;
		std::cout << "레벨: " << level << std::endl;
		std::cout << "체력: " << hp << "/" << maxHp << std::endl;
		std::cout << "공격력: " << attack << std::endl;
		std::cout << "방어력: " << defense << std::endl;
		std::cout << "경험치: " << exp << "/" << requiredExp << std::endl;
		std::cout << "치료 붕대: " << bandageCount << std::endl;
		std::cout << "남은 포션량 : " << potionCount << std::endl;

		std::cout << "-------------------------" << std::endl;
	}

}

void Player::Heal(int amount)
{
	hp += amount;
	if (hp>maxHp)
	{
		hp = maxHp;
	}

	std::cout << GetName() << "의 체력이 " << amount << " 회복되었습니다. 현재 체력: " << hp << "/" << maxHp << std::endl;
}


bool Player::IsAlive() const
{
	return hp > 0;
	return true;
}
#pragma region 상태 반환

int Player::GetHP() const
{
	return hp;
}

int Player::GetMaxHP() const
{
	return maxHp;
}

int Player::GetAttack() const
{
	return attack;
}

int Player::GetDefense() const
{
	return defense;
}

std::string Player::GetName() const
{
	return name;
}



#pragma endregion

#pragma region 회복수단 반환 함수
// --- 6번: 치료 붕대 관련 함수 ---
bool Player::useBandage() {
    if (bandageCount > 0) {
        bandageCount--;
        Heal(bandageHealAmt);
        std::cout << GetName() << "(이)가 치료 붕대를 사용했습니다. 남은 붕대: " << bandageCount << std::endl;
        return true;
    } else {
        std::cout << "사용할 치료 붕대가 없습니다." << std::endl;
        return false;
    }
}

int Player::getBandageCount() const {
    return bandageCount;
}

void Player::setBandages(int count) {
    // maxBandages가 없으므로, 단순히 현재 붕대 수를 설정합니다.
    bandageCount = count;
    std::cout << GetName() << "(이)가 치료 붕대 " << count << "개를 획득했습니다." << std::endl;
}

void Player::addBandages(int count) {
    bandageCount += count;
    std::cout << GetName() << "(이)가 붕대 " << count << "개를 추가로 획득했습니다. (현재: " << bandageCount << ")" << std::endl;
}

// --- 3번: 포션 관련 함수 ---
bool Player::usePotion() {
    if (potionCount > 0) {
        potionCount--;
        Heal(potionHealAmt);
        std::cout << GetName() << "(이)가 포션을 1회분 사용했습니다. 남은 포션량: " << potionCount << std::endl;
        return true;
    } else {
        std::cout << "사용할 포션이 없습니다." << std::endl;
        return false;
    }
}

int Player::getPotionCount() const {
    return potionCount;
}

// getMaxPotions()는 Player.h에서 제거되었으므로 정의하지 않습니다.

void Player::addPotions(int count) {
    potionCount += count;
    std::cout << GetName() << "(이)가 포션 사용량 " << count << "분을 추가로 획득했습니다. (현재: " << potionCount << ")" << std::endl;
}

#pragma endregion



Player::~Player()
{
}

#pragma endregion





