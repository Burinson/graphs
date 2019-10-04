#include "videogame.h"

Videogame::Videogame()
{
    sz = graphs.size();
    // tipo, id, nivel, vecinos, jefe
    Node node1 = Node("campo", 1, 1, Boss("Saltamontes gigante"));
    Node node2 = Node("desierto", 2, 2, Boss("Musul-man"));
    Node node3 = Node("agua", 3, 3, Boss("Chico percede"));
    Node node4 = Node("castillo", 4, 4, Boss("Miaucula"));
    Node node5 = Node("hielo", 5, 5, Boss("El temible yeti de las nieves"));
    Node node6 = Node("ciudad", 6, 6, Boss("Tron"));
    Node node7 = Node("castillo", 7, 7, Boss("Hombre lobo"));
    // adyacencias
    node1.setNeighbors({node2, node4});
    node2.setNeighbors({node1});
    node3.setNeighbors({node1});
    node4.setNeighbors({node1, node5, node7});
    node5.setNeighbors({node4});
    node6.setNeighbors({node7});
    node7.setNeighbors({node4, node6});
    // id, vecinos
    global = Graph(0, {
        node1, node2, node3, node4, node5, node6, node7
    });
}
vector<Node> Videogame::getView(int id) {
    for(Node node : global.getNodes()) {
        if (node.getId() == id) {
            return node.getNeighbors();
        }
    }
}
void Videogame::add()
{
    int id;
    cout << "ID: " << endl;
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
    cout << "ID: " << endl;
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
    cout << "ID: " << endl;
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
    return sz;
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

