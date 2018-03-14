#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s1[10000];
    char s2[10000];
    char s[10000];
    //fgets(s1, 10000, stdin);
    //fgets(s2, 10000, stdin);
    gets(s1);
    gets(s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int k = 0;
    for (int i = 0; i < len1; i++) {
        bool flag = false;
        for (int j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                flag = true;
            }
        }
        if (!flag) {
            printf("%c", s1[i]);
        }
    }
}