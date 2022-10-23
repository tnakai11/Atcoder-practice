#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define MP make_pair
bool DEBUG = 0;
// https://atcoder.jp/contests/abc274/tasks/abc274_c
// 木の深さをDPで調べて O(N)
int depth[400005];
void solve(){ 
    // setup
    int N; cin >> N;
    int M = N*2+1;
    // make tree
    for(int i=1;i<=N;++i){
        int a; cin >> a;
        depth[i*2] = depth[a] + 1;
        depth[i*2+1] = depth[a] + 1;
    }
    // answer
    for(int k=1;k<=M;++k){
        cout << depth[k] << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}