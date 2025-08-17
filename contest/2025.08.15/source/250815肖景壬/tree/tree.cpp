#include<bits/stdc++.h>
using namespace std;
int n,fa1[100005],fa2[100005],a[100005],xx;
vector<int> v1[100005],w1[100005],v2[100005];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	while(n--) cout<<"0 ";
	return 0;
	
	for(int i = 2; i <= n; i++)
	{
		cin>>fa1[i];
		v1[i].push_back(fa1[i]);
		v1[fa1[i]].push_back(i);
	}
	for(int i = 2; i <= n; i++)
	{
		cin>>xx;
		w1[i].push_back(xx);
		w1[fa1[i]].push_back(xx);
	}
	for(int i = 2; i <= n; i++)
	{
		cin>>fa2[i];
		v2[i].push_back(fa2[i]);
		v2[fa2[i]].push_back(i);
	}
	
}
