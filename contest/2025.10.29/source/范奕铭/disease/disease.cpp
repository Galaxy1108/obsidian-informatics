#include<bits/stdc++.h>
using namespace std;
int N,P;
vector<int>q[100005];
int main()
{
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    cin>>N>>P;
    for(int i=1;i<=P;i++){
        int i,j;
        cin>>i>>j;
        q[i].push_back(j);
        q[j].push_back(i);
    }
    cout<<N-P;
    return 0;
}
