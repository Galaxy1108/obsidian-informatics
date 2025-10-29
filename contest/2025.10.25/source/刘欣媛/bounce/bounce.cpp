#include <bits/stdc++.h>
using namespace std;
bool bk[1000005];
int b[1000005];
int main()
{
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	int tp,m,an=0;
	while(q--)
	{
		cin>>tp>>m;
		if(tp==1)
		{
			for(register int i=1;i<=n;i+=m)
			{
				an+=1-bk[i];
				bk[i]=1;
				//an++;
			}
		}
		else if(tp==2){
			int o=0,tot=1;
			while(tot<=n)
			{
				if(bk[tot]==0)
				{
					bk[tot]=1,o=0,an++;
					break;
				}
				//cout<<tot<<" ";
				tot++;
			}
//			cout<<tot<<"\n";
			for(register int i=tot;i<=n;i++)
			{
				o+=1-bk[i];
				if(o==m){
					o=0,bk[i]=1,an++;
				}
				
			}
		}
		else
		{
			int o=-1,a=an;
			for(int i= 1;i<=n;i++) {
				b[i]=bk[i];
//				cout<<b[i]<<" ";
			}
//			cout<<"\n";
			int op=0;
			while(a<n)
			{
				//cout<<a<<" ";
				int tot;
				if(op==0){
					tot=1;
					while(tot<=n)
					{
						if(b[tot]==0)
						{
							b[tot]=1,o=0,a++;
							if(a==n){
								cout<<tot<<"\n";
							}
							break;
						}
						
						tot++;
					}
					if(a==n){
						break;
					}
					for(register int i=tot;i<=n;i++)
					{
						o+=1-b[i];
						if(o==m){
							o=0,b[i]=1,a++;
							if(a==n)
							{
								cout<<i<<"\n";
								break;
							}
						}
						
					}
				}
				else
				{
					tot=n;
					while(tot>=1)
					{
						if(b[tot]==0)
						{
							b[tot]=1,o=0,a++;
							if(a==n){
								cout<<tot<<"\n";
							}
							break;
						}
						
						tot--;
					}
					if(a==n){
						break;
					}
					for(register int i=tot;i>=1;i--)
					{
						o+=1-b[i];
						if(o==m){
							o=0,b[i]=1,a++;
							if(a==n)
							{
								cout<<i<<"\n";
								break;
							}
						}
						
					}
				}
				op=1-op;
				
			}
			
		}
	}
	
	
	return 0;
 } 
