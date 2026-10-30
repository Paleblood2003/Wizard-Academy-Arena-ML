// neccesary setup
#include <iostream>
#include <string>       // neccesary to add strings
using namespace std;    // this line keeps me from having to type std:: each time

// initializing all of my functions to prevent errors
void displaySpellBanner(string spellName, string tier = "NOVICE", int chargeLevel = 1);
double castSpell(string spellName = "MAGIC MISSILE", int basePower = 10, double multiplier = 1.0);
double calculateShield(double baseShield = 20.0, double absorptionRate = 0.25);     // I need to define fallbacks for undefined calls for tier, charge level, spellName, etc.
// initializating part 2
int registerCombo(bool hitSuccessful);
void consumeMana(int cost = 5);     // defaults the mana use to 5 unless specified otherwise
bool processBossRage(double damageDealt);
int gainWizardXP(int expGained);

// this is the beginning of the functions for part one
int main()
{
    cout << "=== WIZARD ACADEMY BATTLE SIMULATOR ===\n\n";

    char continueBattle = 'y';
    int turn = 1;

    while (continueBattle == 'y' || continueBattle == 'Y')
    {
        cout << "\n----------------------------------------\n";
        cout << "TURN" << turn << "\n";
        cout << "----------------------------------------\n";

        int choice = 0;
        cout << "Select Action:\n";
        cout << "1) Quick Magic Missile (Default attack)\n";
        cout << "2) Heavy Lightning Storm (Custom attack)\n";
        cout << "3) Cast Defensive Barrier\n";
        cout << "4) Miss Attack\n";
        cout << "Choice: ";
        cin >> choice;

        double damageDealt = 0.0;
        bool successfulHit = false;

        if (choice == 1)
            {
            displaySpellBanner("Magic Missile");
            damageDealt = castSpell();  // Uses default Arguments
            consumeMana();              // Uses default mana cost (5)
            successfulHit = true;
        }
        else if (choice == 2)
            {
            displaySpellBanner("Lightning Storm", "Adept", 2);
            damageDealt = castSpell("Lightning Storm", 30, 1.4);
            consumeMana(15);             // Custom mana cost
            successfulHit = true;
        }
        else if (choice == 3)
            {
            displaySpellBanner("Arcane Shield", "Novice", 1);
            double shieldVal = calculateShield(20.0, 0.25);
            cout << "Shield generated! Absorbs " << shieldVal << " incoming damage.\n";
            consumeMana(8);
            successfulHit = true;
        }
        else {
            cout << "Your attack missed completely!\n";
            successfulHit = false;
        }

        // --- UPDATE PERSISTENT GAME STATE VIA STATIC FUNCTIONS ---
        int currentCombo = registerCombo(successfulHit);
        if (successfulHit) 
        {
            cout << "Current Combo Streak: " << currentCombo << "x\n";
            gainWizardXP(30); // Award XP for hitting
        }

        // Check if boss enters enrage mode
        bool isBossEnraged = processBossRage(damageDealt);
        if (isBossEnraged)
        {
            cout << "!!! WARNING: BOSS HAS ENTERED ENRAGE MODE !!!\n";
        }

        turn++;
        cout << "\nEnd turn? Continue fighting? (y/n): ";
        cin >> continueBattle;
    }

    cout << "\n=== BATTLE SIMULATION ENDED ===\n";
    return 0;
}

void displaySpellBanner(string spellName, string tier, int chargeLevel) // used to display the casting of a spell
{
    cout << "Casting spell " << tier << " tier " << spellName << " at level " << chargeLevel << endl;
}

double castSpell(string spellName, int basePower, double multiplier) // used to calculate the damage returned by the cast spell
{
    double spellDamage = basePower * multiplier;
    cout << spellName << " successfully cast!\n"
        << spellName << " has a base power of " << basePower << ", with a multiplier of " << multiplier << " that's " << spellDamage << " damage!!" << endl;
    return spellDamage;
}

double calculateShield(double baseShield, double absorptionRate) // used to calculate the damage blocked by the defender's ward
{
    double totalBlock = baseShield * (1.0 + absorptionRate); // 1.0 is needed to prevent the absorption rate from decreasing the baseShield rather than increasing it
    return totalBlock;
}

// Functions added in part two

int registerCombo(bool hitSuccessful) // Keeps track of the current combo
{
    static int comboCount = 0;
    if (hitSuccessful)
    {
        comboCount++;
    }
    else
    {
        comboCount = 0;
    }
    return comboCount;
}

void consumeMana(int cost) // Keeps track of how much mana has been used during the fight
{
    static int totalManaUsed = 0;

    totalManaUsed += cost;
    cout << "Total Mana Used: " << totalManaUsed << endl;
}

bool processBossRage(double damageDealt)
{
    static double totalDamageDealt = 0.0;

    totalDamageDealt += damageDealt;
    
    if (totalDamageDealt >= 100.0)
    {
        return true;
    }

    return false;
}

int gainWizardXP(int expGained)
{
    static int totalXP = 0;
    static int wizardLevel;

    totalXP += expGained;

    if (totalXP >= wizardLevel * 100)
    {
        wizardLevel++;
        cout << "LEVEL UP!\n";
    }
    return wizardLevel;
}