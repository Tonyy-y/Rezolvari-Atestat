#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void interschimbL(int a[21][21], int n, int k1, int k2)
{
    for(int i = 1; i <= n; ++i)
    {
        int aux = a[k1][i];
        a[k1][i] = a[k2][i];
        a[k2][i] = aux;
    }
}

void interschimbC(int a[21][21], int n, int c1, int c2)
{
    for(int i = 1; i <= n; ++i)
    {
        int aux = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = aux;
    }
}

int n, a[21][21];

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            fin >> a[i][j];
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(a[i][i] > a[j][j])
            {
                interschimbC(a, n, i, j);
                interschimbL(a, n, i, j);
            }
    for(int i = 1; i <= n; ++i, fout << "\n")
        for(int j = 1; j <= n; ++j)
            fout << a[i][j] << " ";

    fin.close();
    fout.close();
    return 0;
}