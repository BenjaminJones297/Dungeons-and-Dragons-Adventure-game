/*
Benjamin Jones
ASU CSE 240
Fall 2023
*/

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

int rand();

class Spell {
    public:
        int numDamageDie;
        int damageDie;
        string name;
        int healDie;
        int numHealDie;
        bool stun;
        int numTurnStunned;
    public:
        Spell(string n, int numD, int d, int hD, int h, bool s, int tS) { 
            name = n;
            numDamageDie = numD;
            damageDie = d;
            healDie = h;
            numHealDie = hD;
            stun = s;
            numTurnStunned = tS;
        }

        void toString() {
            if (numHealDie) {
                cout << name << " does " << numHealDie << " d" << healDie << " healing";
            }
            if (numDamageDie) {
                cout << name << " does " << numDamageDie << " d" << damageDie << " damage";
            }
            if (stun) {
                cout << name << " stuns for " << numTurnStunned << " rounds";
            }
        }

        int getDamage() {
            int damage = 0;
            for (int i = 0; i <= numDamageDie; i++) {
                damage += (rand() % (damageDie - 1)) + 1;
            }
            return damage;
        }

        int getHeal() {
            int heal = 0;
            for (int i = 0; i <= numHealDie; i++) {
                heal += (rand() % (healDie - 1)) + 1;
            }
            return heal;
        }

        string getName() {
            return name;
        }

};

class Armor {
    protected:
        int rating;
        string armorName;
    public:
        Armor() {
            rating = 0;
            armorName = ".";
        }
        Armor(int r, string n) {
            rating = r;
            armorName = n;
        }
        int getRating() {
            return rating;
        }
        void toString() {
            cout << armorName << " has a rating of " << rating << "\n";
        }

};

class Weapon {
    public:
        int numDamageDie;
        int damageDieRange;
        bool isRanged;
        string name;

        Weapon() {
            numDamageDie = 0;
            damageDieRange = 0;
            isRanged = false;
            name = ".";
        }

        Weapon(int nD, int dam, bool r, string n) {
            numDamageDie = nD;
            damageDieRange = dam;
            isRanged = r;
            name = n;
        }
    
        int getDamage() {
            int damage = 0;
            for (int i = 0; i < numDamageDie; i++) {
                damage += ((rand() % (damageDieRange - 1)) + 1);
            }
            return damage;
        }

        string getName() {
            return name;
        }

        void toString() {cout << name << " has " << numDamageDie << " d" << damageDieRange << " damage\n";}
};

class Player {

    protected:
        string name;
        int maxHealth;
        int currrentHealth;
        int strength;
        int wisdom;
        int dexterity;
        int constitution;
        int charisma;
        int intelligence;
        int xp;
        int level;
        bool isaFighter;
        bool isaWizard;
        int stun;

    public:
        Player() {name = "";
            strength = 0;
            wisdom = 0;
            dexterity = 0;
            constitution = 0;
            charisma = 0;
            intelligence = 0; currrentHealth = 10, maxHealth = 10; level = 1; xp = 0; isaFighter = false; isaWizard = false; stun = 0;}
        Player(string n, int mH, int cH, int s, int w, int d, int con, int cha, int in) {
            name = n;
            currrentHealth = cH;
            maxHealth = mH;
            strength = s;
            wisdom = w;
            dexterity = d;
            constitution = con;
            charisma = cha;
            intelligence = in;
            level = 1;
            xp = 0;
            isaFighter = false;
            isaWizard = false;
            stun = 0;
        }

        void levelUp() {
            if (level == 1 && xp >= 100) {
                level++; xp -= 100;
            }

            if (level == 2 && xp >= 150) {
                level++; xp -= 150;
            }

            if (level == 3 && xp >= 200) {
                level++; xp -= 200;
            }

            if (level == 4 && xp >= 300) {
                level++; xp -= 300;
            }

            if (level == 5 && xp >= 350) {
                level++; xp -= 350;
            }

            if (level == 6 && xp >= 400) {
                level++; xp -= 400;
            }

            if (level == 7 && xp >= 450) {
                level++; xp -= 450;
            }

            if (level == 8 && xp >= 500) {
                level++; xp -= 500;
            }

        }

        void setMaxHealth(int h) {maxHealth = h;}
        int getMaxHealth() {return maxHealth;}
        void setCurrentHealth(int h) {currrentHealth = h;}
        int getHealth() {return currrentHealth;}

        void setName(string n) {name = n;}
        string getName() {return name;}

        void setDamage(int d) {currrentHealth -= d;}
        int getCurrentHealth() {return currrentHealth;}

        void heal(int h) {
            this->currrentHealth += h;
            if (this->currrentHealth >= this->maxHealth) {
                this->currrentHealth = this->maxHealth;
            }
        }

        void setStrength(int s) {strength = s;}
        int getStrength() {return strength;}

        void setWisdom(int w) {wisdom = w;}
        int getWisdom() {return wisdom;}

        void setDexterity(int d) {dexterity = d;}
        int getDexterity() {return dexterity;}

        void setConstitution(int con) {constitution = con;}
        int getConstitution() {return constitution;}

        void setCharisma(int cha) {charisma = cha;}
        int getCharisma() {return charisma;}

        void setIntelligence(int in) {intelligence = in;}
        int getIntelligence() {return intelligence;}

        int getMod(int r) {
            if ((r == 1)) {
                return -5;
            }
            else if (r >= 2 && r <= 3) {
                return -4;
            }
            else if (r >= 4 and r <= 5) {
                return -3;
            }
            else if (r >= 6 && r <= 7) {
                return -2;
            }
            else if (r >= 8 and r <= 9) {
                return -1;
            }
            else if (r >= 10 && r <= 11) {
                return 0;
            }
            else if (r >= 12 and r <= 13) {
                return 1;
            }
            else if (r >= 14 && r <= 15) {
                return 2;
            }
            else if (r >= 16 and r <= 17) {
                return 3;
            }
            else if (r >= 18 && r <= 19) {
                return 4;
            }
            else if (r >= 20 and r <= 21) {
                return 5;
            }
            return 0;
        }

        int strengthRoll() {
            return (rand() % 19 + 1) + getMod(strength);
        }

        int dexterityRoll() {
             return (rand() % 19 + 1) + getMod(dexterity);
        }

        int constitutionRoll() {
             return (rand() % 19 + 1) + getMod(constitution);
        }

        int intelligenceRoll() {
             return (rand() % 19 + 1) + getMod(intelligence);
        }

        int wisdomRoll() {
             return (rand() % 19 + 1) + getMod(wisdom);
        }

        int charismaRoll() {
             return (rand() % 19 + 1) + getMod(charisma);
        }

        bool isFighter() {
            return isaFighter;
        }

        bool isWizard() {
            return isaWizard;
        }

        void setStun(int n) {
            stun = n;
        }

        void decStun() {
            stun--;
        }

        int getStun() {
            return stun;
        }

        void toString() {cout << name << " has:\n" << maxHealth << " health\n" 
        << "" << strength << " strength\n" << dexterity << " dexterity\n"
         << constitution << " constitution\n" << intelligence << " intelligence\n"
          << wisdom << " wisdom\n" << charisma << " charisma\n"; }

};

class Fighter: public Player {

    private:
        class Armor playerArmor;
        class Weapon playerWeapon;
    public:
        Armor getArmor() {
            return playerArmor;
        }
        Weapon getWeapon() {
            return playerWeapon;
        }
        Fighter(string n, int mH, int cH, int s, int w, int d, int con, int cha, int in, bool r): Player(n, mH, cH, s, w, d, con, cha, in)
        {
        if (!r) {
                playerWeapon = Weapon(1, 10, false, "Battle Axe");
            }

            else {
                playerWeapon = Weapon(1, 8, true, "CrossBow");
            }
                    
            playerArmor = Armor(15, "Chain Mail");  maxHealth = 15; currrentHealth = 15; isaFighter = true; stun = 0;}

