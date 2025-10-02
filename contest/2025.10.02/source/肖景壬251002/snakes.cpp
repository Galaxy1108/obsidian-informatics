#include<bits/stdc++.h>
using namespace std;
struct pp
{
	int num,id;
};
pp p[1000005],tmp,mx,mn;
bool operator<(const pp& xx,const pp& yy)
{
	if(xx.num!=yy.num) return xx.num<yy.num;
	return xx.id<yy.id;
}
bool operator>(const pp& xx,const pp& yy)
{
	if(xx.num!=yy.num) return xx.num>yy.num;
	return xx.id>yy.id;
}
deque<pp> dq1,dq2,emp;
int n,a[1000005],k,t,x,y,ans;
bool isdel[1000005];
int main()
{
	cin>>t;
	while(t--)
	{
		if(t==1)
		{
			cin>>n;
			for(int i = 1; i <= n; i++) cin>>a[i];
		}
		else
		{
			cin>>k;
			for(int i = 1; i <= n; i++)
			{
				cin>>x>>y;
				a[x]=y;
				isdel[i]=0;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			p[i].num=a[i];
			p[i].id=i;
		}
		for(int i = 1; i < n; i++)
		{
			cout<<"att "<<i<<endl;
			if(i==n-1)
			{
				cout<<1<<endl;
				break;
			}
			mx.num=-100000000;
			mn.num=100000000;
			for(int j = 1; j <= n; j++)
			{
				if(!isdel[j]&&mx<p[j]) mx=p[j];
				if(!isdel[j]&&mn>p[j]) mn=p[j];
			}
			cout<<mx.num<<" "<<mx.id<<" "<<mn.num<<" "<<mn.id<<endl;
			mx.num-=mn.num;
			isdel[mn.id]=1;
			bool flg=1;
			for(int j = 1; j <= n; j++)
			{
				if(!isdel[j]&&mx>p[j])
				{
					flg=0;
					break;
				}
			}
			if(flg)
			{
				cout<<n-i+1<<endl;
				break;
			}
			p[mx.id].num-=p[mn.id].num;
		}
	}
}
