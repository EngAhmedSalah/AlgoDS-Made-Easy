#include "bits/stdc++.h"
using namespace std;
const int N=1e5+5;
#define neighbours(u , e , v) for(int e=head[u] , v ; v=to[e]  , ~e ; e=nxt[e])
int ne, head[N], nxt[N], to[N],  color[N], parent[N],cycle_start, cycle_end,  n, m, a, b;
void addEdge(int FROM, int TO)
{
    to[ne] = TO;
    nxt[ne]=head[FROM];
    head[FROM]=ne++;
}
void initialize_head_with_mins1()
{
    memset(head, -1, n*sizeof head[0]);
    memset(parent, -1, n*sizeof parent[0]);
    ne = 0;
}
bool DFS(int u)
{
    color[u]=1;               //remark the first node with color 1 (in process)
    neighbours(u, e, v)
    {
        if(color[v]==1)       //it means that have been visited before
        {
            cycle_end=u, cycle_start=v;
            return true;
        }
        else if(color[v]==0)
        {
            parent[v]=u;
            if(DFS(v))
                return true;
        }
    }
    color[u]=2;
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    initialize_head_with_mins1();
    while(m--)
    {
        scanf("%d%d", &a, &b);
        addEdge(--a, --b);
    }
    cycle_start=-1;
    for(int i=0; i<n; ++i)
        if(DFS(i))
            break;
    if(-1 == cycle_start)
        puts("Asyclic");
    else
    {
        puts ("Cyclic");
        vector<int>cycle_path;
        cycle_path.push_back(cycle_start);
        for(int i=cycle_end; i!=cycle_start; i=parent[i])
            cycle_path.push_back(i);
        for(int i=cycle_path.size(); i>=0; --i)
            printf("%d ", cycle_path[i]+1);
    }
}
/*
Cycle
5 7
1 2
2 3
3 6
4 1
5 4
5 2
3 5
Acyclic
5 5
0 1
1 2
2 3
0 3
1 4

*/
