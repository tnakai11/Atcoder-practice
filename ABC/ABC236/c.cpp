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
// https://atcoder.jp/contests/abc236/tasks/abc236_c
// map で OK
// sort して尺取りするのでもいけそうではある
void solve(){ 
    int N,M; cin >> N >> M;
    vector<string> v(N); CINA(v,N);
    map<string,int> mp;
    REP(i,M){
        string t; cin >> t;
        ++mp[t];
    }
    for(auto s:v){
        cout << (mp[s]>0?Liny:Linn);
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}