        Fighter(bool r): Player() {
            if (!r) {
                playerWeapon = Weapon(1, 10, false, "Battle Axe");
            }

            else {
                playerWeapon = Weapon(1, 8, true, "CrossBow");
            }
                    
            playerArmor = Armor(15, "Chain Mail");  maxHealth = 15; currrentHealth = 15; isaFighter = true; stun = 0;
        }

        Fighter(): Player() {
            stun = 0;
        }

        int getStun() {
            return Player::getStun();
        }

        bool pierce(int n) {
            if (n > this->getArmor().getRating()) {
                return true;
            }
            else {
                return false;
            }
        }

        void setWeapon(Weapon w) {
            playerWeapon = w;
        }

        void setArmor(Armor a) {
            playerArmor = a;
        }

        void toString() {Player::toString(); playerWeapon.toString(); playerArmor.toString();}

};

class Wizard: public Player {
    public:
        Spell *spellBook[3];
        Armor playerArmor;
    public:

        Wizard(string n, int mH, int cH, int s, int w, int d, int con, int cha, int in) : Player(n, mH, cH, s, w, d, con, cha, in)
        { 
        spellBook[0] = new Spell("Fireball", 2, 4, 0, 0, 0, 0); spellBook[1] = new Spell("Stun", 0,0,0,0,true,3);
        spellBook[2] = new Spell("Heal", 0,0,1,6,false,0); isaWizard = true; stun = 0; playerArmor = Armor();}

        void toString() {
            Player::toString();
            int n = 0;
            while(n < 3) {
                spellBook[n]->toString();
                n++;
                cout << "\n";
            }
        }

        Wizard(): Player() {
            spellBook[0] = new Spell("Fireball", 2, 6, 0, 0, false, 0); spellBook[1] = new Spell("Stun", 0,0,0,0,true,3);
            spellBook[2] = new Spell("Heal", 0,0,1,6,false,0); isaWizard = true; stun = 0; playerArmor = Armor();
        }

        void setArmor(Armor a) {
            playerArmor = a;
        }

        bool pierce(int n) {
            if (n > playerArmor.getRating()) {
                return true;
            }
            else {
                return false;
            }
            return true;
        }

};

class Enemy {
    protected:
        int health;
        int currentHealth;
        Weapon enemyWeapon;
        Armor enemyArmor;
        string name;
        int stun;
        int magicResistance;
        int strength;
        int wisdom;
        int dexterity;
        int constitution;
        int charisma;
        int intelligence;

    public:
        void hit(int damage) {
            currentHealth -= damage;
        }

        bool pierce (int str) {
            if (str >= enemyArmor.getRating()) {
                return true;
            }

            else {
                return false;
            }
        }

        Weapon getWeapon() {
            return enemyWeapon;
        }

        Armor getArmor() {
            return enemyArmor;
        }

        bool spellLand(int wis) {
            if (wis >= magicResistance) {
                return true;
            }

            else {
                return false;
            }

        }
        void setStun(int n) {
            stun = n;
        }
        int getStun() {
            return stun;
        }
        void decStun() {
            stun--;
        }
        int getHealth() {return health;}
        int getCurrentHealth() {return currentHealth;}
        int getDamage() {return enemyWeapon.getDamage();}
        string getName() {return name;}
        void setName(string n) {name = n;}
        void heal(int h) {
            currentHealth += h;
            if (currentHealth >= getHealth()) {
                currentHealth = getHealth();
            }
        }
        Enemy() {health = 1; currentHealth = health; enemyWeapon = Weapon(); enemyArmor = Armor(); stun = 0; magicResistance = 0; int strength;
        wisdom = 5;
        dexterity = 12;
        constitution = 12;
        charisma = 2;
        intelligence = 5;
        strength = 14;}
        void setDead() {
            name += "- Dead";
        }
        int getMod(int r) {
            if ((r == 1)) {
                return -5;
            }
            else if (r >= 2 && r <= 3) {
                return -4;
            }
            else if (r >= 4 and r <= 5) {
                return -3;
            }
            else if (r >= 6 && r <= 7) {
                return -2;
            }
            else if (r >= 8 and r <= 9) {
                return -1;
            }
            else if (r >= 10 && r <= 11) {
                return 0;
            }
            else if (r >= 12 and r <= 13) {
                return 1;
            }
            else if (r >= 14 && r <= 15) {
                return 2;
            }
            else if (r >= 16 and r <= 17) {
                return 3;
            }
            else if (r >= 18 && r <= 19) {
                return 4;
            }
            else if (r >= 20) {
                return 5;
            }
            return 0;
        }

        int strengthRoll() {
            return ((rand() % 19) + 1) + getMod(strength);
        }

        int dexterityRoll() {
             return (rand() % 19 + 1) + getMod(dexterity);
        }

        int constitutionRoll() {
             return (rand() % 19 + 1) + getMod(constitution);
        }

        int intelligenceRoll() {
             return (rand() % 19 + 1) + getMod(intelligence);
        }

        int wisdomRoll() {
             return (rand() % 19 + 1) + getMod(wisdom);
        }

        int charismaRoll() {
             return (rand() % 19 + 1) + getMod(charisma);
        }
        
        Enemy(int h, int s, int d, int c, int w, int i, int ch, Weapon weap, Armor arm, string n, int st, int mR) {
            health = h;
            currentHealth = h;
            strength = s;
            dexterity = d;
            constitution = c;
            wisdom = w;
            intelligence = i;
            charisma = ch;
            enemyWeapon = weap;
            enemyArmor  = arm;
            name = n;
            stun = st;
            magicResistance = mR;
        }

};

class Goblin: public Enemy {
    public:
        Goblin() {name = "Goblin"; health = 7; currentHealth = 7; enemyWeapon = Weapon(1, 4, false, "Claw"); enemyArmor = Armor(0, "none"); stun = 0; magicResistance = 0;
        strength = 11;
        wisdom = 4;
        dexterity = 16;
        constitution = 8;
        charisma = 2;
        intelligence = 4;}
        Goblin(int n) {
            name = "Goblin"; health = 7; currentHealth = 7; enemyWeapon = Weapon(1, 4, false, "Claw"); enemyArmor = Armor(0, "none"); stun = 0; magicResistance = 0;
        }
        string getName() {return Enemy::getName();}

};

class BugBear: public Enemy {
    public:
        BugBear() {name = "Bug Bear"; health = 20; currentHealth = 20; 
        strength = 22;
        wisdom = 4;
        dexterity = 10;
        constitution = 19;
        charisma = 2;
        intelligence = 4;
        enemyWeapon = Weapon(1, 12, false, "Giant Spiked Club"); enemyArmor = Armor(16, "Thick Hide"); stun = 0; magicResistance = 0;}
        string getName() { return Enemy::getName();
        }
};


