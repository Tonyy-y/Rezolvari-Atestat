#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int nrlit(char s[])
{
    int c = 0;
    for(int i = 0; i < strlen(s); ++i)
        if(isupper(s[i]))
            ++c;
    return c;
}

void trans(char s[])
{
    s[0] = toupper(s[0]);
    for(int i = 1; i < strlen(s); ++i)
        s[i] = tolower(s[i]);
}

int n, c;
char s[21];

int main()
{
    fin >> n;
    fin.get();
    for(int i = 1; i <= n; ++i)
    {
        fin >> s;
        c += nrlit(s);
        trans(s);
        fout << s << " ";
    }
    fout << "\n" << c;

    fin.close();
    fout.close();
    return 0;
}