#ifndef LIST_H
#define LIST_H

struct List;

int Add(struct List *p,int val);

int PrintAll(struct List *p);

int Del(struct List *p,int Number);

void freeall(struct List *p);

void Init(struct List **p,int val);

int GetSum(struct List *p);

int Count(struct List *p);

#endif