#ifndef BATTLE_H
#define BATTLE_H

#include "Character.h"

struct Battler{
    Character battleCharacter;
    int currentHealth;
    };

class Battle
{
    public:
        Battle(Character player);
        Character RunBattle();


    private:
        int speedDifference;
        Battler userAttacker;
        Battler opponentAttacker;

        int GetSpeedDifference(Character user, Character opponent);

        Battler Attack(Battler attacker, Battler defender);
        Battler Spell(Battler attacker, Battler defender);

        Battler Heal(Battler healer);
        int GetHealAmount(Character healer);

        Character GenerateOpponent(int playerLevel);

        void UserTurn();

};

#endif // BATTLE_H
