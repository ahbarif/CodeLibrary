#include<bits/stdc++.h>
using namespace std;

long long a[100], b[100], n;

long long modInverse(long long a, long long m)
{
    long long m0 = m, t, q;
    long long x0 = 0LL, x1 = 1LL;

    if (m == 1)    return 0;

    while (a > 1)
    {
        q = a / m;

        t = m;

        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }


    if (x1 < 0)   x1 += m0;

    return x1;
}

long long solve()
{
    long long product = 1LL, res = 0, i;

    for (i = 0; i<n; i++) product *= a[i];

    for (i = 0; i<n; i++)
    {
        long long tmp = product / a[i];

       // cout<<tmp<<" "<<a[i]<<" "<<modInverse(tmp, a[i])<<endl;

        res += b[i] * modInverse(tmp, a[i]) * tmp;
    }

    return res % product;

}


int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%lld", &n);

        for(int i = 0; i<n; i++)    scanf("%lld %lld", &a[i], &b[i]);

        printf("Case %d: %lld\n", ++cs, solve());
    }

    return 0;
}
