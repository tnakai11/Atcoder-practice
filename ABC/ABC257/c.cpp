#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
#define pii pair<int,int>
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc257/tasks/abc257_c
// ややこしいなあ
// 体重順にソートしてXを上げていけばO(N log N)
void solve(){ 
    // input
    int N; cin >> N;
    string s; cin >> s;
    vector<int> w(N); CINA(w,N);

    // setup
    vector<pii> v(N);
    REP(i,N){
        v[i] = MP(w[i],s[i]-'0');
    }
    sort(ALL(v));
    int ans = 0;
    int cand = 0;

    // X = 0
    for(pii p:v){
        if(p.second==1) ++cand;
    }
    chmax(ans,cand);

    // X = wi
    REP(i,N){
        pii p = v[i];
        int border = p.first;
        if(p.second==0){
            ++cand;
        }else{
            --cand;
        }
        if(i+1<N && v[i+1].first==border) continue;
        chmax(ans,cand);
    }
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}