#include "Node.h"
#include <iostream>


Node::Node(int idx, string namex, bool isFilex)
{
    id = idx;
    isFile = isFilex;
    name = namex;
}
Node::~Node()
{
    //dtor
}
bool Node::addNode(int idx, int rootIdx, string namex, bool isFilex){

    if(id == rootIdx && !isFile){
        Node *temp = new Node(idx, namex, isFilex);
        temp->parent = this;
        isLeaf = false;
        children.push_back(temp);
        return true;
    }
    for(int i = 0; i<children.size(); i++){
        children[i]->addNode(idx, rootIdx, namex, isFilex);
    }
    return NULL;
}
void Node::displayBranch(int branchId, string indent){
    if(branchId == id || branchId == NULL){
        branchId = NULL;

        cout << indent << this->id << ". " << this->name
             << "(" << (this->isFile ? "fails" : "katalogs") << ")"
             << endl;
        if(children.size() > 0)indent += "     ";

        for(int i = 0; i<children.size(); i++)
            children[i]->displayBranch(branchId, indent);
    }
     else{
        for(int i = 0; i<children.size(); i++)
            children[i]->displayBranch(branchId, indent);
    }
}
bool Node::deleteNode(int idx){
    if(idx == id || idx == NULL){
        if(idx != NULL)this->parent->removeChild(idx);
        idx = NULL;

        for(int i = 0; i<children.size(); i++)
            children[i]->deleteNode();
        delete this;
    }
    else{
        for(int i = 0; i<children.size(); i++)
            children[i]->deleteNode(idx);
    }
}
void Node::removeChild(int childId){
    for(int i = 0; i<children.size(); i++){
        if(children[i]->id == childId){
            children.erase(children.begin() + i);
        }
    }
}

Node* Node::findById(int idFind){
    for(int i = 0; i<children.size(); i++){
        if(children[i]->id == idFind)return children[i];
        children[i]->findById(idFind);
    }
    //return NULL;
}






