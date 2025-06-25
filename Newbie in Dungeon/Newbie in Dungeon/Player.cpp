#include "Player.h"
#include <string>
#include <iostream>
#include "Monster.h"
#include <algorithm> // std::min, std::max ��� (LevelUp����)

Player::Player(std::string initialName, int initialHp, int initialAttack, int initialDefense):
	name(initialName),
	hp(initialHp),
	maxHp(initialHp),
	attack(initialAttack),
	defense(initialDefense),
	level(1),
	exp(0),
	requiredExp(100)
	// --- 6��: ġ�� �ش� �ʱ�ȭ ---
	bandageCount(0),     // GameManager���� ������ ���̹Ƿ� 0���� ����
	// maxBandages�� Player.h���� ���ŵǾ����Ƿ� ���⼭�� �ʱ�ȭ���� �ʽ��ϴ�.
	bandageHealAmt(20),  // ġ�� �ش� ��� �� ȸ���� (����: 20)
	// --- 3��: ���� �ʱ�ȭ ---
	potionCount(0),      // ������ �� ������ ���̹Ƿ� 0���� ����
	// maxPotions�� Player.h���� ���ŵǾ����Ƿ� ���⼭�� �ʱ�ȭ���� �ʽ��ϴ�.
	potionHealAmt(50)    // ���� ��� �� ȸ���� (����: 50)
	// --- ���ο� ���� �ൿ ���� ��� ���� �ʱ�ȭ ---
	isDefending(false), // ��� ���� �ʱ�ȭ
	strongAttackCooldown(0), // ������ ��ٿ� �ʱ�ȭ
	specialAbilityCooldown(0) // Ư���ɷ� ��ٿ� �ʱ�ȭ



{
	std::cout << "ĳ���Ͱ� �����Ǿ����ϴ�." << std::endl;
}

#pragma region ���� ����


void Player::Attack(Monster& targetEnemy)
{
	if (!IsAlive()) return;
	std::cout << GetName() << "(��)��" << targetEnemy.GetName() << "(��)�� �����մϴ�." << std::endl;
	int damage = attack - targetEnemy.GetDefense();
	if (damage < 0) damage = 0;
	targetEnemy.TakeDamage(damage);
}



// --- TakeDamage �Լ� ���� (��� ȿ�� ����) ---
void Player::TakeDamage(int damageAmount) {
	if (!IsAlive()) return;

	int actualDamage = damageAmount;
	if (isDefending) {
		actualDamage = damageAmount / 2; // ��� �� ���� ���� (����)
		std::cout << GetName() << "(��)�� ����Ͽ� ���ظ� " << actualDamage << "�� �ٿ����ϴ�!" << std::endl;
	}

	hp -= actualDamage;
	std::cout << GetName() << "(��)�� " << actualDamage << "�� ���ظ� �Ծ����ϴ�." << std::endl;

	if (hp <= 0) {
		hp = 0;
		std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
		std::cout << GetName() << "(��)�� ���������ϴ�..." << std::endl;
	}
	else {
		std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
	}
}

// --- ���ο� ���� �ൿ �Լ� ���� ---
void Player::StrongAttack(Monster& targetEnemy) {
	if (strongAttackCooldown > 0) {
		std::cout << "�������� ���� ��ٿ� ���Դϴ�! (" << strongAttackCooldown << "�� ����)" << std::endl;
		return; // ��ٿ� ���̸� ���� �Ұ�
	}
	std::cout << GetName() << "(��)�� ������ �ϰ��� �����ϴ�!" << std::endl;
	int damage = static_cast<int>(attack * 1.5) - targetEnemy.GetDefense(); // 1.5�� ���ݷ� (����), int�� ĳ����
	if (damage < 0) damage = 0;
	targetEnemy.TakeDamage(damage);
	strongAttackCooldown = 3; // 3�� ��ٿ� (����)
}

//��� �ൿ ���
void Player::Defend() {
	std::cout << GetName() << "(��)�� ��� �ڼ��� ���մϴ�. ���� ������ ���ذ� �����մϴ�." << std::endl;
	isDefending = true;
}

// --- �� ���� �� ���� �ʱ�ȭ �Լ� ���� ---
void Player::ResetTurnState() {
	isDefending = false; // ��� ���� ����
	if (strongAttackCooldown > 0) strongAttackCooldown--; // ������ ��ٿ� ����
	if (specialAbilityCooldown > 0) specialAbilityCooldown--; // Ư���ɷ� ��ٿ� ����
}

