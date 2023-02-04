#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc283/tasks/abc283_a
// 素直にpowで計算する
// B<=9よりfor文で愚直に計算してよい
void solve(){ 
    ll A,B; cin >> A >> B;
    ll ans = pow(A,B);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
