#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc247/tasks/abc247_b
// 姓名を数え上げてから各人について他人とダブらない姓or名があるかチェック
// WA
// 「自分以外」がネックか...
struct person{
    string s,t;
};
void solve(){ 
    int N; cin >> N;
    vector<person> p(N);
    map<string, int> mp;
    REP(i,N){
        string s,t; cin >> s >> t;
        p[i].s = s;
        p[i].t = t;
        ++mp[ s ];
        ++mp[ t ];
    }
    bool ok = true;
    for(auto e:p){
        if(mp[e.s]>1 && mp[e.t]>1){
            if(mp[e.s]==2 && e.s==e.t) continue;
            ok = false;
            break;
        }
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}