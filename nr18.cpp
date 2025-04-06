#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void citire(char s[31][101], int& n)
{
    fin >> n;
    for(int i = 0; i < n; ++i)
        fin >> s[i];
}

int stergere(char s[], char c)
{
    int cnt = 0;
    for(int i = 0; i < strlen(s); ++i)
        if(s[i] == c)
            strcpy(s + i, s + i + 1), ++cnt;
    return cnt;
}

char s[31][101];
int n, ok;

int main()
{
    citire(s, n);
    for(int i = 0; i < strlen(s[0]); ++i)
    {
        int c = 0;
        for(int j = 1; j < n; ++j)
            if(stergere(s[j], s[0][i]))
                ++c;
        if(c == n - 1)
            fout << s[0][i] << " ";
    }

    fin.close();
    fout.close();
    return 0;
}