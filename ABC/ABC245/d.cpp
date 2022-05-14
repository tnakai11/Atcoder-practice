#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
typedef long double ld;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc245/tasks/abc245_d

// 総当たりは O(201^M) となり無理

// N,Mの値でいちいち場合分けするのは厳しい

// N=1,M=1 の場合
// A(x) = A1 x + A0
// B(x) = B1 x + B0
// C0 = A0 B0 
// C1 = A1 B0 + A0 B1
// C2 = A1 B1
// C0, C2 だけでOK

// N=1,M=2 の場合
// A(x) = A1 x + A0
// B(x) = B2 x^2 + B1 x + B0
// C0 = A0B0
// C1 = A0B1 + A1B0
// C2 = A0B2 + A1B1
// C3 = A1B2

// N=2,M=2 の場合
// A(x) = A2 x^2 + A1 x + A0
// B(x) = B2 x^2 + B1 x + B0
// C0 = A0B0
// C1 = A1B0 + A0B1
// C2 = A2B0 + A1B1 + A0B2
// C3 = A2B1 + A1B2
// C4 = A2B2

// B0 から順に解いていけば何とかなる ... ?

// N=2,M=3 の場合
// A(x) = A2 x^2 + A1 x + A0
// B(x) = B3 x^3 + B2 x^2 + B1 x + B0
// C0 = A0B0
// C1 = A1B0 + A0B1
// C2 = A2B0 + A1B1 + A0B2 
// C3 = A2B1 + A1B2 + A0B3
// C4 = A2B2 + A1B3
// C5 = A2B3 

// RE ゼロ除算にぶつかる
// |AN|>0 なので上から決めていこう 

ll a[105];
ll b[105];
ll c[205];

void solve(){ 
    const int DEF = -500;
    int N,M; cin >> N >> M;
    REP(i,N+1) cin >> a[i];
    REP(j,M+1) b[j] = DEF;
    REP(k,N+M+1) cin >> c[k];

    for(int k=N+M+1;k>=0;--k){
        int temp = c[k];
        for(int j=min(k,M);j>=0;--j){
            int i = k-j;
            if(min(k,N)<i) continue;
            if(i<0) continue;
            if(i==min(k,N)){ 
                b[j] = temp / a[i];
            }else{
                temp -= b[j] * a[i];
            }
        }
        if(b[0]!=DEF) break;
    }
    REP(j,M+1){
        cout << b[j] << (j<M?' ':'\n');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}