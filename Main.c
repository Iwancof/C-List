#include<stdio.h>
#include<stdlib.h>
#include "List.h"


int main(void){
  //作ったリストで平均を求めるプログラムを作ってみる。
  //クラスの人数は10人、それぞれの点数をリストにいれる。

  struct List *list; //リスト作成。
  Init(&list); //最初の要素を初期化。

  for(int Count = 1;;Count++){
    int x;
    printf("%d人目の点数を入力してください。-1で終了します。",Count);
    scanf("%d",&x);
    if(x == -1) break;
    Add(list,x);
  }

  PrintAll(list); //すべて表示
  printf("\n");

  //機能テストのため、2人目のデータを消してみる。
  Del(&list,1);

  PrintAll(list); //消去後のデータをすべて表示
  printf("\n");

  float Ave = GetSum(list) / (float)Count(list); //平均を求める。
  printf("Ave = %.2f\n",Ave); //表示

  return 0;
}