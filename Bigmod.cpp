
template<class T> inline T bigmod(T a, T b, T mod)
{
    T ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%mod;        a = (a*a)%mod;        b = b>>1;
    }
    return ans%mod;
}