Fighter createFighter() {
    cout << "What is your name? ";
    string in;
    cin >> in;
    int totalPoints = 0;
    int arr[5];
    int smallest = 1;
    for (int i = 0; i < 6; i++) {
        for (int i = 0; i < 5; i++) {
            arr[i] = (rand() % 5 + 1);
            totalPoints += arr[i];
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
            
        }
        totalPoints -= smallest;
    }

    cout << "You have " << totalPoints << "\n";

    cout << "You can allocate your points where you wish, however each of the 6 attributes must be no larger than 20 and no smaller than one\n";
    int input;
    cout << "Would you like to be a ranged character? Please enter 0 for no and 1 for yes: ";
    int r;
    cin >> r;
    if (r) {
        Fighter *p1 = new Fighter(true);
    }
    else {
        Fighter *p1 = new Fighter(false);
    }

    Fighter *p1 = new Fighter(r);
    p1->setName(in);
    cout << "What would you like your strength rating to be?\n";
    
    cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setStrength(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:\n";
            cin >> input;
            p1->setStrength(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }

    cout << "What would you like your dexterity rating to be?\n";
    cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setDexterity(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:\n";
            cin >> input;
            p1->setDexterity(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }

        cout << "What would you like your constitution rating to be?\n";
        cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setConstitution(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:\n";
            cin >> input;
            p1->setConstitution(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        cout << "What would you like your charisma rating to be?\n";
        cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setCharisma(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:\n";
            cin >> input;
            p1->setCharisma(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        cout << "What would you like your intelligence rating to be?\n";
        cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setIntelligence(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:\n";
            cin >> input;
            p1->setIntelligence(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        cout << "What would you like your wisdom rating to be?\n";
    cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setWisdom(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:\n";
            cin >> input;
            p1->setWisdom(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
    return *p1;
}

Wizard createWizard() {
    cout << "What is your name? ";
    string in;
    cin >> in;
    int totalPoints = 0;
    int arr[5];
    int smallest = 1;
    for (int i = 0; i < 6; i++) {
        for (int i = 0; i < 5; i++) {
            arr[i] = ((rand() % 5) + 1);
            totalPoints += arr[i];
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
            
        }
        totalPoints -= smallest;
    }

    cout << "You have " << totalPoints << "\n";

    cout << "You can allocate your points where you wish, however each of the 6 attributes must be no larger than 20 and no smaller than one\n";
    int input;
    Wizard *p1 = new Wizard();
    p1->setName(in);
    cout << "What would you like your strength rating to be?\n";
    
    cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setStrength(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:";
            cin >> input;
            p1->setStrength(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }

    cout << "What would you like your dexterity rating to be?\n";
    cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setDexterity(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:";
            cin >> input;
            p1->setDexterity(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }

        cout << "What would you like your constitution rating to be?\n";
        cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setConstitution(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:";
            cin >> input;
            p1->setConstitution(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        cout << "What would you like your charisma rating to be?\n";
    cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setCharisma(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:";
            cin >> input;
            p1->setCharisma(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        cout << "What would you like your intelligence rating to be?\n";
    cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setIntelligence(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:";
            cin >> input;
            p1->setIntelligence(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        cout << "What would you like your wisdom rating to be?\n";
    cin >> input;
         
        if (input >= 1 && input <= 20) {
            p1->setWisdom(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
        else {
            cout << "You must enter a number between 1 and 20, try again:";
            cin >> input;
            p1->setWisdom(input);
            totalPoints -= input;
            cout << "You have " << totalPoints << " left\n";
        }
    return *p1;
}

int outputEnemies(Enemy *opp[], int n, int enemiesAlive[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (enemiesAlive[i] == 1) {
            cout << (i + 1) << ". " << opp[i]->getName() << "\n";
            count++;
        }
    }

    return count;
}

int playerFighterTurn(Fighter p, int n, Enemy *opp[], int enemiesAlive[], int numEn) {
    if (p.getStun() > 0) {
        p.decStun();
    }

    if (p.getStun() <= 0) {
        int input = 0;
        cout << "Which enemy would you like to attack?\n";

        outputEnemies(opp, n, enemiesAlive);

        int target = 0;
        cin >> target;
        target--;

        cout << "Which weapon would you like to use?\n";
        cout << "1. "; 
        p.getWeapon().toString();
        cin >> input;

        int roll = 0;
        if (p.getWeapon().isRanged) {
            roll = p.dexterityRoll();
        }

        else {
            roll = p.strengthRoll();
        }

        if (roll <= 1) { // not nat 1 just 1 after mod
            if (!(p.getWeapon().isRanged)) {

                if (((rand() % 100) % 2) == 0) {
                    cout << "Critical fail, you hit yourself in the foot, you take 1 damage\n";
                    p.setDamage(1);
                }

                else {
                    cout << "Critical fail, you have missed and your axe is stuck in the ground, your next turn will be used to pick it up\n";
                    p.setStun(1);
                }
            }

            else  {
                cout << "Critical fail, you shot yourself in the foot, you take 1 damage\n";
                p.setDamage(1);
            }

        }
        bool hit = opp[target]->pierce(roll);
        if (hit) {
            int damage = p.getWeapon().getDamage();
            opp[target]->hit(damage);
            cout << "You hit " << opp[target]->getName() << " and did " << damage << " damage\n";
            if ((opp[target]->getCurrentHealth() <= 0) && (enemiesAlive[target] == 1)) {
                cout << "It was a fatal wound\n";
                enemiesAlive[target] = 0;
                numEn--;
            }
        }

        else {
            cout << "Your attack did not pierce " << opp[target]->getName() << "'s armor\n";
        }

    }

    return numEn;

}


int playerWizardTurn(Wizard p, int n, Enemy *opp[], int enemiesAlive[], int numEn) {
    int spellNumber = 0;
    if (p.getStun() > 0) {
            p.decStun();
        }

    if (p.getStun() <= 0) {
        int input = 0;
        cout << "Which enemy would you like to attack?\n";

        numEn = outputEnemies(opp, n, enemiesAlive);

        int target = 0;
        cin >> target;
        target--;

        cout << "Which spell would you like to use?\n";
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". ";
            p.spellBook[i]->toString();
            cout << endl;
        }
        cin >> spellNumber;
        spellNumber--;

        int roll = p.wisdomRoll();
        cout << "Your wisdom check is " << roll << "\n";

        if (roll <= 1) { // not nat 1 just 1 after mod
            if (p.spellBook[spellNumber]->numDamageDie > 0) {
                cout << "Critical fail, your fireball exploded in your face, even worse your eyebrows are gone! You take 1 damage\n";
                p.setDamage(1);
            }
            else if (p.spellBook[spellNumber]->numHealDie > 0) {
                cout << "Critical fail, you miss and heal the enemy on accident\n";
                int totalHeal = 0;
                for(int i = 0; i < p.spellBook[spellNumber]->numHealDie; i++) {
                    totalHeal += ((rand() % p.spellBook[spellNumber]->healDie) + 1);
                }
                int index = rand() % n;
                opp[index]->heal(totalHeal);
            }

            else {
                cout << "Critical fail, you stun yourself 1 round\n";
                p.setStun(1);
            }

        }
        else  {
            if (p.spellBook[spellNumber]->numDamageDie > 0) {
                cout << "weapon does damage\n";
                bool hit = opp[target]->spellLand(roll);
                if (hit) {
                    int damage = p.spellBook[spellNumber]->getDamage();
                    opp[target]->hit(damage);
                    cout << p.spellBook[spellNumber]->getName() << " did " << damage << " damage\n";
                    if ((opp[target]->getCurrentHealth() <= 0 )&& (enemiesAlive[target] == 1)) {
                        cout << opp[target]->getName() << " has been incinerated\n";
                        enemiesAlive[target] = 0;
                        numEn--;
                    }
                }
                else {
                    cout << "you did not hit\n";
                }
            }

            else if (p.spellBook[spellNumber]->numHealDie > 0) {
                if (roll > 0) {
                    int heal = p.spellBook[spellNumber]->getHeal();
                    p.heal(heal);
                    cout << "You have been healed " << heal << " hp\n";
                }

            }

            else if (p.spellBook[spellNumber]->numTurnStunned > 0) {
                int num = p.spellBook[spellNumber]->numTurnStunned;
                opp[target]->setStun(num);
                cout << opp[target]->getName() << " has been stunned for " << num << " rounds\n"; 
            }

            else {
                cout << "Your attack did not hit\n";
            }
        }
    }
    return numEn;
}



void enemyTurn(Enemy *en, Fighter* p1) {
    if (en->getStun() > 0) {
        en->decStun();
    }
    else {
        int roll = en->strengthRoll();
        if (p1->pierce(roll)) {
            int damage = en->getDamage();
            p1->setDamage(damage);
            cout << en->getName() << " has hit you with " << en->getWeapon().getName() << " and dealt " << damage << " damage!\n";
            cout << "Your health is now at: " << p1->getCurrentHealth() << "\n";
        }
        else {
            cout << en->getName() << "'s attack did not pierce your armor\n";
        }

    }
}

void enemyTurn(Enemy *en, Wizard* p1) {
    if (en->getStun()) {
        en->decStun();
    }
    else {
        int roll = en->strengthRoll();
        if (p1->pierce(roll)) {
            int damage = en->getDamage();
            p1->setDamage(damage);
            cout << en->getName() << " has hit you with " << en->getWeapon().getName() << " and dealt " << damage << " damage!\n";
            cout << "Your health is now at: " << p1->getCurrentHealth() << "\n";
        }
    }
}

void combat(Fighter* p1, int n, Enemy *opp[]) {
    int numEnemiesAlive = n;
    int aliveEnemies[n];
    for (int i = 0; i < n; i++) {
        aliveEnemies[i] = 1;
    }
    while (p1->getCurrentHealth() > 0) {
        numEnemiesAlive = playerFighterTurn(*p1, n, opp, aliveEnemies, numEnemiesAlive);
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                if ((opp[i]->getCurrentHealth() <= 0)) {
                }
                else {
                    enemyTurn(opp[i], p1);
                }
            }
        }
        if (numEnemiesAlive <= 0) {
            cout << "You defeated all the enemies!\n";
            return;
        }
    }
    cout << "You died, try again\n";
    return;
}

void combat(Wizard* p1, int n, Enemy *opp[]) {
    int numEnemiesAlive = n;
    int aliveEnemies[n];
    for (int i = 0; i < n; i++) {
        aliveEnemies[i] = 1;
    }
    while (p1->getCurrentHealth() > 0) {
        numEnemiesAlive = playerWizardTurn(*p1, n, opp, aliveEnemies, numEnemiesAlive);
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                if ((opp[i]->getCurrentHealth() <= 0)) {
                }
                else {
                    enemyTurn(opp[i], p1);
                }
            }
        }
        if (numEnemiesAlive <= 0) {
            cout << "You defeated all the enemies!\n";
            p1->setCurrentHealth(p1->getMaxHealth());
            return;
        }
    }
    cout << "You died, try again\n";
    return;
}

void adventure(Wizard p1) {
    int choice = 0;
    Wizard* pPtr = &p1;
    cout << "\n\n\n";

    cout << p1.getName() << " you have woken up and found yourself in a dark cave, to your right you see a path that seems to lead to some sort of "
    << "light source, on your left you see a path that heads into darkness\n";
    Sleep(2000);
    cout << "Which path would you like to take? 1 for right and 2 for left\n";
    cin >> choice;

    if (choice == 1) {
        cout << "You see a group of 3 goblins around a fire they seem to have a dwarf tied up and are getting ready feast\n\n";
        Sleep(2000);
        cout << "What will you do?\n";
        Sleep(2000);
        cout << "1. Try to sneak away unnoticed and go down other path\n";
        cout << "2. Save the dwarf\n";
        cin >> choice;
            if (((p1.dexterityRoll() > 12) && (choice == 1))) {
                cout << "You managed to sneak away unnoticed.\n";
                cout << "You find yourself at the same spot you were in last time.\n";
                adventure(p1);
                return;
            }

            else {
                if (choice == 1) {
                    cout << "You tripped on a rock and disturbed the goblins, now you must fight for your life!\n";
                    Sleep(3000);
                    p1.setStun(1);
                }
                
                Enemy *en[3];
                en[0] = new Goblin();
                en[1] = new Goblin();
                en[2] = new Goblin();

                combat(pPtr, 3, en);
                if (p1.getCurrentHealth() <= 0) {
                    return;
                }
                cout << "Dwarf - \"Oi! Could you give me a hand here?\"";
                Sleep(2000);
                cout << "Would you like to\n 1. Untie the dwarf\n2. Leave him and head back the way you came.\n";
                cin >> choice;
                if (choice == 1) {
                    cout << "Thanks for the help, I had myself in a wee pinch.\nWhat do you call yourself?\n";
                    cout << p1.getName();
                    cout << "\nPleasure to meet you " << p1.getName() << "\nGloin, at your service.\n";
                    Sleep(2000);
                    cout << "Gloin: \"What do you say we get out of here?\nThere are more evil things in these caves than those goblins, more ancient things\".\n";
                    Sleep(4000);
                    cout << "Will you\n1. Follow Gloin\n2. Go back the way you came.\n";
                    cin >> choice;
                    if (choice == 1) {
                        cout << "Gloin: Alright let's head out.\n";
                        Sleep(2000);
                        cout << "He leads you back the way you came and heads down the left path.\n";
                        Sleep(4000);
                        cout << "Which leads to two more paths, the left one has a positive incline\nThe right one heads generally downward and you see a faded flicker of torches\n";
                        Sleep(4000);
                        cout << "\"Let's head down friend\" says Gloin as he marches down the right path\n";
                        Sleep(4000);
                        cout << "Gloin: \"Trust me I know my way around here, us dwarves live in mountains.\"\n";
                        Sleep(4000);
                        cout << "Eventually you reach a wide chasm, it descends into darkness farther than the eye can see.\n";
                        cout << "You find two bridges, the first is a white gentle arch, no wider than 18 inches.\nIt appears quite sturdy but has no guard rail.\n The other is an old creaky wooden bridge that appears to have seen better days but it does have a guard rail.\n";
                        Sleep(4000);
                        cout << "Gloin: \"I hate this accursed bridge but the old creaky one couldn't hold my boot.\"\nHe mumbles as he tight-rope walks down the narrown sturdy bridge\n";
                        Sleep(4000);
                        cout << "Which bridge would you like to take?\n";
                        cout << "1. Follow Gloin\n2. Try the old creaky wooden bridge\n";
                        cin >> choice;
                        if (choice == 2) {
                            cout << "As you test the bridge gingerly you feel it almost snap\nYou realize that Gloin was right and it could not support anyone.\n You must follow him.\n";

                        }
                        if (2 == 2) {
                            if (p1.dexterityRoll() > 10) {
                                cout << "You manage to get across the bridge without falling\n";
                                Sleep(5000);
                                cout << "Gloin: \"Well here we are, the exit.\"\n";
                                Sleep(5000);
                                cout << "You stare blankly at the solid stone wall, wondering how it is considered an exit.\n";
                                Sleep(5000);
                                cout << "Gloin: \"You see son this is an elvish door, let me find it\"\n";
                                Sleep(2000);
                                cout << "He feels around the wall for several minutes until all of a sudden a shining outline of a door appears\n";
                                Sleep(2000);
                                cout << "Gloin: \"Alright, lets see here, I am trying to remember the password...\"\n";
                                Sleep(5000);
                                cout << "He tries several foreign sounding phrases, but nothing works\n";
                                Sleep(4500);
                                cout << "Gloin: \"Hm, you wouldn't happen to know any elvish would you?\"\n";
                                Sleep(3000);
                                cout << "You recall something deep in your thoughts\nThe first thing you have remembered since your name\nYou start to chant in a language you didn't know you even spoke.\n";
                                Sleep(9000);
                                cout << "Ammon edhellen, edro hi ammen!\nFennas nogothrim, lasto beth lammen!\n";
                                Sleep(5000);
                                cout << "Suddenly the gate swings open\n";
                                Sleep(5000);
                                cout << "You find yourself in a valley at the base of a great mountain\nYou see a river in the northwest direction, on your right.\n";
                                Sleep(6000);
                                cout << "Gloin: \"Alright let's be very quiet, it's best to go unnoticed in these parts\"\n";
                                Sleep(3000);
                                cout << "Unfortunately the first step Gloin makes is on a particularly loud twig.\n";
                                Sleep(2500);
                                cout << "Gloin: \"Oh no, that can't be good.\"\n";
                                Sleep(4000);
                                cout << "In the distance you can already hear footsteps coming around the left side of the mountain at a rapid pace.\n";
                                Sleep(4000);
                                cout << "Gloin: \"Well, they found us. I s'pose the best thing we can do is stand our ground.\"\n";
                                Sleep(4000);
                                cout << "Seconds later a pack of large evil looking wolves rounds the bend\n";
                                Sleep(4000);
                                cout << "Mounted on the largest one you see a great monstrous orc, hideous in appearance.\nHe stands perhaps 8 feet tall wielding a fearsome blade.\n";
                                Sleep(4500);
                                cout << "Gloin: \"I'll take him, you deal with the others.\"\n";
                                Sleep(3400);
                                cout << "The wargs are sprinting toward you, you must fight for your life!\n";
                                Enemy* wargs[2];
                                Weapon enemyWeapon = Weapon(1, 8, false, "Bite"); Armor enemyArmor = Armor(4, "Hide");
                                
                                wargs[0] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
                                wargs[1] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
                                //wargs[2] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);

                                combat(pPtr,2,wargs);
                                if (p1.getCurrentHealth() <= 0) {
                                    return;
                                }
                                if (p1.getCurrentHealth() > 0) {
                                    cout << "Meanwhile Gloin has slain the largest warg and has been holding off the lead orc.\n";
                                    cout << "The battle has been fierce you see Gloin blocking his foe's attacks with his own axe while trying to occasionally get in a swing in.\nAs you watch the battle you see the orc break gloin's axe in half, he falls unarmed at the mercy of the monster.\n";
                                    Sleep(2000);
                                    cout << "What will you do?\n1. Backup Gloin\n2. Flee\n";
                                    cin >> choice;
                                    if (choice == 1) {
                                        enemyWeapon = Weapon(1, 12, false, "Great Broadsword"); enemyArmor = Armor(16, "Steel-crafted war armor");
                                        wargs[0] = new Enemy(18, 18, 14, 15, 10, 4, 4, enemyWeapon, enemyArmor, "Orc leader", 0, 0);
                                        combat(pPtr, 1, wargs);
                                        if (p1.getCurrentHealth() <= 0) {
                                            return;
                                        }
                                        cout << "As the life leaves the face of the great orc chief your gaze turns to gloin who is laying down\nExhausted but appears to be without serious injury.\n";
                                        cout << "Gloin: \"Well I'll be darned, you are made of tougher stuff than I thought kid.\nI owe you my life after this one\n";
                                        cout << "I know of a town not too far from here, let's make our way to a nice soft bed, on me!\"";
                                        cout << "You arrive at the inn, and fall asleep as soon as you hit the mattress.\n";
                                        cout << "What happens in the morning? Well that is for another time...\n";
                                        return;
                                    
                                    }
                                    else {
                                        cout << "As you run, mile after mile you find no civilization\nOther than a few villages that appear to have been burned to the ground.\n";
                                        Sleep(3000);
                                        cout << "As dusk approaches you realize you must set up camp for the night.\n";
                                        Sleep(3000);
                                        cout << "After more than a days worth of adventure you fall into a deep slumber.\n";
                                        Sleep(3000);
                                        cout << "What happens in the morning? Well that is for another time...\n";
                                        return;
                                    }
                                
                                }

                            }
                            else {
                                cout << "As you carefully walk the bridge you take a wrong step, you trip slightly. Carefully you try to rebalance but it is too late you already heading head over heels down into the abyss.\n";
                                cout << "The last thing you hear is Gloin yelling as you fall to your demise\nYou have died, try again\n";
                                return;
                            }
                        }
                    }
                    else {
                        cout << "You go back the way you came and find yourself at the same spot.\n";
                        adventure(p1);
                        return;
                    }
                }
                else {
                    cout << "You find yourself back at the same spot you began.\n";
                    adventure(p1);
                    return;
                }
            }
    }

    else {
        cout << "After stumbling through the darkness for an hour or two you come to a fork in the road.\n";
        cout << "One path goes to the left and generally up, the other to the right and downward.\n";
        cout << "Which path will you take?\n1. The right path.\n2. The left path.\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Eventually you reach a wide chasm, it descends into darkness farther than the eye can see.\n";
            Sleep(2000);
            cout << "You find two bridges, the first is a white gentle arch, no wider than 18 inches\nIt appears quite sturdy but has no guard rail\nThe other is an old creaky wooden bridge that appears to have seen better days but it does have a guard rail.\n";
            Sleep(4000);
            cout << "Which bridge would you like to take?\n";
            cout << "1. The narrow, sturdy one\n2. The old creaky wooden bridge\n";
            cin >> choice;
            if (choice == 1) {
                if (p1.dexterityRoll() > 10) {
                    cout << "You manage to get across the bridge without falling\n";
                    Sleep(2000);
                    cout << "On the other side you see an opening in the cave and go out it.\n";
                    Sleep(200);
                    cout << "Only a few yards from the exit you see a stout dwarf being surrounded by a small pack of wargs, monstrous orc-bred wolves. Led by a large orc.\n";
                    cout << "The beasts smell you instantly and dart towards you ravenously.\nYou must fight for your life!\n";
                    Enemy* wargs[2];
                    Weapon enemyWeapon = Weapon(1, 8, false, "Bite"); Armor enemyArmor = Armor(4, "Hide");
                                
                    wargs[0] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
                    wargs[1] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
                    //wargs[2] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);

                    combat(pPtr,2,wargs);
                    if (p1.getCurrentHealth() <= 0) {
                        return;
                    }
                    cout << "Meanwhile the dwarf has slain the greatest warg and has been holding off the lead orc.\n";
                    cout << "The battle has been fierce, you see the dwarf blocking his foe's attacks with his own axe while trying to occasionally get in a swing in.\nAs you watch the battle you see the orc break gloin's axe in half, he falls unarmed at the mercy of the monster.\n";
                    Sleep(2000);
                    cout << "What will you do?\n1. Backup the dwarf\n2. Flee\n";
                    cin >> choice;
                    if (choice == 1) {
                        enemyWeapon = Weapon(1, 12, false, "Great Broadsword"); enemyArmor = Armor(16, "Steel-crafted war armor");
                        wargs[0] = new Enemy(18, 18, 14, 15, 10, 4, 4, enemyWeapon, enemyArmor, "Orc leader", 0, 0);
                        combat(pPtr, 1, wargs);
                        if (p1.getCurrentHealth() <= 0) {
                            return;
                        }
                        cout << "Dwarf: \"Thanks for the help, I had myself in a wee pinch.\nWhat do you call yourself?\"\n";
                        cout << p1.getName();
                        cout << "\nPleasure to meet you " << p1.getName() << "\nGloin, at your service.\n";
                        Sleep(2000);
                        cout << "Gloin: \"I know of a town not too far from here, let's make our way to a nice soft bed, on me!\"\n";
                        Sleep(3000);
                        cout << "You follow your new ally and arrive at the inn, and fall asleep as soon as you hit the mattress.\n";
                        Sleep(3000);
                        cout << "What happens in the morning? Well that is for another time...\n";
                        return;
                                    
                    }
                    else {
                        cout << "As you run, mile after mile you find no civilization other than a few villages that appear to have been burned to the ground.\n";
                        Sleep(2000);
                        cout << "As dusk approaches you realize you must set up camp for the night.\n";
                        Sleep(2000);
                        cout << "After more than a days worth of adventure you fall into a deep slumber.\n";
                        Sleep(2000);
                        cout << "What happens in the morning? Well that is for another time...\n";
                        return;
                    }
                }
                else {
                    cout << "As you carefully walk the bridge you take a wrong step, you trip slightly. Carefully you try to rebalance but it is too late you already heading head over heels down into the abyss.\n";
                    cout << "You have died, try again\n";
                    return;
                }
            }
            else {
                cout << "As you gingerly walk across the old creaky bridge, about halfway through a plank falls underneath you.\n";
                Sleep(1500);
                cout << "And another! And another!\n";
                Sleep(2000);
                cout << "Both your legs fall through and you twist the bridge upside down.\n";
                cout << "You fall to your doom, screaming the whole way.\n";
                cout << "You have died, try again.\n";
                return;
            }
        }
        else {
            cout << "After just a few minutes you stumble upon a sleeping troll.\n";
            Sleep(2000);
            cout << "It appears to be in a deep slumber.\n";
            cout << "What will you do?\n1. Go back the way you came.\n2. Attack the troll in it's sleep.\n";
            cin >> choice;
            if (choice == 1) {
                cout << "You find yourself in the same place as before.\n";
                adventure(p1);
                return;
            }
            else {
                Enemy *troll[1];
                troll[0] = new BugBear();
                troll[0]->setName("Troll");
                combat(pPtr, 1, troll);
                if (p1.getCurrentHealth() <= 0) {
                    return;
                }
                // beat troll
                cout << "As the troll lets out one last roar. The blood in it's face comes out it's mouth and it is no more.\n";
                Sleep(1000);
                cout << "You realize that other than few skeletons there is not much else of interest. You head back the way you came and find yourself at the same spot.\n";
                adventure(p1);
                return;
            }
        }
    }
}

void adventure(Fighter p1) {
    int choice = 0;
    Fighter* pPtr = &p1;
    cout << "\n\n\n";

    cout << p1.getName() << " you have woken up and found yourself in a dark cave, to your right you see a path that seems to lead to some sort of "
    << "light source, on your left you see a path that heads into darkness\n";
    Sleep(2000);
    cout << "Which path would you like to take? 1 for right and 2 for left\n";
    cin >> choice;

    if (choice == 1) {
        cout << "You see a group of 3 goblins around a fire they seem to have a dwarf tied up and are getting ready feast.\n";
        Sleep(2000);
        cout << "What will you do?\n";
        Sleep(2000);
        cout << "1. Try to sneak away unnoticed and go down other path\n";
        cout << "2. Save the dwarf\n";
        cin >> choice;
            if (((p1.dexterityRoll() > 12) && (choice == 1))) {
                cout << "You managed to sneak away unnoticed.\n";
                cout << "You find yourself at the same spot you were in last time.\n";
                adventure(p1);
                return;
            }

            else {
                if (choice == 1) {
                    cout << "You tripped on a rock and disturbed the goblins, now you must fight for your life!\n";
                    Sleep(3000);
                    p1.setStun(1);
                }
                
                Enemy *en[3];
                en[0] = new Goblin();
                en[1] = new Goblin();
                en[2] = new Goblin();

                combat(pPtr, 3, en);
                if (p1.getCurrentHealth() <= 0) {
                    return;
                }
                cout << "Dwarf - \"Oi! Could you give me a hand here?\"\n";
                Sleep(2000);
                cout << "Would you like to\n 1. Untie the dwarf\n2. Leave him and head back the way you came.\n";
                cin >> choice;
                if (choice == 1) {
                    cout << "Thanks for the help, I had myself in a wee pinch.\n\nWhat do you call yourself?\n\n";
                    cout << p1.getName();
                    cout << "\nPleasure to meet you " << p1.getName() << "\nGloin, at your service.\n\n";
                    Sleep(2000);
                    cout << "Gloin: \"What do you say we get out of here?\n\nThere are more evil things in these caves than those goblins, more ancient things\".\n\n";
                    Sleep(4000);
                    cout << "Will you\n1. Follow Gloin\n2. Go back the way you came.\n";
                    cin >> choice;
                    if (choice == 1) {
                        cout << "Gloin: Alright let's head out.\n\n";
                        Sleep(2000);
                        cout << "He leads you back the way you came and heads down the left path.\n\n";
                        Sleep(4000);
                        cout << "Which leads to two more paths, the left one has a positive incline\nThe right one heads generally downward and you see a faded flicker of torches\n\n";
                        Sleep(4000);
                        cout << "\"Let's head down friend\" says Gloin as he marches down the right path\n";
                        Sleep(4000);
                        cout << "Gloin: \"Trust me I know my way around here, us dwarves live in mountains.\"\n\n";
                        Sleep(4000);
                        cout << "Eventually you reach a wide chasm, it descends into darkness farther than the eye can see.\n\n";
                        cout << "You find two bridges, the first is a white gentle arch, no wider than 18 inches\nit appears quite sturdy but has no guard rail\n The other is an old creaky wooden bridge that appears to have seen better days\nBut it does have a guard rail.\n\n";
                        Sleep(4000);
                        cout << "Gloin: \"I hate this accursed bridge but the old creaky one couldn't hold my boot.\"\nHe mumbles as he tight-rope walks down the narrown sturdy bridge\n\n";
                        Sleep(4000);
                        cout << "Which bridge would you like to take?\n";
                        cout << "1. Follow Gloin\n2. Try the old creaky wooden bridge\n";
                        cin >> choice;
                        if (choice == 2) {
                            cout << "As you test the brideg gingerly you feel it almost snap, you realize that Gloin was right and it could not support anyone.\nYou must follow him.\n\n";

                        }
                        if (2 == 2) {
                            if (p1.dexterityRoll() > 10) {
                                cout << "You manage to get across the bridge without falling\n\n";
                                Sleep(5000);
                                cout << "Gloin: \"Well here we are, the exit.\"\n";
                                Sleep(5000);
                                cout << "You stare blankly at the solid stone wall, wondering how it is considered an exit.\n";
                                Sleep(5000);
                                cout << "Gloin: \"You see son this is an elvish door, let me find it\"\n\n";
                                Sleep(2000);
                                cout << "He feels around the wall for several minutes until all of a sudden a shining outline of a door appears\n\n";
                                Sleep(2000);
                                cout << "Gloin: \"Alright, lets see here, I am trying to remember the password...\"\n";
                                Sleep(5000);
                                cout << "He tries several foreign sounding phrases, but nothing works\n";
                                Sleep(4500);
                                cout << "Gloin: \"Hm, you wouldn't happen to know any elvish would you?\"\n";
                                Sleep(3000);
                                cout << "You recall something deep in your thoughts\nThe first thing you have remembered since your name\nYou start to chant in a language you didn't know you even spoke.\n";
                                Sleep(9000);
                                cout << "Ammon edhellen, edro hi ammen!\nFennas nogothrim, lasto beth lammen!\n";
                                Sleep(5000);
                                cout << "Suddenly the gate swings open\n\n";
                                Sleep(5000);
                                cout << "You find yourself in a valley at the base of a great mountain\nYou see a river in the northwest direction, on your right.\n";
                                Sleep(6000);
                                cout << "Gloin: \"Alright let's be very quiet, it's best to go unnoticed in these parts\"\n";
                                Sleep(3000);
                                cout << "Unfortunately the first step Gloin makes is on a particularly loud twig.\n";
                                Sleep(2500);
                                cout << "Gloin: \"Oh no, that can't be good.\"\n\n";
                                Sleep(4000);
                                cout << "In the distance you can already hear footsteps coming around the left side of the mountain at a rapid pace.\n";
                                Sleep(4000);
                                cout << "Gloin: \"Well, they found us. I s'pose the best thing we can do is stand our ground.\"\n";
                                Sleep(4000);
                                cout << "Seconds later a pack of large evil looking wolves rounds the bend\n\n";
                                Sleep(4000);
                                cout << "Mounted on the largest one you see a great monstrous orc, hideous in appearance.\nHe stands perhaps 8 feet tall wielding a fearsome blade.\n";
                                Sleep(4500);
                                cout << "Gloin: \"I'll take him, you deal with the others.\"\n";
                                Sleep(3400);
                                cout << "The wargs are sprinting toward you, you must fight for your life!\n";
                                Enemy* wargs[2];
                                Weapon enemyWeapon = Weapon(1, 8, false, "Bite"); Armor enemyArmor = Armor(4, "Hide");
                                
                                wargs[0] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
                                wargs[1] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
                                //wargs[2] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);

                                combat(pPtr,2,wargs);
                                if (p1.getCurrentHealth() < 0) {
                                    return;
                                }
                                if (p1.getCurrentHealth() > 0) {
                                    cout << "Meanwhile Gloin has been holding off the lead orc.\n\n";
                                    cout << "The battle has been fierce. Gloin has slain the great beast the orc was riding.\nGloin has been blocking his foe's attacks with his own axe\nwhile trying to occasionally get in a swing in.\nAs you watch the battle you see the orc break gloin's axe in half\nHe falls unarmed at the mercy of the monster.\n\n";
                                    Sleep(2000);
                                    cout << "What will you do?\n1. Backup Gloin\n2. Flee\n";
                                    cin >> choice;
                                    if (choice == 1) {
                                        enemyWeapon = Weapon(1, 12, false, "Great Broadsword"); enemyArmor = Armor(16, "Steel-crafted war armor");
                                        wargs[0] = new Enemy(18, 18, 14, 15, 10, 4, 4, enemyWeapon, enemyArmor, "Orc leader", 0, 0);
                                        combat(pPtr, 1, wargs);
                                        if (p1.getCurrentHealth() <= 0) {
                                            return;
                                        }
                                        cout << "As the life leaves the face of the great orc chief your gaze turns to gloin who is laying down\nExhausted but appears to be without serious injury.\n\n";
                                        cout << "Gloin: \"Well I'll be darned, you are made of tougher stuff than I thought kid.\nI owe you my life after this one\n";
                                        cout << "I know of a town not too far from here, let's make our way to a nice soft bed, on me!\"\n";
                                        cout << "You arrive at the inn, and fall asleep as soon as you hit the mattress.\n";
                                        cout << "What happens in the morning? Well that is for another time...\n";
                                        return;
                                    
                                    }
                                    else {
                                        cout << "As you run, mile after mile you find no civilization other than a few villages that appear to have been burned to the ground.\n";
                                        Sleep(3000);
                                        cout << "As dusk approaches you realize you must set up camp for the night.\n";
                                        Sleep(3000);
                                        cout << "After more than a days worth of adventure you fall into a deep slumber.\n";
                                        Sleep(3000);
                                        cout << "What happens in the morning? Well that is for another time...\n";
                                        return;
                                    }
                                
                                }

                            }
                            else {
                                cout << "As you carefully walk the bridge you take a wrong step, you trip slightly. Carefully you try to rebalance but it is too late you already heading head over heels down into the abyss.\n";
                                cout << "The last thing you hear is Gloin yelling as you fall to your demise\nYou have died, try again\n";
                                return;
                            }
                        }
                    }
                    else {
                        cout << "You go back the way you came and find yourself at the same spot.\n";
                        adventure(p1);
                        return;
                    }
                }
                else {
                    cout << "You find yourself back at the same spot you began.\n";
                    adventure(p1);
                    return;
                }
            }
    }

    else {
        cout << "After stumbling through the darkness for an hour or two you come to a fork in the road.\n";
        cout << "One path goes to the left and generally up, the other to the right and downward.\n";
        cout << "Which path will you take?\n1. The right path.\n2. The left path.\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Eventually you reach a wide chasm, it descends into darkness farther than the eye can see.\n";
            cout << "You find two bridges, the first is a white gentle arch, no wider than 18 inches\nIt appears quite sturdy but has no guard rail\n The other is an old creaky wooden bridge that appears to have seen better days but it does have a guard rail.\n";
            Sleep(4000);
            cout << "Which bridge would you like to take?\n";
            cout << "1. The narrow, sturdy one\n2. The old creaky wooden bridge\n";
            cin >> choice;
            if (choice == 1) {
                if (p1.dexterityRoll() > 10) {
                    cout << "You manage to get across the bridge without falling\n\n";
                    Sleep(2000);
                    cout << "On the other side you see an opening in the cave and go out it.\n";
                    Sleep(200);
                    cout << "Only a few yards from the exit you see a stout dwarf being surrounded by a small pack of wargs, monstrous orc-bred wolves. Led by a large orc.\n\n";
                    cout << "The beasts smell you instantly and dart towards you ravenously.\nYou must fight for your life!\n";
                    Enemy* wargs[2];
                    Weapon enemyWeapon = Weapon(1, 8, false, "Bite"); Armor enemyArmor = Armor(4, "Hide");
                                
                    wargs[0] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
                    wargs[1] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
                    //wargs[2] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);

                    combat(pPtr,2,wargs);
                    if (p1.getCurrentHealth() <= 0) {
                        return;
                    }

                    cout << "Meanwhile the dwarf has been holding off the lead orc.\n\n";
                    cout << "The battle has been fierce.\nThe dwarf has slain the largest warg the orc was riding and is blocking his foe's attacks with his own axe while trying to occasionally get in a swing in.\nAs you watch the battle you see the orc break gloin's axe in half, he falls unarmed at the mercy of the monster.\n";
                    Sleep(2000);
                    cout << "What will you do?\n1. Backup the dwarf\n2. Flee\n";
                    cin >> choice;
                    if (choice == 1) {
                        enemyWeapon = Weapon(1, 12, false, "Great Broadsword"); enemyArmor = Armor(16, "Steel-crafted war armor");
                        wargs[0] = new Enemy(18, 18, 14, 15, 10, 4, 4, enemyWeapon, enemyArmor, "Orc leader", 0, 0);
                        combat(pPtr, 1, wargs);
                        if (p1.getCurrentHealth() <= 0) {
                            return;
                        }
                        cout << "Dwarf: \"Thanks for the help, I had myself in a wee pinch.\nWhat do you call yourself?\"\n";
                        cout << p1.getName();
                        cout << "Pleasure to meet you " << p1.getName() << "Gloin, at your service.\n";
                        Sleep(2000);
                        cout << "Gloin: \"I know of a town not too far from here, let's make our way to a nice soft bed, on me!\"\n\n1";
                        cout << "You follow your new ally and arrive at the inn, and fall asleep as soon as you hit the mattress.\n";
                        cout << "What happens in the morning? Well that is for another time...\n";
                        return;
                                    
                    }
                    else {
                        cout << "As you run, mile after mile you find no civilization other than a few villages that appear to have been burned to the ground.\n";
                        Sleep(2000);
                        cout << "As dusk approaches you realize you must set up camp for the night.\n";
                        Sleep(2000);
                        cout << "After more than a days worth of adventure you fall into a deep slumber.\n";
                        Sleep(2000);
                        cout << "What happens in the morning? Well that is for another time...\n";
                        return;
                    }
                }
                else {
                    cout << "As you carefully walk the bridge you take a wrong step, you trip slightly. Carefully you try to rebalance but it is too late you already heading head over heels down into the abyss.\n";
                    cout << "You have died, try again\n";
                    return;
                }
            }
            else {
                cout << "As you gingerly walk across the old creaky bridge, about halfway through a plank falls underneath you.\n";
                Sleep(1500);
                cout << "And another! And another!\n";
                Sleep(2000);
                cout << "Both your legs fall through and you twist the bridge upside down.\n";
                cout << "You fall to your doom, screaming the whole way.\n";
                cout << "You have died, try again.\n";
                return;
            }
        }
        else {
            cout << "After just a few minutes you stumble upon a sleeping troll.\n";
            Sleep(2000);
            cout << "It appears to be in a deep slumber.\n";
            cout << "What will you do?\n1. Go back the way you came.\n2. Attack the troll in it's sleep.\n";
            cin >> choice;
            if (choice == 1) {
                cout << "You find yourself in the same place as before.\n";
                adventure(p1);
                return;
            }
            else {
                Enemy *troll[1];
                troll[0] = new BugBear();
                troll[0]->setName("Troll");
                combat(pPtr, 1, troll);
                if (p1.getCurrentHealth() <= 0) {
                    return;
                }
                // beat troll
                cout << "As the troll lets out one last roar. The blood in it's face comes out it's mouth and it is no more.\n";
                Sleep(1000);
                cout << "You realize that other than few skeletons there is not much else of interest. You head back the way you came and find yourself at the same spot.\n";
                adventure(p1);
                return;
            }
        }
    }

}

void dungeon(Fighter p1) {
    cout << "Welcome to dungeon mode.\nIn this mode you must go through rooms of enemies and defeat them all... or Perish!\nLevel 1: You enter a room with 3 goblins, you must fight for your life!";
        int choice = 0;
        int level = 1;
        Fighter* pPtr = &p1;
        Enemy* en1[3];
        en1[0] = new Goblin();
        en1[1] = new Goblin();
        en1[2] = new Goblin();
        combat(pPtr, 3, en1);
        if (p1.getCurrentHealth() <= 0) {
            return;
        }
        level = 2;
        cout << "You may have survived this first challenge, but be wary of the next one.\nThe next room has 2 ravenous wargs waiting for their next meal.\n";
        Enemy* wargs[2];
        Weapon enemyWeapon = Weapon(1, 8, false, "Bite"); Armor enemyArmor = Armor(4, "Hide");
                                
        wargs[0] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
        wargs[1] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);

        combat(pPtr,2,wargs);
        if (p1.getCurrentHealth() <= 0) {
            return;
        }
        level = 3;
        cout << "You have completed the second challenge, you may now rest and restore your health.\n";
        p1.setCurrentHealth(p1.getMaxHealth());
        Sleep(3000);
        cout << "The next challenge however will not prove so easy, you must now face an enraged bug bear, swinging his large club.\n";
        Enemy* bugBear[1];
        Weapon w = Weapon(1, 12, false, "Giant Spiked Club"); Armor a = Armor(16, "Thick Hide");
        bugBear[0] = new Enemy(20, 22, 8, 19, 4, 4, 2, w, a, "Bugbear", 0, 0);
        combat(pPtr, 1, bugBear);
        if (p1.getCurrentHealth() <= 0) {
            return;
        }
        cout << "Congratulations, you have fought valiantly, and for that you shall be rewarded.\n";
        cout << "You have been given two points to increase your stats.\nWhich category would you like to add them to?\n";
        cout << "1. Strength\n2. Dexterity\n3. Constitution\n4. Charisma\n5. Intelligence\n6. Wisdom\n";
        cin >> choice;
        if (choice == 1) {
            p1.setStrength(p1.getStrength() + 2);
        }
        else if (choice == 2) {
            p1.setDexterity(p1.getDexterity() + 2);
        }
        else if (choice == 3) {
            p1.setConstitution(p1.getConstitution() + 2);
        }
        else if (choice == 4) {
            p1.setCharisma(p1.getCharisma() + 2);
        }
        else if (choice == 5) {
            p1.setIntelligence(p1.getIntelligence() + 2);
        }
        else {
            p1.setWisdom(p1.getWisdom() + 2);
        }

        cout << "Now for level 4!\nYou must defend yourself from the great orc Zogstuf";
        enemyWeapon = Weapon(1, 12, false, "Great Broadsword"); enemyArmor = Armor(16, "Steel-crafted war armor");
        wargs[0] = new Enemy(18, 18, 14, 15, 10, 4, 4, enemyWeapon, enemyArmor, "Zogstuf", 0, 0);
        combat(pPtr, 1, wargs);
        if (p1.getCurrentHealth() <= 0) {
            return;
        }
        cout << "Well you may have won this time, perhaps next time you won't be so lucky, as a reward here is a better Axe.\n";
        cout << "You now have a double sided battle axe that does 2d6 damage.\n";
        Weapon axe = Weapon(2, 6, false, "Double-sided Battle-Axe");
        p1.setWeapon(axe);
        level = 4;

    return;
}

void dungeon(Wizard p1) {
        cout << "Welcome to dungeon mode.\nIn this mode you must go through rooms of enemies and defeat them all... or Perish!\nLevel 1: You enter a room with 3 goblins, you must fight for your life!";
        int choice = 0;
        int level = 1;
        Wizard* pPtr = &p1;
        Enemy* en1[3];
        en1[0] = new Goblin();
        en1[1] = new Goblin();
        en1[2] = new Goblin();
        combat(pPtr, 3, en1);
        if (p1.getCurrentHealth() <= 0) {
            return;
        }
        level = 2;
        cout << "You may have survived this first challenge, but be wary of the next one.\nThe next room has 2 ravenous wargs waiting for their next meal.\n";
        Enemy* wargs[2];
        Weapon enemyWeapon = Weapon(1, 8, false, "Bite"); Armor enemyArmor = Armor(4, "Hide");
                                
        wargs[0] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);
        wargs[1] = new Enemy(10, 16, 20, 12, 7, 4, 4, enemyWeapon, enemyArmor, "Warg", 0, 0);

        combat(pPtr,2,wargs);
        if (p1.getCurrentHealth() <= 0) {
            return;
        }
        cout << "You have completed the second challenge, your maximum health has now been increased by 2.\n";
        p1.setMaxHealth(p1.getMaxHealth() + 2);
        Sleep(3000);
        cout << "The next challenge however will not prove so easy, you must now face an enraged bug bear, swinging his large club.\n";
        Enemy* bugBear[1];
        Weapon w = Weapon(1, 12, false, "Giant Spiked Club"); Armor a = Armor(16, "Thick Hide");
        bugBear[0] = new Enemy(20, 22, 8, 19, 4, 4, 2, w, a, "Bugbear", 0, 0);
        combat(pPtr, 1, bugBear);
        if (p1.getCurrentHealth() <= 0) {
            return;
        }
        cout << "Congratulations, you have fought valiantly, and for that you shall be rewarded.\n";
        cout << "You have been given two points to increase your stats.\nWhich category would you like to add them to?\n";
        cout << "1. Strength\n2. Dexterity\n3. Constitution\n4. Charisma\n5. Intelligence\n6. Wisdom\n";
        cin >> choice;
        if (choice == 1) {
            p1.setStrength(p1.getStrength() + 2);
        }
        else if (choice == 2) {
            p1.setDexterity(p1.getDexterity() + 2);
        }
        else if (choice == 3) {
            p1.setConstitution(p1.getConstitution() + 2);
        }
        else if (choice == 4) {
            p1.setCharisma(p1.getCharisma() + 2);
        }
        else if (choice == 5) {
            p1.setIntelligence(p1.getIntelligence() + 2);
        }
        else {
            p1.setWisdom(p1.getWisdom() + 2);
        }

        cout << "Now for level 4!\nYou must defend yourself from the great orc Zogstuf";
        enemyWeapon = Weapon(1, 12, false, "Great Broadsword"); enemyArmor = Armor(16, "Steel-crafted war armor");
        wargs[0] = new Enemy(18, 18, 14, 15, 10, 4, 4, enemyWeapon, enemyArmor, "Zogstuf", 0, 0);
        combat(pPtr, 1, wargs);
        if (p1.getCurrentHealth() <= 0) {
            return;
        }
        cout << "Well you may have won this time, perhaps next time you won't be so lucky, as a reward here is some armor to protect you in battle.\n";
        cout << "You now have light chain mail armor with a rating of 12.\n";
        Armor mail = Armor(12, "Chain-mail");
        p1.setArmor(mail);

    return;
}


int main() {

    srand (time(NULL));
    int input;
    cout << "Would you like to be a wizard or fighter? Enter 0 for fighter and 1 for wizard: ";
    cin >> input;
    Wizard pWiz;
    Fighter pFight;

    if (input == 1) {
        pWiz = createWizard();
        pWiz.toString();
        cout << "Would you like to play:\n1. Adventure\\Story mode.\n2. Fighter\\Dungeon mode\n";
        cin >> input;
        if (input == 1) {
            adventure(pWiz);
        }
        else {
            dungeon(pWiz);
        }
        Sleep(4000);
        cout << "\n\n\n Thank you for playing the game!\nMore to be added soon!\n";
        Sleep(3000);
        cout << "Created by Benjamin Jones, ASU student.\n";
    }

    else {
        pFight = createFighter(); // make pointer
        pFight.toString();
        cout << "Would you like to play:\n1. Adventure\\Story mode.\n2. Fighter\\Dungeon mode\n";
        cin >> input;
        if (input == 1) {
            adventure(pFight);
        }
        else {
            dungeon(pFight);
        }
        Sleep(4000);
        cout << "\n\n\n Thank you for playing the game!\nMore to be added soon!\n";
        Sleep(3000);
        cout << "\nCreated by Benjamin Jones, ASU student.\n";
    }
    
    return 0;
}
