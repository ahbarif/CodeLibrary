ll segmented_sieve(ll a, ll b)
{
	bool mark[b-a+10];

	memset(mark, 0, sizeof(mark));

	ll i, j;

	for(i = 0; i<prime.size(); i++)
	{
		ll st = prime[i] * ((a + prime[i]-1) / prime[i]);

		for(j=st; j<=b; j+=prime[i])	if(j!=prime[i]) mark[j-a] = true;
	}

	ll res = 0;

	for(i=a; i<=b; i++)
	{
		if(mark[i-a]==false && i!=1)	++res;
	}

	return res;
}