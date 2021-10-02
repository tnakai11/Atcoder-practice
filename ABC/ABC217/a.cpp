#include <bits/stdc++.h>
using namespace std;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc217/tasks/abc217_a
// やるだけ
// 言語によっては面倒くさいかもしれない
void solve(){ 
    string s,t; cin >> s >> t;
    if(s<t) cout << Liny;
    else cout << Linn;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}