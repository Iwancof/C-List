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

int PrintAll(struct List *p){
  struct List *CurrentPointer = p;
  int Count = 0;
  for(;;Count++){
    printf("%d,",CurrentPointer -> Value); //表示
    if(CurrentPointer -> isEnd == 1) break; //そのデータが最後だったら終了
    CurrentPointer = CurrentPointer -> Next;
  }
  return Count + 1;
}

int Del(struct List *p,int Number) {
  struct List *CurrentPointer = p;
  int Result = 0;
  for(int Count = 0;;Count++){
    if(Count == Number - 1) { //消す奴の一個前まで来たら
      Result = CurrentPointer -> Next -> Value;
      CurrentPointer -> Next = CurrentPointer -> Next -> Next;
    }
    CurrentPointer = CurrentPointer -> Next;
  }
  return Result;
}

int main(void){
  struct List *list;
  list = (struct List*)malloc(sizeof(struct List));
  list -> isEnd = 1;
  list -> Value = 10;

  int x = 0;

  x = Add(list,30);
  Add(list,100);
  Add(list,987654);
  Add(list,114514);
  Del(list,1);
  x = PrintAll(list);

  printf("%d\n" ,x);

  return 0;

}
