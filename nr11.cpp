#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int oglindit(int x)
{
    int a = 0;
    while(x)
    {
        a = a * 10 + x % 10;
        x /= 10;
    }
    return a;
}

void maxim(int a[21][21], int n, int& p)
{
    p = -1;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i][i] == oglindit(a[i][i]) && a[i][i] > p)
            p = a[i][i];
        if(a[i][n + 1 - i] == oglindit(a[i][n + 1 - i]) && a[i][n + 1 - i] > p)
            p = a[i][n + 1 - i];
    }
}

int n, a[21][21], p;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            fin >> a[i][j];
    maxim(a, n, p);
    if(p != -1)
        fout << p;
    else
        fout << "nu exista";

    fin.close();
    fout.close();
    return 0;
}