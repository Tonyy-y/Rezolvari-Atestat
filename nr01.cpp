#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int p_cifra(int y)
{
    if(y < 10)
        return y;
    return p_cifra(y / 10);
}

void sortare(int v[], int n)
{
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(v[i] < v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

int v[101], n, m, x, cf;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
        fin >> x;
        cf = p_cifra(x);
        if(cf == 1 || cf == 4 || cf == 9)
            v[++m] = x;
    }
    if(!m)
        fout << "nu exista";
    else
    {
        sortare(v, m);
        for(int i = 1; i <= m; ++i)
            fout << v[i] << " ";
    }

    fin.close();
    fout.close();
    return 0;
}