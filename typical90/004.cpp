#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA2(a,n,m) REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/typical90/tasks/typical90_d
// 愚直に計算すると 各マスの出力に O(H+W) かかる
// 総時間計算量は O(HW*(H+W)) であるから間に合わない
// 各行・各列の総和をメモしておけば 各マスの出力は O(1)
// メモに必要な時間計算量は O(HW)
// 総時間計算量も O(HW) となり間に合う

// 各マスで出力する値は sumRow[i] + sumColumn[j] - a[i][j] 
// a[i][j] を引くのは重複分を除くため

const int MAX = 2005;
int H,W;
int a[MAX][MAX];
vector<int> r(MAX,0);
vector<int> c(MAX,0);

void solve(){ 
    cin >> H >> W;
    CINA2(a,H,W);
    REP(i,H){
        REP(j,W){
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }
    REP(i,H){
        REP(j,W){
            int ans = r[i] + c[j] - a[i][j];
            cout << ans << ' ';
        }
        cout << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}