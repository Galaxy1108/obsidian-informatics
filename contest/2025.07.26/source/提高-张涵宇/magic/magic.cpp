#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn = 2e5+10;
int a[maxn],b[maxn];
int ans[5*maxn];
struct ques{
	int t,i,pos;
}q[5*maxn];
int read()
{
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
bool ok=true;
bool cmp(ques a,ques b)
{
	return a.t<b.t;
}
bool cmp2(ques a,ques b)
{ 
	return a.pos<b.pos;
}
void out(int x)
{
	if(x>=0&&x<=9){
		 putchar(x+'0');
		 return;	
	}
	out(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int N,Q;N=read();Q=read();
	for(int i=1;i<=N;i++){
		a[i]=read();
	}
	int maxx=0;
	for(int k=1;k<=Q;k++){
		q[k].t=read();
		q[k].i=read();q[k].pos=k;
		maxx=max(maxx,q[k].t);
	}
	sort(q+1,q+1+Q,cmp);
	int cnt=0,q_cnt=1;
	for(int i=0;i<=maxx;i++){
		while(q[q_cnt].t==i)
		{
			ans[q[q_cnt].pos]=a[q[q_cnt].i];
			q_cnt++;
		}
		if(ok)
		{
			cnt++;
			for(int j=1;j<=N;j++){
				b[j]=a[j];
			}
			int l=1,r=N/2+1;
			bool flag=true;
			for(int j=1;j<=N;j++){
				if((l==N/2+1||b[l]>b[r])&&r<N+1)
				{
					if(a[j]!=b[r]) flag=false;
					a[j]=b[r];
					r++;
				}
				else if((r==N+1||b[r]>b[l])&&l<N/2+1)
				{
					if(a[j]!=b[l]) flag=false;
					a[j]=b[l];
					l++;
				}
			}
			if(flag){
				ok=false;
			}	
		}
	}
	for(int i=1;i<=Q;i++){
		out(ans[i]);
		printf("\n");
	}
	
	return 0;
}
