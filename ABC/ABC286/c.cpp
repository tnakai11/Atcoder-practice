#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
// https://atcoder.jp/contests/abc286/tasks/abc286_c
// Nが小さいのでO(N^2)の愚直で通せそう
void solve(){ 
    int N; cin >> N;
    ll A,B; cin >> A >> B;
    string s; cin >> s;
    string t = s + s;
    ll ans = (A+B)*N;
    REP(start,N){
        ll cand = A * start;
        int l = start;
        int r = start+ N-1;
        while(l<r){
            if(DEBUG)cout << l << r << endl;
            if(t[l]!=t[r]) cand += B;
            ++l;
            --r;
        }
        chmin(ans,cand);
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}