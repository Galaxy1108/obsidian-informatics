#include<iostream>

using namespace std;
int n,a[2000086],lmin[2000086],rmin[2000086],q[2000086],tree[8000086][2],h=1,t=0;
__int128 ans;
void write(__int128 x){
	char c=x%10+'0';
	if(x<10){
		cout << c;
		return;
	}
	else write(x/10);
	cout << c;
}
void pushup(int p){
	tree[p][1]=max(tree[p*2][1],tree[p*2+1][1]);
	tree[p][0]=min(tree[p*2][0],tree[p*2+1][0]);
}
void build(int s,int e,int p){
	tree[p][0]=1e9;
	if(s==e){
		tree[p][0]=tree[p][1]=a[s];
		return;
	}
	int mid=s+((e-s)>>1);
	build(s,mid,p*2);
	build(mid+1,e,p*2+1);
	pushup(p);
}
int querymin(int s,int e,int l,int r,int p){
	if(s>=l&&e<=r)return tree[p][0];
	int mid=s+((e-s)>>1),res=1e9;
	if(l<=mid)res=min(res,querymin(s,mid,l,r,p*2));
	if(r>mid)res=min(res,querymin(mid+1,e,l,r,p*2+1));
	return res;
}
int querymax(int s,int e,int l,int r,int p){
	
	if(s>=l&&e<=r)return tree[p][1];
	int mid=s+((e-s)>>1),res=0;
	if(l<=mid)res=max(res,querymax(s,mid,l,r,p*2));
	if(r>mid)res=max(res,querymax(mid+1,e,l,r,p*2+1));
	return res;
}
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		lmin[i]=n+1;
		rmin[i]=0;
	}
	for(int i=1;i<=n;i++){
		while(h<=t&&a[q[t]]>a[i]){
			lmin[q[t]]=i;
			t--;
		}
		q[++t]=i;
	}
	h=1;
	t=0;
	for(int i=n;i>=1;i--){
		while(h<=t&&a[q[t]]>a[i]){
			rmin[q[t]]=i;
			t--;
		}
		q[++t]=i;
	}
	build(1,n,1);
	for(int i=1;i<=n;i++){
		__int128 sum=1;
		sum*=lmin[i]-rmin[i]-1;
		sum*=querymin(1,n,rmin[i]+1,lmin[i]-1,1);
		sum*=querymax(1,n,rmin[i]+1,lmin[i]-1,1);
		ans=max(ans,sum);
	}
	write(ans);
	return 0;
} 
