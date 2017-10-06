#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef pair<long long, long long> pii;

template <typename T>

using ordered_set = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

unordered_map<long long, int> id;
ordered_set<pii> segments;
set<long long> points;


int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        long long n, q, x, n1, n2, cur;

        scanf("%lld %lld", &n, &q);

        segments.insert(make_pair(n, ++id[n]));
        points.insert(0);
        points.insert(n);

        printf("Case %d:\n", ++cs);

        while(q--)
        {
            char ss[2];

            scanf("%s", ss);

            if(ss[0]=='C')
            {

                scanf("%lld", &x);

                if(x>n) continue;
                auto it = points.lower_bound(x);
                long long up = *it;
                it--;
                long long down = * it;

                if(up==x||down==x) continue;

                points.insert(x);

                long long cur = up - down;

                int xxx = id[cur];

                segments.erase(make_pair(cur,xxx));

                id[cur]--;

                if(up-x>0)
                {
                    segments.insert(make_pair(up-x,++id[up-x]));
                }
                if(x-down>0)
                    segments.insert(make_pair(x-down,++id[x-down]));

            }

            else
            {
                int k;
                scanf("%d", &k);
                pii temp = *segments.find_by_order(k-1);
                printf("%lld\n",temp.first);

            }
        }

        segments.clear();
        points.clear();
        id.clear();

    }
}
