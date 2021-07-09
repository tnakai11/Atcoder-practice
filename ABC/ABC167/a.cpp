#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc167/tasks/abc167_a
// |S|文字目までを比較すればOK
void solve(){ 
    string s,t; cin >> s >> t;
    REP(i,s.size()){
        if(s[i]!=t[i]){
            cout << "No\n"; return;
        }
    }
    cout << "Yes\n";
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}