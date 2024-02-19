#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"

int main() {

    Jugador *player = new Jugador("Carpincho", 100, 10, 6, 8);
    Enemy *enemy = new Enemy("Carpincho albino", 50, 5, 2, 3);

    player->doAttack(enemy);
    enemy->doAttack(player);

    cout<< player->toString()<< endl;
    cout<< enemy->toString()<< endl;

    delete player;
    delete enemy;
    return 0;
}
