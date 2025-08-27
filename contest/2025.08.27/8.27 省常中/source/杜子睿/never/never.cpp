 #include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 ll T,n,s,t,x,y;
 vector<ll> e;
 map<ll,int> b;
 int main(){
    freopen("never.in","r",stdin);
    freopen("never.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
    	cin>>n>>s>>t>>x>>y; 
        if(s>=t){
            ll kk=(s-t+1+x-1)/x;
            if(n<=kk){
                cout<<s-x*n<<endl;
                continue;
            }
            else{
                n-=kk;
                s-=kk*x;
            }
        }
        else if(t-s>y){
            ll kk=(t-s-1)/y;
            if(n<=kk){
                cout<<s+n*y<<endl;
                continue;
            }
            n-=kk;
            s+=kk*y;
        }
        if(x==y){
            n=n%2;
            if(n)
                cout<<s+y<<endl;
            else
                cout<<s<<endl;
            continue;
        }
        else{
            vector<ll> kk;
            map<ll,int> kkk;
            e=kk;
            b=kkk;
            while(1){
                b[s]++;
                if(b[s]>=2)
                    break;
                e.push_back(s);
                if(s>=t)
                    s-=x;
                else
                    s+=y;
            }
            n=n%e.size();
            cout<<e[n]<<endl;
        }
    }
    return 0;
 }
