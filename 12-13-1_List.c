#include<stdio.h>
#include<stdlib.h>

struct List {
  int Value; //データ部分
  int isEnd; //最後だったら1;
  struct List *Next; //次のデータ構造体
};

int Add(struct List *p,int val){
  struct List *CurrentPointer = p;
  int Count = 0;
  for(;;Count++){
    if(CurrentPointer -> isEnd != 1){ //最後でない
      CurrentPointer = CurrentPointer -> Next; //調べるポインタを入れ替える。
      continue;
    }
    CurrentPointer -> isEnd = 0; //最後でなくなるので
    struct List *newlist; //連結するデータを作成して
    newlist = (struct List*)malloc(sizeof(struct List)); //メモリ確保をして
    newlist -> isEnd = 1; //最後なので設定して
    newlist -> Value = val; //追加する値を入れる。
    CurrentPointer -> Next = newlist; //データ列に追加
    break;
  }
  return Count + 1; //リストの個数を入れる(最初は0で個数は「0が一つ」なので+1)
}

int PrintAll(struct List *p){ //すべての要素を表示
  struct List *CurrentPointer = p;
  int Count = 0;
  for(;;Count++){
    printf("%d,",CurrentPointer -> Value); //表示
    if(CurrentPointer -> isEnd == 1) break; //そのデータが最後だったら終了
    CurrentPointer = CurrentPointer -> Next;
  }
  return Count + 1; //返り値として、リストの要素数を返す。
}

int Del(struct List *p,int Number) {
  if(Number == 0){ //一番最初だったら、前回の結果を参考に消去ができないため、別の処理を用意する。
    //具体的には、最初の値をfreeして、そこに別のインスタンスをつっこみ、Nextに三つ目のポインタを入れる。
    //freeせずにそのままインスタンスを作る方向に変更
    struct List tmp = *p;
    p = (struct List*)malloc(sizeof(struct List));
    p -> Value = tmp.Next -> Value;
    p -> Next = tmp.Next -> Next;
  }
  struct List *CurrentPointer = p;
  int Result = 0;
  for(int Count = 0;;Count++){
    if(Count == Number - 1) { //消す奴の一個前まで来たら
      Result = CurrentPointer -> Next -> Value;
      struct List *tmp = CurrentPointer -> Next;
      CurrentPointer -> Next = CurrentPointer -> Next -> Next;
      free(tmp);
      break;
    }
    CurrentPointer = CurrentPointer -> Next;
  }
  return Result;
}

void freeall(struct List *p) { //リストすべてのメモリの開放
  struct List *CurrentPointer = p;
  struct List *tmp;
  for(;;){
    if(CurrentPointer -> isEnd == 1) break; //最後だったら終了
    tmp = CurrentPointer -> Next; //次で開放してしまうため、次のポインターの情報を取っておく。
    free(CurrentPointer); //開放
    CurrentPointer = tmp; //次
  }
}

void Init(struct List **p,int val) { //リスト最初の要素を初期化
  *p = (struct List*)malloc(sizeof(struct List)); //メモリを確保して、
  (*p) -> Value = val; //値を入れ、
  (*p) -> isEnd = 1; //最後であることを指定する。
  /*
    struct List **pとなっているのは、ポインタのポインタを渡して、それにmalloc
    してもらったら、「ポインタが参照渡し」され、向こう(この関数)で値が書き換わるから。
  */
}

int main(void){
  struct List *list; //リスト作成。
  Init(&list,10); //最初の要素を初期化。

  Add(list,20);
  Add(list,30);
  Add(list,50);
  Add(list,80);

  PrintAll(list);


  printf("\n");
  return 0;

}
