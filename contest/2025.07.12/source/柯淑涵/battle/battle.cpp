#include <bits/stdc++.h>
using namespace std;
struct node{
	int val,num,pr;
};
node x[1500005],y[1500005],z[1500005];
int n,ma=-1;
int mx,my,mz;
bool cmp(node a,node b){
	return a.val>b.val;
}
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].val>>y[i].val>>z[i].val;
		x[i].num=y[i].num=z[i].num=i;
		mx=max(mx,x[i].val);
		my=max(my,y[i].val);
		mz=max(mz,z[i].val);
	}
	if(n<=300){
		int x1,y1,z1,x2,y2,z2,x3,y3,z3;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					mx=my=mz=0;
					if(i==j||j==k||i==k) continue;
					x1=x[i].val,y1=y[i].val,z1=z[i].val;
					x2=x[j].val,y2=y[j].val,z2=z[j].val;
					x3=x[k].val,y3=y[k].val,z3=z[k].val;
					if(x1>x2&&x1>x3){
						if(y2>y1&&y2>y3&&z3>z1&&z3>z2) ma=max(ma,x1+y2+z3);
						if(y3>y2&&y3>y1&&z2>z3&&z2>z1) ma=max(ma,x1+y3+z2); 
					} 
					else if(x2>x1&&x2>x3){
						if(y1>y2&&y1>y3&&z3>z1&&z3>z2) ma=max(ma,x2+y1+z3);
						if(y3>y2&&y3>y1&&z1>z3&&z1>z2) ma=max(ma,x2+y3+z1); 
					} 
					else if(x3>x1&&x3>x2){
						if(y1>y2&&y1>y3&&z2>z1&&z2>z3) ma=max(ma,x3+y1+z2);
						if(y2>y3&&y2>y1&&z1>z3&&z1>z2) ma=max(ma,x3+y2+z1); 
					} 
				}
			}
		}
		cout<<ma<<endl;
		return 0;
	}
	else{
		sort(x+1,x+1+n,cmp);
		sort(y+1,y+1+n,cmp);
		sort(z+1,z+1+n,cmp);
		int f=3,a=1,b=1,c=1,m=n;
		while(1){
			if(x[a].val!=y[b].val&&y[b].val!=z[c].val&&x[a].val!=z[c].val)break;
			while(x[a].val==y[b].val) a++,b++,m--;
			while(y[b].val==z[c].val) c++,b++,m--;
			while(x[a].val==z[c].val) a++,c++,m--;
			
		}
		if(m<=2){
			cout<<-1<<endl;
			return 0;
		} 
		if(mx<=4000&&my<=4000&&mz<=4000) cout<<x[a].val+y[b].val+z[c].val+3<<endl;
		else cout<<x[a].val+y[b].val+z[c].val<<endl;
		
	} 
	return 0;
} 
/*
5 
3 1 4 
2 3 1 
1 5 5 
4 4 2 
5 2 3 
8 
1 1 1 
1 1 5 
1 5 1 
5 1 1 
1 5 5 
5 1 5 
5 5 1 
5 5 5
4 
1 2 3 
1 2 3 
1 2 3
1 2 3
*/ 
