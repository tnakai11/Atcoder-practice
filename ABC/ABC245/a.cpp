#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc245/tasks/abc245_a
// A, C を比較
// A==C なら B,D を比較
void solve(){ 
    int a,b,c,d; cin >> a >> b >> c >> d;
    string ta = "Takahashi";
    string ans = "Aoki";
    if(a==c && b<=d){
        ans = ta;
    }else if(a<c){
        ans = ta;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}