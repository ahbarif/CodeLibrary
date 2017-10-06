int par[505];

struct edge
{
    int u, v, w;

    edge() {}
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }

    bool operator<(const edge &p)const{
        return w<p.w;
    }
};


void makeset(int n){
    par[n] = n;
}

int find_par(int n){
    if (par[n]==n) return n;
    par[n]=find_par(par[n]);
	return par[n];
}

void union_(int x, int y)
{
    int u = find_par(x);
    int v = find_par(y);

    if(u==v)    return;
    par[u] = v;
}

int main()
{

    vector<edge> E;
    int n, m, x, y, z, i;

    for(i=0; i<505; i++)    makeset(i);

    scanf("%d %d", &n, &m);

    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &x, &y, &z);

        E.push_back(edge(x, y, z));
    }

    sort(E.begin(), E.end());

    for(i=0; i<E.size(); i++)
    {
            x = E[i].u;
            y = E[i].v;
            z = E[i].w;

            if(find_par(x)==find_par(y))    continue;
            else
            {
                union_(x, y);
                g[x].push_back(y);
                g[y].push_back(x);
                cost[x].push_back(z);
                cost[y].push_back(z);
            }
    }
