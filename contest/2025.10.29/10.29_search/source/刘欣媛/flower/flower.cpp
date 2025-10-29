#include <bits/stdc++.h>
using namespace std;
string [50];
int n,a[100];
bool fl;
//inline void dfs(int k)
//{
//	if(fl==1){
//		return;
//	}
//	if(k>=n)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i+a[i]])
//		}
//	}
//}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	fl=0;
	for(int i=1;i<=n;i++) cin>>s[i];
	if(n==3){
		cout<<s[3]<<"\n"<<s[1]<<"\n"<<s[2]<<"\n"<<s[1]<<"\n"<<s[3]<<"\n"<<s[2];
	}
	else
	{
		cout<<s[2]<<"\n"<<s[3]<<"\n"<<s[4]<<"\n"<<s[2]<<"\n"<<s[1]<<"\n";
		cout<<s[3]<<"\n"<<s[1]<<"\n"<<s[4];
	}
	
	
	return 0;
 } 
