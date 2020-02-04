//Explanation of DFS & BFS on problem [is it a tree SPOJ]
#include "bits/stdc++.h"
using namespace std;
typedef pair<int , int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define neigbours(u, e, v) for(int e = head[u], v ; v = to[e], ~e ; e = nxt[e]) //v = to[e], ~e  will assign to[e] to v in each loop instead of opening {}
const int N = 2e5+5, M = 4e4 + 5;
/*
                is it a tree SPOJ
        (DFS with adj list coach)
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
    memset(head, -1, n*sizeof head[0]);
    ne = 0;
}

int DFS(int u)
{
    if(visited[u]) return  0;
    visited[u]=1;
    int ans = 1;
    neigbours(u, e, v)
    ans+=DFS(v);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    initialize_head_with_mins1();
    while(m--)
    {
        scanf("%d%d",&a,&b);
        addEdge(--a, --b);
    }
    puts(ne != n-1 || DFS(0) != n ? "NO" : "YES");

}
                is it a tree SPOJ vector of vector
#include "bits/stdc++.h"
using namespace std;
#define neig(u ,e , v) for(int e =head[u] , v ; v = to[e] , ~e ; e = nxt[e])
typedef long long lld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’
const int N = 10000, M = 20000;
int n, m, a, b, visited[M];
vector<vector<int> > adjlist(N);
int DFS2(int u)
{
    if(visited[u])
        return 0;
    visited[u] = 1;
    int ans = 1;
    for(auto v : adjlist[u])
        ans+=DFS2(v);
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m ; ++i)
    {
        scanf("%d%d",&a,&b);
        adjlist[--a].push_back(--b);
    }
    puts(m != n-1 || DFS2(0) != n ? "NO" : "YES");
}

                //(DFS Adj list vector of vector)
vector<vector<int> > AdjList;
bool visited[N];
void DFS(int u)
{
    visited[u]=true;
    for(int i=0;i<AdjList[u].size();++i)
        if(!visited[i])
            DFS(i);
}

        (note: this is not the version on implicit graph)
void floodfill(int u , int color)
{
    visited[u]=color;
    for(int i=0;i<AdjList[i].size();++i)
        if(visited[i]!=color)
            floodfill(i , color);
}
int n, m;
queue<int> q;
int  visited[N], d[N], p[N];     //p(n) which stores for each vertex the vertex from which we reached it
vector<vector<int>> adj(N);                //d(n) which stores the current layer that I have visit now
int BFS(int u)
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
        {
            if (!visited[u])    //if the neighbor is not visited then visit it , else it mean that node is not belongs to this graph
            {
                visited[u] = true;  //remark it as visited if it is not visited
                q.push(u);          //push it in the queue
                ++ans;
                d[u] = d[v] + 1;    //save the current layer in the tree to know which layer I work
                p[u] = v;           //save the node that I come from
            }
            else
                return 0;           //if can not visit it , it mean that node is not belongs to this graph
        }
    }
    return ans;
}

void shorest(int u)         //get the shortest path to reach u node
{
    if (!visited[u])
        cout << "No path!";
    else
    {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])          //v!=-1 because the first node has p[0]=-1
            path.push_back(v);
       printf("Path Size = %d\n" , path.size());
       for(int v=path.size()-1;~v;--v)
            printf("%d ", path[v]);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);                //to solve is it a tree problem put adj[--a].push_back(--b);
    }
    puts(BFS(0) != n ? "NO" : "YES");
    shorest(3);
}
=====================================================================================================
                                Adj List (map of String)
using namespace std;
#include <bits/stdc++.h>
typedef long long lld;
#define MAX 200
#define CFT int ACCEPTED = 1 ;
#define MYT int ACCEPTED = 1000 ;
#define T_ISA ACCEPTED--
#define watch(x) cout << (#x) << " is " << (x) << endl
#define write_to_file() freopen("output.txt","w",stdout);
#define read_from_file() freopen("input.txt","r",stdin);
#define watchSTL(container) {\
	cout << (#container) << " values =  "; \
for (auto _E : container)cout << _E << " "; \
	printf("\n"); \
}
map<string, vector<string> > adj;
map<string, bool> visited;
map<string, int> d;
queue<string>q;
void BFS(string u)
{
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        string v = q.front();
        q.pop();
        for(auto u : adj[v])
            if(!visited[u])
            {
                visited[u] = 1;
                q.push(u);
                d[u] = d[v] + 1;
            }
    }
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s1, s2, s3;
        cin>>s1>>s2>>s3;
        int Size = s1.length();
        for(int i = 0 ; i < Size ; ++i)
            s1[i] = tolower(s1[i]);
        Size = s3.length();
        for(int i = 0 ; i < Size ; ++i)
            s3[i] = tolower(s3[i]);
        cout<<s1<<"   "<<s3<<"\n";
        adj[s3].push_back(s1);
    }
    //BFS(adj["polycarp"]);
    puts("");
    puts("");
    for(auto ii=adj.begin(); ii!=adj.end(); ++ii)
    {
        cout << (*ii).first << ": ";
        vector <string> inVect = (*ii).second;
        for (auto j=0; j<inVect.size(); j++)
        {
            cout << inVect[j] << " ";
        }
        cout << endl;
    }
}
*/
