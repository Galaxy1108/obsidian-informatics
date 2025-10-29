#include <iostream>
#include <cstdio>
#define MAXn (int)1e6+5
using namespace std;
int n,q,op,m,sum;
struct L{
	int nxt;
	int pre;
	int v=1;
}T[MAXn];
void Out(int i){
	if(i>n||i<1) return;
	T[T[i].pre].nxt=T[i].nxt;
	T[T[i].nxt].pre=T[i].pre;
	T[i].nxt=i;T[i].pre=i;
}
void In(int i,int a){
	if(i>n||i<1) return;
	T[i].pre=a;T[i].nxt=T[a].nxt;
	T[T[a].nxt].pre=a;T[a].nxt=i;
}
int main(){
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++){
    	T[i].nxt=i+1;
    	T[i].pre=i-1;
	}
	T[0].nxt=1;T[0].pre=n;
	T[n].nxt=0;
	sum=n;
    while(q--){
        scanf("%d%d",&op,&m);
		if(op==1){
			for(int i=1; i<=n; i+=m){
				if(T[i].v){
					Out(i);
					T[i].v=0;
					sum--;
				}
			} 
		}
		else if(op==2){
			int i=T[0].nxt;
			while(i<=n&&i>=1){
				if(T[i].v){
					int q=i;
					i=T[i].nxt;
					Out(q);
					T[i].v=0;
					sum--;
				}
				for(int j=2; j<=m&&i<=n&&i>=1; j++){
					i=T[i].nxt;
				}
			}
		}
		else{
			int i=T[0].nxt;
			int cnt=sum;
			int las=-1;
			while(cnt){
				while(1<=i&&i<=n&&cnt){
					if(T[i].nxt!=i){
						las=i;
						i=T[i].nxt;
						Out(las);
						cnt--;
					}
					for(int j=2; j<=m&&i<=n&&i>=1; j++){
						i=T[i].nxt;
					}
				}
				i=T[0].pre;
				while(1<=i&&i<=n&&cnt){
					if(T[i].pre!=i){
						las=i;
						i=T[i].pre;
						Out(las);
						cnt--;
					}
					for(int j=2; j<=m&&i<=n&&i>=1; j++){
						i=T[i].pre;
					}
				}
				i=T[0].nxt;
			}
			cout<<las<<endl;
			int p=0;
			for(int i=1; i<=n; i++){
				if(T[i].nxt==i) In(i,p);
				if(T[i].v) p=i;
			}
		}
    }
    return 0;
} 
