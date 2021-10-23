#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc220/tasks/abc220_a
// A<=x<=Bを全探索するのが一番楽
void solve(){ 
    int A,B,C; cin >> A >> B >> C;
    int ans = -1;
    for(int x=A;x<=B;++x){
        if(x%C==0){
            ans = x;
            break;
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}