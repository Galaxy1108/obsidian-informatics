#include<bits/stdc++.h>
#define int long long
using namespace std;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1;
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
signed main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int T=fread();
	while(T--)
	{
		int S=fread(),K=fread();
		if(S%2==1)
		{
			if(K>S/2)
			{
				cout<<-1<<endl;
			}
			else
			cout<<K*2<<endl;
		}
		else
		{
			if(K>=S/2)
			{
				cout<<-1<<endl;
			}
//			else
//			{
//				if(S/2%2)
//				{
//					int fir=S/2;
//					if(fir%2) fir+=2;
//					else fir+=1;
//					if(K<=S/4)
//					{
//						cout<<fir+(K-1)*2<<endl;
//					 } 
//					 else if(K==S/4+1)
//					 {
//					 	cout<<S/2-1<endl;
//					 }
//					 else
//					 if(k<=)
//				}
//			}
		}
	}
	return 0;
 } 
