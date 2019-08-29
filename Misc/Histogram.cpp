#include<bits/stdc++.h>
using namespace std;
 
typedef long long i64;
int a[30005];
 
int getMaxArea(int n)
{
 
    a[n] = 0;
    n++;
    stack<int> s;
 
    int res = 0, tp, tmp, i = 0;
 
    while (i < n)
    {
        if (s.empty() || a[s.top()] <= a[i])    s.push(i++);
 
        else
        {
            tp = s.top();
 
            s.pop();
 
            tmp = a[tp] * (s.empty() ? i : i - s.top() - 1);
 
            if (res < tmp)  res = tmp;
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
        int n;
 
        scanf("%d", &n);
 
        for(int i = 0; i<n; i++) scanf("%d", &a[i]);
 
        printf("Case %d: %d\n", ++cs, getMaxArea(n));
    }
 
    return 0;
}

