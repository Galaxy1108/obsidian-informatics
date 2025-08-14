#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int T,p,b,ary[50],av[N];
bool pd(int k,int ez)
{
	int anslt=0;
	int cnt=0,fez=ez;
	while(fez)
	{
		ary[++cnt]=fez%b;
		fez/=b;
	}
	int az=0;
	for(int s=0;s<=cnt/k+(cnt%k>0);s++)
	{
		int num;
		int L=s*k+1,R=min(cnt,L+k-1);
		int z=0;
		for(int i=R;i>=L;i--)
		{
			z*=b;
			z+=ary[i];	
		}
		if(s%2==0)
		{
			az*=b;
			az+=z%p;
		}
		else
		{
			az*=b;
			az+=(p-z%p)%p;
		}
	}
	if(az%p==0)return false;
	else return true;
}
signed main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	cin>>T>>p;
	srand(time(0));
	while(T--)
	{
		for(int i=1;i<=p;i++)av[i]=false;
		int anslt=0;
		cin>>b;
		for(int i=1;i<=1000;i++)
		{
			int cy=(rand()*rand()+rand()*13+7)*p;
			for(int i=1;i<p;i++)av[i]|=pd(i,cy);
		}			
		for(int i=1;i<p;i++)
			if(!av[i])
			{
				anslt=i;
				break; 
			}
		if(anslt)cout<<anslt<<endl;
		else cout<<-1<<endl;
	}	
	
	return 0;
} 
