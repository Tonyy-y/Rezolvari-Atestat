#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int verif(int x)
{
    while(x)
    {
        if(x % 10 % 2)
            return 0;
        x /= 10;
    }
    return 1;
}

void modif(int& x)
{
    int a = 0, c = 1;
    while(x)
    {
        int cf = x % 10;
        if(cf % 2 == 0)
            cf /= 2;
        a = cf * c + a;
        c *= 10;
        x /= 10;
    }
    x = a;
}

int n, v[101];

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        if(verif(v[i]))
            modif(v[i]);
        fout << v[i] << " ";
    }

    fin.close();
    fout.close();
    return 0;
}