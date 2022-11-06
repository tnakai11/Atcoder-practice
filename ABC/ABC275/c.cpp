#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
#define ALL(a) (a).begin(),(a).end()
template<class T> void printVec(vector<T> v){ int v_size = v.size(); int i = 0; for(const auto & e:v){ cout << e << (i<v_size-1?' ':'\n'); ++i; } }
// https://atcoder.jp/contests/abc275/tasks/abc275_c
// 斜めがあるか...
// 4点全探索で 9^2^4 = 9^8 通り
// 重複は割ろう
struct point{
    int h,w;
};
int N = 9;
string board[9];
bool isSame(int h1,int w1, int h2, int w2){
    return h1==h2 && w1==w2;
}
bool exist(int h, int w){
    return board[h][w] == '#';
}
bool isSquare( int h1, int w1, int h2, int w2, int h3, int w3, int h4, int w4){
    vector<int> v(6);
    v[0] = (h1-h2)*(h1-h2) + (w1-w2)*(w1-w2);
    v[1] = (h1-h3)*(h1-h3) + (w1-w3)*(w1-w3);
    if(v[0]!=v[1] && v[0]!=v[1]*2 && v[0]*2!=v[1]) return false;
    v[2] = (h1-h4)*(h1-h4) + (w1-w4)*(w1-w4);
    if(v[1]!=v[2] && v[1]!=v[2]*2 && v[1]*2!=v[2]) return false;
    v[3] = (h2-h3)*(h2-h3) + (w2-w3)*(w2-w3);
    if(v[2]!=v[3] && v[2]!=v[3]*2 && v[2]*2!=v[3]) return false;
    v[4] = (h2-h4)*(h2-h4) + (w2-w4)*(w2-w4);
    if(v[3]!=v[4] && v[3]!=v[4]*2 && v[3]*2!=v[4]) return false;
    v[5] = (h3-h4)*(h3-h4) + (w3-w4)*(w3-w4);
    if(v[4]!=v[5] && v[4]!=v[5]*2 && v[4]*2!=v[5]) return false;
    sort(ALL(v));
    if(v[0]==0) return false;
    if(v[1]!=v[0]) return false;
    if(v[2]!=v[0]) return false;
    if(v[3]!=v[0]) return false;
    if(v[4]!=v[0]*2) return false;
    if(v[5]!=v[0]*2) return false;
    return true;
}
void solve(){ 
    REP(i,N){
        cin >> board[i];
    }
    int ans = 0;
    REP(h1,N){
        REP(w1,N){
            if(!exist(h1,w1)) continue;
            REP(h2,N){
                REP(w2,N){
                    if(isSame(h1,w1,h2,w2)) continue;
                    if(!exist(h2,w2)) continue;
                    REP(h3,N){
                        REP(w3,N){
                            point p3 = {h3,w3};
                            if(isSame(h1,w1,h3,w3)) continue;
                            if(isSame(h2,w2,h3,w3)) continue;
                            if(!exist(h3,w3)) continue;
                            REP(h4,N){
                                REP(w4,N){
                                    if(isSame(h1,w1,h4,w4)) continue;
                                    if(isSame(h2,w2,h4,w4)) continue;
                                    if(isSame(h3,w3,h4,w4)) continue;
                                    if(!exist(h4,w4)) continue;
                                    if(!isSquare(h1,w1,h2,w2,h3,w3,h4,w4)) continue;
                                    ++ans;
                                }
                            }
                        }
                    }
                }
            } 
        } 
    }
    ans /= 4*3*2;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}