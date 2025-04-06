#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

struct fractie
{
    int x, y;
} v[101];

int cmmdc(int a, int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

fractie suma(fractie f, fractie g)
{
    fractie s;
    s.x = f.x * g.y + f.y * g.x;
    s.y = f.y * g.y;
    return s;
}

int n, c;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int x, y;
        fin >> x >> y;
        if(cmmdc(x, y) == 1)
        {
            v[++c].x = x;
            v[c].y = y; 
        }
    }
    if(!c)
        fout << "nu exista";
    else
    {
        v[0].y = 1;
        for(int i = 1; i <= c; ++i)
            v[0] = suma(v[0], v[i]);
        int aux = cmmdc(v[0].x, v[0].y);
        v[0].x /= aux;
        v[0].y /= aux;
        for(int i = 0; i <= c; ++i)
            fout << v[i].x << "/" << v[i].y << "\n"; 
    }

    fin.close();
    fout.close();
    return 0;
}