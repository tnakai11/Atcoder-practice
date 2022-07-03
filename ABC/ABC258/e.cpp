#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc258/tasks/abc258_e
// 解説写経
// i個目のジャガイモから箱詰めを始めたとき次に箱詰めが始まるジャガイモを調べる 
// 尺取り法で O(N)
// K回遷移した結果をダブリングで計算 O(QlogK)
int w[200005];
int jump[200005];
void solve(){ 
    // load
    int N,Q,X; cin >> N >> Q >> X;
    CINA(w,N);

    // graph
    ll s = 0;
    REP(i,N) s += w[i];
    ll period = X/s;
    ll restW = X%s;

    // (尺取り)
    ll next = period * N;
    REP(i,N){
        while(restW >= 1){
            restW -= w[(i+next)%N];
            ++next;
        }
        jump[i] = next;
        --next;
        restW += w[i];
    }

    // For doubling
    int D = 41;
    vector< vector<int> > d(D,vector<int>(N)); // 2^i 回遷移するのを j から始めた場合の遷移先
    REP(j,N){
        d[0][j] = (j+jump[j])%N;
    }
    REP(i,D-1){
        REP(j,N){
            d[i+1][j] = d[i][ d[i][j] ];
        }
    }

    // answer
    REP(q,Q){
        ll K; cin >> K;
        --K;
        int si = 0;
        for(int i=D-1; i>=0;--i){
            if(K>>i&1) si = d[i][si];
        }
        cout << jump[si] << '\n';
    }
    
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}