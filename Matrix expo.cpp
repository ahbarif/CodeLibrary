#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long i64;
 
struct Matrix
{
    i64 r, c, a[20][20];
 
    Matrix()
    {
        memset(a, 0,sizeof(a));
    }
 
    Matrix(i64 n, i64 m)
    {
        r = n;
        c = m;
        memset(a, 0,sizeof(a));
    }
 
    Matrix(i64 n)
    {
        r = c = n;
        memset(a, 0, sizeof(a));
    }
 
    Matrix operator * (Matrix b)
    {
        Matrix res(r, b.c);
 
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<b.c; j++)
            {
                i64 temp = 0;
 
                for(int k=0; k<c; k++)
                {
                    temp = (temp + (a[i][k]*b.a[k][j]));
                }
                res.a[i][j] = temp;
            }
        }
        return res;
    }
 
    Matrix operator ^(i64 n)
    {
        Matrix res(r);
        res.identity();
        Matrix p(r, c);
        for(int i = 0; i<r; i++)
            for(int j=0; j<c; j++)  p.a[i][j] = a[i][j];
 
        while(n)
        {
            if( n & 1 ) res = res * p;
            p = p * p;
            n >>= 1;
        }
 
        return res;
    }
 
    void identity()
    {
        memset(a, 0, sizeof(a));
        for(int i=0; i<20; i++) a[i][i] = 1;
    }
 
};
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        i64 p, q, n;
 
        cin>>p>>q>>n;
 
        Matrix a(2);
 
        a.a[0][0] = p;
        a.a[0][1] = -q;
        a.a[1][0] = 1;
        a.a[1][1] = 0;
 
        a = a^(n-1);
 
        i64 ff = a.a[0][0] * p;
        i64 ss = a.a[0][1] * 2;
       
        i64 res = ff+ss;
       
        if(n==0)    res = 2;
 
        cout<<"Case "<<++cs<<": "<<res<<endl;
    }
 
 
    return 0;
 
}
