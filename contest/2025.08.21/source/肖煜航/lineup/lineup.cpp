#include<cstdio>
#include<algorithm>
using namespace std;
const int N=55;
int n,a[N],b[N];
void solve(int x,int l,int r){
	if(l>r) return;
	int mi=1e9,id=0;
	for(int i=l;i<=r;i++){
		if(mi>a[i]){
			mi=a[i];
			id=i;
		}
	}
	swap(a[id],a[x]);
	solve(id,id+1,r);
}
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	int len=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+len+1,a[i])-b;
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	int cnt=0;
	for(int i=n;i>1;i--){
		int mx=0,id=0;
		for(int j=1;j<=i;j++){
			if(a[j]>=mx){
				mx=a[j];
				id=j;
			}
		}
		solve(id,id+1,i);
		cnt+=i-id;
	}
	printf("%d",cnt*2);
	return 0;
}
