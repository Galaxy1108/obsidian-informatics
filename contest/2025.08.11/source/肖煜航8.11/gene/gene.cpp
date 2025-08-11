#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int read(){
	int p=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p*w;
}
const int N=1e6+5;
int n,l,r,ans=1000000000;
int a[N];
bool vis[N];
set<int> b[N];
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout); 
	n=read(),l=read(),r=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[a[i]].insert(i);
	int pos=r+1;
	for(int i=l-1;i;i--){
		auto u=b[a[i]].lower_bound(i);
		u++;
		int o=0;
		if(u==b[a[i]].end()) o=n+1;
		else o=*u;
		u--;
		if(u!=b[a[i]].begin()) continue;
		for(;;pos++){
			if(pos>n) break;
			if(pos>=o) break;
			if(a[pos]==a[i]){
				continue;
			}
			else{
				auto v=b[a[pos]].lower_bound(pos);
				v++;
				if(v==b[a[pos]].end()){
					v--;
					if(v==b[a[pos]].begin()){
						ans=min(ans,pos-i+1);
						break;
					}
					else{
						v--;
						if(*v<i){
							ans=min(ans,pos-i+1);
							break;
						}
					}
				}
			}
		}
	}
	if(ans==1000000000) printf("-1");
	else printf("%d",ans);
	return 0;
}
