#include <bits/stdc++.h>
using namespace std;
#define int __int128
__int128 read(){
	__int128 x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
void write(__int128 x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<=9){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
void Main(){
    int n,s,t,x,y;
    n=read(),s=read(),t=read(),x=read(),y=read();
//    write(n);
//    cout << " ";
//    write(s);
//    cout << " ";
//    write(t);
//    cout << " ";
//    write(x);
//    cout << " ";
//    write(y);
//    cout << endl;
//    cout << endl;
    int now=s,i=1;
    if(n<=1e6){
        while(i<=n){
            if(now>=t){
                now-=x;
            }
            else now+=y;
            i++;
        }
    }
    else{
        while(i<=n){
    //        cout << now <<endl;
            if(now>=t){
                if(n-i<(now-t)/x+1){
                    now-=x;
                    i++;
                    continue;
                }
                if((now-t)%x==0){
                    i+=(now-t)/x;
                    now=t-x;
                    i++;
                }
                else {
                    i+=(now-t)/x;
                    int k=(now-t)/x*x+x;
                    now-=k;
                    i++;
                }
            }
            if(now<t){
                if(n-i<(t-now)/y+1){
                    now+=y;
                    i++;
                    continue;
                }
                if((t-now)%y==0){
                    i+=(t-now)/y;
                    now=t;
                }
                else{
                    i+=((t-now)/y);
                    int k=(t-now)/y*y+y;
                    now+=k;
                    i++;
                }
            }
        }
    }
    
    write(now);
    puts("");
}
signed main(){
    freopen("never.in","r",stdin);
    freopen("never.out","w",stdout);
    long long T;
    cin >> T;
    while(T--)Main();
    return 0;
}

