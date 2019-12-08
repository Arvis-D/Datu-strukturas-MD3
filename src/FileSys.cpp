#include "FileSys.h"
#include <iostream>
using namespace std;

FileSys::FileSys(int idx, string namex, bool filex)
{
    id = idx;
    name = namex;
    file = filex;
}

FileSys::~FileSys()
{
    //dtor
}

bool FileSys::operator!=(const FileSys x){
    return (id != x.id ? true : false);
}

bool FileSys::operator==(const FileSys x){
    return (id == x.id ? true : false);
}

ostream &operator<<(ostream &os, const FileSys a){
    os << a.id << ". " << a.name << " " << (a.file ? "(fails)" : "(katalogs)");
    return os;
}
