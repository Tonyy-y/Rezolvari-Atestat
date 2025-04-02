#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void elimColoana(int& n, int a[22][22], int k)
{
    for(int j = k; j < n; ++j)
        for(int i = 1; i <= n; ++i)
            a[i][j] = a[i][j + 1];
    --n;
}

int cifreImpare(int x)
{
    while(x)
    {
        if(x % 10 % 2 == 0)
            return 0;
        x /= 10;
    }
    return 1;
}

int a[22][22], n, m;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            fin >> a[i][j];
    m = n;
    for(int j = 1; j <= n; ++j)
    {
        int c = 0;
        for(int i = 1; i <= n; ++i)
            c += cifreImpare(a[i][j]);
        if(c == j)
        {
            elimColoana(m, a, j);
            break;
        }
    }
    if(n == m)
        fout << "matrice nemodificata";
    else for(int i = 1; i <= n; ++i, fout << "\n")
        for(int j = 1; j <= m; ++j)
            fout << a[i][j] << " ";
    
    fin.close();
    fout.close();
    return 0;
}