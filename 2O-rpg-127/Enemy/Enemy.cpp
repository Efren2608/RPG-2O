//
// Created by Victor Navarro on 13/02/24.
//Modificado por Efren Miguel Sanchez Rodriguez 23310127
//
#include "Enemy.h"
#include <iostream>


using namespace std;

//TODO: Check the circular dependency
int getRolledAttack(int attack) {
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}

Enemy::Enemy(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed, false) {
}

void Enemy::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<getName()<<" va a saludar al gallo de oro"<<endl;
    }
    else {
        cout<<getName()<<" recibio " << damage << " danho en navajazos" << endl;
    }
}

void Enemy::flee(vector<Player *> teamMembers) {
    std::sort(teamMembers.begin(), teamMembers.end(), compareSpeed);
    Player *fastestPlayer = [0];
    bool fleed = false;
    if (this->getSpeed() > fastestPlayer->getSpeed()) {
        fleed = true;
    } else {
        srand(time(nullptr));
        int chance = rand() % 100;
        cout << "chance: " << chance << endl;
        fleed = chance > 95;
    }

    this->fleed = fleed;
}

Character* Enemy::getTarget(vector<Player *> teamMembers) {
    // Obtiene el miembro del equipo con menor vida
    int targetIndex = 0;
    int lowestHealth = INT_MAX;
    for(int i=0; i < teamMembers.size(); i++) {
        if(teamMembers [i]->getHealth() < lowestHealth) {
            lowestHealth = teamMembers[i]->getHealth();
            targetIndex = i;
        }
    }

    return teamMembers[targetIndex];
}

Action Enemy::takeAction(const vector<Player *>& player) {
    Action myAction;
    myAction.speed = getSpeed();
    myAction.subscriber = this;
    Character* target = nullptr;
    if (getHealth() <= (getHealth() * .15)){
        myAction.action = [this, player]() {
            flee(player);
        };
    } else {
        target = getTarget(player);
        myAction.target = target;
        myAction.action = [this, target]() {
            doAttack(target);
        };
    }

    return myAction;
}

