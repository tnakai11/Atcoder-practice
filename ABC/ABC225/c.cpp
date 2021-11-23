#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA2(a,n,m) REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc225/tasks/abc225_c
// B_ij = (i-1)*7 + j より
// B_(i+1)j = i*7 + j だから

// B_(i+1)j - B_ij = 7
// 同様に
// B_i(j+1) - B_ij = 1
// これらは必要条件なのであと一手必要である
// 1 2 3 4 5 6 0 mod 7 の並び順を崩さない

void solve(){ 
    int N,M; cin >> N >> M;
    int b[N][M]; CINA2(b,N,M);
    bool ok = true;
    REP(j,M-1){
        if(b[0][j]%7==0){ 
            ok=false; break;
        }
    }
    REP(i,N){
        if(!ok) break;
        REP(j,M-1){
            if(b[i][j+1]-b[i][j]!=1){
                ok = false; break;
            }
        }
    }
    REP(j,M){
        if(!ok) break;
        REP(i,N-1){
            if(b[i+1][j]-b[i][j]!=7){
                ok = false; break;
            }
        }
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}