#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "CharClass.h"


class Character
{
    public:
        Character();
        Character(std::string charName, CharClass role);
        Character(CharClass role);

        std::string GetName();

        int GetLevel();
        void SetLevel(int readLevel);

        int GetMoney();
        void SetMoney(int readMoney);

        int GetHealth();
        void SetHealth(int readHealth);

        CharClass GetClass();
        void SetClass(CharClass readClass);

        int GetCurrentExp();
        void SetCurrentExp(int readCurrentExp);

        int GetExpToLevelUp();
        void SetExpToLevelUp(int readExpToLevelUp);

        int GetStrength();
        void SetStrength(int readStrength);

        int GetMagicStrength();
        void SetMagicStrength(int readMagicStrength);

        int GetSpeed();
        void SetSpeed(int readSpeed);

        int GetDefense();
        void SetDefense(int readDefense);

        int GetMana();
        void SetMana(int readMana);

        int GetInventory();
        void SetInventory(int readInventory);

        void IncreaseInventory();
        void DecreaseInventory();


        int GenExp();
        void GainExp(int expGained);
        void LevelUp();

        int GenMoney();
        void GainMoney(int moneyGained);

        void Print();



    private:
        static const int MAX_LEVEL = 100;

        std::string name;
        int level;
        int health;
        int money;
        CharClass userClass;
        int currentExp;
        int expToLevelUp;
        int strength;
        int magicStrength;
        int speed;
        int defense;
        int mana;
        int inventory;


};

#endif // CHARACTER_H
