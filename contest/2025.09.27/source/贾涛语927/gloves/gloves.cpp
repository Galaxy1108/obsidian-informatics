#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=1e5+5;
struct L{
	int si;
	bool used;
}le[maxn];
struct R{
	int si;
	bool used;
}ri[maxm];
int ans=0;
int n,m,now=1;
int l,r,mid;
bool cmp1(L x,L y){
	return x.si<y.si;
}
bool cmp2(R x,R y){
	return x.si<y.si; 
}
int abs_(int a){
	if(a>=0) return a;
	return -a;
}
int main(){
	freopen("gloves.in","r",stdin);freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>le[i].si;
		le[i].used=0;
	}
	for(int i=1;i<=m;i++){
		cin>>ri[i].si;
		ri[i].used=0;
	}
	sort(le+1,le+n+1,cmp1);sort(ri+1,ri+m+1,cmp2);
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=max(ans,abs_(le[i].si-ri[i].si));
		}
		cout<<ans;
	}
	else if(n>m){
		for(int i=1;i<=m;i++){
			l=now+1;r=n;mid=(l+r)/2;
			now=l;
			while(l<r){
				if(n-mid>=m-i&&abs_(le[now].si-ri[i].si)>abs_(le[mid].si-ri[i].si)){
					now=mid;
					l=mid+1;
					mid=(l+r)/2;
					
				}
				else{
					r=mid-1;
					mid=(l+r)/2;
				}
			}
			ans=max(ans,abs_(le[now].si-ri[i].si));
		}
		cout<<ans;
	}
	else if(n<m){
		for(int i=1;i<=n;i++){
			l=now+1,r=m,mid=(l+r)/2;
			now=l;
			while(l<r){
				if(m-mid>=n-i&&abs_(ri[now].si-le[i].si)>=abs_(ri[mid].si-le[i].si)){//1.le-now和ri-i差值不会再变小2.mid大于等于m剩余 
					now=mid;
					l=mid+1;
					mid=(l+r)/2;
				}
				else{
					r=mid-1;
					mid=(l+r)/2;
				}
			}
			ans=max(ans,abs_(ri[now].si-le[i].si));
		}
		cout<<ans;
	}
	return 0;
} 
