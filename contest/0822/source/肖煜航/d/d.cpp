#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,Q,T;
int a[N];
bool check(int l,int r,int A,int b,int c){
	for(int i=l;i<=r;i++){
		if(a[i]!=(A*(i-l)+b)/c) return 0;
	}
	return 1;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&Q);
		bool flag=0;
		if(n<=20&&Q<=20) flag=1;
		while(Q--){
			int l,r;
			scanf("%d%d",&l,&r);
			if(flag){
				bool ok=0;
				for(int c=1;c<=10;c++){
					for(int A=0;A<=10;A++){
						for(int b=0;b<=10;b++){
							if(check(l,r,A,b,c)){
								ok=1;
								printf("%d %d %d\n",A,b,c);		
								break;
							}
						}
						if(ok) break;
					}
					if(ok) break;
				}
			}
			else{
				if(l==r){
					printf("%d %d 1\n",0,a[l]);
				}
				else{
					long long A,b=a[l];
					A=a[l+1]-b;
					printf("%d %d 1\n",A,b); 
				}
			}
		}
	}
	return 0;
}
