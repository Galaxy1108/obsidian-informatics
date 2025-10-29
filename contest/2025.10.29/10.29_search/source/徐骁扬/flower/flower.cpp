#include <bits/stdc++.h>
using namespace std;
int n,i;
string flo[41];
int num[90];
bool abl[90],hav_ans;
void dfs(int dep)
{
	if(hav_ans) return;
	if(dep==0) 
	{
		hav_ans=true;
		for(i=1;i<=2*n;i++)
			cout<<flo[num[i]]<<",";
		return;
	}
	for(int i=1;i+dep<2*n;i++)
	{
		if(abl[i]||abl[i+dep+1]) continue;
		abl[i]=abl[i+dep+1]=true;
		num[i]=num[i+dep+1]=dep;
		dfs(dep-1);
		abl[i]=abl[i+dep+1]=false;
		num[i]=num[i+dep+1]=0;
	}
	return;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>flo[i];
	dfs(n);
	return 0;
}
