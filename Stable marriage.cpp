#include<bits/stdc++.h>
using namespace std;

int prefer[205][105];
int wPartner[105];
bool mPartner[105];
int N;

bool wpreference(int w, int m, int m1)
{
    for (int i = 1; i <= N; i++)
    {
        if(prefer[w][i] == m1) return true;

        else if(prefer[w][i] == m) return false;
    }
}

void stableMarriage()
{
    memset(wPartner, -1, sizeof(wPartner));
    memset(mPartner, 0, sizeof(mPartner));

    int freeCount = N;

    while (freeCount > 0)
    {

        int m;
        for (m = 1; m <= N; m++)
            if (mPartner[m] == false)
                break;

        for (int i = 1; i <= N && mPartner[m] == false; i++)
        {
            int w = prefer[m][i];

            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mPartner[m] = true;
                freeCount--;
            }

            else
            {
                int m1 = wPartner[w-N];

                if (wpreference(w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mPartner[m] = true;
                    mPartner[m1] = false;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) printf(" (%d %d)",wPartner[i], i+N);

}

int main()
{
   // freopen("in.txt", "r", stdin);

    int test, cs = 0;

    cin>>test;

    while(test--)
    {

        scanf("%d", &N);

        for(int i = 1; i<=2*N; i++)
        {
            for(int j = 1; j<=N; j++)   scanf("%d", &prefer[i][j]);
        }
        printf("Case %d:", ++cs);
        stableMarriage();
        puts("");
    }

    return 0;
}



