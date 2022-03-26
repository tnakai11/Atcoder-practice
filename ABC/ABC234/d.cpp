#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc234/tasks/abc234_d
// i=N の場合はソートするまでもなくN-K+1が答え
// i=K の場合はp[1]~p[K] をソートした後の p[K] が答え
// p_sort[K] より値が小さい p[i] -> 出力されない
// p_sort[K] より値が大きい p[i] -> 出力されるかもしれない 
// -> ヒープに突っ込む？

void solve(){ 
    int N,K; cin >> N >> K;
    int p[N+1]; 
    for(int i=1;i<=N;++i) cin >> p[i];
    sort(p+1,p+K+1,greater<int>());

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > q;

    for(int i=1;i<=K;++i){
        q.push( p[i] );
    }

    cout << q.top() << '\n';

    for(int i=K+1;i<=N;++i){
        if(p[i]>q.top()){
            q.push(p[i]);
            q.pop();
        }
        cout << q.top() << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}