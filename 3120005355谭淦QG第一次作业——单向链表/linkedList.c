#include <stdio.h>
#include "linkedList5.h"
#include "malloc.h"

#define FALSE 0

#define OK  1

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	LNode* head;
	head = (LNode*)malloc(sizeof(LNode));

	head->data = 0;
	head ->next = NULL;
	*L = head;
	return OK;

}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	if (*L == NULL) {
		printf("链表本来为空，不用删除");
	}
	//}
	//LinkedList cur1,cur2;
	//cur1 = *L;
	//cur2 = cur1->next;
	//while (cur2) {
	//	free(cur1);
	//	cur2 = cur2->next;
	//	cur1 = cur2;
	//}
		LinkedList cur;
		while (*L) {
			cur = (*L)->next;
			free(*L);
			*L = cur;
		}
		printf("删除成功！");

	

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if (p == NULL) { return FALSE; }
	LNode* cur = (LNode*)malloc(sizeof(LNode));
	cur = p->next;
	p->next = q;
	//q->next = cur;
	return OK;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if (p == NULL||p->next ==NULL) { printf("输入要删除的链表本来为空或者下一位为空，不用删除！");return FALSE; }

	LNode* cur2 = (LNode*)malloc(sizeof(LNode));
	cur2 = p;
	
	*e = cur2->next->data;
	p = cur2->next;
	cur2->next = cur2->next->next;

	free(p);
	printf("删除节点的数据为%d", *e);
	return OK;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
 TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode* p;
	p = L;
	while (p) {
		visit(p->data);
		p = p->next;
	}
}
 visit(ElemType e)
{
	printf("%d ", e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode* cur = (LNode*)malloc(sizeof(LNode));
	int* p;
	cur = L;
	for (int i = 0;cur!=NULL;i++) { 
		if (cur->data == e) { 
			printf("找到了该值对应的索引，其对应的索引为%d\n", i );
			p = &e;
			*p = i + 1;
			return OK; }
		cur = cur->next;
		
	}

	return FALSE;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	//这是我自己理解的链表反转方法，我觉得思路很清晰
	if (!(*L) && !(*L)->next)
	{
		return ERROR;
	}
	LNode* cur1, * cur2, * cur3;		
	cur1 = *L;
	cur2 = (*L)->next;				
	cur1->next = NULL;
	while (cur2) {
		cur3 = cur2->next;			
		cur2->next = cur1;		
		cur1 = cur2;				
		cur2 = cur3;
	}
	*L = cur1;					

	//if (L == NULL) { return FALSE; }
	//LNode* cur1, * cur2, * cur3;

	//cur1 = *L;
	//cur2 = cur1->next;
	//cur3 = cur1->next->next;
	//while (cur3!=NULL)
	//{
	//	cur2->next = cur1;
	//	cur1 = cur2;
	//	cur2 = cur3;
	//	cur3 = cur3->next;
	//}
	////最后一个还没有反转
	//cur2->next = cur1;
	//*L = cur2;
	return OK;
	
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	//LNode* cur1 = (LNode*)malloc(sizeof(LNode));
	//LNode* cur2 = (LNode*)malloc(sizeof(LNode));
	//cur1 = L;
	//cur2 = L;
	//for (;cur2 != NULL;) {
	//	cur1 = cur1->next;
	//	cur2 = cur2->next->next;
	//	if (cur2->data == cur1->data) { 
	//		printf("改链表为圈圈链表");
	//		return OK; }
	//}
	//printf("该链表为单向链表");
	//return FALSE;
	LNode* cur1, * cur2;
	cur2 = cur1 = L;				
	while (cur2 && cur1->next) {
		cur1 = cur1->next;			
		cur2 = cur2->next->next;	
		if (cur1 == cur2)
		{
			printf("这个是个圈圈表\n");
			return SUCCESS;
		}
	}
	printf("这个是个单向链表\n");
	return ERROR;

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

	

	LNode* pre, * mid, * Next;		//前中后指针，和反转差不多而已
	pre = *L;
	*L = pre->next;
	while (pre && pre->next) {
		mid = pre->next;
		Next = mid->next;
		if (mid->next && mid->next->next) {			
			pre->next = mid->next->next;			
		}
		else {										
			pre->next = mid->next;
		}
		mid->next = pre;							
		pre = Next;
	}
	return *L;

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LNode* cur1 = (LNode*)malloc(sizeof(LNode));
	LNode* cur2 = (LNode*)malloc(sizeof(LNode));
	cur1 = *L; cur2 = *L;
	for (;cur2 != NULL;) {
		cur2 = cur2->next->next;
		cur1 = cur1->next;

	
	}
	return cur1;
}

