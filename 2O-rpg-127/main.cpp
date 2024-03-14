//Efren Miguel Sanchez 23310127//
#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include <queue>

using namespace std;

int main() {
    Player *player = new Player("Carpincho albino", 80, 7, 2, 10);
    Enemy *enemy = new Enemy("Carpincho N", 20, 5, 2, 7);
    Enemy *enemy2 = new Enemy("Gaviota", 30, 4, 2, 2);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat* combat = new Combat(participants);
    combat->doCombat();

    delete player;
    delete enemy;
    delete enemy2;
    delete combat;

    return 0;
}