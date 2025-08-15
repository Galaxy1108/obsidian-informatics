#include<bits/stdc++.h>
using namespace std;
const int mn=114514,mod=998244353;
int n,a[10*mn],m,b[10*mn];
int maxa;
long long dp[10*mn],asum,num[mn],sum[10*mn];
long long tre[8*mn],ans;
int pp,pt;

struct orz{
	int p;
	long long val;
}ord[10*mn];

bool cmp(orz x,orz y){
	return x.val<y.val || (x.val==y.val && x.p<y.p);
}

void mdf(int p,int s,int e){
	if(s>=e){
		tre[p]+=dp[pp];
//		cout<<s<<' '<<e<<' '<<tre[p]<<endl;
		return;
	}
	int mid=(s+e)/2;
	if(a[pp]<=mid) mdf(p*2,s,mid);
	else mdf(p*2+1,mid+1,e);
	tre[p]+=dp[pp];
	tre[p]%=mod;
//	cout<<s<<' '<<e<<' '<<tre[p]<<endl;
	return;
}

int get(int p,int s,int e){
	if(s>=e) return 0;
	long long pans;
	int mid=(s+e)/2;
	if(a[pp]<=mid) pans=get(p*2,s,mid);
	else pans=tre[p*2]+get(p*2+1,mid+1,e);
	return pans%mod;
}

int find(int s,int e,int num,int p){
	int mid;
	while(s<e){
		mid=(s+e)/2;
		if(num==ord[mid].val){
			if(p>=ord[mid].p) s=mid+1;
			else e=mid;
		}
		else if(num>ord[mid].val) s=mid+1;
		else e=mid;
	}
	return e;
}

int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
		ord[i].val=a[i];
		ord[i].p=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	b[m+1]=-mn;
	
	for(int i=n;i>=1;i--){
		dp[i]=asum-num[a[i]]+1;
		dp[i]%=mod;
		num[a[i]]=dp[i];
		asum+=dp[i];
		asum%=mod;
	}
	
//	for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
//	cout<<endl;
	
	sort(ord+1,ord+n+1,cmp);
	
//	for(int i=1;i<=n;i++) cout<<ord[i].p<<' '<<ord[i].val<<endl;
//	cout<<endl;
	
	for(int i=n;i>=1;i--){
		pp=i;
		sum[i]=get(1,1,maxa);
		mdf(1,1,maxa);
	}
	
//	for(int i=1;i<=n;i++) cout<<sum[i]<<' ';
//	cout<<endl;
	
	pt=find(1,n,b[1],0);
	for(int i=1;i<pt;i++) ans+=dp[ord[i].p];
	ans%=mod; 
//	cout<<pt<<' '<<ans<<endl;
	
	if(ord[pt].val==b[1]) for(int i=2;i<=m;i++){
		pt=find(1,n,b[i],pt);
		ans+=sum[ord[pt].p]+1;
		ans%=mod;
		if(ord[pt].val!=b[i]) break;
	}
	ans++;
	ans%=mod;
	cout<<ans<<endl;
	
	return 0;
}
/*
4
1 2 4 1
1
2
*/
