#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc256/tasks/abc256_a
// 256 = 2^8
// *2 をN回行うかビット演算をするかでOK
// オーバーフローに注意
void solve(){ 
    int N; cin >> N;
    int ans = (1<<N);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}