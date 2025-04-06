#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void nrElem1(int n, int v[], int& s)
{
    s = 0;
    for(int i = 1; i <= n; ++i)
        s += v[i];
}

int sumaElem(int n, int a[31][31])
{
    int s = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            s += a[i][j];
    return s;
}

int n, a[31][31], x, y, Min = 1e9;

int main()
{
    fin >> n;
    while(fin >> x >> y)
        a[x][y] = a[y][x] = 1;
    for(int i = 1; i <= n; ++i)
    {
        int s;
        nrElem1(n, a[i], s);
        if(s < Min)
            Min = s;
    }
    for(int i = 1; i <= n; ++i)
    {
        int s;
        nrElem1(n, a[i], s);
        if(s == Min)
            for(int j = 1; j <= n; ++j)
                a[i][j] = a[j][i] = 0;
    }
    fout << sumaElem(n, a) / 2;

    fin.close();
    fout.close();
    return 0;
}