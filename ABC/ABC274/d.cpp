#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc274/tasks/abc274_d
// 条件に従って(0,0) から (x,y) にぴったり到着できるか
// 奇数条件はx軸、偶数条件はy軸を規定する
// 取り得る値が -10^4 ~ 10^4 程度なのでDPでよさそう
const int MAX = 30000;
const int BASE = MAX/2;
int dpX[505][MAX];
int dpY[505][MAX];
void solve(){ 
    // setup
    int N,X,Y; cin >> N >> X >> Y;
    vector<int> v,w;
    REP(i,N){
        int a; cin >> a;
        if(i==0) {
            dpX[0][a+BASE] = 1;
            dpY[0][BASE] = 1;
            continue;
        }
        if(i%2==0) v.emplace_back(a);
        else w.emplace_back(a);
    }
    // about x
    int index=1;
    for(int e:v){
        for(int x=0;x<MAX;++x){
            if(dpX[index-1][x]==1){
                if(DEBUG) cout << x << ' ';
                dpX[index][x+e] = 1;
                dpX[index][x-e] = 1;
            }
        }
        ++index;
    }
    if(dpX[index-1][X+BASE]!=1){
        cout << Linn;
        return;
    }
    // about y
    int jndex=1;
    for(int e:w){
        for(int y=0;y<MAX;++y){
            if(dpY[jndex-1][y]==1){
                dpY[jndex][y+e] = 1;
                dpY[jndex][y-e] = 1;
            }
        }
        ++jndex;
    }
    if(dpY[jndex-1][Y+BASE]!=1){
        cout << Linn;
        return;
    }
    // ok
    cout << Liny;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}