#include "Node.h"
#include <iostream>

template<class type>
Node<type>::Node(type x)
{
    data = x;
}

template<class type>
Node<type>::~Node()
{
    //dtor
}

template <class type>
bool Node<type>::addNode(type x){
    Node *temp = new Node(x);
    children.push_back(temp);

    return true;
}

template <class type>
void Node<type>::displayBranch(type x, string indent){
    if(x == data || x == NULL){
        x = NULL;

        cout << indent << x
             << endl;
        if(children.size() > 0)indent += "     ";

        for(int i = 0; i<children.size(); i++)
            children[i]->displayBranch(x, indent);
    }
     else{
        for(int i = 0; i<children.size(); i++)
            children[i]->displayBranch(x, indent);
    }
}

template <class type>
bool Node<type>::deleteNode(type x){
    if(x == data || x == NULL){
        if(x != NULL)this->parent->removeChild(x);
        x = NULL;

        for(int i = 0; i<children.size(); i++)
            children[i]->deleteNode();
        delete this;
    }
    else{
        for(int i = 0; i<children.size(); i++)
            children[i]->deleteNode(x);
    }
}

template <class type>
void Node<type>::removeChild(type x){
    for(int i = 0; i<children.size(); i++){
        if(children[i]->id == x){
            children.erase(children.begin() + i);
        }
    }
}

template <class type>
Node<type>* Node<type>::findNode(type x){
    if(this->data == x)return this;

    for(int i = 0; i < children.size(); i++)
        children[i]->findNode(x);

    return NULL;
}






