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

    /*

    CZEMU NIBY UŻYWASZ INT I STRING DO USUWANIA I POSZUKIWANIA 
    SĄSIADUJĄCYCH??????????????
    TO MAJĄ BYĆ OBIEKTY
    FUCNA ISADJECTESDTO() POWINNA PRZYJMOWAĆ VERTES OBEJCT
    ISADJEECTEDTO(VERTEX) I W PROGRAMIE ODPOWIEDNIO ITEROWAĆ PO 
    GRAPHIE!!!

    W OGÓLE TEN PLIK JEST AKTUALNY????

    ONES KEFT \/
    (to powinny być funnkcje klasy edge)
    endVertices(Edge class e) -> return vertex connected to edge
    opposite(vertex class v) -> returns the oter vertex beside v
    isAdjectedToEdge(edge class e) -> check
    isIncidentOn(vertex class c) -> check


    Ale i tak są źle te rzeczy i nie wiem czemu nie zrobiłeś według ksiązki 
    z podziałem na metody klas graph, edge i vertex ??      
    */

};


#endif 