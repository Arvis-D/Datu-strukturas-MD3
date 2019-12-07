#ifndef FILESYS_H
#define FILESYS_H
#include <string>
using namespace std;

class FileSys
{
    public:
        FileSys(int, string, bool = false);
        virtual ~FileSys();

        bool operator == (const FileSys);
        bool operator != (const FileSys);
        friend ostream &operator<<(ostream &os, FileSys a){
            os << a.id;
            return os;
        }
        //istream operator >>)
    private:
        int id;
        string name;
        bool leaf;
        bool file;
};
#endif // FILESYS_H
