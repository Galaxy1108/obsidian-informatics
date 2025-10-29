#define n 100000
#include <cstdio>
int main(){
    for(int i=1;i<=n;i++){
	int ans=0;
	for(int j=1;j<=n;j++){
	    if(i%j==0) ans+=j;
	}
	if(ans>=4*i){
	    printf("%d %d\n",ans,i);
	}
    }
}
