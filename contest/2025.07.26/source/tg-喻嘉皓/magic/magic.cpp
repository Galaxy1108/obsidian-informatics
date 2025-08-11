#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,q;
int p[N];
int maxx,top;
bool bk2=1;
struct Qus{
	int t,i;
}qus[1000010];
int tmp[N];
bool flag=0;
void change(){
	int it1=1,it2=n/2+1;
	int now=1;
	while(now<=n){
		if(it1>n/2) tmp[now++]=p[it2++];
		else if(it2>n) tmp[now++]=p[it1++];
		else{
			if(p[it1]<p[it2]) tmp[now++]=p[it1++];
			else tmp[now++]=p[it2++];
		} 
	}
	bool chk=1;
	for(int i=1;i<=n;i++){
		if(p[i]!=tmp[i]) chk=0;
		p[i]=tmp[i];	
	}
	flag=chk;
}
int res1[1010][1010];
int res2[320][100010];
void solve1(){
	for(int i=1;i<=maxx;i++){
		change();
		for(int j=1;j<=n;j++) res1[i][j]=p[j];
		if(flag){
			top=i-1;
			break;	
		}
	}
	for(int i=1;i<=q;i++){
		if(qus[i].t>=top){
			cout<<p[qus[i].i]<<'\n';	
			continue;
		}
		cout<<res1[qus[i].t][qus[i].i]<<'\n';
	}
}
void solve2(){
	for(int i=1;i<=maxx;i++){
		change();
		if(flag){
			top=i-1;
			break;	
		}
	}
 	for(int i=1;i<=q;i++){
		cout<<p[qus[i].i]<<'\n';
	}
}
void solve3(){
	int lim=sqrt(n);
	for(int i=1;i<=maxx;i++){
		change();
		if(i<=lim) for(int j=1;j<=n;j++) res2[i][j]=p[j];
		if(flag){
			top=i-1;
			break;	
		}
	}
	for(int i=1;i<=q;i++){
		if(qus[i].t>=top){
			cout<<p[qus[i].i]<<'\n';	
			continue;
		}
		if(qus[i].t<=lim){
			cout<<res2[qus[i].t][qus[i].i]<<'\n';
		}
		else cout<<"CAO\n";
	}
} 
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>p[i];	
		res1[0][i]=res2[0][i]=p[i];
	}
	maxx=0;
	for(int i=1;i<=q;i++){
		cin>>qus[i].t>>qus[i].i;
		if(i>1&&qus[i].t!=qus[i-1].t) bk2=0;
		maxx=max(maxx,qus[i].t);
	}
	top=maxx;
	if(n<=1000) solve1();
	else if(bk2) solve2();
	else if(n<=100000) solve3();
	return 0;
}

