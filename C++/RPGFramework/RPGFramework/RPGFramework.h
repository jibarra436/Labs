// character class
class Character
{
    // private variables
    std::string name;
    int _hp;
    int _maxhp;
    int _atk;
    int _def;
    int _lvl;
    int _xp = 0;
    int _xpReward;

protected:
    // protected methods
    virtual void SetMaxHP(int hp);
    virtual void SetAtk(int atk);
    virtual void SetDef(int def);
    virtual void SetLevel(int lvl);

public:
    // public methods and constructors
    Character() { this->name = "Dummy"; }
    Character(std::string Name) { this->name = Name; }
    virtual int GetHP() const;
    virtual int GetMaxHP() const;
    virtual int GetAtk() const;
    virtual int GetDef() const;
    virtual int GetLevel() const;
    virtual int GetXPReward() const;
    virtual bool IsDead() const;
    virtual void Victory();
    void Attack(Character& other);
    void Load(int hp, int atk, int def, int lvl);
    void Load(int difficulty, int playerLevel);

    // SetHP in public for use in fightAgain() function (RPGFramework.cpp)
    virtual void SetHP(int hp);
};

// getter methods (hp, atk, def, lvl, xpreward)
int Character::GetHP() const { return this->_hp; }

int Character::GetMaxHP() const { return this->_maxhp; }

int Character::GetAtk() const { return this->_atk; }

int Character::GetDef() const { return this->_def; }

int Character::GetLevel() const { return this->_lvl; }

int Character::GetXPReward() const { return this->_xpReward; }

// setter methods (hp, atk, def, lvl)
void Character::SetHP(int hp) { this->_hp = hp; }

void Character::SetMaxHP(int hp) { this->_maxhp = hp; }

void Character::SetAtk(int atk) { this->_atk = atk; }

void Character::SetDef(int def) { this->_def = def; }

void Character::SetLevel(int lvl) { this->_lvl = lvl;  }

// check if character is dead (hp <= 0)
bool Character::IsDead() const
{
    if (this->_hp <= 0) {
        return true;
    }
    else return false;
}

// handle victory
void Character::Victory()
{
    // if the current xp is < 100 show how much is left.  otherwise level up the character and carry remaining xp to next level.
    if (this->_xp < 100)
    {
        std::cout << this->name << " is victorious!\t" << "XP to next level: " << this->_xp << "/100" << std::endl;
    }
    else
    {
        // level up the character by 1
        this->SetLevel(this->_lvl + 1);
        // remove 100 from current xp, carrying over the remainder
        this->_xp -= 100;
        std::cout << this->name << " is victorious!\t" << "Leveled up to level " << this->_lvl << "\tXP to next level: " << this->_xp << "/100" << std::endl;
    }
}

// attack method
void Character::Attack(Character& other)
{
    // prevent dead characters from attacking
    if (this->_hp <= 0) { return;  }

    // base damage is aggressor atk - target def
    int damage = this->_atk - other.GetDef();

    // add random d10 roll to damage
    damage +=  rand() % 10 + 1;

    // if the damage is enough to get through target's defense
    if (damage > 0)
    {
        other.SetHP(other.GetHP() - damage);
        std::cout << this->name << " hit " << other.name << " for " << damage << " damage!" << std::endl;
    }
    else std::cout << this->name << "'s attack on " << other.name << " was ineffective!" << std::endl;

    // update the user with new hit point values
    std::cout << this->name << "'s HP: " << this->_hp << "\t" << other.name << "'s HP: " << other.GetHP() << std::endl << std::endl;

    // if the target died in the attack
    if (other.IsDead())
    {
        std::cout << std::endl << this->name << " has defeated " << other.name << " and has recieved " << other.GetXPReward() << " experience!" << std::endl;
        this->_xp += other.GetXPReward();
        this->Victory();
        return;
    }
}

// initializes some stats for a character using setters
void Character::Load(int hp, int atk, int def, int lvl)
{
    this->SetHP(hp);
    this->SetAtk(atk);
    this->SetDef(def);
    this->SetLevel(lvl);

    this->SetMaxHP(hp);

    // set xp reward now that we have initialized stats
    // xp reward is given by (lvl*5) + (attack / 4) + (defense / 4)     (according to lab author)
    this->_xpReward = (this->_lvl * 5) + (this->_atk / 4) + (this->_def / 4);

    // confirm stats to user
    std::cout << this->name << " has loaded stats: " << this->_lvl << " LVL\t" << this->_hp << " HP\t" << this->_atk << " ATK\t" << this->_def << " DEF\t" << std::endl;
}

// overload the load function to support difficulty
void Character::Load(int difficulty, int playerLevel)
{
    // load enemy stats based on difficulty and the player's level
    // easy, medium, and hard use different stats
    if (difficulty == 1) // EASY
    {
        this->Load(30, 3, 3, playerLevel);
    }
    else if (difficulty == 2) // MEDIUM
    {
        this->Load(40, 3, 3, playerLevel);
    }
    else if (difficulty == 3) // HARD
    {
        this->Load(45, 3, 3, playerLevel);
    }
    else // just in case this somehow happens
    {
        std::cout << "ERROR!  Assuming Medium Difficulty!";
        this->Load(40, 3, 3, playerLevel);
    }
}