#include "menu.h"
Menu::Menu()
{

}

void Menu::show()
{
    Videogame v;
    int op;
    do {
        cout << "~" << endl
             << "1) Crear grafo" << endl
             << "2) Eliminar grafo" << endl
             << "3) Mostrar grafo global" << endl
             << "4) Acceder" << endl;
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
                cout << "~/" << id << endl
                     << "1) Mostrar grafo" << endl
                     << "2) Mostrar lugar actual" << endl
                     << "3) Mostrar lugares adyacentes" << endl
                     << "4) Desplazarse" << endl
                     << "0) Regresar" << endl;
                cin >> op2;
                switch(op2) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    v.move(id, id);
                    break;
                case 0:
                    break;
                default:
                    cout << "Opción inválida" << endl;
                }
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
