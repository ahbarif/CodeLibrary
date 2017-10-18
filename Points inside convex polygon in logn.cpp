#include<bits/stdc++.h>
using namespace std;

typedef long long i64;

struct point
{

    i64 x, y;

    point() {}

    point(int x, int y) : x(x), y(y) {}

} a[100005];

i64 orientation(point a, point b, point c) // triangle area
{

    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y);

}

bool binarySearch(point qp, int n)
{

    int lo = 1, hi = n-1, mid;

    while((hi-lo) > 1)
    {

        mid = (hi+lo)/2;

        if(orientation(a[0], a[mid], qp) < 0) hi = mid;

        else lo = mid;

    }

    if(orientation(a[0], a[lo], qp)  < 0) return false;

    if(orientation(a[lo], a[hi], qp) < 0) return false;

    if(orientation(a[hi], a[0], qp)  < 0) return false;

    return true;

}

int main()
{

    int test, cs = 0;

    cin>>test;

    while(test--)
    {

        int n;

        scanf("%d", &n);

        for(int i = 0; i<n; i++) scanf("%lld %lld", &a[i].x, &a[i].y);

        int q;

        cin>>q;

        printf("Case %d:\n", ++cs);

        while(q--)
        {
            point tmp;

            scanf("%lld %lld", &tmp.x, &tmp.y);

            if(binarySearch(tmp, n)==true) puts("y");

            else puts("n");
        }


    }

    return 0;

}

