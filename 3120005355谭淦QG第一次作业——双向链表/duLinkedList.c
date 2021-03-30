#include "duLinkedList.h"
#include"malloc.h"
#include <stdio.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L = (DuLinkedList)malloc(sizeof(DuLinkedList));
	if (!(*L))
		return ERROR;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return SUCCESS;
}


void DestroyList_DuL(DuLinkedList *L) {
	(*L) = (*L)->next;
	DuLinkedList cur;
	while (*L) {
		cur = (*L)->next;
		free(*L);
		*L = cur;
		if (cur)
			cur->prior = NULL;
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {

	if (!p)
		return ERROR;
	if (p->prior) {
		LINK(p->prior, q);
	}
	LINK(q, p);
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	
	if (!p) { return ERROR; }
	if (p->next) {
		LINK(q, p->next);
	}
	LINK(p, q);
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if (!p && !p->next)
		return ERROR;
	DuLNode* cur;
	cur = p->next;
	*e = cur->data;
	cur->next->prior = p;
	p->next = cur->next;
	printf("删除成功，删除的位置的值是%d", *e);
	free(cur);
	
	return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
 void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode* cur;
	cur = L;
	while (cur) {
		(*visit)(cur->data);
		cur = cur->next;
	}
}
 visit(ElemType e)
{
	printf("%d ", e);
}
 //连接p q 的函数
 void LINK(DuLNode* p, DuLNode* q) {
	 if (p != NULL && q != NULL) {
		 p->next = q;
		 q->prior = p;
	 }
 

 }
