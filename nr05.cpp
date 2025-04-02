#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void citeste(float v[], int& n)
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
        fin >> v[i];
}

float pozmax(float v[], int p1, int p2)
{
    float Max = v[p1], j = p1;
    for(int i = p1 + 1; i <= p2; ++i)
        if(v[i] > Max)
            Max = v[i], j = i;
    return j;
}

int n;
float v[101];

int main()
{
    citeste(v, n);
    for(int i = 1; i <= n; ++i)
    {
        int p = pozmax(v, i, n);
        float aux = v[p];
        v[p] = v[i];
        v[i] = aux;
        fout << v[i] << " ";
    }

    fin.close();
    fout.close();
    return 0;
}