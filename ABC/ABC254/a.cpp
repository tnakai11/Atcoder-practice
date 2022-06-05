#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc254/tasks/abc254_a
// N%100 をゼロ埋めで出力
// ゼロ埋めが面倒ならstring型として後ろ２文字を出力
void solve(){ 
    int N; cin >> N;
    printf("%02d\n",N%100);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}