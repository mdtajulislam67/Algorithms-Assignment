#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; 

bool valid(int x, int y)
{

    if (x >= 0 && x < n && y >= 0 && y < m && (graph[x][y] == '.' || graph[x][y]=='B' ) && vis[x][y]==false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool bfs(int si, int sj, int ei, int ej)
{

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {

        pair<int, int> node = q.front();
        q.pop();
        int nrow = node.first;
        int ncol = node.second;

        if(nrow==ei && ncol==ej)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {

            int ci = nrow + dx[i];
            int cj = ncol + dy[i]; 

            if (valid(ci, cj))
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
    return false;
}

int main()
{

    cin >> n >> m;
    pair<int,int> rstart, rend;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j]=='A')
            {
                rstart={i,j};
            }
            else if( graph[i][j]=='B')
            {
                rend={i,j};
            }
        }
    }

    memset(vis,false,sizeof(vis));

    if (bfs(rstart.first, rstart.second, rend.first, rend.second))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO";
}