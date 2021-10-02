#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc217/tasks/abc217_b
// map で調べれば O(N)
void solve(){ 
    map<string,int> mp;
    int M = 3;
    REP(i,M){
        string s; cin >> s;
        ++mp[s];
    }
    for(auto s: {"ABC","ARC","AGC","AHC"}){
        if(mp[s]==0){
            cout << s << '\n';
            break;
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}