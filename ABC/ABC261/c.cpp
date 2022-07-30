#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc261/tasks/abc261_c
// map で OK.  O(N log N)
void solve(){ 
    int N; cin >> N;
    map<string,int> mp;
    REP(i,N){
        string s; cin >> s;
        cout << s;
        if(mp[s]>0){
            cout << '(' << mp[s] << ')';
        }
        cout << '\n';
        ++mp[s];
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}