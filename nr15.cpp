#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int verif(char s[])
{
    int c[strlen(s)] = {0};
    c[0] = strchr("aeiou", s[0]) == nullptr;
    for(int i = 1; i < strlen(s); ++i)
    {
        c[i] = strchr("aeiou", s[i]) == nullptr;
        if(c[i] + c[i - 1] == 2)
            return 1;
    }
    return 0;
}

int nrvoc(char s[])
{
    int c = 0;
    for(int i = 0; i < strlen(s); ++i)
        if(strchr("aeiou", s[i]))
            ++c;
    return c;
}

char s[101];
int ok;

int main()
{
    fin.getline(s, 101);
    for(char* p = strtok(s, " "); p; p = strtok(nullptr, " "))
        if(verif(p) && nrvoc(p) >= 3)
            fout << p << "\n", ok = 1;
    if(!ok)
        fout << "nu exista";

    fin.close();
    fout.close();
    return 0;
}