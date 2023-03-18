#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc293/tasks/abc293_b
// 愚直にやればOK
void solve(){ 
    int N; cin >> N;
    map<int,int> called;
    for(int i=1;i<=N;++i){
        int a; cin >> a;
        if(called[i]) continue;
        called[a] = 1;
    }
    vector<int> v;
    for(int i=1;i<=N;++i){
        if(called[i]) continue;
        v.emplace_back(i);
    }
    int M = v.size();
    cout << M << '\n';
    for(int i=0;i<M;++i){
        cout << v[i] << (i<M-1?' ':'\n');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}