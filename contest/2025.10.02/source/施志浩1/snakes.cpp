#include<iostream>
#include<deque>
//#include<map>
using namespace std;
struct she{
	int no,w;
};
int t,n,k,x,y,val;
deque<she> a;
/*inline bool chi(const she& djb,const she& xjb)
{
	if(djb.w>xjb.w)
		return true;
	if(djb.w==xjb.w&&djb.no>xjb.no)
		return true;
	return false;
}
inline int ef(int l,int r,const she& yq)
{
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(chi(yq,a[mid]))
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
inline bool check(const deque<she> jiancha)
{
	if(jiancha.size()==1)
		return true;
	if(jiancha.size()==2)
		return false;
	she wei=jiancha.back();
	jiancha.pop_back();
	wei.w-=jiancha.front().w;
	if(chi(jiancha.back()))
}*/
inline void solve()
{
	deque<she> q=a;
/*	map<int,int> jilu;
	int cnt=0;
	while(*/
	if(q[2].w-q[0].w>=q[1].w)
	{
		cout<<"1"<<'\n';
	}
	else
	{
		cout<<"3"<<'\n';
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a.push_back({i,x});
	}
	solve();
	while(--t)
	{
		cin>>k;
		while(k--)
		{
			cin>>x>>y;
			a[x-1].w=y;
		}
		solve();
	}
	return 0;
}
/*
2 
3 
11 14 14  
3 
1 5 2 6 3 25

*/ 
 
