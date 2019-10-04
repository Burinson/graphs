#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <graph.h>
#include <vector>
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
    vector<Graph> graphs;
    int getSz() const;
    void setSz(int value);
    Graph getGlobal() const;
    void setGlobal(const Graph &value);
private:
    int sz;
    Graph global;
};

#endif // VIDEOGAME_H
