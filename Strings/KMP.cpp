#include<bits/stdc++.h>
using namespace std;

int lps[1000005];
char a[1000005], b[1000005];

void computeLPSArray(char *pat, int M)
{

    int len = 0, i = 1;

    lps[0] = 0;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


int KMPSearch(char *txt, char *pat)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int res = 0;

    computeLPSArray(pat, M);

    int i = 0;
    int j  = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
         //   printf("Found pattern at index %d \n", i-j);
            ++res;
            j = lps[j-1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0) j = lps[j-1];

            else i = i+1;
        }
    }

    return res;
}



int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%s %s", &a, &b);

        printf("Case %d: %d\n", ++cs, KMPSearch(a, b));
    }

    return 0;
}

