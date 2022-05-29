#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc249/tasks/abc249_c
// 全パターン検討すると高々 2^15 < 10^5 パターンなのでbit全探索でいける
void solve(){ 
    int N,K; cin >> N >> K;
    string s[N]; REP(i,N) cin >> s[i];

    int ans = 0;
    for(ll bits=0;bits<(1<<N);++bits){
        map<char,int> mp;
        for(ll i=0;i<N;++i){
            if( (bits>>i)&1 ){
                for(char c:s[i]){
                    ++mp[c];
                }
            }
        }
        int count = 0;
        for(char c='a';c<='z';++c){
            if(mp[c]==K){
                ++count;
            }
        }
        chmax(ans,count);
    }
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}