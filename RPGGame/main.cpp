#include <iostream>
#include <fstream>
#include <string>
#include "CharClass.h"
#include "Character.h"
#include "Battle.h"

using namespace std;

Character SplashMenu();
Character LoadCharacter();
Character CreateCharacter();

void MainMenu(Character);
Character Shop(Character);
void ViewStats(Character);
void Save(Character);



int main()
{
    Character user = SplashMenu();
    MainMenu(user);
    return 0;
}

Character SplashMenu()
{
    const string NewChar = "new";
    const string Load = "load";
    string saveLoadChoice = "";

    bool notValidInput = true;
    while(notValidInput)
    {
        cout<< "Welcome to the game" <<endl;
        cout<< "Would you like to: load or new"<<endl;
        cin>>saveLoadChoice;

        if(saveLoadChoice.compare(NewChar) == 0)
        {
            notValidInput = false;
            return CreateCharacter();
        }

        if(saveLoadChoice.compare(Load) == 0)
        {
            notValidInput = false;
            return LoadCharacter();
        }

        cout<<"Not a valid input"<<endl;

    }

    Character nonChar = Character();
    return nonChar;
}

Character CreateCharacter()
{
    string newCharName = "";
    cout<<"What is your characters name"<<endl;
    cin>>newCharName;

    const string Warrior = "Warrior";
    const string Mage = "Mage";
    const string Archer = "Archer";

    CharClass parsedCharClass;

    bool notValidInput = true;
    while(notValidInput)
    {
        string newCharClass = "";
        cout<<"What class do you choose?"<<endl;
        cout<<"Warrior Mage Archer"<<endl;
        cin>>newCharClass;

        if(newCharClass.compare(Warrior) == 0)
        {
            notValidInput = false;
            parsedCharClass = CharClass::Warrior;
        }

        if(newCharClass.compare(Mage) == 0)
        {
            notValidInput = false;
            parsedCharClass = CharClass::Mage;
        }

        if(newCharClass.compare(Archer) == 0)
        {
            notValidInput = false;
            parsedCharClass = CharClass::Archer;
        }

    }

    Character playerCharacter = Character(newCharName, parsedCharClass);
    return playerCharacter;
}

Character LoadCharacter()
{
    string charName = "";
    cout<<"Enter the name of the character you want to load"<<endl;
    cin>>charName;

    ifstream saveFile;
    saveFile.open("savefile.txt");
    string inputLine = "";

    getline(saveFile, inputLine);


    if(charName.compare(inputLine) == 0)
    {
        string name = inputLine;

        getline(saveFile,inputLine);
        string classType = inputLine;

        const string Warrior = "Warrior";
        const string Mage = "Mage";
        const string Archer = "Archer";

        CharClass parsedCharClass;

        bool notValidInput = true;
        while(notValidInput)
        {

            if(classType.compare(Warrior) == 0)
            {
                notValidInput = false;
                parsedCharClass = CharClass::Warrior;
            }

            if(classType.compare(Mage) == 0)
            {
                notValidInput = false;
                parsedCharClass = CharClass::Mage;
            }

            if(classType.compare(Archer) == 0)
            {
                notValidInput = false;
                parsedCharClass = CharClass::Archer;
            }
        }

        Character playerCharacter = Character(name, parsedCharClass);

        string s_level = "";
        getline(saveFile, s_level);
        int i_level = stoi(s_level);
        playerCharacter.SetLevel(i_level);

        string s_money = "";
        getline(saveFile, s_money);
        int i_money = stoi(s_money);
        playerCharacter.SetMoney(i_money);

        string s_health = "";
        getline(saveFile, s_health);
        int i_health = stoi(s_health);
        playerCharacter.SetHealth(i_health);

        string s_currenExp = "";
        getline(saveFile, s_currenExp);
        int i_currentExp = stoi(s_currenExp);
        playerCharacter.SetCurrentExp(i_currentExp);

        string s_expToLevelUp = "";
        getline(saveFile, s_expToLevelUp);
        int i_expToLevelUp = stoi(s_expToLevelUp);
        playerCharacter.SetExpToLevelUp(i_expToLevelUp);

        string s_strength = "";
        getline(saveFile, s_strength);
        int i_strength = stoi(s_strength);
        playerCharacter.SetStrength(i_strength);

        string s_magicStrength = "";
        getline(saveFile, s_magicStrength);
        int i_magicStrength = stoi(s_magicStrength);
        playerCharacter.SetMagicStrength(i_magicStrength);

        string s_speed = "";
        getline(saveFile, s_speed);
        int i_speed = stoi(s_speed);
        playerCharacter.SetSpeed(i_speed);

        string s_defense = "";
        getline(saveFile, s_defense);
        int i_defense = stoi(s_defense);
        playerCharacter.SetDefense(i_defense);

        string s_mana = "";
        getline(saveFile, s_mana);
        int i_mana = stoi(s_mana);
        playerCharacter.SetMana(i_mana);

        string s_inventory = "";
        getline(saveFile, s_inventory);
        int i_inventory = stoi(s_inventory);
        playerCharacter.SetInventory(i_inventory);

        saveFile.close();
        return playerCharacter;
    }
    saveFile.close();
    cout<<"Character not found"<<endl;
    cout<<"Let's make a new one"<<endl;
    return CreateCharacter();

}

