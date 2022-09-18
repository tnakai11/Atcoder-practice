#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc269/tasks/abc269_a
// 問題文通りに出力すればOK
void solve(){ 
    int a,b,c,d; cin >> a >> b >> c >> d;
    int ans = (a+b)*(c-d);
    cout << ans << '\n';
    cout << "Takahashi\n";
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}