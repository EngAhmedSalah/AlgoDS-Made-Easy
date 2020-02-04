#include "bits/stdc++.h"
using namespace std;
const int AKA = 1e6 + 6 , N = 1e6 + 6;
vector<vector<int> > adj(N);
int parent[AKA] , color[AKA] , cycle_start , cycle_end;
bool DFS(int u)
{
	color[u] = 1;
	for(auto v : adj[u])
	{
		if(!color[v])
		{
			parent[v] = u;
			DFS(v);
		}
		else if(color[v] && parent[u] != v)
		{
			cycle_start = v , cycle_end = u;
			return true;
		}
	}
	color[u] = 2;
	return false;
}
int main()
{
	int n , m , a , b;
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < m ; ++i)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cycle_start=-1;
    for(int i=1; i <= n; ++i)
        if(DFS(i))
            break;

    if(-1 == cycle_start)
        puts("Asyclic");
    else
    {
        puts ("Cyclic");
        vector<int>cycle_path;
        cycle_path.push_back(cycle_end);
        for(int i=cycle_start; i != cycle_end; i = parent[i])
            cycle_path.push_back(i);
        for(int i= 0 ; i < cycle_path.size(); ++i)
            printf("%d ", cycle_path[i]);
    }
}
