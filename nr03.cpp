#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void inversareCifre(int& x)
{
    int a = 0, c = 1;
    while(x > 10)
    {
        a = a * 10 + x % 10;
        c *= 10;
        x /= 10;
    }
    x = x * c + a;
}

int nrDivizori(int x)
{
    int c = 2, i = 2;
    for(i = 2; i * i < x; ++i)
        if(x % i == 0)
            c += 2;
    if(i * i == x)
        ++c;
    return c;
}

int n, v[101], ok;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        if(nrDivizori(v[i]) > 4)
        {
            ok = 1;
            inversareCifre(v[i]);
        }
    }
    if(!ok)
        fout << "nu au fost facute modificari";
    else for(int i = 1; i <= n; ++i)
        fout << v[i] << " ";

    fin.close();
    fout.close();
    return 0;
}