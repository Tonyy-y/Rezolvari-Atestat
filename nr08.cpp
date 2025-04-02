#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int inftr(int a[21][21], int n)
{
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(a[i][j])
                return 0;
    return 1;
}

int produs(int a[21][21], int n)
{
    if(!n)
        return 1;
    return a[n][n] * produs(a, n - 1);
}

int a[21][21], n;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            fin >> a[i][j];
    if(inftr(a, n))
        fout << "da\n" << produs(a, n);
    else
        fout << "nu\nnedeterminat";

    fin.close();
    fout.close();
    return 0;
}