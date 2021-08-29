#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_a
// Y / X > price / Z  
// Y * Z > price * X
void solve(){ 
    int X,Y,Z; cin >> X >> Y >> Z;
    int ans = Y * Z / X;
    if(Y*Z==ans*X) --ans;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}