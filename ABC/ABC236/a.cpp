#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc236/tasks/abc236_a
// やるだけ
// swap しない場合は for と if でやるとか
void solve(){ 
    string s; cin >> s;
    int a,b; cin >> a >> b;
    --a; --b;
    swap(s[a],s[b]);
    cout << s << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}