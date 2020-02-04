/*
        Topological Sort With DFS
#include "bits/stdc++.h"
using namespace std;
const int N=3e3+3;
int head[N] , nxt[N] , to[N] , visited[N] ,ne , n , m ;
vector<int>toposort;
#define neighbors(u , e , v) for(int e=head[u] , v; v=to[e] , ~e ; e=nxt[e])
void init()
{
    memset(head , -1 , sizeof head);
    ne=0;
}
void addEdge(int f , int t)
{
    to[ne]=t , nxt[ne]=head[f] , head[f]=ne++;
}
void DFS(int u)
{
    visited[u] = true;
    neighbors(u , e , v)
        if (!visited[v])
            DFS(v);
   toposort.push_back(u);
}
void topological_sort()
{
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            DFS(i);
    for(int i=toposort.size()-1;i>=0;--i)
        printf("%d " , toposort[i]+1);
}
int main()
{
    freopen("input.txt" , "r" , stdin);
    scanf("%d%d", &n , &m);
    init();
    while(m--)
    {
            int a , b;
            scanf("%d%d" , &a , &b);
            addEdge(--a , --b);
    }
    topological_sort();
}
*/
        //Topological Sort BFS
#include <bits/stdc++.h>

using namespace std;
#define neighbors(u , e ,v) for(int e=head[u] , v ; v=to[e] , ~e ; e=nxt[e])
const int N = 2e4 + 5, M = 2e6 + 5, OO = 0x3f3f3f3f;

int ne, head[N], nxt[M], to[M], in[N];
int n, m, a, b;

struct cmp{
	bool operator () (const int & a, const int & b) const{return a>b;}
};

void addEdge(int f, int t){
	nxt[ne] = head[f];
	to[ne] = t;
	in[t]++;
	head[f] = ne++;
}

void init(){
	memset(head, -1, n*sizeof head[0]);
	ne = 0;
}
vector<int> result;

void BFS()
{
	queue<int>q;
	for(int i = 0 ; i < n ; ++i)
		if(!in[i])
                q.push(i);
	while(!q.empty())
        {
		int u = q.front();
		result.push_back(u);
		q.pop();
		neighbors(u , e , v)
			if(!--in[v])
				q.push(v);
		}
}

int main(){
	scanf("%d %d", &n, &m);
	init();
	for(int i = 0 ; i < m ; ++i){
		scanf("%d %d", &a, &b);
		addEdge(a, b);
	}
	BFS();
			for(auto x:result)
                printf("%d " ,x);
}

/*
input
7 9
0 2
1 2
2 4
1 4
4 5
4 6
3 5
3 6
5 6
*/
