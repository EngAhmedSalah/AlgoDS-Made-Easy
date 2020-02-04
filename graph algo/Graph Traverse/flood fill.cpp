#include "bits/stdc++.h"
using namespace std;
int SD()
{
    int x ;
    scanf("%d", &x) ;
    return x;
}
int dr[] = {-1, -1, -1, 0, 0, 1, 1,1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int visited[101][101], n, m;
char grid[101][101];
int floodFill(int r, int c)
{
    if(r < 0 || r > n || c < 0 || c > m || visited[r][c] || grid[r][c] != 'W')
        return 0;
    visited[r][c] = 1;
    int ans = 1;
    for(int i = 0 ; i < 8 ; ++i)
        ans += floodFill(r+dr[i], c + dc[i]);
    return ans;
}
int main()
{
    int t = SD() ;
    while(t--)
    {
        memset(visited , 0 , sizeof visited);
        memset(grid , 0 , sizeof grid);
        int i = 0;
        char s[101];
        for(i = 0 ; ; ++i)
        {
            scanf("%s", &s);
            int Size = strlen(s);
            if(!isalpha(s[0]))
                break;
            for(int j = 0 ; j < Size ; ++j)
                grid[i][j] = s[j];
        }
        n = i;
        m = strlen(grid[0]);

        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < m ; ++j)
                if(grid[i][j] == 'W')
                    printf("%d\n", floodFill(i, j));
    }
}
/*
input 
1
LLLLLLLLL
LLWWLLWLL
LWWLLLLLL
LWWWLWWLL
LLLWWWLLL
LLLLLLLLL
LLLWWLLWL
LLWLWLLLL
LLLLLLLLL

*/