#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <graph.h>
#include <vector>
#define MONKEY 🐵
using namespace std;

class Videogame
{
public:
    Videogame();
    void add();
    void remove();
    void showGlobal();
    bool exists(int id);
    int access();
    void showPos(int id);
    void showGraph(int id);
    void showAdj(int id);
    vector<Graph> graphs;
    int getSz() const;
    void setSz(int value);
    Graph getGlobal() const;
    void setGlobal(const Graph &value);
    vector<Node> getView(int id);
    void move(const int id);
    bool validMove(int id, int newId);
    string ids[9] = {"🐒", "🦊", "🦄", "🐇", "🐀", "🐧", "🐸", "🐈", "🐕"};
    Graph &getGraph(int id);
private:
    int sz;
    Graph global;
};

#endif // VIDEOGAME_H
