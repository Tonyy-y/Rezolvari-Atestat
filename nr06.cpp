#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void construire(int v[], int& n)
{
    int x;
    while(fin >> x)
        if(100 <= x && x <= 999)
            v[++n] = x;
}

int cautare(int v[], int n, int x)
{
    int left = 1, right = n;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(v[mid] == x)
            return mid;
        else if(v[mid] > x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int n, v[101], x;

int main()
{
    construire(v, n);
    cin >> x;
    int c = cautare(v, n, x);
    if(c != -1)
        fout << c;
    else
        fout << "nu exista";

    fin.close();
    fout.close();
    return 0;
}