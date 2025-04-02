#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int prim(int x)
{
    if(x < 2)
        return 0;
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0)
            return 0;
    return 1;
}

int contorizare(int y)
{
    if(!y)
        return 0;
    return 1 - y % 10 % 2 + contorizare(y / 10);
}

int n, a[21][21], ans, p;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            fin >> a[i][j];
            if(prim(a[i][j]))
            {
                int c = contorizare(a[i][j]);
                if(c > p)
                {
                    ans = a[i][j];
                    p = c;
                }
                else if(c == p && a[i][j] < ans)
                    ans = a[i][j];
            }
        }
    if(ans)
        fout << ans << "\n" << p;
    else
        fout << "nu exista";    

    fin.close();
    fout.close();
    return 0;
}