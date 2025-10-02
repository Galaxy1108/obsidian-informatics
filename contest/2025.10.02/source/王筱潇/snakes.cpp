#include<bits/stdc++.h>
using namespace std;
int T,n,k,s[2000010],a[1000010];
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x;
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read();
	for(int I=1;I<=T;I++){
		if(I==1){
			n=read();
			for(int i=1;i<=n;i++) s[i]=read();
		}
		else{
			k=read();
			int x,y;
			for(int i=1;i<=n;i++){
				x=read(),y=read();
				s[x]=y;
			}
		}
		for(int i=1;i<=n;i++) a[i]=s[i];
		int f=n;
		while(f!=1){
			if(a[f]-a[1]<a[2]&&f!=2){
				break;
			}
			else{
				a[1]=a[f]-a[1];
				a[f]=0;
			}
			f--;
			sort(a+1,a+f);
		}
		if(f==1){
			printf("1\n");
			continue;
		}
		sort(a+1,a+n,cmp);
		for(int i=1;i<=f/2;i++){
			swap(a[i],a[f-i+1]);
		}
		int flag=f;
		while(a[2]>a[1]){
			a[1]=a[flag]-a[1];
			a[flag]=0;
			flag--;
		}
		if((f-flag)%2==0) printf("%d\n",f);
		else printf("%d\n",f-1);
	}
	return 0;
} 
