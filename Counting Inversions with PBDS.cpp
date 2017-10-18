#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> st;
map<string, int> mp;

int a[30005];

void getInversionCount(int n)
{
    st.clear();

    for(int i = 0; i<n; i++) st.insert(a[i]);

    int res = 0;

    for(int i = 0; i<n; i++)
    {
        int t = st.order_of_key(a[i]);
        res += t;
        st.erase(a[i]);
    }

    printf("%d\n", res);
}

int main()
{

   
        for(int i = 0; i<n; i++) a[i] = nxt();

        getInversionCount(n);

}
