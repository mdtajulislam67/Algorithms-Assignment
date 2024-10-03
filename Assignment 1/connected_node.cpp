#include <bits/stdc++.h>
using namespace std;
vector<int> mat[1001];
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(mat[x].empty())
        {
            cout<<"-1"<<endl;
        }
        else{
            vector<int> v= mat[x];
            sort(v.rbegin(),v.rend());
            for(int val : v)
            {
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }

    
    return 0;
}