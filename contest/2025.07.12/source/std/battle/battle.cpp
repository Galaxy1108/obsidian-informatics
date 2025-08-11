#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
typedef pair<int,int> pr;
int n,x[150010],y[150010],z[150010],a,b,c;
bool del[150010];
priority_queue<pr> Qx,Qy,Qz;
int main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	
	n=Qread();
	for(int i=1;i<=n;i++)
	{
		Qx.push(make_pair(x[i]=Qread(),i));
		Qy.push(make_pair(y[i]=Qread(),i));
		Qz.push(make_pair(z[i]=Qread(),i));
	}
	while(!Qx.empty()&&!Qy.empty()&&!Qz.empty())
	{
		a=Qx.top().second,b=Qy.top().second,c=Qz.top().second;
		if(a==b||a==c) del[a]=true;
		else if(b==c) del[b]=true;
		else if(y[a]==y[b]||z[a]==z[c]) del[a]=true;
		else if(x[a]==x[b]||z[b]==z[c]) del[b]=true;
		else if(x[a]==x[c]||y[b]==y[c]) del[c]=true;
		else return printf("%d\n",x[a]+y[b]+z[c]),0;
		while(!Qx.empty()&&del[Qx.top().second]) Qx.pop();
		while(!Qy.empty()&&del[Qy.top().second]) Qy.pop();
		while(!Qz.empty()&&del[Qz.top().second]) Qz.pop();
	}
	printf("-1\n");
	return 0;
}