#include <cstdio>
#include <cstring>

using namespace std;

const int LEN = 10000;

int main()
{
    char a[LEN];
    char b[LEN];
    bool hash[256];
    //fgets(a, LEN, stdin);
    //fgets(b, LEN, stdin);
    gets(a);
    gets(b);
    int lena = strlen(a);
    int lenb = strlen(b);
    for (int i = 0; i < lenb; i++) {
        hash[b[i]] = true;
    }
    for (int i = 0; i < lena; i++) {
        if (hash[a[i]] == false) {
            printf("%c", a[i]);
        }
    }
}