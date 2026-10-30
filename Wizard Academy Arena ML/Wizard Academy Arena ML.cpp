// neccesary setup
#include <iostream>
#include <string>       // neccesary to add strings
using namespace std;    // this line keeps me from having to type std:: each time

// initializing all of my functions to prevent errors
void displaySpellBanner(string spellName, string tier = "NOVICE", int chargeLevel = 1);
double castSpell(string spellName = "MAGIC MISSILE", int basePower = 10, double multiplier = 1.0);
double calculateShield(double baseShield = 20.0, double absorptionRate = 0.25);     // I need to define fallbacks for undefined calls for tier, charge level, spellName, etc.

// this is the beginning of the functions for part one
int main()
{
    cout << "=== ARENA WARM-UP: TESTING DEFAULT ARGUMENTS ===\n\n";

    displaySpellBanner("MAGIC MISSILE");
    double dmg1 = castSpell();
    double ward1 = calculateShield();
    cout << "WARD ABSORBS: " << ward1 << " HP\n\n";

    displaySpellBanner("INFERNO FIREBALL", "MASTER", 3);
    double dmg2 = castSpell("INFERNO FIREBALL", 35, 1.5);
    double ward2 = calculateShield(30.0, 0.50);
    cout << "WARD ABSORBS: " << ward2 << " HP\n\n";

    return 0;
}

void displaySpellBanner(string spellName, string tier, int chargeLevel)
{
    cout << "CASTING SPELL " << tier << " TIER " << spellName << " AT LEVEL " << chargeLevel << endl;
}

double castSpell(string spellName, int basePower, double multiplier)
{
    double spellDamage = basePower * multiplier;
    cout << spellName << " SUCCESSFULLY CAST\n"
        << spellName << " HAS A BASE POWER OF " << basePower << ", WITH A MULTIPLIER OF " << multiplier << " THAT'S " << spellDamage << " DAMAGE!!" << endl;
    return spellDamage;
}

double calculateShield(double baseShield, double absorptionRate)
{
    double totalBlock = baseShield * (1.0 + absorptionRate); // 1.0 is needed to prevent the absorption rate from decreasing the baseShield rather than increasing it
    return totalBlock;
}

// Functions added in part two
