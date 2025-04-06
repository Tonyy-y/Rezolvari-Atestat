#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int radacina(int v[], int n)
{
    for(int i = 1; i <= n; ++i)
        if(!v[i])
            return i;
    return 0;
}

void construieste(int v[], int n, int a[101][101])
{
    for(int i = 1; i <= n; ++i)
        a[i][v[i]] = a[v[i]][i] = 1;
}

int n, v[101], a[101][101];

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
        fin >> v[i];
    fout << radacina(v, n) << "\n";
    construieste(v, n, a);
    for(int i = 1; i <= n; ++i, fout << "\n")
        for(int j = 1; j <= n; ++j)
            fout << a[i][j] << " ";

    fin.close();
    fout.close();
    return 0;
}