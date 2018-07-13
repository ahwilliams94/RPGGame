#include <iostream>
#include <cstdlib>
#include "Battle.h"
#include "Character.h"
#include "CharClass.h"

Battle::Battle(Character player)
{
    userAttacker.battleCharacter = player;
    userAttacker.currentHealth = userAttacker.battleCharacter.GetHealth();
    opponentAttacker.battleCharacter = GenerateOpponent(userAttacker.battleCharacter.GetLevel());
    opponentAttacker.currentHealth = opponentAttacker.battleCharacter.GetHealth();
    speedDifference = GetSpeedDifference(userAttacker.battleCharacter, opponentAttacker.battleCharacter);
}

Character Battle::RunBattle()
{
    bool noDead = true;
    while(noDead)
    {
        std::cout<<userAttacker.battleCharacter.GetName()<<" "<<userAttacker.battleCharacter.GetLevel()<<" "<<userAttacker.currentHealth<<"/"<<userAttacker.battleCharacter.GetHealth()<<std::endl;
        std::cout<<opponentAttacker.battleCharacter.GetName()<<" "<<opponentAttacker.battleCharacter.GetLevel()<<" "<<opponentAttacker.currentHealth<<"/"<<opponentAttacker.battleCharacter.GetHealth()<<std::endl;

        if(speedDifference >= 0)
        {
            UserTurn();
            if(opponentAttacker.currentHealth <= 0)
            {
                noDead = false;
                std::cout<<"You win!"<<std::endl;
                /*COME BACK HERE TO ADD IN EXP GAIN*/
                int expReward = opponentAttacker.battleCharacter.GenExp();
                userAttacker.battleCharacter.GainExp(expReward);

                int moneyReward = opponentAttacker.battleCharacter.GenMoney();
                userAttacker.battleCharacter.GainMoney(moneyReward);
                return userAttacker.battleCharacter;

            }

            userAttacker = Attack(opponentAttacker, userAttacker);

            if(userAttacker.currentHealth <= 0)
            {
                noDead = false;
                std::cout<<"You died!"<<std::endl;
                break;
            }
        }
        else
        {
            userAttacker = Attack(opponentAttacker,userAttacker);

            if(userAttacker.currentHealth <= 0)
            {
                noDead = false;
                std::cout<<"You died!"<<std::endl;
                break;
            }

            UserTurn();

            if(opponentAttacker.currentHealth <= 0)
            {
                noDead = false;
                std::cout<<"You win!"<<std::endl;
                /*COME BACK HERE TO ADD IN EXP GAIN*/
                int expReward = opponentAttacker.battleCharacter.GenExp();
                userAttacker.battleCharacter.GainExp(expReward);

                int moneyReward = opponentAttacker.battleCharacter.GenMoney();
                userAttacker.battleCharacter.GainMoney(moneyReward);
                return userAttacker.battleCharacter;

            }

        }
    }

    return userAttacker.battleCharacter;

}

int Battle::GetSpeedDifference(Character user, Character opponent)
{
    return user.GetSpeed() - opponent.GetSpeed();
}

Battler Battle::Attack(Battler attacker, Battler defender)
{
    int damage = 0;
    damage = attacker.battleCharacter.GetStrength() - defender.battleCharacter.GetDefense();
    if(damage <= 0)
    {
        damage = 1;
    }
    defender.currentHealth = defender.currentHealth - damage;
    return defender;
}

Battler Battle::Spell(Battler attacker, Battler defender)
{
    int damage = 0;
    damage = attacker.battleCharacter.GetMagicStrength() - defender.battleCharacter.GetDefense();
    if(damage <= 0)
    {
        damage = 1;
    }
    defender.currentHealth = defender.currentHealth - damage;
    return defender;
}

Battler Battle::Heal(Battler healer)
{
    int numPotions = healer.battleCharacter.GetInventory();
    if(numPotions > 0)
    {
        healer.currentHealth = healer.currentHealth + GetHealAmount(healer.battleCharacter);
        healer.battleCharacter.DecreaseInventory();
    }
    else
    {
        std::cout<<"You don't have any healing items"<<std::endl;
    }
    return healer;
}

int Battle::GetHealAmount(Character healer)
{
    return (int)(healer.GetHealth() * .3);
}

Character Battle::GenerateOpponent(int playerLevel)
{
    int minOpponentLevel = playerLevel - 2;
    int maxOpponentLevel = playerLevel + 2;
    int opponentLevel = (rand() % (maxOpponentLevel - minOpponentLevel)) + minOpponentLevel;
    int classPicker = rand() % 3;
    CharClass opponentClass;

    switch(classPicker)
    {
        case 0:
            opponentClass = CharClass::Warrior;
            break;
        case 1:
            opponentClass = CharClass::Mage;
            break;
        case 2:
            opponentClass = CharClass::Archer;
            break;
    }

    Character opponent = Character(opponentClass);
    for(int levelUps = 0; levelUps < opponentLevel; levelUps++)
    {
        opponent.LevelUp();
    }

    return opponent;

}

void Battle::UserTurn()
{
    bool invalidInput = true;
    while(invalidInput)
    {
        std::cout<<"What will you do?"<<std::endl;
        std::cout<<"Attack Spell Heal"<<std::endl;

        std::string choice = "";
        std::cin>>choice;

        const std::string s_Attack = "Attack";
        const std::string s_Spell = "Spell";
        const std::string s_Heal = "Heal";

        if(choice.compare(s_Attack) == 0)
        {
            opponentAttacker = Attack(userAttacker, opponentAttacker);
            invalidInput = false;
        }

        if(choice.compare(s_Spell) == 0)
        {
            opponentAttacker = Spell(userAttacker, opponentAttacker);
            invalidInput = false;
        }

        if(choice.compare(s_Heal) == 0)
        {
            Heal(userAttacker);
            invalidInput = false;
        }

        if(invalidInput == true)
        {
            std::cout<<"Your input was invalid"<<std::endl;
        }
    }
}
