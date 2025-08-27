#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
signed main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	int T=fread();
	while(T--)
	{
		int n=fread(),s=fread(),t=fread(),x=fread(),y=fread();
		if(s-(n-1)*x>=t) 
		{
			cout<<s-n*x<<endl;
		}
		else if(s+(n-1)*y<t)
		{
			cout<<s+n*y<<endl;
		}
		else if(x==y)
		{
			if(s==t)
			{
				if(n%2==0)
				cout<<t<<endl;
			}
			else if(s<t)
			{
				int cnt=(t-s-1)/y+1;
				n-=cnt;
				int now=s+cnt*y;
				if(n%2==0) cout<<now<<endl;
				else cout<<now-x<<endl;
			}
			else
			{
				int cnt=(s-t)/x+1;
				n-=cnt;
				int now=s-cnt*x;
				if(n%2==0) cout<<now<<endl;
				else
				cout<<now+y<<endl;
			}
		}
		else
		{
			int now=s;
			for(int i=1;i<=n;i++)
			{
				if(now<t) now+=y;
				else now-=x; 
//				if(n==10000000000) cout<<now<<'\n';
			}
//			cout<<endl;
			cout<<now<<endl;
		}
	}
//		else if(s<t)
//		{
//			int cntst=ceil((t-s)/1.0/y);//要跳几步才到s右边(一开始能移动几次）
////			cout<<cntst<<endl;
//			int l=s+cntst*y-t;//距离t的长度 (<=y)
////			cout<<l<<endl;
//			n-=cntst;
//			int now=t+l;
////			cout<<now<<endl<<n<<endl<<endl;
//			if(x==y)
//			{
//				if(n%2==0)
//				{
//					cout<<t+l<<endl;
//				}
//				else
//				{
//					cout<<t+l-x<<endl;
//				}
//			} 
//			else 
//			{
//				for(int i=1;i<=n;i++)
//				{
//					if(now>=t) now-=x;
//					else
//					now+=y;
//				}
//				cout<<now<<endl;
//			}
//			
//		}
//		else if(s>=t)
//		{
//			int cntst=ceil(1.0*(s-t+1)/x);
//			int l=t-(s-cntst*x);
//			n-=cntst;
//			int now=t-l;
//			if(x==y)
//			{
//				if(n%2==0)
//				{
//					cout<<t-l<<endl;
//				}
//				else
//				cout<<t-l+x<<endl;
//			}
//			else
//			{
//				for(int i=1;i<=n;i++)
//				{
//					if(now>=t) now-=x;
//					else
//					now+=y;
//				}
//				cout<<now<<endl;
//			}
//		}
//	}
	return 0;
}


