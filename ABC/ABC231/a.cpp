#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc231/tasks/abc231_a
// 型だけ気をつければたぶんOK
// 100で割るだけなので小数点の挿入でもOK
void solve(){ 
    int D; cin >> D;
    printf("%d.%02d",D/100,D%100);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}