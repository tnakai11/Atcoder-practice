#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc286/tasks/abc286_a
// for文で愚直にやる
// 配列を新しく作るか注意して出力するかは選べそう
int a[105];
int b[105];
void solve(){ 
    int N,P,Q,R,S; cin >> N >> P >> Q >> R >> S;
    for(int i=1;i<=N;++i){
        cin >> a[i];
        b[i] = a[i];
    }
    for(int i=P; i<=Q;++i){
        int index = (i-P);
        int j = R + index;
        b[i] = a[j];
        b[j] = a[i];
    }
    for(int i=1; i<=N;++i){
        cout << b[i] << (i<N?' ':'\n');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}