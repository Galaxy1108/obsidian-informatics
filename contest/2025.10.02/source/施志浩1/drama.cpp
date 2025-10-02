#include<iostream>
#include<queue>
using namespace std;
using ll=unsigned long long;
int n,h[2000001],mx,mn;
priority_queue<ll> ansq,gc;
int main()
{
	ios::sync_with_stdio(0);
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	for(int i=1;i<=n;i++)
	{
		mx=h[i],mn=h[i];
		for(int j=i;j>=1;j--)
		{
			if(h[j]>mx)
				mx=h[j];
			if(h[j]<mn)
				mn=h[j];
			gc.push(mx*(i-j+1)*mn);
		}
		ansq.push(gc.top());
	//	cout<<gc.top()<<" ";
		while(gc.size())
		{
			gc.pop();
		}
	}
	cout<<ansq.top();
	return 0;
}
/*
9 
5 11 15 17 19 3 19 9 4 

*/
