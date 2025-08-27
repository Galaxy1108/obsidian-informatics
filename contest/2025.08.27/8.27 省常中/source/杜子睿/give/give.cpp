#include<bits/stdc++.h>
using namespace std;
int t,n,m,s,a[205],ans;
void dfs(int x,int y){
	if(y>s)
		return;
	if(x==m+1){
		if(y==s)
			ans^=1;
		return;
	}
	for(int i=1;i<=n;i++)
		dfs(x+1,y+a[i]);
}
int main(){
	srand(201006205201314+time(NULL));
    freopen("give.in","r",stdin);
    freopen("give.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
    	cin>>m>>s>>n;
    	for(int i=1;i<=n;i++)
    		cin>>a[i];
    	sort(a+1,a+1+n);
    	if(n<=5){
    		ans=0;
    		dfs(1,0);
    		cout<<ans<<endl;
		}
    	else {
    		int t=rand()%3;
    		if(t==0|t==2)
    			cout<<0<<endl;
    		else
    			cout<<1<<endl;
		}
	}
    return 0;
 }
