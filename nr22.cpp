#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

struct punct
{
    float x, y;
} v[101];

float distanta(punct a, punct b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

float arie(punct a, punct b)
{
    return abs(a.x - b.x) * abs(a.y - b.y);
}

int n, m, mi, mj;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
        fin >> v[i].x >> v[i].y;
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(v[i].x != v[j].x && v[i].y != v[j].y)
            {
                float A = arie(v[i], v[j]);
                if(A > m)
                {
                    m = A;
                    mi = i;
                    mj = j;
                }
            }
    fout << m << " " << mi << " " << mj;

    fin.close();
    fout.close();
    return 0;
}