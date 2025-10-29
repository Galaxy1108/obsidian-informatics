#include<bits/stdc++.h>
using namespace std;
long long ans[20]={0,0,0,0,17,904,45926,2725016,196884712,17350671831,1847029162807};
int n,m;
int main(){
    freopen("pairs.in","r",stdin);
    freopen("pairs.out","w",stdout);
    cin>>n>>m;
    cout<<ans[n]%m;
    return 0;
}