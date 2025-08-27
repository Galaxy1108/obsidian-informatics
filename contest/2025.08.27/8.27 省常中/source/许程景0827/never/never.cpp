#include <cstdio>
int main(){
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,s,t,x,y;
		scanf("%d%d%d%d%d",&n,&s,&t,&x,&y);
		while(n--){
			if(s>=t) s-=x;
			else s+=y;
		}
		printf("%d\n",s);
	}
}