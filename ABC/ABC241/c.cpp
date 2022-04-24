#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc241/tasks/abc241_c
// 尺取りしながら全探索でたぶんいける
// 斜めは２種類あることに注意する
// WA 
// k が小さいので愚直に書いてみる
// AC

bool isOK(int blackNum){
    return blackNum>=4;
}

void solve(){ 
    int N; cin >> N;
    string board[N];
    REP(i,N) cin >> board[i];

    bool ok = false;
    // 横
    REP(h,N){
        REP(w,N){
            if(w+5>=N) break;

            int blackNum = 0;
            REP(d,6){
                int nextH = h;
                int nextW = w+d;
                blackNum += (board[nextH][nextW]=='#');
            }
            ok = isOK(blackNum);
            if(ok){
                cout << Liny; return;
            }
        }
    }
    // 縦
    REP(w,N){
        REP(h,N){
            if(h+5>=N) break;

            int blackNum = 0;
            REP(d,6){
                int nextH = h+d;
                int nextW = w;
                blackNum += (board[nextH][nextW]=='#');
            }
            ok = isOK(blackNum);
            if(ok){
                cout << Liny; return;
            }
        }
    }
    // 斜め1
    REP(h,N){
        if(h+5>=N) break;
        REP(w,N){
            if(w+5>=N) break;

            int blackNum = 0;
            REP(d,6){
                int nextH = h+d;
                int nextW = w+d;
                blackNum += (board[nextH][nextW]=='#');
            }
            ok = isOK(blackNum);
            if(ok){
                cout << Liny; return;
            }
        }
    }
    // 斜め2
    REP(h,N){
        if(h+5>=N) break;
        REP(w,N){
            if(w-5<0) continue;

            int blackNum = 0;
            REP(d,6){
                int nextH = h+d;
                int nextW = w-d;
                blackNum += (board[nextH][nextW]=='#');
            }
            ok = isOK(blackNum);
            if(ok){
                cout << Liny; return;
            }
        }
    }

    cout << Linn;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}