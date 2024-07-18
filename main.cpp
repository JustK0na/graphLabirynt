#include <cstdlib>
#include <iostream>
#include "graph.hpp"




int main(int argc, char **argv){

    edgeList g;
    Vertex tmp;
    Edge tmpE;
    
    g.insertVertex("a");
    g.insertVertex("b");
    g.insertVertex("c");
    g.insertVertex("d");
    g.insertVertex("e");
    g.insertVertex("f");
    g.insertVertex("g");
    g.insertVertex("h");
    g.insertVertex("i");

    std::vector<Vertex> tmpVector;
    tmpVector = g.allVertices();

    for(int i=0; i<(int)tmpVector.size(); i++){
        std::cout<<tmpVector.at(i).data<<std::endl;
    }

    g.insertEdge(0,1,1);
    g.insertEdge(0,2,0.23);
    g.insertEdge(1,2,0.42);
    g.insertEdge(2,3,0.67);
    g.insertEdge(2,4,0.36);
    g.insertEdge(2,5,0.51);
    g.insertEdge(3,7,0.92);
    g.insertEdge(5,7,0.91);
    g.insertEdge(5,6,0.72);
    g.insertEdge(7,8,0.31);


    std::vector<Edge> tmpVectorE;
    tmpVectorE = g.allEdges();

    for(int i=0; i<(int)tmpVectorE.size(); i++){
        std::cout<<"Edge pomiedzy: "<<tmpVectorE.at(i).vertexStart<<", a: "<<tmpVectorE.at(i).vertexEnd<<" o wadze: "<<tmpVectorE.at(i).weight<<std::endl;
    }
    
    std::vector<Edge> incident;
    std::string edgeNumber = "c";
    incident = g.incidentEdges(edgeNumber);
    std::cout<<"Edges incident to Vertex "<< edgeNumber <<": "<<std::endl;

    for(int i=0; i<(int)incident.size(); i++){
        std::cout<<"\t"<<incident.at(i).index<<std::endl;
    }

    std::string ver1="e",ver2="c";
    bool sasiad = g.isAdjectedTo(ver1,ver2);
    std::string odp;

    std::cout<<"Czy "<<ver1<<" jest sasiadem "<<ver2<<" ?\t"<<(odp = sasiad ? "tak":"nie" )<<std::endl;

    //g.removeEdge(4);
    //sasiad = g.isAdjectedTo(ver1,ver2);
    //std::cout<<"Czy "<<ver1<<" jest sasiadem "<<ver2<<" ?\t"<<(odp = sasiad ? "tak":"nie" )<<std::endl;
    g.removeVertex("e");
    
    sasiad = g.isAdjectedTo(ver1,ver2);
    std::cout<<"Czy "<<ver1<<" jest sasiadem "<<ver2<<" ?\t"<<(odp = sasiad ? "tak":"nie" )<<std::endl;

    tmpVector = g.allVertices();

    for(int i=0; i<(int)tmpVector.size(); i++){
        std::cout<<tmpVector.at(i).data<<std::endl;
    }

    edgeNumber = "c";
    incident = g.incidentEdges(edgeNumber);
    std::cout<<"Edges incident to Vertex "<< edgeNumber <<": "<<std::endl;
    for(int i=0; i<(int)incident.size(); i++){
        std::cout<<"\t"<<incident.at(i).index<<std::endl;
    }

    int exampledge = 3;
    std::cout<<"This Vertices are at the end of: "<<exampledge<<" edge"<<std::endl;

    std::vector<Vertex> endVerttices;

    endVerttices = g.endVertices(exampledge);

    for(int i=0; i<(int)endVerttices.size(); i++)
        std::cout<<"\t"<<endVerttices.at(i).data<<"\n";
    
    Vertex opposite;
    opposite = g.opposite(exampledge, edgeNumber);
    std::cout<<"This Vertex: "<<opposite.data<<" is at the other end of: "<<exampledge<<" than: "<<edgeNumber<<"\n";
    
    return 0;

}   