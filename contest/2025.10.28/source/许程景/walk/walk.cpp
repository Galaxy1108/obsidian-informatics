#include <cstdio>
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    int n,inp,pref=0,mn=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&inp);
	pref+=inp&1;
	if(pref*2-i<mn) mn=pref*2-i;
	if((pref*2-i-mn)>ans) ans=pref*2-i-mn;
    }
    printf("%d\n",pref-ans);
}
