#ifndef LIST_H
#define LIST_H

typedef float ValueType;

struct List;

int Add(struct List *p,ValueType val);

int PrintAll(struct List *p);

ValueType Del(struct List **p,int Number);

void freeall(struct List *p);

void Init(struct List **p);

ValueType GetSum(struct List *p);

int Count(struct List *p);

#endif