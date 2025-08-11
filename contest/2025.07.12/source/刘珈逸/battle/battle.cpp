#include<bits/stdc++.h>
#define l(p) t[p].ls
#define r(p) t[p].rs
#define v(p) t[p].val
using namespace std;
const int N=1.5e5+5,mx=1e8;
int n;
struct Rg{
	int x,y,z;
}r[N];
bool operator<(Rg x,Rg y){
	return x.x<y.x;
}
struct Node{
	int ls,rs,val;
}t[N<<7];
int tot,rt1,rt2,rt3,rt4;
void change(int&p,int l,int r,int k,int v){
	if(!p)p=++tot;
	v(p)=max(v(p),v);
	if(l==r)return;
	int mid=l+r>>1;
	if(k<=mid)change(l(p),l,mid,k,v);
	else change(r(p),mid+1,r,k,v);
}
int query(int p,int l,int r,int l1,int r1){
	if(!p||l1>r1)return 0;
	if(l1<=l&&r<=r1)return v(p);
	int mid=l+r>>1,ans=0;
	if(l1<=mid)ans=max(ans,query(l(p),l,mid,l1,r1));
	if(r1>mid)ans=max(ans,query(r(p),mid+1,r,l1,r1));
	return ans;
}
int ans=-1;
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].z);
	sort(r+1,r+1+n);
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(r[i].x==r[j].x&&j<=n)j++;
		j--;
		for(int k=i;k<=j;k++){
			int res1=query(rt3,1,mx,r[k].y+1,mx);
			int res2=query(rt4,1,mx,r[k].z+1,mx);
			if(res1)ans=max(ans,res1+r[k].x);
			if(res2)ans=max(ans,res2+r[k].x);
		}
		for(int k=i;k<=j;k++){
			change(rt1,1,mx,r[k].y,r[k].z);
			change(rt2,1,mx,r[k].z,r[k].y);
		}
		for(int k=i;k<=j;k++){
			int res1=query(rt1,1,mx,1,r[k].y-1);//³äµ±y 
			int res2=query(rt2,1,mx,1,r[k].z-1);//³äµ±z 
			if(res1){
				change(rt3,1,mx,r[k].y,r[k].y+res1);
				change(rt4,1,mx,res1,r[k].y+res1);
			}
			if(res2){
				change(rt3,1,mx,res2,r[k].z+res2);
				change(rt4,1,mx,r[k].z,r[k].z+res2);
			}
		}
	}printf("%d\n",ans);
	return 0;
}
/*
 
*/
