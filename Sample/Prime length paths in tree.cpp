#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 100010;
const int maxl = 20;
set<int> adj[maxn];
int ndist[maxl][maxn], subSize[maxn];
int primes[maxn], mark[maxn], len;
ll ans;
int nn;

void getSize(int u, int p) {
    subSize[u]=1;
    nn++;
    for(auto v : adj[u]) {
        if(v!=p) {
            getSize(v, u);
            subSize[u] += subSize[v];
        }
    }
}

int getCentroid(int u, int p) {

    for(auto v: adj[u]) {
        if(v != p && subSize[v] > nn/2) {
            return getCentroid(v, u);
        }
    }
    return u;
}

void dfs3(int u,int p,int depth,int dist, int add) {
    ndist[depth][dist] += add;
    for(auto v: adj[u]) {
        if(v != p) {
            dfs3(v, u, depth, dist+1, add);
        }
    }
}

ll dfs4(int u, int p, int depth, int dist) {

    ll ret = 0;
    for(int i=0; i<len; i++) {
        if(primes[i] - dist<0) continue;
        if(!ndist[depth][primes[i]-dist])break;
        if(primes[i]!=dist) ret+=ndist[depth][primes[i]-dist];
        else ret+=2*ndist[depth][primes[i]-dist];
    }

    for(auto v:adj[u]){
        if(v!=p){
            ret += dfs4(v, u, depth, dist+1);
        }
    }

    return ret;
}

void decompose(int root,int depth) {

    nn=0;
    getSize(root,root);
    int centroid = getCentroid(root,root);
    dfs3(centroid,centroid,depth,0,1);
    ll add=0;
    int u=centroid;
    for(auto v : adj[u]) {
        dfs3(v, u, depth, 1, -1);
        add +=  dfs4(v, u, depth, 1);
        dfs3(v, u, depth, 1, 1);
    }
    ans += add/2;
    for(auto v : adj[u]) {
        adj[v].erase(u);
        decompose(v, depth+1);
    }
    for(int i=0; i<maxn && ndist[depth][i]; i++)
        ndist[depth][i]=0;
}
void sieve() {
    for(int i=2; i*i<maxn; i++){
        if(mark[i] == 0){
            for(int j = i*i; j<maxn; j+= i){
                mark[j] = 1;
            }
        }

    }

    for(int i = 2; i<maxn; i++){
        if(!mark[i]) primes[len++] = i;
    }
}

int main() {

    sieve();

    ll n;

    cin>>n;

    for(int i=1; i<n; i++) {
        int u, v;
        scanf("%d %d",&u, &v);
        u--;
	v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    decompose(0,0);

    double den = (n*(n-1))/2.0;
    double neu = 1.0 * ans;
    printf("%0.10lf\n", neu/den);

    return 0;
}
