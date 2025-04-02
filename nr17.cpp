#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void construieste(char s[])
{
    char p[201];
    fin.getline(p, 201);
    strcpy(s, p);
    strcat(s, " ");
    while(fin.getline(p, 201))
    {
        strcat(s, p);
        strcat(s, " ");
    }
}

void decodifica(char s[])
{
    char vocale[] = "aeiou";
    for(int i = 0; i < strlen(s); ++i)
        if(isalnum(s[i]))
        {
            if(isdigit(s[i]))
                s[i] = vocale[s[i] - '0'];
            else ++s[i];
        }
}

char s[201];

int main()
{
    construieste(s);
    fout << s << "\n";
    decodifica(s);
    fout << s;

    fin.close();
    fout.close();
    return 0;
}