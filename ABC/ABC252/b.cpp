#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc252/tasks/abc252_b
// 最大値と最大値を達成するインデックスをO(N)で調査すればOK
// インデックスが数列Bに含まれる場合 Yes
// インデックスが数列Bに含まれる場合 No
void solve(){ 
    // input
    int N,K; cin >> N >> K;
    vector<int> a(N); REP(i,N) cin >> a[i];
    map<int,int> mp;
    REP(count,K){
        int b; cin >> b;
        --b;
        ++mp[b];
    }
    // search max
    int max = 0;
    for(auto e:a){
        if(max<e) max = e;
    }
    // search index
    bool possible = false;
    REP(i,N){
        if(a[i]==max && mp[i]>0){
            possible = true;
            break;
        }
    }
    cout << (possible?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}