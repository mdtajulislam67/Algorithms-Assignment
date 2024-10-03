#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
map<pair<int, int>, pair<int, int>> par;

int n, m;

char graph[N][N];

bool valid(int ci, int cj)
{

    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
    {
        return true;
    }
    else
        return false;
}

void bfs(int si, int sj)
{
    vis[si][sj] = true;

    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = node.first + dx[i];
            int cj = node.second + dy[i];

            if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] != '#')
            {
                vis[ci][cj] = true;
                par[{ci, cj}] = {node.first, node.second};
                q.push({ci, cj});
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    memset(vis, false, sizeof(vis));

    pair<int,int> start, dest;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'R') 
            { 
                start = {i, j}; 
            } 
            else if (graph[i][j] == 'D') 
            { 
                dest = {i, j};
            }
        }
    }
    bfs(start.first,start.second);

    if (vis[dest.first][dest.second])
    {

        int xi = dest.first;
        int xj = dest.second;

        while (par.find({xi,xj}) != par.end())
        {
            pair<int,int> parent = par[{xi, xj}];

            if (graph[parent.first][parent.second] != 'D' && graph[parent.first][parent.second] != 'R')
            {
                graph[parent.first][parent.second] = 'X';
            }
            xi = parent.first;
            xj = parent.second;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }

    cout << endl;
}