#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc217/tasks/abc217_c
// 配列を用意し順番に値を代入していけば O(N)
void solve(){ 
    int N; cin >> N;
    int q[N+1];
    for(int i=1;i<=N;++i){
        int p; cin >> p;
        q[p] = i;
    }
    for(int i=1;i<=N;++i){
        cout << q[i] << (i<N?' ':'\n');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}