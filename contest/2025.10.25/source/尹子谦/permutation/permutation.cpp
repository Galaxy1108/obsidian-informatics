#include<bits/stdc++.h>
using namespace std;
const int N=610,M=1e9+7;
int n,a[N],vis[N];
map<vector<int>,bool> mp;
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int tot=1;
	int tmp[N];	
	cin>>n;
	for(int i=1;i<=2*n;i++)cin>>a[i],tot*=i,tmp[i]=2*n-i+1;
	for(int i=1;i<=tot;i++)
	{
		next_permutation(tmp+1,tmp+2*n+1);
		bool b=1;
		for(int i=1;i<=2*n;i++)
			if(a[i]!=-1&&a[i]!=tmp[i])
			{
				b=0;
				break;
			}
		if(!b) continue;
		vector<int> bb(n+1);
		for(int i=1;i<=n;i++) bb[i]=min(tmp[i*2-1],tmp[2*i]);
		//for(int i=1;i<=n;i++) cout<<bb[i]<<' ';
		//cout<<endl;
		mp[bb]=1;
	}
	cout<<mp.size();
	return 0;
}
/*
5
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
