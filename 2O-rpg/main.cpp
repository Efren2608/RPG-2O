#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"


struct Personaje 
{
    std::string nombre;
    int salud;
    int Fuerza;
    int defensa;
};

void Ataque(Personaje& atacante, Personaje& defensor) {
    int daño = atacante.Fuerza - defensor.defensa;
    defensor.salud -= daño > 0 ? daño : 0;
    std::cout << atacante.nombre << "Pico a " defensor.nombre << "." << std::endl;
}

int main() {
    srand(time(nullptr));


    Jugador *player = new Jugador("Carpincho", 100, 10, 6, 8);
    Enemy *enemy = new Enemy("Carpincho albino", 50, 5, 2, 3);
    
    std::cout << "comienzam los trancazos" << std::endl;
    std::cout << std::endl;

    while (Jugador.salud > 0 && Enemy.salud > 0)
    {
        Ataque(Jugador, Enemy);
        if (Enemy.salud <= 0) break;
        Ataque(Enemy, Jugador);
        if (Jugador.salud <= 0) break;
        std::cout << std::endl;
    }

    if (Jugador.salud <= 0 & Enemy.salud <= 0)
    {
        std::cout << "Han empatado (creo que pelearon con cuchillos)" << std::endl;
    } else if (jugador1.salud <= 0) {
        std::cout << Enemy.nombre << " acuchillo a su oponente" << std::endl;
    }
    else {
        std::cout << Jugador.nombre << " acuchillo a su oponente" << std::endl;
    }
   
    return 0;
}