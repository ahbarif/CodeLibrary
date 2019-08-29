
ll bigmod(ll a, ll b, ll mod)
{
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;        
	b = b>>1;
    }
    return ans%mod;
}
