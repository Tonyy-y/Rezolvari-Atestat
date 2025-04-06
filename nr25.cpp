#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void citire(int a[21][21], int& n)
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            fin >> a[i][j];
}

int suma(int v[], int k)
{
    int s = 0;
    for(int i = 1; i <= k; ++i)
        s += v[i];
    return s;
}

int n, a[21][21], ok;

int main()
{
    citire(a, n);
    for(int i = 1; i <= n; ++i)
        if(suma(a[i], n) == 0)
            fout << i << " ", ok = 1;
    if(!ok)
        fout << "nu există noduri izolate";

    fin.close();
    fout.close();
    return 0;
}