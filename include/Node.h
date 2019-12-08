#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

using namespace std;

template <class type>
class Node
{
public:
    Node<type>(type* x){
        data = x;
    };
    ~Node(){
        //deleteNode();
    }
    Node* addNode(type* x, type* n = NULL){
        Node* temp = new Node(x);

        if(n != NULL){
            Node * found = findNode(n);
            if(found != NULL){
                found->children.push_back(temp);
                temp->parent = found;
            }
            else return NULL;

            return temp;
        }

        temp->parent = this;
        children.push_back(temp);
        return temp;
    };

    bool deleteNode(type* x = NULL){ // izdzes mezglu, ja ir padots type mainigais atrod berna mezglu un zid
            if(x != NULL){
            Node * temp = findNode(x);
            if(temp != NULL){
                temp->deleteNode();
                return true;
            }
            else return false;
        }
        for(int i = 0; i<children.size(); i++){
            children[i]->deleteNode();
        }
        if(parent != NULL)parent->removeChild(data);
        delete data;
        delete this;
        return true;
    };

    bool displayBranch(type* x = NULL, string indent = ""){
        if (x != NULL) {
            Node* temp = findNode(x);
            if(temp != NULL){
                temp->displayBranch();
                return true;
            }
            else return false;
        }
        cout << indent << *data << endl;
        if (children.size() > 0)
        indent += "     ";
        for (int i = 0; i < children.size(); i++)
            children[i]-> displayBranch(x, indent);
        return true;
    };

    Node* findNode(type* x){
        if (*data == *x)return this;

        Node *temp = NULL;
        //cout << data << endl;
        for(int i = 0; i < children.size(); i++){
            temp = children[i]->findNode(x);
            if(temp != NULL)return temp;
        }
        return temp;
    };
    type* getData(){
        return data;
    }

private:
    void removeChild(type* x){
        for (int i = 0; i < children.size(); i++) {
            if (children[i]->data == x) {
                children.erase(children.begin() + i);
            }
        }
    };

    type* data;
    Node* parent = NULL;
    vector<Node*> children;
};

#endif // NODE_H
