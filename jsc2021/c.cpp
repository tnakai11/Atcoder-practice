#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_c
// 最大公約数の候補 d (1<= d <= 10^5) を総当たり
// [A,B] に d の倍数が2つ以上あれば d は公約数たり得る
void solve(){ 
    int A,B; cin >> A >> B;
    int ans = 1;
    for(int d=2;d<=100000;++d){
        int n = B/d;
        int m = (A-1)/d;
        if(n-m>=2) ans = d;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}