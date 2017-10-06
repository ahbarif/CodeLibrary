#include<stdio.h>
#include<string.h>
using namespace std;

const int N = 50005;



long long a[N], tree[4*N], MOD = 1000000007LL;

void construct(int node, int lo, int hi)
{

    if(lo==hi)
    {
        tree[node] = a[lo];
        return;
    }

    int Left  = 2*node;
    int Right = Left + 1;
    int mid   = (lo+hi)>>1;

    construct(Left, lo, mid);
    construct(Right, mid+1, hi);

    tree[node] = tree[Left] * tree[Right];
    tree[node] %= MOD;


}

long long query(int node, int lo, int hi, int i, int j)
{
    if(i>hi || j<lo)    return 1;

    if(i<=lo && j>=hi)  return tree[node];

    int left  = 2*node;
    int right = left + 1;
    int mid   = (lo+hi)>>1;

    long long x = 1, y = 1;

    x = query(left, lo, mid, i, j);
    y = query(right, mid+1, hi, i, j);

    return (x*y)%MOD;
}

void update(int node, int lo, int hi, int i, long long val)
{

    if(i>hi || i<lo)    return;

    if(lo==hi)
    {
        tree[node] = val;
        return;
    }

    int left  = 2*node;
    int right = left + 1;
    int mid   = (lo+hi)>>1;


    update(left, lo, mid, i, val);

    update(right, mid+1, hi, i, val);

    tree[node] = tree[left] * tree[right];

    tree[node] %= MOD;

}

int main()
{

    int T, C;

    scanf("%d", &T);

    for(C=1; C<=T; C++)
    {
        memset(a, 0, sizeof a);
        memset(tree, 0, sizeof tree);

        int n, q, t, x, y, i;

        scanf("%d", &n);

        for(i=1; i<=n; i++) scanf("%lld", &a[i]);

        construct(1, 1, n);

        scanf("%d", &q);

        while(q--)
        {
            scanf("%d", &t);

            if(t==1)
            {
                int k;
                long long p;

                scanf("%d", &k);

                scanf("%lld", &p);

                update(1, 1, n, k, p);
            }

            else
            {
                scanf("%d %d", &x, &y);

                printf("%lld\n", query(1, 1, n, x, y));
            }


        }

    }

    return 0;
}
