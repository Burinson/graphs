#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <videogame.h>
using namespace std;

class Menu
{
public:
    Menu();
    void show();
    void load();
    void save();
    Videogame v;
};

#endif // MENU_H
