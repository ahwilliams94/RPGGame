#include <cstdlib>
#include <iostream>
#include "Character.h"

Character::Character(){}

Character::Character(std::string charName, CharClass role)
{
    name = charName;
    level = 1;
    money = 0;
    userClass = role;
    health = 10;
    currentExp = 0;
    expToLevelUp = 10;
    strength = 5;
    magicStrength = 5;
    speed = 5;
    defense = 5;
    mana = 5;
    inventory = 0;
}

Character::Character(CharClass role)
{
    name = "Opponent";
    level = 1;
    money = 0;
    userClass = role;
    health = 10;
    currentExp = 0;
    expToLevelUp = 10;
    strength = 5;
    magicStrength = 5;
    speed = 5;
    defense = 5;
    mana = 5;
    inventory = 0;
}

std::string Character::GetName()
{
    return name;
}

int Character::GetLevel()
{
    return level;
}

void Character::SetLevel(int readLevel)
{
    level = readLevel;
}

int Character::GetMoney()
{
    return money;
}

void Character::SetMoney(int readMoney)
{
    money = readMoney;
}

int Character::GetHealth()
{
    return health;
}

void Character::SetHealth(int readHealth)
{
    health = readHealth;
}


CharClass Character::GetClass()
{
    return userClass;
}

void Character::SetClass(CharClass readClass)
{
    userClass = readClass;
}

int Character::GetCurrentExp()
{
    return currentExp;
}

void Character::SetCurrentExp(int readCurrentExp)
{
    currentExp = readCurrentExp;
}

int Character::GetExpToLevelUp()
{
    return expToLevelUp;
}

void Character::SetExpToLevelUp(int readExpToLevelUp)
{
    expToLevelUp = readExpToLevelUp;
}

int Character::GetStrength()
{
    return strength;
}

void Character::SetStrength(int readStrength)
{
    strength = readStrength;
}

int Character::GetMagicStrength()
{
    return magicStrength;
}

void Character::SetMagicStrength(int readMagicStrength)
{
    magicStrength = readMagicStrength;
}

int Character::GetSpeed()
{
    return speed;
}

void Character::SetSpeed(int readSpeed)
{
    speed = readSpeed;
}

int Character::GetDefense()
{
    return defense;
}

void Character::SetDefense(int readDefense)
{
    defense = readDefense;
}

int Character::GetMana()
{
    return mana;
}

void Character::SetMana(int readMana)
{
    mana = readMana;
}

int Character::GetInventory()
{
    return inventory;
}

void Character::SetInventory(int readInventory)
{
    mana = readInventory;
}

void Character::IncreaseInventory()
{
    inventory += 1;
}

void Character::DecreaseInventory()
{
    inventory -= 1;
}

int Character::GenExp()
{
    return level;
}

void Character::GainExp(int expGained)
{
    currentExp = currentExp + expGained;
    if(currentExp > expToLevelUp)
    {
        int leftOverExp = currentExp - expToLevelUp;
        currentExp = leftOverExp;
        expToLevelUp = expToLevelUp * 1.5;
        LevelUp();
    }
}

int Character::GenMoney()
{
    return level;
}

void Character::GainMoney(int moneyGained)
{
    money = money + moneyGained;
}

void Character::LevelUp()
{
    if(level < MAX_LEVEL)
    {

        level = level + 1;
        health = health + 5;

        int strRate = 0;
        int defRate = 0;
        int spdRate = 0;
        int mgstrRate = 0;



        switch(userClass)
        {
            case CharClass::Warrior:
                strRate = 8;
                defRate = 6;
                spdRate = 4;
                mgstrRate = 2;
                break;
            case CharClass::Mage:
                strRate = 4;
                defRate = 3;
                spdRate = 5;
                mgstrRate = 9;
                break;
            case CharClass::Archer:
                strRate = 7;
                defRate = 5;
                spdRate = 9;
                mgstrRate = 4;
                break;

        }

        bool noIncrease = true;
        int increaseChance = (rand() % 10) + 1;
        while(noIncrease)
        {
            if(increaseChance > (10 - strRate))
            {
                strength = strength + 2;
                noIncrease = false;
            }
            if(increaseChance > (10 - defRate))
            {
                defense = defense + 2;
                noIncrease = false;
            }
            if(increaseChance > (10 - spdRate))
            {
                speed = speed + 2;
                noIncrease = false;
            }
            if(increaseChance > (10 - mgstrRate))
            {
                magicStrength = magicStrength + 2;
                noIncrease = false;
            }
        }
    }
}

void Character::Print()
{
    std::cout<<name<<" level:"<<level<<std::endl;
    std::cout<<"exp:"<<currentExp<<"/"<<expToLevelUp<<std::endl;
    std::cout<<money<<" gold "<<inventory<<" potions"<<std::endl;
    std::cout<<"Strength:"<<strength<<std::endl;
    std::cout<<"Magic:"<<magicStrength<<std::endl;
    std::cout<<"Defense:"<<defense<<std::endl;
    std::cout<<"Speed:"<<speed<<std::endl;
    std::cout<<"Mana:"<<mana<<std::endl;
}
