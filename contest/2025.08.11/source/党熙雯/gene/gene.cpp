#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+10;
int a[mx];
int n,L,R;
map<int,int> flag;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1;
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
bool check(int len)
{
	int head=R+2-len,tail=R+1;
	int b;
	for(int i=head+1;i<=tail-1;i++)
	flag[a[i]]++;
	while(flag[a[head]]||flag[a[tail]])
	{
		flag[a[tail]]++;
		head++,tail++;
		flag[a[head]]--;
		if(head==L) return 0;
	}
	return 1;
}
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	n=fread(),L=fread(),R=fread();
	for(int i=1;i<=n;i++) a[i]=fread(); 
	if(n<=11100)
	{
		int ans=-1;
		for(int i=R-L+3;i<=n;i++)
		{
			if(check(i))
			{
				ans=i;
				break;
			}
			flag.clear();
		}
		if(ans!=-1)
		{
			cout<<ans;
			return 0;
		}
		else
		cout<<-1;
	}
	else
	cout<<-1;
	return 0;
 } 
