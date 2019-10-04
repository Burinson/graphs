#include "videogame.h"

Videogame::Videogame()
{
    // tipo, id, nivel, vecinos, jefe
    Node node1 = Node("campo", 1, 1, Boss("Saltamontes gigante"));
    Node node2 = Node("desierto", 2, 2, Boss("Musul-man"));
    Node node3 = Node("agua", 3, 3, Boss("Chico percede"));
    Node node4 = Node("castillo", 4, 4, Boss("Miaucula"));
    Node node5 = Node("hielo", 5, 5, Boss("El temible yeti de las nieves"));
    Node node6 = Node("ciudad", 6, 6, Boss("Tron"));
    Node node7 = Node("castillo", 7, 7, Boss("Hombre lobo"));
    Node node8 = Node("volcán", 8, 8, Boss("Magmortor"));
    Node node9 = Node("pradera", 9, 9, Boss("Vaca loka"));
    // adyacencias
    node1.setNeighbors({node2, node4});
    node2.setNeighbors({node1, node3, node5});
    node3.setNeighbors({node2, node6});
    node4.setNeighbors({node1, node5, node7});
    node5.setNeighbors({node2, node4, node6, node8});
    node6.setNeighbors({node3, node5, node9});
    node7.setNeighbors({node4, node8});
    node8.setNeighbors({node5, node7, node9});
    node9.setNeighbors({node6, node8});
    // id, vecinos
    global = Graph(0, {
        node1, node2, node3, node4, node5, node6, node7, node8, node9
    });
}
vector<Node> Videogame::getView(int id) {
    for(Node node : global.getNodes()) {
        if (node.getId() == id) {
            return node.getNeighbors();
        }
    }
}

bool Videogame::validMove(int id, int newId) {
    for(Node n : getView(id)) {
        if (n.getId() == newId)
            return true;
    }
    return false;
}

void Videogame::move(const int id, int pos)
{
    cout << "~/" << id << endl;
    switch(pos) {
    case 1:
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║ "<<ids[id-1]<<" ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    break;
    case 2:
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║ "<<ids[id-1]<<" ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    break;
    case 3:
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║ "<<ids[id-1]<<" ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    break;
    case 4:
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║ "<<ids[id-1]<<" ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    break;
    case 5:
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║ "<<ids[id-1]<<" ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    break;
    case 6:
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║ "<<ids[id-1]<<" ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    break;
    case 7:
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║ "<<ids[id-1]<<" ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    break;
    case 8:
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║ "<<ids[id-1]<<" ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    break;
    case 9:
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║    ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
        cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
        cout << "║    ║" << "║    ║" << "║ "<<ids[id-1]<<" ║" << endl;
        cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    break;
    }

    char dir;

    cout << "wasd para desplazarse" << endl;
    cout << "0) Regresar" << endl;
    cin >> dir;
    switch(dir) {
    case 'w':
        if (validMove(pos, pos-3)) {
            move(id, pos-3);
        } else {
            cout << "Movimiento inválida" << endl;
            move(id, pos);
        }
    break;
    case 'd':
        if (validMove(pos, pos+1)) {
            move(id, pos+1);
        } else {
            cout << "Movimiento inválida" << endl;
            move(id, pos);
        }
    break;
    case 's':
        if (validMove(pos, pos+3)) {
            move(id, pos+3);
        } else {
            cout << "Movimiento inválida" << endl;
            move(id, pos);
        }
    break;
    case 'a':
        if (validMove(pos, pos-1)) {
            move(id, pos-1);
        } else {
            cout << "Movimiento inválida" << endl;
            move(id, pos);
        }
    break;
    case '0':
    break;
    default:
    cout << "Selección incorrecta" << endl;
    }

    for(Graph g : graphs) {
        if (g.getId() == id) {
            g.setPos(pos);
        }
    }
}
void Videogame::add()
{
    int id;
    for(int i = 1; i <= 9; ++i) {
        cout << i <<  ") " << ids[i-1] << endl;
    }
    cout << "Personaje: ";
    cin >> id;
    if (!exists(id)) {
        Graph g(id);
        graphs.push_back(g);
        g.setNodes(getView(id));
    } else {
        cout << "Este identificador ya existe" << endl;
    }
}

void Videogame::remove()
{
    int id;
    for(int i = 1; i <= 9; ++i) {
        cout << i << ") " << ids[i-1] << endl;
    }
    
    cin >> id;
    if (exists(id)) {
        for(int i = 0; i < sz; ++i) {
            if (graphs[i].getId() == id) {
                graphs.erase(graphs.begin() + i);
            }
        }
    } else {
        cout << "Este grafo no existe" << endl;
    }
}

void Videogame::showGlobal()
{
        cout << "╔═════╗" << "╔═════╗" << "╔═════╗" << endl;
        cout << "║  1  ║" << "║  2  ║" << "║  3  ║" << endl;
        cout << "╚═════╝" << "╚═════╝" << "╚═════╝" << endl;
        cout << "╔═════╗" << "╔═════╗" << "╔═════╗" << endl;
        cout << "║  4  ║" << "║  5  ║" << "║  6  ║" << endl;
        cout << "╚═════╝" << "╚═════╝" << "╚═════╝" << endl;
        cout << "╔═════╗" << "╔═════╗" << "╔═════╗" << endl;
        cout << "║  7  ║" << "║  8  ║" << "║  9  ║" << endl;
        cout << "╚═════╝" << "╚═════╝" << "╚═════╝" << endl;
}

bool Videogame::exists(int id)
{
    for(auto g : graphs) {
        if (g.getId() == id) {
            return true;
        }
    }
    return false;
}

int Videogame::access()
{
    int id;
    cout << "ID: ";
    cin >> id;
    if (exists(id)) {
        return id;
    } else {
        cout << "No existe este grafo" << endl;
        return -1;
    }
}

int Videogame::getSz() const
{
    return global.getNodes().size();
}

void Videogame::setSz(int value)
{
    sz = value;
}

Graph Videogame::getGlobal() const
{
    return global;
}

void Videogame::setGlobal(const Graph &value)
{
    global = value;
}