void Player::GainExperience(int expAmount)
{

	exp += expAmount;
	std::cout << GetName() << "��(��) ����ġ " << expAmount << "��(��) ȹ���߽��ϴ�. (���� ����ġ: " << exp << "/" << requiredExp << ")" << std::endl;
	while (exp >= requiredExp) {
		LevelUp();
	}

}

void Player::LevelUp()
{
	level++;
	exp -= requiredExp; // ���� ����ġ ó��
	requiredExp = level * 100; // ���� ������ �ʿ� ����ġ (����)

	// ���� ���� (����)
	maxHp += 10;
	hp = (maxHp/2); // ������ �� ü�� ���� ȸ�� (�Ǵ� ���� ȸ��)
	attack += 2;
	defense += 1;

	std::cout << "\n--- ������! ---" << std::endl;
	std::cout << GetName() << "��(��) ���� " << level << "��(��) �Ǿ����ϴ�!" << std::endl;
	DisplayStatus(); // ������ �� ���� ǥ��
	//�������� ���� ����
	potionCount++;
	std::cout << GetName() << "�� ���������� ���ǻ�� Ƚ���� 1�����߽��ϴ�! (����: " << potionCount << ")" << std::endl;
}



void Player::DisplayStatus()
{
	{
		std::cout << "--- " << name << "�� ���� ---" << std::endl;
		std::cout << "����: " << level << std::endl;
		std::cout << "ü��: " << hp << "/" << maxHp << std::endl;
		std::cout << "���ݷ�: " << attack << std::endl;
		std::cout << "����: " << defense << std::endl;
		std::cout << "����ġ: " << exp << "/" << requiredExp << std::endl;
		std::cout << "ġ�� �ش�: " << bandageCount << std::endl;
		std::cout << "���� ���Ƿ� : " << potionCount << std::endl;

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

	std::cout << GetName() << "�� ü���� " << amount << " ȸ���Ǿ����ϴ�. ���� ü��: " << hp << "/" << maxHp << std::endl;
}


bool Player::IsAlive() const
{
	return hp > 0;
	return true;
}
#pragma region ���� ��ȯ

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

#pragma region ȸ������ ��ȯ �Լ�
// --- 6��: ġ�� �ش� ���� �Լ� ---
bool Player::useBandage() {
    if (bandageCount > 0) {
        bandageCount--;
        Heal(bandageHealAmt);
        std::cout << GetName() << "(��)�� ġ�� �ش븦 ����߽��ϴ�. ���� �ش�: " << bandageCount << std::endl;
        return true;
    } else {
        std::cout << "����� ġ�� �ش밡 �����ϴ�." << std::endl;
        return false;
    }
}

int Player::getBandageCount() const {
    return bandageCount;
}

void Player::setBandages(int count) {
    // maxBandages�� �����Ƿ�, �ܼ��� ���� �ش� ���� �����մϴ�.
    bandageCount = count;
    std::cout << GetName() << "(��)�� ġ�� �ش� " << count << "���� ȹ���߽��ϴ�." << std::endl;
}

void Player::addBandages(int count) {
    bandageCount += count;
    std::cout << GetName() << "(��)�� �ش� " << count << "���� �߰��� ȹ���߽��ϴ�. (����: " << bandageCount << ")" << std::endl;
}

// --- 3��: ���� ���� �Լ� ---
bool Player::usePotion() {
    if (potionCount > 0) {
        potionCount--;
        Heal(potionHealAmt);
        std::cout << GetName() << "(��)�� ������ 1ȸ�� ����߽��ϴ�. ���� ���Ƿ�: " << potionCount << std::endl;
        return true;
    } else {
        std::cout << "����� ������ �����ϴ�." << std::endl;
        return false;
    }
}

int Player::getPotionCount() const {
    return potionCount;
}

// getMaxPotions()�� Player.h���� ���ŵǾ����Ƿ� �������� �ʽ��ϴ�.

void Player::addPotions(int count) {
    potionCount += count;
    std::cout << GetName() << "(��)�� ���� ��뷮 " << count << "���� �߰��� ȹ���߽��ϴ�. (����: " << potionCount << ")" << std::endl;
}

#pragma endregion



Player::~Player()
{
}

#pragma endregion





