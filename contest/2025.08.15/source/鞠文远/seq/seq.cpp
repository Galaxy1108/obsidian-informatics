#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],m;
vector<vector<int>>vec;
vector<int>b,lc;
void dfs(int pos)
{
	if(pos==n+1){if(lc.size())vec.push_back(lc);return;}
	lc.push_back(a[pos]);dfs(pos+1);
	lc.pop_back();dfs(pos+1);
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1,x;i<=m;i++){cin>>x;b.push_back(x);}
	dfs(1);sort(vec.begin(),vec.end());unique(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)if(vec[i]==b){cout<<i+1;break;}
	
	return 0;
} 
