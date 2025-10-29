//dfs#3
#include<bits/stdc++.h>
using namespace std;
const int maxn=1086;
const int gouba=4000000; 
int a[maxn];
int t[maxn];
int ori[maxn];
int pl[20];
int use[20];
int ss[gouba];
int cnt=0;
int n,mod;
int lb(int x) {return x&-x;} 
int query(int x){int ans=0;while(x>0){ans+=t[x];x-=lb(x);}return ans;}
void add(int x,int k){while(x<=n){t[x]+=k;x+=lb(x);}}
int get_pair()
{
//	cout<<n<<endl;
	for(int i=1;i<=n;i++)
	a[i]=n+1-pl[i];
	memset(t,0,sizeof(t));
	int ans=0;
//	cout<<n<<endl;
	for(int i=1;i<=n;i++) 
	{
	//	cout<<"??"<<endl;
		add(a[i],1);
	//	for(int j=1;j<=n;j++) cout<<t[j]<<' ';
	//	cout<<endl;
		ans+=query(a[i]-1);
	}
	return ans;
}
void dfs(int x)
{
	if(x==n)
	{
		ss[++cnt]=get_pair();
		return;
	} 
	for(int i=1;i<=n;i++)
    {	
       if(!use[i])
     	{
	    	pl[x+1]=i;
	    	use[i]=1;
	    	dfs(x+1);
	    	use[i]=0;
     	}
	} 
}
int get_ans()
{
	memset(t,0,sizeof(t));
	for(int i=1;i<=cnt;i++)
	{
	  a[i]=(n*(n-1))/2-ss[i];
	}
	 for(int i=1;i<=cnt;i++)
	cout<<a[i]<<' ';
	cout<<endl;
	int ans=0;
	for(int i=1;i<=cnt;i++)
    { 
	 // cout<<"jj"<<endl;
	  add(a[i]+1,1);
	  ans+=query(a[i]);
	  ans%=mod;
	}	
	return ans;
}
int main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	cin>>n>>mod;
	dfs(0);
//	cout<<"!!"<<cnt<<endl;
//	for(int i=1;i<=cnt;i++)
//	cout<<ss[i]<<' ';
//	cout<<endl;
    cout<<get_ans()<<endl;
	return 0;
} 
//Ï¹jbÂÒ×ö 
