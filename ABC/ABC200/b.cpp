#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
// https://atcoder.jp/contests/abc200/tasks/abc200_b
// 愚直に操作するとNが 5^10 倍くらいになる可能性
// long long を使えばいけそう

void solve(){ 
    ll N,K; cin >> N >> K;
    REP(i,K){
        if(N%200==0){
            N /= 200;
        }else{
            N = N * 1000 + 200;
        }
    }
    cout << N << '\n';
}
int main(int argc, char *argv[]){
  solve();
  return 0;
}