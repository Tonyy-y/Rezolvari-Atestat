#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

struct complexi
{
    float a, b;
} v[26];

float modul(complexi x)
{
    return sqrt(x.a * x.a + x.b * x.b);
}

complexi suma(complexi x, complexi y)
{
    complexi z;
    z.a = x.a + y.a;
    z.b = x.b + y.b;
    return z;
}

int n, c;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
        complexi z;
        fin >> z.a >> z.b;
        float aux = modul(z);
        if(aux == (int)aux)
            v[++c] = z;
    }
    if(!c)
        fout << "nu exista";
    else
    {
        for(int i = 1; i <= c; ++i)
            v[0] = suma(v[0], v[i]);
        fout << v[0].a << " " << v[0].b;
    }

    fin.close();
    fout.close();
    return 0;
}