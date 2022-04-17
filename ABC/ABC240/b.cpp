#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc240/tasks/abc240_b
// map を使えばOK
void solve(){ 
    int N; cin >> N;
    map<int,int> mp;
    REP(i,N){
        int a; cin >> a;
        ++mp[a];
    }
    cout << mp.size() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}