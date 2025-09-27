#include <cstdio>
char s[400];
int abs(int x){return x<0?-x:x;}
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
    int n=0;
    while(scanf("%c",&s[n++])!=EOF);
    int ans=0;
    for(int i=0;i<n;i++){
	if(s[i]=='0') ans++;
    }
    if(n&1){
	if(ans>(n>>1)+1){
	    printf("-1");
	    return 0;
	}else if(ans==(n>>1)+1){
	    ans=0;int j=0;
	    for(int i=0;i<n;i++){
		if(s[i]=='0') ans+=abs(i-j),j+=2;
	    }
	    printf("%d\n",ans);
	    return 0;
	}else printf("0\n");
    }else{
	if(ans>(n>>1)){
	    printf("-1\n");
	    return 0;
	}else printf("0\n");
    }
}
