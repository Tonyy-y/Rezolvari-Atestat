#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void prefixe(char s[])
{
    for(int i = 1; i <= strlen(s); ++i, fout << " ")
        for(int j = 0; j < i; ++j)
            fout << s[j];
}

void sufixe(char s[])
{
    for(int i = strlen(s) - 1; i >= 0; --i)
        fout << s + i << " ";
}

char s[50][31];
int Max, Min, MaxI, MinI, n;

int main()
{
    fin >> s[0];
    Max = Min = strlen(s[0]);
    while(fin >> s[++n])
    {
        int size = strlen(s[n]);
        if(size >= Max)
        {
            Max = size;
            MaxI = n;
        }
        if(size < Min)
        {
            Min = size;
            MinI = n;
        }
    }
    fout << s[MinI] << " ";
    prefixe(s[MinI]);
    fout << "\n" << s[MaxI] << " ";
    sufixe(s[MaxI]);

    fin.close();
    fout.close();
    return 0;
}