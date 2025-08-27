#include<iostream>
#include<cstring>
using namespace std;
long long t,n,s,x,y,time;
long long gcd(long long x,long long y){
	if(x==0){
		return y;
	}
	else return gcd(y%x,x);
}
void st(){
	if(n==0)cout << s << endl;
	else if(s>=t){
		if(n%(x/y+1)==0){
			cout << s << endl;
		}		
		else cout << s-x+(n%(x/y+1)-1)*y << endl;
	}
	else{
		if(n%(x/y+1)==0){
			cout << s << endl;
		}		
		else cout << s-x+(n%(x/y+1)-1)*y << endl;
	}
	return;
}
void ts(){
	if(n==0)cout << s << endl;
	else if(s>=t){
		if(n%(x/y+1)==0){
			cout << s << endl;
		}		
		else cout << s+y-(n%(x/y+1)-1)*x << endl;
	}
	else{
		if(n%(x/y+1)==0){
			cout << s << endl;
		}		
		else cout << s+y-(n%(x/y+1)-1)*x << endl;
	}
	return;
}
int main(){
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	cin >> time;
	while(time--){
		cin >> n >> s >> t >> x >> y;
		long long len=gcd(x,y);
		__int128 nx=n,ny=n;
		nx*=x;
		ny*=y; 
		if(s<t && ny<=t-s){
			cout << s+1ll*y*n << endl;
			continue;
		}
		if(s>t && nx<=s-t){
			cout << s-1ll*n*x << endl;
			continue;
		}
		if(x==y){
			if(s>=t){
				n-=(s-t)/x;
				s-=((s-t)/x)*x;
				if(n%2==0)cout << s << endl;
				else cout << s-x << endl;
			}
			else{
				n+=(t-s)/y;
				s+=((t-s)/y)*y;
				if(s==t){
					if(n%2==0)cout << s << endl;
					else cout << s-x << endl;
				}
				else if(n%2==0)cout << s << endl;
				else cout << s+y << endl;
			}
			continue;
		}
		int now=s;
		while(n--){
			if(now>=t)now-=x;
			else now+=y;
		}
		cout << now << endl;
	}
	return 0;
} 