void MainMenu(Character player)
{
    Character user = player;
    bool exit = false;
    while(!exit)
    {
        cout<<"What would you like to do?"<<endl;
        cout<<"Stats Battle Shop Save Exit"<<endl;

        string choice = "";
        cin>>choice;

        const string stats = "Stats";
        if(choice.compare(stats) == 0)
        {
            ViewStats(user);
        }

        const string battle = "Battle";
        if(choice.compare(battle) == 0)
        {
            Battle conflict = Battle(user);
            user = conflict.RunBattle();

        }

        const string shop = "Shop";
        if(choice.compare(shop) == 0)
        {
            user = Shop(user);
        }

        const string save = "Save";
        if(choice.compare(save) == 0)
        {
            Save(user);
        }

        const string leaveGame = "Exit";
        if(choice.compare(leaveGame) == 0)
        {
            return;
        }
    }
}

void Save(Character player)
{
    ofstream saveFile;
    saveFile.open("savefile.txt", ios::trunc);
    saveFile<<player.GetName()<<endl;

    switch(player.GetClass())
    {
        case CharClass::Warrior:
            saveFile<<"Warrior"<<endl;
            break;
        case CharClass::Mage:
            saveFile<<"Mage"<<endl;
            break;
        case CharClass::Archer:
            saveFile<<"Archer"<<endl;
            break;
    }

    saveFile<<player.GetLevel()<<endl;
    saveFile<<player.GetMoney()<<endl;
    saveFile<<player.GetHealth()<<endl;
    saveFile<<player.GetCurrentExp()<<endl;
    saveFile<<player.GetExpToLevelUp()<<endl;
    saveFile<<player.GetStrength()<<endl;
    saveFile<<player.GetMagicStrength()<<endl;
    saveFile<<player.GetSpeed()<<endl;
    saveFile<<player.GetDefense()<<endl;
    saveFile<<player.GetMana()<<endl;
    saveFile<<player.GetInventory()<<endl;

    saveFile.close();

}

void ViewStats(Character player)
{
    player.Print();
}

Character Shop(Character Buyer)
{
    const int potionCost = 30;

    bool notValid = true;
    while(notValid)
    {
        cout<<"Want to buy a potion for " <<potionCost<< " gold?"<<endl;
        cout<<"yes or no?"<<endl;
        cout<<"You have: "<<Buyer.GetMoney()<<endl;

        string input = "";
        cin>>input;

        const string Yes = "yes";
        const string No = "no";

        if(input.compare(Yes) == 0)
        {
            if(Buyer.GenMoney() >= potionCost)
            {
                cout<<"You purchased a potion"<<endl;
                int potions = Buyer.GetInventory() + 1;
                Buyer.SetInventory(potions);
                return Buyer;
            }
            else
            {
                cout<<"You don't have enough money"<<endl;
                notValid = false;
            }
        }
        if(input.compare(No) == 0)
        {
            break;
        }

        cout<<"Not valid input"<<endl;
    }

    return Buyer;
}
