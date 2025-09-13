#include<iostream>

using namespace std;
int n,l,r,q,x,y,fa[2000086];
string s;
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx!=yy)fa[yy]=xx;
} 
int main(){
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r;
	cin >> s;
	s=" "+s;
	cin >> q;
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0,lp=1,rp=1;
	while(cnt<l){
		if(s[lp]=='a')cnt++;
		if(cnt==l)break;
		lp++;
	}
	rp=lp;
	while(cnt<r){
		merge(1,rp);
		rp++;
		if(s[rp]=='a')cnt++;
		if(cnt==r)break;
	}
	while(s[rp+1]=='b'&&rp+1<=n){
		merge(1,rp);
		rp++;
	}
	merge(1,rp);
	int ll=lp,lr=rp;
	for(int i=2;i<=n&&lp<=n;i++){
		if(s[i-1]=='b')merge(i-1,i);
		else{
			if(s[lp]=='a')lp++;
			while(s[lp]!='a'&&lp<=n){
				lp++;
			}
			if(lp>lr){
				rp=lp;
				merge(i,rp);
				while(s[rp+1]!='a'&&rp+1<=n){
					merge(i,rp+1);
					rp++;
					
				}
				merge(i,rp);
			}
			else{		
				if(rp<n)rp++;
				merge(i,rp);
				while(s[rp+1]!='a'&&rp+1<=n){
					merge(i,rp+1);
					rp++;	
				}
				merge(i-1,i);
			}
			ll=lp,lr=rp;
		}
	}
	for(int i=1;i<=q;i++){
		cin >> x >> y;
		if(find(x)==find(y)){
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
} 
