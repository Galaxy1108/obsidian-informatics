#include <bits/stdc++.h> 
using namespace std;
int n,q,x,y,fo[30],ans[30],a[1000010],c[1000010],flag=1;
int main(){
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	scanf("%d%d",&n,&q);
	int sum=n;
	while(q--){
		scanf("%d%d",&x,&y);
		if(x==1){
			flag=1;
		 	if(fo[y]==1) continue;
			for(int i=1;i<=n;i+=y) a[i]=1,sum--; 
			fo[y]=1;
		}
		else if(x==2){
			flag=1;
			int cnt=0,f=1;
			for(int i=1;i<=n;i++){
				if(f&&!a[i]) a[i]=1,cnt++,sum--,f=0;
				if(cnt==y&&!a[i]) a[i]=1,cnt=1,sum--;
				if(!a[i]) cnt++;
			}
		}
		else if(x==3){
			if(flag){
				for(int i=1;i<=20;i++){
					for(int k=1;k<=n;k++) c[k]=a[k];
					int fg=sum;
					int s=1;
					while(fg){
						if(s%2){
							int cnt=0,f=1;
							for(int j=1;j<=n;j++){
								if(f&&!c[j]) c[j]=1,f=0,fg--,cnt++;
								if(fg==0){
									ans[i]=j;
									break;
								}
								if(cnt==i&&!c[j]) c[j]=1,cnt=0,fg--,cnt++;
								if(fg==0){
									ans[i]=j;
									break;
								}
								if(!c[j]) cnt++;
							}
						}
						else{
							int cnt=0,f=1;
							for(int j=n;j>=1;j--){
								if(f&&!c[j]) c[j]=1,f=0,cnt++,fg--;
								if(fg==0){
									ans[i]=j;
									break;
								}
								if(cnt==i&&!c[j]) c[j]=1,cnt++,fg--;
								if(fg==0){
									ans[i]=j;
									break;
								}
								if(!c[j]) cnt++;
							}
						}
						s++;
					}
				}
			}
			flag=0;
//			for(int i=1;i<=20;i++) printf("%d ",ans[i]); 
			printf("\n%d\n",ans[y]);
		}
	}
	return 0;
}
