#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc219/tasks/abc219_a
// 場合分けか1点ずつ上げて都度チェック
void solve(){ 
    int X; cin >> X;
    int ans = 0;
    for(int t:{40,70,90}){
        if(X<t){
            ans = t - X;
            break;
        }
    }
    if(ans>0) cout << ans << '\n';
    else cout << "expert\n";
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}