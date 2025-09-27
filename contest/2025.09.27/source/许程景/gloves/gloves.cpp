#include <cstdio>
#include <algorithm>
int l[100000],r[100000];
int n,m;
bool check(int k){
    int i=0,j=0;
    while(j!=m){
	if(i==n) return 0;
	while(l[i]-r[j]<-k) i++;
	if(l[i]-r[j]>k) return 0;
	else i++,j++;
    }
    return 1;
}
int main(){
    freopen("gloves.in","r",stdin);
    freopen("gloves.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",l+i);
    for(int i=0;i<m;i++) scanf("%d",r+i);
    if(n<m){
	std::swap(l,r);
	std::swap(n,m);
    }
    std::sort(l,l+n);
    std::sort(r,r+m);
    int l=0,r=1e9+1,ans=-1,tmp;
    while(1){
	int m=(l+r)>>1;
	if(r-l==1) tmp=1;
	if(check(m)) ans=m,r=m;
	else l=m+1;
	if(tmp) break;
    }
    printf("%d\n",ans);
}
