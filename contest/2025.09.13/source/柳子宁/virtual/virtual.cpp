#include<bits/stdc++.h>
using namespace std;
int n,L,R,x,y,Q;
int fa[2000010],FA[2000010],l[2000010],r[2000010],sum[2000010];
char s[2000010];
int Qread(){
	char st=getchar();int ans=0;
	while(!isdigit(st)) st=getchar();
	while(isdigit(st)) ans=(ans<<3)+(ans<<1)+(st^48),st=getchar();
	return ans;
}
int fnd(int x){
	if(fa[x]!=x) fa[x]=fnd(fa[x]);
	return fa[x];
}
int FND(int x){
	if(FA[x]!=x) FA[x]=FND(FA[x]);
	return FA[x];
}
void Addline(int l,int r,int id){
	int x=l,lst=0;
	while(1){
		if(x>r) break;
		x=FND(x);
		if(lst) FA[FND(lst)]=x;
		lst=x;
		fa[fnd(x)]=fnd(id);
		++x;
	}
	return;
}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	
	n=Qread(),L=Qread(),R=Qread();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+(s[i]=='a');
		if(!l[sum[i]]) l[sum[i]]=i;
		r[sum[i]]=i;
		fa[i]=i,FA[i]=i;
	}
	for(int i=1;i<=n;++i){
		int sl=sum[i-1]+L,sr=sum[i-1]+R;
		if(sl<=sum[n]){
			sr=min(sr,sum[n]);
			Addline(l[sl],r[sr],i);
		}
	}
	
	Q=Qread();
	for(int i=1;i<=Q;++i){
		x=Qread(),y=Qread();
		if(fnd(x)==fnd(y)){
			putchar('Y');
			putchar('e');
			putchar('s');
			putchar('\n');
		}
		else{
			putchar('N');
			putchar('o');
			putchar('\n');
		}
	}
	return 0;
}
