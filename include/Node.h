#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
using namespace std;

class Node
{
    public:
        Node(int, string, bool = false);
        virtual ~Node();
        bool addNode(int, int, string, bool = false);
        bool deleteNode(int = NULL);
        void displayBranch(int = NULL, string = "");
        void removeChild(int);
        int getId(){return id;};
        Node* findById(int);

    private:
        int id;
        int rootId;
        bool isLeaf = true;
        bool isFile;
        string data;
        string name;
        Node *parent = NULL;
        vector <Node*> children;
};

#endif // NODE_H
