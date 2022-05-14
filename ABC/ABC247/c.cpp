#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc247/tasks/abc247_c
// 再帰でいけそう
// S_16.size() < 3^16 < 10^8
// WA
// string なのを忘れていた
string func(int n){
    if(n==1){
        return "1";
    }
    string b = func(n-1);
    return b + " " + to_string(n) + " " + b;
}
void solve(){ 
    int N; cin >> N;
    string ans = func(N);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}