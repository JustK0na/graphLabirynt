#ifndef GRAPH_LIB
#define GRAPH_LIB
#include <vector>
#include <string>
void sayHi();

class Edge{

    public:
    int vertexStart;
    int vertexEnd;
    float weight;
    int index;

    Edge();
    Edge(int, int, float);

};

class Vertex{

    public:
    std::string data;
    int index;

    Vertex();
    Vertex(std::string);

};

class edgeList{
    private:
    int score;
    std::vector<Edge> edges;
    std::vector<Vertex> verticies;

    public:
    edgeList();

    std::vector<Edge> allEdges();
    std::vector<Vertex> allVertices();

    Vertex insertVertex(std::string);
    Edge insertEdge(int, int, float);

    std::vector<Edge> incidentEdges(std::string);
    bool isAdjectedTo(std::string,std::string);

    void removeEdge(int);
    void removeVertex(std::string);

};


#endif 