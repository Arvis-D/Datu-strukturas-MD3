#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

template <class type>
class Node
{
public:
    Node(type x){
        data = x;
    };

    bool addNode(type x, type n = NULL){
        Node* temp = new Node(x);

        if(n != NULL){
            Node * found = findNode(n);
            if(found != NULL){
                found->children.push_back(temp);
                temp->parent = found;
            }
            else return false;

            return true;
        }

        temp->parent = this;
        children.push_back(temp);
        return true;
    };

    bool deleteNode(type x = NULL){
        if(x != NULL){
            findNode(x)->deleteNode();
            return true;
        }
        for(int i = 0; i<children.size(); i++)
            children[i]->deleteNode();

        parent->removeChild(data);
        delete this;
    };

    void displayBranch(type x = NULL, string indent= ""){
        if (x == data || x == NULL) {
            x = NULL;

            cout << indent << data << endl;
            if (children.size() > 0)
                indent += "     ";

            for (int i = 0; i < children.size(); i++)
                children[i]-> displayBranch(x, indent);
        }
        else {
            for (int i = 0; i < children.size(); i++)
                children[i]->displayBranch(x, indent);
        }
    };

    void removeChild(type x){
        for (int i = 0; i < children.size(); i++) {
            if (children[i]->data == x) {
                children.erase(children.begin() + i);
            }
        }
    };

    Node* findNode(type x){
        if (this->data == x)return this;

        Node *temp = NULL;
        //cout << data << endl;
        for(int i = 0; i < children.size(); i++){
            temp = children[i]->findNode(x);
            if(temp != NULL)return temp;
        }
        return temp;
    };

private:
    type data;
    Node* parent = NULL;
    vector<Node*> children;
};

#endif // NODE_H
