#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc268/tasks/abc268_b
// 頭から一文字ずつ比較すればOK
bool solve(){ 
    string s,t; cin >> s >> t;
    if(s.size()>t.size()){
        return false;
    }
    REP(i,s.size()){
        if(s[i]!=t[i]) return false;
    }
    return true;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  cout << (solve()?Liny:Linn);
  return 0;
}