#include <iostream>
#include <string>
#include "FileSys.h"
#include "Node.h"

using namespace std;

int main() {
    FileSys h(0,"home");
    FileSys a(1, "downloads");
    FileSys b(2, "documents");
    FileSys c(3, "gdfhfg.jpg", true);
    FileSys d(4, "ligumi");
    FileSys f(5, "l1.pdf", true);
    FileSys g(6, "l2.pdf", true);
    FileSys j(7, "pictures");

    Node<FileSys>tree(&h);

    tree.addNode(&a);
    tree.addNode(&b);
    tree.addNode(&j);

    tree.addNode(&c, &a);
    tree.addNode(&d, &b);
    tree.addNode(&f, &d);
    tree.addNode(&g, &d);

    tree.displayBranch();

    cout << endl;
    cout << "Pievienojot mezglu pareizs ievades formats ir '+id,tevaId,vards,tips'" << endl
         << "Dzest: '-id'" << endl
         << "Atelot: '*id' vai '*' lai attelot visu koku" << endl
         << "iziet: $" << endl << endl;

    string name = "";
    int rootId = 0;
    bool file = false;
    int id = 0;
    string number = "";
    string command = "";
    int x = 0;
    FileSys* sample = new FileSys(0, "");
    FileSys* sample2 = new FileSys(0, "");
    Node<FileSys>* n1 = new Node<FileSys>(sample);
    Node<FileSys>* n2 = new Node<FileSys>(sample);

                                                        // lietotaja saskarne
    while (command != "$") {
        x = 0;
        number = "";
        cout << "ludzu ievadiet komandu: ";
        cin >> command;
        cout << endl;
        if (command == "*") {
            tree.displayBranch();
            cout << endl;
            continue;
        }
        if (command[0] == '*') {
            for (int i = 1; i < command.size(); i++) {

                number += command[i];
            }
            id = stoi(number);
            sample = new FileSys(id, "");
            if(!tree.displayBranch(sample))cout << "shads mezgls neeksiste!" << endl;
            cout << endl;
            continue;
        }
        if (command[0] == '-') {
            for (int i = 1; i < command.size(); i++) {
                number += command[i];
            }
            id = stoi(number);
            sample = new FileSys(id, "");
            if(!tree.deleteNode(sample))cout << "shads mezgls neeksiste!" << endl;
            continue;
        }
        if (command[0] == '+') {
            for (int i = 1; i < command.size(); i++) { // no komandas tiek izvilkti parametri, tad pieskirti FileSys objektiem
                if (command[i] == ',') {
                    if (x == 0) {
                        id = stoi(number);
                        number = "";
                    }
                    if (x == 1) {
                        rootId = stoi(number);
                        number = "";
                    }
                    if (x == 2) {
                            //cout << number;
                        name = number;
                        number = "";
                    }
                    x++;
                    continue;
                }
                if (i == command.size()-1) {
                    if (number == "fail") file = true;
                    else file = false;
                }
                number += command[i];
            }
            sample2 = new FileSys(rootId, ""); // pec si objekta tiek atrasts teva mezgls
            sample = new FileSys(id, name, file);
            n1 = tree.findNode(sample2);
            if(n1 != NULL){
                if(n1->getData()->isFile()){
                    cout << "Failam nevar but apaksmezglu!" << endl;
                    continue;
                }
                n2 = n1->findNode(sample);
                if(n2 != NULL){
                    if(sample->isFile() == n2->getData()->isFile()){
                        n2->deleteNode();
                        n1->addNode(sample);
                    }
                    else cout << "Mezgls ar shadu id un atskirigu tipu saja kataloga jau eksiste!" << endl;
                }
                else n1->addNode(sample);
            }
            else cout << "shads mezgls neeksiste!" << endl;
            continue;
        }
        if (command == "$") break;
        cout << "Kludaina komanda, ludzu meginiet velreiz" << endl; // Jebkuras ievades kludas gadijuma
        command = "";
    }
    return 0;
}
