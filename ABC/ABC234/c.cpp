#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc234/tasks/abc234_c
// 小さい順に並べると
// 0 ... 0
// 2 ... 1
// 20 ... 2
// 22 ... 3
// 200 ... 4
// 202 ... 5
// 220 ... 6
// となり概ね二進法
void solve(){ 
    ll K; cin >> K;
    ll temp = K;
    string ans = "";
    while(temp>0){
        if(temp%2==1){
            ans = "2" + ans;
        }else{
            ans = "0" + ans;
        }
        temp /= 2;
    }
    if(ans==""){
        ans = "0";
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}