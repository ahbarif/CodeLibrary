
// finding ap:
void find_articulation_point(int v)
{
    vis[v] = true;
    low[v] = dis[v] = ++timer;

    int u, subtree = 0, i;

    for(i=0; i<g[v].size(); i++)
    {
        u = g[v][i];

        if(vis[u]==false)
        {
            subtree++;
            par[u] = v;
            find_articulation_point(u);

            low[v] = min(low[v], low[u]);

            if(par[v]!=-1 && low[u]>=dis[v])    ap[v] = true;
            if(par[v]==-1 && subtree>1) ap[v] = true;
        }

        else if(u!=par[v])  low[v]=min(low[v],dis[u]);
    }
}

// finding bridge

void dfs(int u, int par)
{
    vis[u] = true;
    low[u] = dis[u] = ++timer;


    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];

        if(vis[v]==false)
        {
            dfs(v, u);

            low[u] = min(low[v], low[u]);

            if(low[v]>dis[u])
            {
                cout<<u<<" "<<v<<endl;
            }
        }

        else if(v!=par)  low[u]=min(low[u],dis[v]);
    }
}
