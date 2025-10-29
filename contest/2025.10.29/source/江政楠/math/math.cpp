#include<bits/stdc++.h>
using namespace std;
const int N=10000;
vector<int> an;
struct node{
	long long son,mom;
};
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
node minu(long long p1,long long q1,long long p2,long long q2){
	node result;
	result.son=p1*q2-p2*q1;
	result.mom=q1*q2;
	__int128 g=gcd(result.son,result.mom);
	result.son/=g;
	result.mom/=g;
	return result;
}
int find(double x){
    int ans;
    for(int i=1;i<=N;i++){
        double j=i;
        double now=1.0/j;
        if(x>=now){
            ans=i;
            break;
        }     
    }
    return ans; 
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
    double a,b;
    cin>>a>>b;
    double x=a,y=b;
    double num=x/y;
    while(1){
        int h=find(num);
        an.push_back(h);
        node re=minu(x,y,1,h);
        x=re.son;
        y=re.mom;
        if(x==0) break;
        num=x/y;
    }
    cout<<an.size()<<"\n";
    for(int i:an)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}
