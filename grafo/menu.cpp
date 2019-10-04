#include "menu.h"
#include <fstream>
Menu::Menu()
{
}

void Menu::show()
{
    int op;
    do {
        cout << "~" << endl
             << "1) Crear grafo" << endl
             << "2) Eliminar grafo" << endl
             << "3) Mostrar grafo global" << endl
             << "4) Acceder" << endl
             << "0) Salir" << endl;
        cin >> op;
        switch(op) {
        case 1:
            v.add();
            break;
        case 2:
            v.remove();
            break;
        case 3:
            v.showGlobal();
            break;
        case 4:
        {
            int id = v.access();
            int op2;
            if (id != -1) {
                do {

                    cout << "~/" << v.ids[id-1] << endl
                         << "1) Mostrar grafo" << endl
                         << "2) Mostrar lugar actual" << endl
                         << "3) Mostrar lugares adyacentes" << endl
                         << "4) Desplazarse" << endl
                         << "0) Regresar" << endl;
                    cin >> op2;
                    switch(op2) {
                    case 1:
                        v.showGraph(id);

                        break;
                    case 2:
                        v.showPos(id);
                        break;
                    case 3:
                        v.showAdj(id);
                        break;
                    case 4:
                        v.move(id);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opción inválida" << endl;
                    }
                } while(op2);
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Opción inválida" << endl;
        }

    } while(op);


}

void Menu::save()
{
    ofstream file("videogame.bin", ios::out | ios::binary | ios::trunc);
    if (file.fail())
        cout << "No existe este archivo" << endl;
    else {
        file.write(reinterpret_cast<char *>(&v), sizeof(Videogame));
    }
    file.close();
}

void Menu::load()
{
    ifstream file("videogame.bin", ios::in | ios::binary);
    if (file.fail())
        cout << "No existe este archivo" << endl;
    else {
        file.seekg(0);
        file.read(reinterpret_cast<char *>(&v), sizeof(Videogame));
    }
    file.close();
}
