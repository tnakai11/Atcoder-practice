#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc229/tasks/abc229_a
// 条件より##** or **## or #*#* or *#*# のいずれかが成立すればOK
void solve(){ 
    vector<string> s(2);
    CINA(s,2);
    bool ok = false;
    for(auto e:s){
        if(e=="##"){
            ok = true;
        }
    }
    REP(j,2){
        char c = s[0][j];
        char d = s[1][j];
        if(c=='#' && c==d){
            ok = true;
        }
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}
