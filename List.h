#ifndef __LIST_H__
#define __LIST_H__
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class List{
private:
    Node<T>* root;
    int version;
public:
    List();
    void addNode(vector<T> &values);
    void printList();   
    void insert(int positionNode,int positionValue,T value);
    void buscar(int positionNode,int version,int positionValue);
    int getVersion(){return version;};
    Node<T>* getRoot(){return root;};


};

template <class T>
List<T>::List(){
    this-> version=0;
    this-> root=NULL;
}

template <class T>
void List<T>::addNode(vector<T> &values){
    Node<T>** temp=&root;
    Node<T>** temp2;
    if(!(*temp)){
        (*temp)=new Node<T>(values,++version);   
        return;
    }

    while(!(*temp)->modsNextNode.empty()){  
        for(typename map<int,Node<T>*>::iterator it=(*temp)->modsNextNode.begin();it!=(*temp)->modsNextNode.end();++it){
            temp2=&(it->second);
        }
        temp=&(*temp2);
    }
    ++version;
    (*temp)->modsNextNode[version]=new Node<T>(values,version);
    
    
}

template <class T>
void List<T>::printList(){
    Node<T>* temp=root;
 
    while(temp!=NULL){
        cout<<(*temp)<<endl;
        
        if(!(temp)->modsNextNode.empty()){
            typename map<int,Node<T>*>::reverse_iterator it=(temp)->modsNextNode.rbegin();
            temp=(it->second);
        }
        else{
            (temp)=temp->nextNode;
        }
    }
 
}

template <class T>
void List<T>::insert(int positionNode,int positionValue,T value){
    Node<T>** iterador=&root;
    while((*iterador) and (--positionNode)>0){
        if(!(*iterador)->modsNextNode.empty()){
            typename map<int,Node<T>*>::reverse_iterator it=(*iterador)->modsNextNode.rbegin();
            iterador=&(it->second);
        }
        else
            iterador=&((*iterador)->nextNode);
    }
    (*iterador)->insertValue(++version, positionValue, value); 

}

template <class T>
void List<T>::buscar(int positionNode,int version,int positionValue){
    Node<T>* temp=root;
    T valueFind;
    int flag=0;
    for(int i=1;i<positionNode;i++){
  
        typename map<int,Node<T>*>::reverse_iterator it=(temp)->modsNextNode.rbegin();
        if(temp->currentVersion<=version)
            temp=(it->second);
        else{
            cout<<endl<<"No existe el valor para esta version"<<endl;
            return;
        }
    }
    for(auto&it:temp->modsValues){
            if(it.positionValue==positionValue and it.version<=version){
                valueFind=it.value;
                flag++;
            }
        }        
    if(temp->currentVersion<=version and flag==0){
        cout<<"Version: "<<version<<"| En Nodo: "<<positionNode<<endl;
        cout<<"Position Value: "<<positionValue<<"| value: "<<temp->values[positionValue];

    }
    else{
        cout<<"Version: "<<version<<"| En Nodo: "<<positionNode<<endl;
        cout<<"Position Value: "<<positionValue<<"| value: "<<valueFind;           
    }
}


#endif