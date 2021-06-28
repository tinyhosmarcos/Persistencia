#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include "ModsTable.h"
using namespace std;

template <class T>
class Node{

public:
    //map<int,pair<int,T>> modsValues; //order version[position_value, value];
    map<int,Node<T>*>    modsNextNode; //version nodeNext
    vector<ModsTable<T>> modsValues;
    int currentVersion;
    vector<T>            values;
    Node<T>*             nextNode;
    Node(int _currentVersion);
    Node(vector<T>&_values, int _currentVersion);
    Node(vector<T>&_values,Node<T>* nextNode, int _currentVersion);
    T getValue(int position,int version=0);
    void insertValue(int version,int positionValue,T value);
    void insertNextNode(int version,Node<T>* nextNode);
    void printValues();
    Node<T>* getNextNode(int version=0);
    
};

template <class T>
Node<T>::Node(int _currentVersion){
    this->currentVersion=_currentVersion;
    this->nextNode=NULL;
    
}
template <class T>
Node<T>::Node(vector<T>&_values,int _currentVersion ){
    this->nextNode=NULL;
    this->currentVersion=_currentVersion;
    this->values=_values;

}
template <class T>
Node<T>::Node(vector<T>&_values,Node<T>* nextNode,int _currentVersion){
    this->values=_values;
    this->nextNode=NULL;
    this->currentVersion=_currentVersion;
}

template <class T>
void Node<T>::insertNextNode(int version,Node<T>* nextNode){
    modsNextNode[version++]=nextNode;

}

template <class T>
void Node<T>::insertValue(int version,int positionValue,T value){
    //modsValues[version++]=make_pair(positionValue,value);
    modsValues.push_back(ModsTable<T>(version,positionValue,value));

}

template <class T>
T Node<T>::getValue(int position, int version){
    T temp=position;
    return temp;
}
template <class T>
Node<T>* Node<T>::getNextNode(int version){
    return modsNextNode[version];
}
template <class T>
void Node<T>::printValues(){
    cout<<"values iniciales: "<<endl;
    for(int i=0;i<values.size();i++){
        cout<<values[i]<<" ";
    }
    cout<<endl;
    if(modsValues.size()>0)
        cout<<"versiones "<<endl;
    
    for(typename vector<ModsTable<T>>::iterator it=modsValues.begin();it!=modsValues.end();it++){
        cout<<"version: "<<it->version<<", value position: "<<it->positionValue<<", value: "<<it->value<<endl;
    }
}

template <class T>
std::ostream&operator<<(std::ostream& os,const Node<T>& NodeT){

    int tempPosition=0;
    os<<"-------------Valores Iniciales del Nodo-------------       "<<"\n";
    os<<"--Version del Nodo: "<<NodeT.currentVersion<<"\n\n";  
    os<<"   [Position Value]    [Value]     "<<"\n";
    if(NodeT.values.empty())
        os<<"       Empty Values        "<<"\n";
    
    
    for(auto&it :NodeT.values){
        
        os<<"\t["<<tempPosition<<"]\t\t["<<it<<"]     "<<"\n";
        tempPosition++;
    }
 
    os<<"\n-------------------Mods Values-------------------"<<"\n";
    os<<"   [version]    [Position Value:] [Value]     "<<"\n";
    if(NodeT.modsValues.empty())
        os<<"       Empty Mods Values       "<<"\n";
    
    for(auto&it :NodeT.modsValues)
        os<<"   ["<<it.version<<"]     \t["<<it.positionValue<<"]\t\t  ["<<it.value<<"]     "<<"\n";

    os<<"\n-------------------Mods NextNode-------------------"<<"\n";
    os<<"   [version]    [Value]     "<<"\n";
    if(NodeT.modsNextNode.empty())
        os<<"       Empty Mods NextNode       "<<"\n";
    
    for(auto&it :NodeT.modsNextNode)
        os<<"   ["<<it.first<<"]    ["<<it.second<<"]     "<<"\n";
    return os;      
}

#endif