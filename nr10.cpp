#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void fibo(int n, int& x)
{
    int a = 0, b = 1, c;
    while(true)
    {
        c = a + b;
        if(c > n)
        {
            x = b;
            return;
        }
        a = b;
        b = c;
    }
}

int divprim(int a)
{
    for(int i = 2; i * i <= a; ++i)
        if(a % i == 0)
        {
            int c = 0;
            for(int j = 2; j * j <= i; ++j)
                if(i % j == 0)
                    ++c;
            if(!c)
                return i;
        }
    return a;
}

int n, m, a[21][21], s, c, x;

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            fin >> a[i][j];
            fibo(a[i][j], x);
            if(a[i][j] == x && divprim(a[i][j]) == a[i][j])
            {
                s += a[i][j];
                ++c;
            }
        }
    if(c)
        fout << (float) s / c;
    else
        fout << "nu exista";

    fin.close();
    fout.close();
    return 0;
}