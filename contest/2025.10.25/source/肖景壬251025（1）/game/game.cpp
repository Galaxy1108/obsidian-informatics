#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[2000005],n,maxx,maxid,secmax,cur,cur2,cur3;
bool flg;
long long ans; 
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		b[a[i]]++;
		if(a[i]>maxx)
		{
			maxx=a[i];
			maxid=i;
		}
	}
	if(n==1)
	{
		cout<<(a[1]+1)/2;
		return 0;
	}
	a[maxid]=0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i]>secmax) secmax=a[i];
	}
	a[maxid]=maxx;
	//cout<<maxx<<" "<<secmax<<endl;
	for(int i = 1; i <= 1000000; i++) b[i]+=b[i-1];
	for(int d = 1; d <= 1000000; d++)
	{
		if(d>maxx) break;
		if(maxx/d>(secmax/d+1)) continue;
		if(maxx/d==(secmax/d+1))
		{
			//cout<<"dflknlkjbfdlkwreakj"<<endl;
			if((secmax/d)==0)
			{
				//cout<<"sd";
				ans++;
				continue;
			}
			//cout<<d<<" "<<maxx/d<<" "<<maxx/d*d+d-1<<" "<<b[secmax/d*d+d-1]<<" "<<b[max(secmax/d*d-1,0)]<<endl;
			if((b[secmax/d*d+d-1]-b[max(secmax/d*d-1,0)])&1==1) ans++;
		}
		else
		{
			//cout<<"deakj"<<endl;
			cur=n-b[secmax/d*d-1]-1;
			//cout<<cur<<" "<<d<<" "<<maxx/d<<endl;
			//if(cur&1==0) ans++;
			if(maxx/d==2)
			{
				cur2=n-b[d-1]-2,cur3=n-b[2*d-1]-1;
				if(cur2&1==1||cur3&1==1) flg=0;
				else flg=1;
			}
			else if((secmax/d)>2)
			{
				cur2=n-b[(maxx/d-1)*d-1];
				if(cur2&1==1) flg=1;
				else flg=0; 
			}
			else
			{
				//cout<<"sdaf";
				flg=0;
			}
			//cout<<cur<<flg<<" "<<(cur&1==0)<<endl;
			if(((cur&1)==0)&&flg==0) ans+=(cur+1);
		}
	}
	cout<<ans<<endl;
}
