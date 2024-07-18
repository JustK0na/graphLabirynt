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

    std::vector<Edge> allEdges(); //graph method
    std::vector<Vertex> allVertices(); //graph method

    Vertex insertVertex(std::string); //graph method
    Edge insertEdge(int, int, float); //graph method
    
    void removeEdge(int);   //graph method
    void removeVertex(std::string); //graph method

    std::vector<Edge> incidentEdges(std::string); //Vertex method
    bool isAdjectedTo(std::string,std::string); //Vertex mehod

    std::vector<Vertex> endVertices(int); //Edge method
    Vertex opposite(int, std::string); //edge method
    bool isAdjectedToEdge(int, int);
    bool isIncidentOn(int, std::string);


    /*
    endVertices(Edge class e) -> return vertex connected to edge ./DONE
    opposite(vertex class v) -> returns the oter vertex beside v ./DONE
    isAdjectedToEdge(edge class e) -> check
    isIncidentOn(vertex class c) -> check


    Q: czemu nie zrobiłeś z podziałem na metody klas graph, edge i vertex ?? 

    A: bo graph nie wie nic o krawędziach prowadzących do niego
    */

};


#endif 