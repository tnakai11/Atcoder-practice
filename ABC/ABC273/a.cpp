#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc273/tasks/abc273_a
// A. 0~10までif文で全部書く
// B. N をデクリメントしながら掛け算
// C. 再起関数を書く
int f(int k){
    if(k==0) return 1;
    return k * f(k-1);
}
void solve(){
    int N; cin >> N;
    cout << f(N) << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}