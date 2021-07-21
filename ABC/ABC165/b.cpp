#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc165/tasks/abc165_b
// 小数点以下切り捨てなのでシミュレーションのほうが解きやすい

// サンプルより 1,000,000,000,000,000,000 = 10^18 でも
// 3760 ステップで解決するので計算時間は余裕

void solve(){ 
    ll X; cin >> X;
    ll balance = 100;
    ll year = 0;
    while(balance<X){
        ++year;
        balance += balance/100;
    }
    cout << year << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}