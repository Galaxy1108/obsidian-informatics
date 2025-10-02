#include<iostream>
using namespace std;
int n,m,q,auv,b[3],x,a[1000005],t,minn;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		scanf("%d",&auv);
		b[auv&1]++;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&auv);
		a[x]=auv&1+1;
		b[auv&1]--;
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&t,&x);
		if(t==1){
			b[a[x]-1]++;
			a[x]=0;
		}
		else{
			scanf("%d",&auv);
			a[x]=auv&1+1;
			b[auv&1]--;
		}
		cout<<rand()%n<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
