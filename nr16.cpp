#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int cifra(char c)
{
    return isdigit(c);
}

void numar(int& n, char cif)
{
    n = n * 10 + (cif - '0');
}

int n, fr[10];
char s;

int main()
{
    while(fin >> s)
        if(cifra(s))
        {
            int aux = 0;
            numar(aux, s);
            fr[aux] = 1;
        }
    for(int i = 1; i <= 9; i += 2)
        if(fr[i])
            n = n * 10 + i;
    for(int i = 8; i >= 0; i -= 2)
        if(fr[i])
            n = n * 10 + i;
    if(n)
        fout << n;
    else
        fout << "nu exista";

    fin.close();
    fout.close();
    return 0;
}