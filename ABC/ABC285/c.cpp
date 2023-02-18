#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc285/tasks/abc285_c
// c = (A~Zの文字数) とすると
// IDの長さがnである問題の数... c^n
// またIDの長さがnである問題についてあるIDが何番目なのかは
// ID文字列をc進数と解釈すればわかる
// よって入力Sに対する答えは sum_{i=1}^{len(S)-1} c^i + num(S) + 1
const ll c = 'Z' - 'A' + 1;
ll num(string s, int N){
    ll result = 0;
    ll temp = 1;
    for(int i=N-1;i>=0;--i){
        result += (s[i]-'A')*temp;
        temp *= c;
    }
    return result;
}
void solve(){ 
    string s; cin >> s;
    int N = s.size();
    ll ans = 1;
    ll temp = 1;
    for(ll i=1;i<N;++i){
        temp *= c;
        ans += temp;
    }
    ans += num(s,N);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}