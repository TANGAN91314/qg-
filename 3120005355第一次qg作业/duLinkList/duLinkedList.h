#ifndef _DULINKEDLIST_H_


typedef int ElemType;

typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

typedef enum Status {
	ERROR,
	SUCCESS,
} Status;
DuLNode* createlist();

Status InitList_DuL(DuLinkedList *L);

void DestroyList_DuL(DuLinkedList *L);

void LINK(DuLNode* p, DuLNode* q);
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);


Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);


Status DeleteList_DuL(DuLNode *p, ElemType *e);


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));


#endif  _DULINKEDLIST_H_