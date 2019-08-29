// Number of divisors
template<class T> inline T NOD(T n)
{
    T i, p = 0, ans = 1;

    if(n%2==0)
        while(n%2==0) n = n>>1, p++;

    ans*= (p+1);

    for(i=3; i*i<=n; i+=2){
        if(n%i==0){
            p = 0;
            while(n%i==0) n/=i, ++p;
            ans*=(p+1);
    }}

    return (n>1?ans*2:ans);
}

//SOD
template<class T> inline T SOD(T n)
{
    T i, ans = 1, tmp = 1;

    if(n%2==0){
        while(n%2==0) n = n>>1, tmp*=2;
        ans = ans*((tmp*2 - 1)/(2-1)));
    }

    for(i=3; i*i<=n; i+=2){
        if(n%i==0){
            tmp = 1;
            while(n%i==0) n/=i, tmp*=i;
            ans = ans*((tmp*i - 1)/(i-1));
    }}

    if(n>1) ans = ans*((n*n - 1)/(n-1));
    return ans;
}
