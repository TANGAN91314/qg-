#include<stdio.h>
#include "duLinkedList.h"
#include "malloc.h"

int main() {
	int insert;
	int index;
	int n;
	DuLNode* head,*insertList,*newHead;
	printf("请输入您要输入的链表：\n");

	void chooseview();
	head = createlist();
	getchar();
	
	char flag1;

	printf("输入 y 就会继续操作！\n");
	getchar();
	char flag3;
	flag3 = getchar();
 while (flag3 == 'y') {
	chooseview();
	getchar();
	printf("请输入数字进行对应的操作\n");
	flag1 = getchar();
	switch (flag1)
	{
	case '1':
		printf("请输入整数");
		head = createlist();getchar();getchar();
		printf("操作过后的链表为：\n");
		link_print1(head);getchar();getchar();
		break;
	case '2':DestroyList_DuL(&head);
		printf("操作过后的链表为：\n");
		link_print1(head);getchar();getchar();
		break;


	case '3':

		printf("请创建你像插入的链表\n");
		printf("链表开始创建，请耐心等待！\n");
		insertList = (createlist())->next;getchar();getchar();
		printf("请输入你想插入的位置：");
		scanf("%d", &index);
		newHead = head;
		for (int i = 0; i < index&&newHead!=NULL;i++) {
			newHead = newHead->next;
		}
		InsertBeforeList_DuL(newHead, insertList);
		printf("操作过后的链表为：\n");
		link_print1(head);getchar();getchar();
		break;

	case '4':		
		printf("请创建你像插入的链表\n");
		printf("链表开始创建，请耐心等待！\n");
		insertList = (createlist())->next;
		link_print1(insertList);
		getchar();getchar();
		printf("请输入你想插入的位置：");
		scanf("%d", &index);
		//newHead = (DuLNode*)malloc(sizeof(DuLNode));
		newHead = head;
		for (int i = 0; i < index;i++) {
			newHead = newHead->next;
		}
		InsertAfterList_DuL(newHead, insertList);
		printf("操作过后的链表为：\n");
		link_print1(head);getchar();getchar();
		break;
	case '5': 		
		printf("请输入你想删除的位置：");
		scanf("%d", &index);
		//newHead = (DuLNode*)malloc(sizeof(DuLNode));
		newHead = head;
		for (int i = 0; i < index;i++) {
			newHead = newHead->next;
		}
		DeleteList_DuL(newHead, &n);

	case '6':
		link_print1(head);




	default:printf("您输入有误，请重新输入");
		break;
	}

	printf("输入 y 就会继续操作！\n");
	getchar();
	scanf("%c", &flag3);
	
}


}
DuLNode* createlist() {
	DuLNode* head = NULL, * p, * q = NULL;
	int n, i = 1;
	p = (DuLNode*)malloc(sizeof(DuLNode));
	head = (DuLNode*)malloc(sizeof(DuLNode));
	p = head;

	head->prior = NULL;
	head->next = NULL;
	while (scanf("%d", &n) == 1)//当输入不为整数时结束
	{
		printf("当输入不是整数时候结束\n");

		q = (DuLNode*)malloc(sizeof(DuLNode));
		printf("请输入链表的第%d个节点的值:", i);


		if (i == 1) {
			printf("链表的第一个节点应该为空节点；\n");

		}

		if (i >= 2) {
			q = (DuLNode*)malloc(sizeof(DuLNode));

			q->data = n;
			p ->next = q;
			q->prior = p;
			q->next = NULL;
			p = q;
			q = NULL;
			
			

		}
		//我用头cha法进行判断
		//else if(head->next!=NULL)
		//{
		//	
		//	p->data = n;
		//	LINK(p, head->next);
		//	LINK(head, p);
		//}

		i++;

	}
	return head;
}

void chooseview() {
	printf("*************************************************************\n");
	printf("请输入您要进行的操作：\n");
	printf("1 初始化链表\n");
	printf("2 删除整个链表\n");
	printf("3 前插入\n");
	printf("4 后插入\n");
	printf("5 删除链表的输入链表节点，重复这节点的下个值为输入值\n");
	printf("6 遍历链表\n");


	printf("**************************************************************\n");

}


 link_print1(DuLinkedList  head)
{
	 //if (head == NULL) {
		// prtint("该链表是个空链表！\n");
	 //}
	DuLNode* p_mov ;
	p_mov = head;
	if (p_mov == NULL||p_mov ->next == NULL) {
		printf("该链表为空链表！\n");
	}
	else {
		printf("这个链表为:\n");
		p_mov = p_mov->next;

		while (p_mov != NULL)//条件为当前节点，遍历时主要显示当前节点
		{
			printf("%d\n", p_mov->data);
			p_mov = p_mov->next;

		}
	}

}