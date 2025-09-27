#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char c;c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	return x;
}
int n,m,k,a[50005],nb[40],pd[50005][40],pp[50005],nbb;
int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	n=read(),k=read(),m=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();nb[a[i]]++;
	}
	for(int i=1;i<=k;i++){
		if(nb[i]!=-1) {nbb++;break;}
	}
	memset(pp,-1,sizeof(pp));
	for(int i=1,o;i<=n;i++){
		for(int j=i;j>0;j--){
			pd[i][a[j]]++;o=0;
			for(int l=1;l<=k;l++) if(!pd[i][l]) {o++;break;}
			if(!o){
				pp[i]=j-1;break;
			}
		}
	}
	for(int i=0,x,y,o,ax;i<m;i++){
		x=read();
		if(x==1){
			x=read(),y=read();
			ax=a[x];a[x]=y;
			nb[ax]--,nb[y]++;
			for(int j=x,o;j<=n&&(pp[j]<x||!nbb);j++){
				pd[j][ax]--,pd[j][y]++;
				if(pp[j]==-1){
					o=0;
					for(int p=1;p<=k;p++) if(!pd[j][p]) {o++;break;}
					if(o) continue;
					pp[j]=0;
					for(;pd[j][a[pp[j]+1]]-1;pp[j]++) pd[j][a[pp[j]+1]]--;
					continue;
				}
				for(;!pd[j][ax]&&pp[j]>=0;pp[j]--) pd[j][a[pp[j]]]++;
				if(pp[j]==-1) continue;
				for(;pd[j][a[pp[j]]]-1;pp[j]++) pd[j][a[pp[j]]]--;
				pp[j]--;
			}
			nbb=0;
			for(int i=1;i<=k;i++) if(pp[i]!=-1) {nbb=1;break;}
		}
		else{
			o=0;
			for(int j=1;j<=k;j++)
				if(nb[j]==0){
					cout<<"-1\n";o++;break;
				}
			if(o) continue;
			int ans=1e9;
			for(int j=k;j<=n;j++) if(pp[j]+1) ans=min(ans,j-pp[j]);
			cout<<ans<<'\n';
		}
	}
}
