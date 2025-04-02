#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int vocale(char prop[])
{
    int c = 0;
    for(int i = 0; i < strlen(prop); ++i)
        if(strchr("aeiou", prop[i]))
            ++c;
    return c;
}

void cuvant(char prop[], char cuv[])
{
    int Max = 0;
    for(char* p = strtok(prop, " "); p; p = strtok(nullptr, " "))
        if(strlen(p) > Max)
        {
            strcpy(cuv, p);
            Max = strlen(p);
        }
}

int n;
char prop[256], s[256];

int main()
{
    fin >> n;
    fin.get();
    for(int i = 1; i <= n; ++i)
    {
        fin.getline(prop, 256);
        char cuv[256];
        cuvant(prop, cuv);
        strcat(s, cuv);
        strcat(s, " ");
    }
    fout << s << "\n";
    int c = vocale(s);
    if(c)
        fout << c;
    else
        fout << "fara vocale";

    fin.close();
    fout.close();
    return 0;
}