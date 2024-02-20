#include "Player.h"
#include <iostream>

using namespace std;

Jugador::Jugador(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed) {
    experience = 0;
    level = 1;
}

void Jugador::doAttack(Character *target) {
    int trueDamage = getAttack() - target->getDefense();
    target->takeDamage(trueDamage);
}

void Jugador::takeDamage(int damage) {
    setHealth(health - damage);

    if(health <= 0) {
        cout<<"Te moriste"<<endl;
    }
    else {
        cout<<"Recibiste " << damage << " danho" << endl;
    }
}

void Jugador::flee() {
    //TODO: Implement flee
    cout<<"espera, esta chambeando"<<endl;
}

void Jugador::emote() {
    cout<<"Ich will nitch" << endl;
}

void Jugador::levelUp() {
    level++;
    setHealth(getHealth() + 15);
    setAttack(getAttack() + 5);
    setDefense(getDefense() + 6);
    setSpeed(getSpeed() + 8);
}

void Jugador::gainExperience(int exp) {
    experience += exp;
    if (experience >= 150) {
        levelUp();
        experience = 0;
    }
}