#include <iostream>

#include <Node.h>

using namespace std;

int main() {
    Node root(0, "user");
    root.addNode(1, 0, "Downloads");
    root.addNode(2, 0, "Documents");
    root.addNode(3, 0, "Pictures");
    root.addNode(4, 0, "Music");
    root.addNode(5, 1, "sdf823f8hdf.jpg", true);
    root.addNode(6, 1, "keys.txt", true);
    root.addNode(7, 2, "ligums.docx", true);
    root.addNode(8, 2, "10.12.2019");
    root.addNode(9, 8, "asdasd.docx", true);
    root.addNode(10, 8, "rekins.pdf", true);

    root.displayBranch();
    cout << endl << endl;

    string name = "";
    int rootId = 0;
    bool file = false;
    int id = 0;
    string number = "";
    string command = "";
    bool error;
    int x = 0;

    while (command != "$") {
        error = false;
        number = "";
        cout << "ludzu ievadiet komandu: ";
        cin >> command;
        cout << endl;
        if (command == "*") {
            root.displayBranch();
            cout << endl;
            continue;
        }
        if (command[0] == '*') {
            for (int i = 1; i < command.size(); i++) {

                number += command[i];
            }
            id = stoi(number);
            root.displayBranch(id);
            cout << endl;
            continue;
        }
        if (command[0] == '-') {
            for (int i = 1; i < command.size(); i++) {
                number += command[i];
            }
            id = stoi(number);
            root.deleteNode(id);
            continue;
        }
        if (command[0] == '+') { //Pareizs formats ir "+x,y"
            for (int i = 1; i < command.size(); i++) { // no komandas tiek izvilkti x un y skaitli, tad pieskirti punktam b un punkta b kopija tiek ielikta rinda
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
            if(!root.addNode(id, rootId, name, file))cout << "shads fails jau eksiste vai nav tada mezgla" << endl;
            x = 0;
            continue;
        }
        if (command == "$") break;
        cout << "Kludaina komanda, ludzu meginiet velreiz" << endl; // Jebkuras ievades kludas gadijuma
    }
}
