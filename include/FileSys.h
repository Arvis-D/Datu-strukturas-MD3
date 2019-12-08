#ifndef FILESYS_H
#define FILESYS_H
#include <string>
using namespace std;

class FileSys
{
    public:
        FileSys(int, string, bool = false);
        virtual ~FileSys();
        bool isFile(){return file;};
        bool operator == (const FileSys); // operatoru parslogosana
        bool operator != (const FileSys);
        friend ostream &operator<<(ostream &, const FileSys);
        //istream operator >>)
    private:
        int id;
        string name;
        bool leaf;
        bool file;
};
#endif // FILESYS_H
