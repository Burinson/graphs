#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Boss {
    string name;
public:
    Boss(string name);
    Boss();
    string getName() const;
    void setName(const string &value);
};

class Node {
private:
    int id;
    vector<Node> neighbors;
    string type;
    int level;
    Boss boss;
public:
    Node();
    Node(string type, int id, int level, Boss boss);
    int getId() const;
    void setId(int value);
    vector<Node> getNeighbors() const;
    void setNeighbors(const vector<Node> &value);
    string getType() const;
    void setType(const string &value);
    int getLevel() const;
    void setLevel(int value);
    Boss getBoss() const;
    void setBoss(const Boss &value);
};
class Graph
{
public:
    int getId() const;
    void setId(int value);
    Graph();
    Graph(int id, vector<Node> nodes);
    vector<Node> getNodes() const;
    void setNodes(const vector<Node> &value);
    int getPos() const;
    void setPos(int value);
    set<int> getVis() const;
    void setVis(const set<int> &value);

private:
    int id;
    vector<Node> nodes;
    int pos;
    set<int> vis;
};

inline Graph::Graph()
{

}

inline Graph::Graph(int id, vector<Node> nodes = vector<Node>())
{
    this->id = id;
    this->nodes = nodes;
    this->pos = id;
}

inline vector<Node> Graph::getNodes() const
{
return nodes;
}

inline void Graph::setNodes(const vector<Node> &value)
{
nodes = value;
}

inline int Graph::getPos() const
{
return pos;
}

inline void Graph::setPos(int value)
{
pos = value;
}

inline set<int> Graph::getVis() const
{
return vis;
}

inline void Graph::setVis(const set<int> &value)
{
vis = value;
}

inline int Graph::getId() const
{
return id;
}

inline void Graph::setId(int value)
{
id = value;
}

inline int Node::getId() const
{
return id;
}

inline void Node::setId(int value)
{
id = value;
}

inline vector<Node> Node::getNeighbors() const
{
return neighbors;
}

inline void Node::setNeighbors(const vector<Node> &value)
{
neighbors = value;
}

inline string Node::getType() const
{
return type;
}

inline void Node::setType(const string &value)
{
type = value;
}

inline int Node::getLevel() const
{
return level;
}

inline void Node::setLevel(int value)
{
level = value;
}

inline Boss Node::getBoss() const
{
return boss;
}

inline void Node::setBoss(const Boss &value)
{
boss = value;
}


inline Node::Node()
{

}

inline Node::Node(string type, int id, int level, Boss = Boss())
{
    this->type = type;
    this->id = id;
    this->level = level;
}


inline string Boss::getName() const
{
return name;
}

inline void Boss::setName(const string &value)
{
name = value;
}

inline Boss::Boss(string name)
{
    this->name = name;
}

inline Boss::Boss()
{

}
#endif // GRAPH_H
