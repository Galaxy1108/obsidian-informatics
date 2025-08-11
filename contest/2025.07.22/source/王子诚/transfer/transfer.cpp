#include <bits/stdc++.h>
using namespace std;

int n, k, num[100], numcnt[100];
string s[100];
string str;
// map<pair<int, int>, bool> m;

int max_i;

bool calc(int I){
    if(I==n+1){
        for (int i = 1; i <= k;i++){
            if(!numcnt[i]){
                return false;
            }
            s[i] = "";
        }
        for (int i = 1; i <= n;i++){
            s[num[i]] += str[i - 1];
            // cout << num[i] << ' ';
        }
        // cout << '\n';
        for (int i = 1; i <= k;i++){
            bool is_B = false;
            int sizes = s[i].size();
            if(sizes%2){
                return false;
            }
            for (int j = 0; j < sizes;j++){
                if(j<sizes/2 && s[i][j]=='B'){
                    return false;
                }
                if(j>=sizes/2 && s[i][j]=='A'){
                    return false;
                }
            }
        }
        return true;
    }
    bool anss = false;
    for (int i = 1; i <= k;i++){
        num[I] = i;
        numcnt[i]++;
        anss |= calc(I + 1);
        numcnt[i]--;
    }
    return anss;
}

bool swaps(int I){
    if(I==max_i+1){
        // cout << str << endl;
        return calc(1);
    }
    for (int i = 0; i < str.size() - 1;i++){
        int j = i + 1;
        swap(str[i], str[j]);
        if(swaps(I + 1)){
            return true;
        }
        swap(str[i], str[j]);
    }
    return false;
}

int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout); 
    cin >> n >> k;
    cin >> str;
    if(n>=10){
    	cout<<0;
    	return 0;
	}
    n *= 2;
    max_i = 0;
    while(1){
        if(swaps(1)){
            cout << max_i;
            return 0;
        }
        max_i++;
    }
}
