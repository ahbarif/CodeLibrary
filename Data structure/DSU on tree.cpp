#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 100005;
typedef pair<int, int> pii;
 
int sz[maxn], res[maxn];
int cnt[maxn], color[maxn], ck[maxn];
bool heavy[maxn];
 
vector<int> g[maxn];
vector<pii> query[maxn];
 
void countSize(int u, int par, int dep){
 
    sz[u] = 1;
    for(auto v: g[u]){
        if(v != par){
            countSize(v, u, dep+1);
            sz[u] += sz[v];
        }
    }
}
 
void add(int u, int par, int x){
 
  
    cnt[color[u]] += x;
    ck[ cnt[color[u]] ] += x;

    for(auto v:g[u]){
        if(v!= par && !heavy[v]){
            add(v, u, x);
        }
    }
 
}
 
void dfs(int u, int par, bool keep){
 
    int mx = -1, heavyChild = -1;
 
    for(auto v : g[u]){
        if(v==par) continue;
 
        if(sz[v]>mx){
            mx = sz[v];
            heavyChild = v;
        }
    }
 
    for(auto v : g[u]){
        if(v != par && v != heavyChild){
            dfs(v, u, 0);
        }
    }
 
    if(heavyChild != -1)    {
        dfs(heavyChild, u, 1);
        heavy[heavyChild] = 1;
    }
 
    add(u, par, 1);
 
    for(auto vv : query[u])  {
        res[vv.second] = ck[vv.first];
    }
 
    if(heavyChild != -1) heavy[heavyChild] = 0;
 
    if(keep == 0){
        add(u, par, -1);
    }
 
}
 

int main(){
 
    int n, m, x, y, v, k;
 
    scanf("%d %d", &n, &m);
 
    for(int i = 1; i<=n; i++) scanf("%d", &color[i]);
 
    for(int i = 1; i<n; i++){
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    for(int i = 1; i<=m; i++) {
        cin>>v>>k;
        query[v].push_back(make_pair(k, i));
 
    }
 
    countSize(1, -1, 0);
    dfs(1, -1, 0);
 
    for(int i = 1; i<=m; i++) printf("%d\n", res[i]);
 
    return 0;
}
