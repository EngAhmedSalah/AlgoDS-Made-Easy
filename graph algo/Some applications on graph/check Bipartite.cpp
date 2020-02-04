#include <bits/stdc++.h>
using namespace std;
#define neighbours(u , e , v) for(int e = head[u] , v ; v = to[e] , ~e ; e = nxt[e])
const int N = 2e4 + 5, M = 2e6 + 5, OO = 0x3f3f3f3f;
int ne,  head[N], nxt[M], to[M], color[N];
int  n, m, a, b;
void addEdge(int f, int t)
{
    to[ne]  = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}
void addBiEdge(int a , int b)
{
    addEdge(a , b);
    addEdge(b , a);
}
void init()
{
    memset(head, -1, sizeof head);
    memset(color, -1, sizeof color);
    ne = 0;
}
bool Bipartite(int u)
{
    queue<int>q;
    q.push(u);
    color[u] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        neighbours(u, e, v)
        if(color[v] == -1)
            color[v] = 1 - color[u], q.push(v);
        else if(color[u] == color[v])
            return false;
    }
    return true;
}
int main()
{
    scanf("%d%d" , &n , &m);
    init();
    while(m--)
    {
        scanf("%d%d" , &a , &b);
        addBiEdge(a , b);
    }
    cout<<Bipartite(0);

}
/*
input
6 8
0 2
0 3
0 4
1 2
1 3
1 4
1 5
4 5
0

5 6
0 2
0 3
0 4
1 2
1 3
1 4
1
*/
