#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){ if(DEBUG){ cout << s << "\n"; } }
template<class T> void printVec(vector<T> v){ int v_size = v.size(); int i = 0; for(const auto & e:v){ cout << e << (i<v_size-1?' ':'\n'); ++i; } }
// https://atcoder.jp/contests/abc254/tasks/abc254_c
// 入れ替え可能なペアが固定されている
// ペアごとに昇順ソートするのが最善手なのでそれで無理なら無理
// WA
// ペアごとでなく mod K のグループごとか
void solve(){ 
    int N,K; cin >> N >> K;
    vector<int> a(N); REP(i,N) cin >> a[i];
    vector<int> checked(N,0);
    
    REP(i,N-K){
        if(checked[i]) continue;
        vector<int> idxs,vals;
        REP(x,N){
            int idx = i + K*x;
            if(idx>=N) break;
            idxs.emplace_back(idx);
            vals.emplace_back(a[idx]);
        }
        sort(ALL(vals));
        REP(x,idxs.size()){
            int idx = idxs[x];
            a[idx] = vals[x];
            checked[idx] = 1;
        }
    }
    if(DEBUG) printVec(a);

    bool ok = true;
    REP(i,N-1){
        if(a[i] > a[i+1]) {
            ok = false;
            break;
        }
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}