#include <bits/stdc++.h>
using namespace std;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc285/tasks/abc285_d
// グラフっぽい
// a->b
// b->c
// c->d
// ならなんとかなる
// a->b
// b->c
// c->a
// だと詰む
// 有向グラフにループができるかどうかを判定すればOK

int N; 
string s[100005];
string t[100005];
// 更新による向き先（ない場合0）
int nextNode[100005];
int isVisited[100005];
bool hasLoop(int start, int x){
    if(x==0) return false;
    if(start==x) return true;
    isVisited[x] = 1;
    int y = nextNode[x];
    return hasLoop(start, y);
}

void solve(){ 
    cin >> N;
    // 更新前の文字列と番号
    map<string, int> bf;
    // 入力とマッピング
    for(int i=1;i<=N;++i){
        cin >> s[i] >> t[i];
        bf[s[i]] = i;
    }
    // 枝を張る
    for(int i=1;i<=N;++i){
        int j = bf[t[i]];
        if(j>0){
            nextNode[i] = j;
        }
    }
    // dfsでループ探索
    bool ng = false;
    for(int start=1;start<=N;++start){
        if(isVisited[start]) continue;
        ng = hasLoop(start, nextNode[start]);
        if(ng) break;
    }

    cout << (ng ? Linn : Liny);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}