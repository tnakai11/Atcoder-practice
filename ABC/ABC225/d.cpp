#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc225/tasks/abc225_d
// データ構造を工夫する問題であろう
// 双方向リストぽいので何とかならんか
// 出力する電車の個数の合計が高々 10^6 なので
// 電車を舐める回数も高々 2 * 10^6 程度
struct train{
    int front = 0;
    int back = 0;
};
void solve(){ 
    int N; cin >> N;
    int Q; cin >> Q;
    train t[N+1];
    REP(q,Q){
        int order;
        cin >> order;
        if(order==1){
            int x,y; cin >> x >> y;
            t[x].back = y;
            t[y].front = x;
        }else if(order==2){
            int x,y; cin >> x >> y;
            t[x].back = 0;
            t[y].front = 0;
        }else{
            int x; cin >> x;
            while(t[x].front!=0){
                x = t[x].front;
            }
            vector<int> v;
            v.push_back(x);
            while(t[x].back!=0){
                v.push_back(t[x].back);
                x = t[x].back;
            }
            int M = v.size();
            cout << M << ' ';
            REP(m,M){
                cout << v[m] << (m<M-1?' ':'\n');
            }
        }
    }

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}