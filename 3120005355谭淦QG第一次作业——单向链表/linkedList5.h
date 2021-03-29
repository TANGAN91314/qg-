#ifndef _LINKEDLIST5_H_
#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

LNode* createlist(void);
Status InitList(LinkedList *L);

void DestroyList(LinkedList *L);


Status InsertList(LNode *p, LNode *q);


Status DeleteList(LNode *p, ElemType *e);

TraverseList(LinkedList L, void (*visit)(ElemType e));


Status SearchList(LinkedList L, ElemType e);


Status ReverseList(LinkedList *L);


Status IsLoopList(LinkedList L);


LNode* ReverseEvenList(LinkedList *L);


LNode* FindMidNode(LinkedList *L);
#endif  _LINKEDLIST5_H_

