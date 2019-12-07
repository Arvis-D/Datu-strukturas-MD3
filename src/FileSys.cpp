#include "FileSys.h"
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
