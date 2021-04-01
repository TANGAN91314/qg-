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
	printf("��������Ҫ���������\n");
	int n;
	int num;

	head = createlist();
	char flag1 ;
	LinkedList r;
	LinkedList k;
	printf("���� y �ͻ����������\n");
	getchar();
	getchar();
	char flag3;
	flag3 = getchar();

	LOOP: while (flag3 == 'y' ) {
		chooseview();

		printf("���������ֽ��ж�Ӧ�Ĳ���\n");
		
		getchar();
		flag1 = getchar();
		switch (flag1)
		{
		case '1':
			InitList(&head);		
			printf("�����������Ϊ��");
			link_print1(head);break;
		case '2':DestroyList(&head);break;
			printf("�����������Ϊ��");
			link_print1(head);
		case '3':
			printf("�������ڲ��������\n");getchar();getchar();
			insert = createlist();
			printf("��������������head�����е�λ��(�����������):");
			getchar();getchar();
			scanf("%d", &n);
			p = head;
			for (int i = 0; i < n - 1&&p !=NULL;i++) {
				p = p->next;
			}
			InsertList(p, insert);
			printf("�����������Ϊ��");
			link_print1(head);
			break;
		case '4':
			printf("������ɾ���ڵ��λ�ã�����������һλ����ɾ����λ��3������Ӧɾ����5λ��:�����������Σ�����\n");
			scanf("%d", &num);
			r = head;
			for (int i = 0;i < num && r != NULL;i++) {
				r = r->next;
			}

			DeleteList(r, &n);
			printf("ɾ���ڵ������Ϊ%d\n", n);

			printf("�����������Ϊ��");
			link_print1(head);
			break;
		case '5':	
			printf("��������ҪѰ�ҵĽڵ���Ǹ�������:\n");
			scanf("%d",&n);
			if (SearchList(head, n)) {
				printf("�ҵ��˸ýڵ�!!!!!!!!!!!!!!!!!!\n"); 
			}
			else printf("�Ҳ����ýڵ�\n");

			break;

		case '6':
			ReverseList(&head);
			printf("�����������Ϊ��");
			link_print1(head);
			break;

		case '7':	
			if (IsLoopList(head)) {
				printf("this is a ȦȦ��\n");
			}
			else
			{
				
				printf("this is a ��������\n");
			}
			printf("���������headŪ����ѭ���������Կ�main.c 102��");
			k = head->next->next;

			k->next = head;
			if (IsLoopList(head)) {
				printf("this is a ȦȦ��\n");
			}
			else
			{
				printf("this is a ��������\n");
			}
			printf("head�Ѿ�����Ū��ȦȦ�����˳����´�������������������");
			
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

		printf("���� y �ͻ����������");
		getchar();
		flag3 = getchar();

	}



	


	////link_print1(head);
	//// ��ż����������
	//head = ReverseEvenList(&head);
	//link_print1(head);
	//head = createlist();
	////��ʼ������
	//InitList(&head);
	//link_print1(head);
	//++++��������
	//head = createlist();
	//LinkedList k = head->next->next;

	//InsertList(head, k);
	//link_print1(head);
	//ɾ���������
	//head = createlist();
	//LinkedList k = head->next->next;
	//DeleteList(head, k);
	//link_print1(head);
	//����ת
	//head = createlist();
	//ReverseList(&head);
	//link_print1(head);
	// �ж��Ƿ�Ϊѭ����
	//head = createlist();
	//if (IsLoopList(head)) {
	//	printf("this is a ȦȦ��\n");
	//}
	//else
	//{
	//	printf("this is a ��������\n");
	//}
	//LinkedList k = head->next->next;
	//k->next = head;
	//if (IsLoopList(head)) {
	//	printf("this is a ȦȦ��\n");
	//}
	//else
	//{
	//	printf("this is a ��������\n");
	//}
	//����
	//head = createlist();
	//if (SearchList(head, 3)) printf("�ҵ��˸ú���");
	//else printf("�Ҳ����ú���");
	//

}

 LNode* createlist(void){
	 LNode* head = NULL, * p, * tail = NULL;
	 int n,i =2;
	 
	 printf("����������ĵ�1���ڵ��ֵ:");
	 while (scanf("%d", &n) == 1)//�����벻Ϊ����ʱ����
	 {
		 printf("����������������ĸ�ᱣ������ \n");
		 p = (LNode*)malloc(sizeof(LNode));
		 printf("����������ĵ�%d���ڵ��ֵ:", i);
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
	 printf("�������Ϊ:\n");
	 while (p_mov != NULL && p_mov->data != NULL)//����Ϊ��ǰ�ڵ㣬����ʱ��Ҫ��ʾ��ǰ�ڵ� 
	 {	
		 printf("%d\n", p_mov->data);
		 p_mov = p_mov->next;
	 }
 }
 void chooseview() {
	 printf("**************************************************************\n");
	 printf("��������Ҫ���еĲ�����\n");
	 printf("1 ��ʼ������\n");
	 printf("2 ɾ����������\n");
	 printf("3 �������������,ֻ��head�����\n");
	 printf("4 ɾ���������������ڵ㣬�ظ���ڵ���¸�ֵΪ����ֵ\n");
	 printf("5 ��������Ľڵ��Ƿ����\n");
	 printf("6 ��ת����\n");
	 printf("7 �ж��Ƿ�ΪȦȦ����\n");
	 printf("8 ��ż����ת\n");
	 printf("9 ��������\n");
	 printf("0 �˳�\n");
	 printf("**************************************************************\n");
 }







////���������ǿ
// void insert() {
//	//�������  �϶�Ҫ�в���������� ���Լ�����������λ�á�
//	 printf("��������Ҫ���������λ�ã�\n");
//	 scanf("%d", &insertPosition);
//	 p = head;
//	 for (int i = 0;i < insertPosition;i++) {
//		 p = p->next;
//	 }
//	 printf("����������Ҫ����׼�����������\n");
//	 k = creatlist();
//	 
//  
//  }


