#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc211/tasks/abc211_b
// やるだけ
// ・フラグを4つ用意する
// ・ソートして調べる
// ・map を使う
// のどれを採用してもOK
void solve(){ 
    map<string,int> mp;
    string s;
    REP(i,4){
        cin >> s;
        ++mp[s];
    }
    bool ok = true;
    for(string x:{"H","2B","3B","HR"}){
        if(mp[x]!=1) ok = false;
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}