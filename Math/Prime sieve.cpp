void sieve()
{
    mark[1] = true;

    for (int i=4; i<sz; i+=2)    mark[i] = true;

    for (int p=3; p<=sz; p+=2)
    {
        if (mark[p] == false)
        {
            for (int i = 2*p; i<sz; i += p)
            {
                mark[i] = true;
            }
        }
    }
}
