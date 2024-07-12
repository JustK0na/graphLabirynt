#include "graph.hpp"
#include <stdio.h>
#include <iostream>
#include <cstring>

void sayHi(){
    std::cout<<"Hellow from graph.cpp"<<std::endl;
}

Vertex::Vertex(){}
Vertex::Vertex(std::string s):data(s){}

Edge::Edge(){}
Edge::Edge(int start, int end, float w):vertexStart(start), vertexEnd(end), weight(w){

}



edgeList::edgeList(){
    std::cout<<"You've made graph with score"<<std::endl;
}

std::vector<Edge> edgeList::allEdges(){
    return edges;
}

std::vector<Vertex> edgeList::allVertices(){
    return verticies;
}

Vertex edgeList::insertVertex(std::string d){
    Vertex v(d);
    v.index=verticies.size();
    verticies.push_back(v);
    return v;
}

Edge edgeList::insertEdge(int s, int e, float w){
    Edge tmp(s,e,w);
    tmp.index=edges.size();
    edges.push_back(tmp);
    return tmp;
}

std::vector<Edge> edgeList::incidentEdges(std::string vertex){
    std::vector<Edge> incidents;
    int index = 0;
    for(int i=0; i<(int)verticies.size(); i++){
        if(verticies.at(i).data==vertex){
            index = i;
            break;
        }
    }
     
    

    for(int i=0; i<(int)edges.size(); i++){
        if(edges.at(i).vertexStart==index||edges.at(i).vertexEnd==index){
            incidents.push_back(edges.at(i));
        }
    }
    return incidents;
}

bool edgeList::isAdjectedTo(std::string ver1, std::string ver2){

    int index1=-1, index2=-1;


    for(int i=0; i<(int)verticies.size(); i++){
        if(verticies.at(i).data == ver1){
            index1 = i;
        }
        if(verticies.at(i).data == ver2){
            index2 = i;
        }
    }

    if(index1<0||index2<0){
        return false;
    }

    for(int i=0; i<(int)edges.size(); i++){
        if((edges.at(i).vertexStart==index1 && edges.at(i).vertexEnd==index2)||(edges.at(i).vertexStart==index2 && edges.at(i).vertexEnd==index1)){
            return true;
        }
    }
    return false;
}

void edgeList::removeEdge(int e){
    edges.erase(edges.begin()+e);
}

void edgeList::removeVertex(std::string v){
    std::vector<Edge> incident;
    int index=-1;
    incident = incidentEdges(v);

    for(int i=0; i<(int)verticies.size(); i++){
        if(verticies.at(i).data==v){
            index = i;
            break;
        }
    }

    if(index<0){
        char name[1024];
        strcpy(name, v.c_str());
        perror("there is no such a vertex as: ");
        perror(name);
        exit(-1);
    }

    for(int i=0; i<(int)incident.size(); i++){
        removeEdge(incident.at(i).index);
    }

    verticies.erase(verticies.begin()+index);

}