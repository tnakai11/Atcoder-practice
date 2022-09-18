#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc269/tasks/abc269_b
// #が存在する文字列の両端がA,B
// #が存在する位置の両端がC,D
// index に注意
void solve(){ 
    int N = 10;
    int M = 10;
    string s[N]; CINA(s,N);
    int A = -1;
    int B = -1;
    int C = -1;
    int D = -1;
    REP(i,N){
        REP(j,M){
            char c = s[i][j];
            if(c=='.') continue;
            if(A==-1){
                A = i+1;
            }
            B = i+1;
            if(C==-1){
                C = j+1;
            }
            D = max(D,j+1);
        }
    }
    printf("%d %d\n%d %d\n",A,B,C,D);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}