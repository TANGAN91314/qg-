#include<stdio.h>
#include "linkedList5.h"
#include "malloc.h"
Status InitList(LinkedList* L);
void DestroyList(LinkedList* L);
Status InsertList(LNode* p, LNode* q);
Status DeleteList(LNode* p, ElemType* e);
TraverseList(LinkedList L, void (*visit)(ElemType e));
void link_print1(LinkedList head);
Status SearchList(LinkedList L, ElemType e);
Status ReverseList(LinkedList* L);
Status IsLoopList(LinkedList L);
void chooseview();
LNode* ReverseEvenList(LinkedList* L);
LNode* createlist(void);

LNode* FindMidNode(LinkedList* L);
LinkedList head;
int insertPosition;
LNode* p;
LNode* k;
LinkedList insert;

int main() {
	LinkedList head;
	printf("请输入您要输入的链表：\n");
	int n;
	int num;

	head = createlist();
	char flag1 ;
	LinkedList r;
	LinkedList k;
	printf("输入 y 就会继续操作！\n");
	getchar();
	getchar();
	char flag3;
	flag3 = getchar();

	LOOP: while (flag3 == 'y' ) {
		chooseview();

		printf("请输入数字进行对应的操作\n");
		
		getchar();
		flag1 = getchar();
		switch (flag1)
		{
		case '1':
			InitList(&head);		
			printf("操作后的链表为：");
			link_print1(head);break;
		case '2':DestroyList(&head);break;
			printf("操作后的链表为：");
			link_print1(head);
		case '3':
			printf("创建用于插入的链表\n");getchar();getchar();
			insert = createlist();
			printf("请输入您想输入head链表中的位置(在索引后插入):");
			getchar();getchar();
			scanf("%d", &n);
			p = head;
			for (int i = 0; i < n - 1&&p !=NULL;i++) {
				p = p->next;
			}
			InsertList(p, insert);
			printf("操作后的链表为：");
			link_print1(head);
			break;
		case '4':
			printf("请输入删除节点的位置：（索引的下一位就是删除的位置3索引对应删除第5位数:）请输入两次！！！\n");
			scanf("%d", &num);
			r = head;
			for (int i = 0;i < num && r != NULL;i++) {
				r = r->next;
			}

			DeleteList(r, &n);
			printf("删除节点的数据为%d\n", n);

			printf("操作后的链表为：");
			link_print1(head);
			break;
		case '5':	
			printf("请输入您要寻找的节点的那个依据数:\n");
			scanf("%d",&n);
			if (SearchList(head, n)) {
				printf("找到了该节点!!!!!!!!!!!!!!!!!!\n"); 
			}
			else printf("找不到该节点\n");

			break;

		case '6':
			ReverseList(&head);
			printf("操作后的链表为：");
			link_print1(head);
			break;

		case '7':	
			if (IsLoopList(head)) {
				printf("this is a 圈圈表\n");
			}
			else
			{
				
				printf("this is a 单向链表\n");
			}
			printf("我在里面把head弄成了循环链表，可以看main.c 102行");
			k = head->next->next;

			k->next = head;
			if (IsLoopList(head)) {
				printf("this is a 圈圈表\n");
			}
			else
			{
				printf("this is a 单向链表\n");
			}
			printf("head已经被我弄成圈圈表，请退出重新创建链表！！！！！！！");
			
			break;
		case '8':	head = ReverseEvenList(&head);
			link_print1(head);
			break;
		case '9':	link_print1(head);
			getchar();
			getchar();


		default:  
			break;
		}

		printf("输入 y 就会继续操作！");
		getchar();
		flag3 = getchar();

	}



	


	////link_print1(head);
	//// 基偶换单向链表
	//head = ReverseEvenList(&head);
	//link_print1(head);
	//head = createlist();
	////初始化链表
	//InitList(&head);
	//link_print1(head);
	//++++插入链表
	//head = createlist();
	//LinkedList k = head->next->next;

	//InsertList(head, k);
	//link_print1(head);
	//删除并且添加
	//head = createlist();
	//LinkedList k = head->next->next;
	//DeleteList(head, k);
	//link_print1(head);
	//链表反转
	//head = createlist();
	//ReverseList(&head);
	//link_print1(head);
	// 判断是否为循环链
	//head = createlist();
	//if (IsLoopList(head)) {
	//	printf("this is a 圈圈表\n");
	//}
	//else
	//{
	//	printf("this is a 单向链表\n");
	//}
	//LinkedList k = head->next->next;
	//k->next = head;
	//if (IsLoopList(head)) {
	//	printf("this is a 圈圈表\n");
	//}
	//else
	//{
	//	printf("this is a 单向链表\n");
	//}
	//查找
	//head = createlist();
	//if (SearchList(head, 3)) printf("找到了该函数");
	//else printf("找不到该函数");
	//

}

 LNode* createlist(void){
	 LNode* head = NULL, * p, * tail = NULL;
	 int n,i =2;
	 
	 printf("请输入链表的第1个节点的值:");
	 while (scanf("%d", &n) == 1)//当输入不为整数时结束
	 {
		 printf("输入除了整数外的字母会保存链表 \n");
		 p = (LNode*)malloc(sizeof(LNode));
		 printf("请输入链表的第%d个节点的值:", i);
		 if (head == NULL)
			 head = p;
		 else
			 tail->next = p;

		 p->data = n;
		 p->next = NULL;
		 tail = p;
		 i++;
	 }
	 return head;
 }

 void link_print1(LinkedList  head)
 {
	 LNode* p_mov = head;
	 printf("这个链表为:\n");
	 while (p_mov != NULL && p_mov->data != NULL)//条件为当前节点，遍历时主要显示当前节点 
	 {	
		 printf("%d\n", p_mov->data);
		 p_mov = p_mov->next;
	 }
 }
 void chooseview() {
	 printf("**************************************************************\n");
	 printf("请输入您要进行的操作：\n");
	 printf("1 初始化链表\n");
	 printf("2 删除整个链表\n");
	 printf("3 插入另外的链表,只再head后插入\n");
	 printf("4 删除链表的输入链表节点，重复这节点的下个值为输入值\n");
	 printf("5 查找输入的节点是否存在\n");
	 printf("6 反转链表\n");
	 printf("7 判断是否为圈圈链表\n");
	 printf("8 奇偶链表反转\n");
	 printf("9 遍历链表\n");
	 printf("0 退出\n");
	 printf("**************************************************************\n");
 }







////插入链表加强
// void insert() {
//	//插入插入  肯定要有插入的新链表 ，以及插入的链表的位置、
//	 printf("请输入你要插入链表的位置：\n");
//	 scanf("%d", &insertPosition);
//	 p = head;
//	 for (int i = 0;i < insertPosition;i++) {
//		 p = p->next;
//	 }
//	 printf("请输入你新要创建准备插入的链表：\n");
//	 k = creatlist();
//	 
//  
//  }


