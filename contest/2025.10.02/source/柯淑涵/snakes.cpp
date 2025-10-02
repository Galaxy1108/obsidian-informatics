#include <bits/stdc++.h>
using namespace std;
struct node{
	int val,num,p;
}a[1000005];
int T,n,s[1000005],m,q;
bool cmp(node x,node y){
	if(x.val!=y.val) return x.val<y.val;
	return x.num<y.num; 
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
//	memset(a,0x3f,sizeof(a));
	cin>>T;
	int r=0;
	while(T--){
		int cnt=0,res=1e9,f=0;
		
		if(r==0){
			cin>>n;
			for(int i=1;i<=n;i++){
				scanf("%d",&s[i]);
				a[i].val=s[i];
				a[i].num=i;
			}
			r=1;
		}
		else{
			cin>>m;
			int x,y;
			for(int i=1;i<=m;i++){
				scanf("%d%d",&x,&y);
				s[x]=y;
			}
			for(int i=1;i<=n;i++){
				a[i].val=s[i];
				a[i].num=i;
			}
		}
		
		a[0].p=0;			
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++) a[i].p=i;
		for(int i=1;i<=n;i++){
			//cout<<a[n].num<<" "<<a[n].val<<endl;
			if(cnt==n-1){
				f=1;
				cout<<1<<endl;
				break;
			} 
			if(a[cnt].p>=res){
			//	cout<<11111<<endl;
				f=1;
				cout<<n-cnt<<endl;
				break;
			}
			a[n].val-=a[++cnt].val;
			res=a[n].p;
			swap(a[n],a[n+1]);
			for(int j=n-1;j>=1;j--){
				if(a[j].val>a[n+1].val||a[j].val==a[n+1].val&&a[j].num>a[n+1].num) swap(a[j],a[j+1]);
				else if(j==cnt){
					swap(a[j+1],a[n+1]);
					break;
				}
				else {
					swap(a[j+1],a[n+1]);
					break;
				}
			}
		}
		if(!f) cout<<n<<endl; 
	}
	return 0;
}
/*
2 
3 
11 14 14  
3 
1 5 2 6 3 25 

2
5
13 31 33 39 42 
5
1 7 2 10 3 24 4 48 5 50 

*/
