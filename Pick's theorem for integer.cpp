#include<bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 x[10005], y[10005];

i64 polygonArea(int n)
{
    i64 area = 0;

    int j = n - 1;

    for (int i = 0; i < n; i++)
    {
        area += (x[j] + x[i]) * (y[j] - y[i]);
        j = i;
    }

    return abs(area / 2);
}

i64 getBoundaryCount(int n)
{
    i64 sum = n;
    x[n] = x[0];
    y[n] = y[0];

    for(int i = 0; i<n; i++)
    {
        int p = i;
        int q = i+1;
        sum += __gcd(abs(x[p] - x[q]), abs(y[p] - y[q]))-1;
    }

    return sum;
}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n;

        scanf("%d", &n);

        for(int i = 0; i<n; i++) scanf("%lld %lld", &x[i], &y[i]);

        i64 A = polygonArea(n);

        i64 B = getBoundaryCount(n);

    //    cout<<A<<" "<<B<<endl;

        i64 res = 1 + A - B/2;

        printf("Case %d: %lld\n", ++cs, res);

    }

    return 0;
}

