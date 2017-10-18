#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define ff first
#define ss second

int lcm(int a, int b)
{
    int gcd = __gcd(a, b);

    return (a*b)/gcd;

}

pii subtract(pii a, pii b)
{
    int denominator = lcm(a.ss, b.ss);

    int n1 = a.ff*(denominator/a.ss);
    int n2 = b.ff*(denominator/b.ss);

    int numerator = n1-n2;

    return make_pair(numerator, denominator);

}

void f(pii n)
{


    int g = (n.ss + n.ff - 1)/(n.ff);

    cout<<1<<"/"<<g;

    pii tmp = subtract(n, make_pair(1, g));

    if(tmp.ff == 0 || tmp.ss == 0) return;

    cout<<" + ";

    f(tmp);

}
int main()
{

    pii n;

    scanf("%d/%d", &n.ff, &n.ss);

    puts("The egyptian fraction representation is: \n");

    f(n);

    puts("");

    return 0;



}

