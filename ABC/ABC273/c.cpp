#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
// https://atcoder.jp/contests/abc273/tasks/abc273_c
// A の中身を set で格納して位置を調べればOK
// set は distance の計算量 O(N) だったか。。。
int a[200005];
set<int> s;
map<int, int> mp;
void solve(){ 
    int N; cin >> N;
    REP(i,N){
        cin >> a[i];
        s.insert(a[i]);
    }
    vector<int> v(ALL(s));
    sort(ALL(v));
    REP(i,N){
        auto iter = lower_bound(ALL(v),a[i]);
        int index = distance(v.begin(),iter);
        int k = v.size() - (index+1);
        if(DEBUG) cout << k << ' ';
        ++mp[k];
    }
    if(DEBUG) cout << '\n';
    for(int k=0;k<=N-1;++k){
        cout << mp[k] << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}