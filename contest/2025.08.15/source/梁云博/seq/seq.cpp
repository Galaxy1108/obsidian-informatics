#include <bits/stdc++.h>
#define N 1000005
using namespace std;
string a,b;
int n,m;
map<string,int>ma;
void Mobius(int p,string res)
{
	if(p>=a.size())
	{
		if(res.size())ma[res]=1;
		return ;
	}
	string k=res+a[p];
	Mobius(p+1,k);
	Mobius(p+1,res);
	
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ios::sync_with_stdio(nullptr);
    cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		a=a+char(x+'0');
	}
	cin>>m;
	for(int i=1,x;i<=m;i++)
	{
		cin>>x;
		b+=char(x+'0');
	}
	Mobius(0,"");
	int cnt=1;
	for(auto it:ma)
	{
		if(it.first == b)cout<<cnt;
		cnt++;
	}
	return 0;
} 
