#include "bits/stdc++.h"
using namespace std;
#define neigbours(u, e, v) for(int e = head[u], v ; v = to[e], ~e ; e = nxt[e]) //v = to[e], ~e  will assign to[e] to v in each loop instead of opening {}
const int N = 2e5+5, M = 4e4 + 5;
int n, m;
queue<int> q;
int  visited[N], d[N], p[N];     //p(n) which stores for each vertex the vertex from which we reached it
vector<vector<int>> adj(N);                //d(n) which stores the current layer that I have visit now
void BFS(int u)
{
    int ans=1;
    q.push(u);                  //push the first node in the queue
    visited[u] = true;          //mark the first node as visited
    p[u] = -1;                  //the node that I come from is myself so mark it with -1
    while (!q.empty())
    {
        int v = q.front();      //the current node
        q.pop();                //pop the current node
        for (int u : adj[v])    //get the neighbors of the current node
            if (!visited[u])    //if the neighbor is not visited then visit it , else it mean that node is not belongs to this graph
            {
                visited[u] = true;  //remark it ass visited if it is not visited
                q.push(u);          //push it in the queue
                ++ans;
                d[u] = d[v] + 1;    //save the current layer in the tree to know which layer I work
                p[u] = v;           //save the node that I come from
            }
    }
}
int ConnectedCom(int n)
{
    int ans=0;
    for(int i=0; i<n; ++i)
    {
        if(!visited[i])
            ++ans;
        BFS(i);
    }
    return ans;
}
int main()
{
    int n , m , ans = 0;
    scanf("%d%d" , &n , &m);
    while(m--)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%d\n",ConnectedCom(n));
}
/*
int ne, head[N], nxt[M], to[M],  visited[N], n, m, a, b;
void addEdge(int FROM, int TO)
{
    to[ne] = TO;
    nxt[ne]=head[FROM];
    head[FROM]=ne++;
}
void addBiEdge(int a,int b)
{
    addEdge(a,b);
    addEdge(b,a);
}
void initialize_head_with_mins1()
{
    memset(head, -1, sizeof head);      //5ally balak enak law 3awez tgeb el connected componnent f hat3alem kol el head be -1
    memset(head, -1, n*sizeof head[0]);//laken 7ena 7aytla3lak bug 3alashan el node elly mesh fe elconnected componnent mesh 7atkon =-1 ya3ny 3addad el neighbours bto37a = garbage
    ne = 0;
}
void DFS(int u)
{
    visited[u]=1;
    neigbours(u , e , v)
        if(!visited[v])
            DFS(v);
}
int ConnectedCom(int n)
{
    int ans=0;
    for(int i=0; i<n; ++i)
    {
        if(!visited[i])
            ++ans;
        DFS(i);
    }
    return ans;
}
int main()
{
    initialize_head_with_mins1();
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addBiEdge(a,b);
    }
    printf("%d\n",ConnectedCom(n));
}
/*
const int N = 100000;
vector<int> adj[N];
bool visited[N];
void dfs(int p)
{
    visited[p]=1;
    for(auto x : adj[p])
        if(!visited[x])
        dfs(x);
}
int ConnectedCom(int n)
{
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(!visited[i])
            ++ans;
            dfs(i);
    }
    return ans;
}

int main()
{
    int n , m , ans = 0;
    scanf("%d%d" , &n , &m);
    while(m--)
    {
        int u = SD() , v=SD();
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    printf("%d\n",ConnectedCom(n));
}
*/
