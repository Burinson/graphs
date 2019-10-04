#include "videogame.h"
#include <fstream>

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

Graph &Videogame::getGraph(int id)
{
    for(Graph &g : graphs) {
        if (g.getId() == id)
            return g;
    }
}

void Videogame::move(const int id)
{
    cout << "~/" << id << "/mover" << endl;
    int pos = getGraph(id).getPos();
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
            getGraph(id).setPos(pos-3);
            set<int> vis = getGraph(id).getVis();
            vis.insert(pos-3);
            getGraph(id).setVis(vis);
            move(id);
        } else {
            cout << "Movimiento inválido" << endl;
            move(id);
        }
    break;
    case 'd':
        if (validMove(pos, pos+1)) {
            getGraph(id).setPos(pos+1);
            set<int> vis = getGraph(id).getVis();
            vis.insert(pos+1);
            getGraph(id).setVis(vis);
            move(id);
        } else {
            cout << "Movimiento inválido" << endl;
            move(id);
        }
    break;
    case 's':
        if (validMove(pos, pos+3)) {
            getGraph(id).setPos(pos+3);
            set<int> vis = getGraph(id).getVis();
            vis.insert(pos+3);
            getGraph(id).setVis(vis);
            move(id);
        } else {
            cout << "Movimiento inválido" << endl;
            move(id);
        }
    break;
    case 'a':
        if (validMove(pos, pos-1)) {
            getGraph(id).setPos(pos-1);
            set<int> vis = getGraph(id).getVis();
            vis.insert(pos-1);
            getGraph(id).setVis(vis);
            move(id);
        } else {
            cout << "Movimiento inválido" << endl;
            move(id);
        }
    break;
    case '0':
    break;
    default:
    cout << "Selección incorrecta" << endl;
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
        set<int> vis;
        vis.insert(g.getPos());
        g.setNodes(getView(id));
        if (validMove(g.getPos(),g.getPos()-3)) {
            vis.insert(g.getPos()-3);
        }
        if (validMove(g.getPos(),g.getPos()+1)) {
            vis.insert(g.getPos()+1);
        }
        if (validMove(g.getPos(),g.getPos()+3)) {
            vis.insert(g.getPos()+3);
        }
        if (validMove(g.getPos(),g.getPos()-1)) {
            vis.insert(g.getPos()-1);
        }
        g.setVis(vis);
        graphs.push_back(g);

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
    string pos[9] = {"", "", "", "", "", "", "", "", ""};
    for(int i = 0; i < 9; ++i) {
        int cnt  = 0;
        for(Graph g : graphs) {
            if (g.getPos() == i+1) {
                pos[i]+=ids[g.getId()-1];
                cnt++;
            }
        }
        for(int j = 0; j < 18-cnt*2; ++j) {
            pos[i]+=" ";
        }
    }

        cout << "╔══════════════════╗" << "╔══════════════════╗" << "╔══════════════════╗"<< endl;
        cout << "║"<<pos[0]<<"║" << "║"<<pos[1]<<"║" << "║"<<pos[2]<<"║" << endl;
        cout << "║                  ║" << "║                  ║" << "║                  ║" << endl;
        cout << "║                  ║" << "║                  ║" << "║                  ║" << endl;
        cout << "╚══════════════════╝" << "╚══════════════════╝" << "╚══════════════════╝" << endl;
        cout << "╔══════════════════╗" << "╔══════════════════╗" << "╔══════════════════╗"<< endl;
        cout << "║"<<pos[3]<<"║" << "║"<<pos[4]<<"║" << "║"<<pos[5]<<"║" << endl;
        cout << "║                  ║" << "║                  ║" << "║                  ║" << endl;
        cout << "║                  ║" << "║                  ║" << "║                  ║" << endl;
        cout << "╚══════════════════╝" << "╚══════════════════╝" << "╚══════════════════╝" << endl;
        cout << "╔══════════════════╗" << "╔══════════════════╗" << "╔══════════════════╗"<< endl;
        cout << "║"<<pos[6]<<"║" << "║"<<pos[7]<<"║" << "║"<<pos[8]<<"║" << endl;
        cout << "║                  ║" << "║                  ║" << "║                  ║" << endl;
        cout << "║                  ║" << "║                  ║" << "║                  ║" << endl;
        cout << "╚══════════════════╝" << "╚══════════════════╝" << "╚══════════════════╝" << endl;
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

void Videogame::showPos(int id)
{
    int pos = getGraph(id).getPos();
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
}

void Videogame::showGraph(int id)
{
    string pos[9];
    for(int i = 0; i < 9; ++i) {
        for(Graph g : graphs) {
            if (g.getVis().count(i+1)) {
                pos[i] ="🍲";
            } else {
                pos[i] = "  ";
            }
        }
    }
    cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
    cout << "║ "<<pos[0]<<" ║" << "║ "<<pos[1]<<" ║" << "║ "<<pos[2]<<" ║" << endl;
    cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
    cout << "║ "<<pos[3]<<" ║" << "║ "<<pos[4]<<" ║" << "║ "<<pos[5]<<" ║" << endl;
    cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
    cout << "║ "<<pos[6]<<" ║" << "║ "<<pos[7]<<" ║" << "║ "<<pos[8]<<" ║" << endl;
    cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
}

void Videogame::showAdj(int id)
{
    string pos[9] = {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "};
    Graph g = getGraph(id);
    pos[g.getPos()-1] = ids[id-1];
    if (validMove(g.getPos(),g.getPos()-3)) {
        pos[g.getPos()-4] = "🍂";
    }
    if (validMove(g.getPos(),g.getPos()+1)) {
        pos[g.getPos()] = "🍂";
    }
    if (validMove(g.getPos(),g.getPos()+3)) {
        pos[g.getPos()+2] = "🍂";
    }
    if (validMove(g.getPos(),g.getPos()-1)) {
        pos[g.getPos()-2] = "🍂";
    }
    cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
    cout << "║ "<<pos[0]<<" ║" << "║ "<<pos[1]<<" ║" << "║ "<<pos[2]<<" ║" << endl;
    cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
    cout << "║ "<<pos[3]<<" ║" << "║ "<<pos[4]<<" ║" << "║ "<<pos[5]<<" ║" << endl;
    cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;
    cout << "╔════╗" << "╔════╗" << "╔════╗" << endl;
    cout << "║ "<<pos[6]<<" ║" << "║ "<<pos[7]<<" ║" << "║ "<<pos[8]<<" ║" << endl;
    cout << "╚════╝" << "╚════╝" << "╚════╝" << endl;

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

