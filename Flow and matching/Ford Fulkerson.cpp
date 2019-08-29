#include<bits/stdc++.h>
using namespace std;

const int mx = 105;

int par[mx];
int graph[mx][mx];
int rGraph[mx][mx];
bool vis[mx];
int n;

bool bfs(int s, int t)
{

    memset(vis, 0, sizeof(vis));
    memset(par, -1, sizeof(par));
    queue <int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=1; v<=n; v++)
        {
            if (vis[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                par[v] = u;
                vis[v] = true;
            }
        }
    }

    return (vis[t] == true);
}


int fordFulkerson(int s, int t)
{

    memset(rGraph, 0, sizeof(rGraph));

    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
             rGraph[u][v] = graph[u][v];


    int max_flow = 0;

    while (bfs(s, t))
    {
        int path_flow = INT_MAX;

        for (int v = t; v != s; v = par[v])
        {
            int u = par[v];

            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = par[v])
        {
            int u = par[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }


    return max_flow;
}


int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        memset(graph, 0, sizeof(graph));

        scanf("%d", &n);

        int s, t, c;

        scanf("%d %d %d", &s, &t,&c);

        while(c--)
        {
            int u, v, w;

            scanf("%d %d %d", &u, &v, &w);

            graph[u][v] += w;
            graph[v][u] += w;

        }

        int res = fordFulkerson(s, t);

        printf("Case %d: %d\n", ++cs, res);

    }

    return 0;
}

