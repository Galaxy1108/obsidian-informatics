#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int maxn=2e6+6;
int n,h[maxn],maxh[maxn],minh[maxn];
ull ans=0;
/*int maxhh(int l,int r){
	int remax=0;
	int sq=sqrt(n);
	if(l%sq==0&&r%sq==0){
		for(int i=l/sq;i<=r/sq;i++) remax=max(remax,maxh[i]);
		return remax;
	}
	else if(l%sq==0&&r%sq!=0){
		for(int i=l/sq;i<=r/sq;i++) remax=max(remax,maxh[i]);
		for(int i=r/sq*sq;i<=r;i++) remax=max(remax,h[i]);
		return remax;
	}
	else if(l%sq!=0&&r%sq==0){
		for(int i=l/sq+1;i<=r/sq;i++) remax=max(remax,maxh[i]);
		for(int i=l;i<=l+sq-l%sq;i++) remax=max(remax,h[i]);
		return remax;
	}
	else{
		for(int i=l/sq+1;i<=r/sq;i++) remax=max(remax,maxh[i]);
		for(int i=r/sq*sq;i<=r;i++) remax=max(remax,h[i]);
		for(int i=l;i<=l+sq-l%sq;i++) remax=max(remax,h[i]);
		return remax;
	}
}
int minhh(int l,int r){
	int remin=0x3f3f3f;
	int sq=sqrt(n);
	if(l%sq==0&&r%sq==0){
		for(int i=l/sq;i<=r/sq;i++) remin=min(remin,minh[i]);
		return remin;
	}
	else if(l%sq==0&&r%sq!=0){
		for(int i=l/sq;i<=r/sq;i++) remin=min(remin,minh[i]);
		for(int i=r/sq*sq;i<=r;i++) remin=min(remin,h[i]);
		return remin;
	}
	else if(l%sq!=0&&r%sq==0){
		for(int i=l/sq+1;i<=r/sq;i++) remin=min(remin,minh[i]);
		for(int i=l;i<=l+sq-l%sq;i++) remin=min(remin,h[i]);
		return remin;
	}
	else{
		for(int i=l/sq+1;i<=r/sq;i++) remin=min(remin,minh[i]);
		for(int i=r/sq*sq;i<=r;i++) remin=min(remin,h[i]);
		for(int i=l;i<=l+sq-l%sq;i++) remin=min(remin,h[i]);
		return remin;
	}
}*/
int main(){
	freopen("drama.in","r",stdin);freopen("drama.out","w",stdout);
	cin>>n;
	int minn=0x3f3f3f,maxx=0;
	/*int len=sqrt(n),now=1,gn;
	if(sqrt(n)*sqrt(n)==n) gn=sqrt(n);
	else gn=sqrt(n)+1;
	*/
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(ull i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			minn=0x3f3f3f,maxx=0;
			for(int k=i;k<=j;k++){
				minn=min(minn,h[k]);
				maxx=max(maxx,h[k]);
			}
			ans=max(ans,minn*maxx*(j-i+1));
		}
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
} 
/*int main(){
	//freopen("drama.in","r",stdin);freopen("drama.out","w",stdout);
	memset(minh,0x3f3f,sizeof(minh));
	cin>>n;
	int len=sqrt(n),now=1,gn;
	if(sqrt(n)*sqrt(n)==n) gn=sqrt(n);
	else gn=sqrt(n)+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(int i=1;i<=gn;i++){
		for(int j=now;j<=now+len-1;j++){
			if(j>n) break;
			maxh[i]=max(maxh[i],h[j]);
			minh[i]=min(minh[i],h[j]);
		}
		now+=len;
	}
	int p,q;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=max(ans,1ull*maxhh(i,j)*minhh(i,j)*(j-i+1));
			if(ans==1ull*maxhh(i,j)*minhh(i,j)*(j-i+1)) p=i,q=j; 
		}
	}
	cout<<ans<<" "<<p<<" "<<q;
	return 0;
} */
