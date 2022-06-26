#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
template<class T> void printVec(vector<T> v){ int v_size = v.size(); int i = 0; for(const auto & e:v){ cout << e << (i<v_size-1?' ':'\n'); ++i; } }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc257/tasks/abc257_b
// 左からLi番目のコマを毎回愚直に調べると O(NQ) で操作が終わる
// 飛び越し操作がないのでコマを左から順に収めた配列を使えばO(Q) 
void solve(){ 
    int N,K,Q; cin >> N >> K >> Q;
    vector<int> a(K); CINA(a,K);
    REP(q,Q){
        int l; cin >> l;
        --l;
        int position = a[l];
        int next = position + 1;
        if(next>N) continue;
        if(l+1<K && next==a[l+1]) continue;
        a[l] = next;
    }
    printVec(a);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}