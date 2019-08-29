const int sz = 10000007;

int phi[sz+5];

void sieve()
{

    for (int i=1; i<=sz; i++)    phi[i] = i;

    for (int p=2; p<=sz; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;

            for (int i = 2*p; i<=sz; i += p)
            {
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }

}

