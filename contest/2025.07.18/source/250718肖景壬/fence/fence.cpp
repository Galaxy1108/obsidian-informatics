#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,h[100005],w[100005],now[100005],nowsz,nowxx;
int sumw[100005],sumwh[100005];
int finans=0,noww;
const int XaoWa118=1000000007,quad=1000000008/4,hal=1000000008/2;
signed main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>h[i];
	for(int i = 1; i <= n; i++) cin>>w[i];
	bool isok=0;
	for(int i = 1; i <= n; i++)
	{
		sumw[i]=(sumw[i-1]+w[i])%XaoWa118;
		sumwh[i]=(sumwh[i-1]+w[i]*((h[i]*h[i-1]/2)%XaoWa118)%XaoWa118);
		if(h[i]>2) isok=1;
		//cout<<sumwh[i]<<endl;
	}
	if(isok==1)
	{
		for(int i = 1; i <= n; i++)
		{
			//1.删除以前的信息
			//2.计算答案
			//3.记录信息
			//cout<<"i:"<<i<<endl;
			int l=1,r=nowsz,ans=0,mid;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(h[now[mid]]>h[i])
				{
					r=mid-1;
				}
				else
				{
					ans=mid;
					l=mid+1;
				}
			}
			noww+=(((((h[i]*(h[i]+1))%XaoWa118)*((w[i]*(w[i]+1))%XaoWa118))%XaoWa118)*quad)%XaoWa118;
			
			//cout<<"ans:"<<ans<<endl;
			//cout<<"noww:"<<noww<<endl;
			
			if(i>1&&h[i]<h[i-1])
			{
				//cout<<"Sp"<<i<<endl;
				nowxx-=(sumwh[i-1]-sumwh[now[ans]]);
				//cout<<"nowxx "<<nowxx<<endl;
				nowxx%=XaoWa118;
				nowxx+=XaoWa118;
				nowxx%=XaoWa118;
				int nowhh=h[i]-h[now[ans]];
				nowxx+=(nowhh*(nowhh+1))*(sumw[i-1]-sumw[now[ans]]);
				nowxx%=XaoWa118;
			}
			//cout<<"nowxx "<<nowxx<<endl;
			noww+=nowxx*w[i];
			noww%=XaoWa118;
			
			nowxx+=(((h[i]*(h[i]+1)/2)%XaoWa118)*w[i])%XaoWa118;
			//cout<<"nowxx2 "<<nowxx<<endl;
			nowsz=ans+1;
			now[nowsz]=i;
		}
		cout<<noww<<endl;
	}
	else
	{
		int finaa=sumw[n],comb=0;
		for(int i = 1; i <= n; i++)
		{
			if(h[i]==2) comb++;
			else
			{
				finaa+=2*comb;
				comb=0;
			}
		}
		finaa+=2*comb;
		cout<<finaa<<endl;
	}
}
