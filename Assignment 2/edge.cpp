#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
bool dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if(leaderA==leaderB)
    {
        return false;
    }
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }

    return true;
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    
    int count=0;

    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;

        if(!dsu_union_by_size(a,b))
        {
            count++;
        }
    }

    cout<<count<<endl;
  
    return 0;
}
