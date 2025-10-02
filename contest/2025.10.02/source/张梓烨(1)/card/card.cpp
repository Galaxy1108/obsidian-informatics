#include<bits/stdc++.h>
using namespace std;
int n,m,q,t;
int ji,ou;
int a[1000005];
int solve(){
	int ans=0;
	int now=0;
	int now_i=0;
	int i_ak_ioi=ji;
	int i_ak_csp=ou;
	bool t=false;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1&&t){
			if(a[i]%2!=now){
				ans++;now=a[i]%2;now_i=i;
			}else{
				int kkk=i-now_i-1;
				kkk=max(kkk,0);
				if(now==1){
					if(ji-kkk<0){
						ans++;
						ji=0;
						now=(now+1)%2;
					}else{
						ji-=kkk;
					}
				}else{
					if(ou-kkk<0){
						ans++;
						ou=0;
						now=(now+1)%2;
					}else{
						ou-=kkk;
					}
				}
				now_i=i;
			}
		}else if(a[i]!=-1){
			t=true;
			now=a[i]%2;
			now_i=i;
			if(now==1){
				if(ji-i+1<0){
					ans++;
					ji=0;
				}else{
					ji-=(i-1);
				}
			}else{
				if(ou-i+1<0){
					ans++;
					ou=0;
				}else{
					ou-=(i-1);
				}
			}
		}
	}
	int ttt=n-now_i-1;
	ttt=max(ttt,0);
	if(now==1){
		if(ji-ttt<0){
			ans++;
		}
	}
	ji=i_ak_ioi;
	ou=i_ak_csp;
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>t;
		if(t%2==0) ji++;
		else ou++; 
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x]=y;
		if(y%2==0) ji--;
		else ou--; 
	}
	for(int i=1;i<=q;i++){
		int op,x,y;
		cin>>op;
		if(op==1){
			cin>>x;
			a[x]=-1;
			if(a[x]%2==0) ji++;
			else ou++; 
		}else{
			cin>>x>>y;
			a[x]=y;
			if(y%2==0) ji--;
			else ou--; 
		}
		cout<<solve()+1<<endl;
	}
	return 0;
}
