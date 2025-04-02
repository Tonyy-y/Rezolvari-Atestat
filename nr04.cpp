#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void sterge(int v[], int& n, int x)
{
    for(int i = 1; i <= n; ++i)
        if(v[i] == x)
        {
            for(int j = i; j < n; ++j)
                v[j] = v[j + 1];
            --n;
            return;
        }
}

int cif(int n)
{
    int x = n % 10 % 2;
    n /= 10;
    while(n)
    {
        if(n % 10 % 2 != x)
            return 0;
        n /= 10;
    }
    return 1;
}

int n, v[101], m;

int main()
{
    fin >> n;
    m = n;
    for(int i = 1; i <= n; ++i)
        fin >> v[i];
    for(int i = 1; i <= n; ++i)
        if(cif(v[i]))
            sterge(v, n, v[i--]);
    if(n == m)
        fout << "nu exista";
    else for(int i = 1; i <= n; ++i)
        fout << v[i] << " ";

    fin.close();
    fout.close();
    return 0;
}