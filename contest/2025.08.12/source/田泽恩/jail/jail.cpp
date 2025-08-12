#include <bits/stdc++.h>
using namespace std;
int q,n,m,S,T,u,v,cnt1,cnt2,book1[124514],book2[124514];
struct arr{
	int s,t;
}a1[124514],a2[124514];
bool cmp(arr x,arr y){
	return x.s<y.s;
}
int main(){
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	cin>>q;
	while(q--){
		for(int i=1;i<=n+10;++i) book1[i]=book2[i]=0;
		cnt1=cnt2=0;
		bool flag=true,f=true;
		cin>>n;
		for(int i=1;i<n;++i){
			cin>>u>>v;
			if(u!=i||v!=i+1) f=false;
		}
		cin>>m;
		for(int i=1;i<=m;++i){
			cin>>S>>T;
			if(S<T){
				a1[++cnt1].s=S;
				a1[cnt1].t=T;
				book1[S]++;
				book1[T+1]--;
			}
			else{
				a2[++cnt2].s=T;
				a2[++cnt2].t=S;
				book2[T]++;
				book2[S+1]--;
			}
		}
		if(f){
			sort(a1+1,a1+cnt1+1,cmp);
			sort(a2+1,a2+cnt2+1,cmp);
			int now1=0,now2=0;
			for(int i=1;i<=n+10;++i){
				book1[i]+=book1[i-1];
				book2[i]+=book2[i-1];
			}
			for(int i=1;i<=n+10;++i){
				book1[i]+=book1[i-1];
				book2[i]+=book2[i-1];
			}
			for(int i=1;i<=cnt1;++i){
				if(a1[i].t<now1||book2[a1[i].t]-book2[a1[i].s-1]){
					flag=false;
					break;
				}
				now1=a1[i].t;
			}
			for(int i=1;i<=cnt2;++i){
				if(a2[i].t<now2||book1[a2[i].t]-book1[a2[i].s-1]){
					flag=false;
					break;
				}
				now2=a2[i].t;
			}
			if(flag) puts("Yes");
			else puts("No");
		}
		else puts("No");
	}
	return 0;
}
