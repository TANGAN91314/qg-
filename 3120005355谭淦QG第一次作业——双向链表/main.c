#include<stdio.h>
#include "duLinkedList.h"
#include "malloc.h"

int main() {
	int insert;
	int index;
	int n;
	DuLNode* head,*insertList,*newHead;
	printf("��������Ҫ���������\n");

	void chooseview();
	head = createlist();
	getchar();
	
	char flag1;

	printf("���� y �ͻ����������\n");
	getchar();
	char flag3;
	flag3 = getchar();
 while (flag3 == 'y') {
	chooseview();
	getchar();
	printf("���������ֽ��ж�Ӧ�Ĳ���\n");
	flag1 = getchar();
	switch (flag1)
	{
	case '1':
		printf("����������");
		head = createlist();getchar();getchar();
		printf("�������������Ϊ��\n");
		link_print1(head);getchar();getchar();
		break;
	case '2':DestroyList_DuL(&head);
		printf("�������������Ϊ��\n");
		link_print1(head);getchar();getchar();
		break;


	case '3':

		printf("�봴��������������\n");
		printf("����ʼ�����������ĵȴ���\n");
		insertList = (createlist())->next;getchar();getchar();
		printf("��������������λ�ã�");
		scanf("%d", &index);
		newHead = head;
		for (int i = 0; i < index&&newHead!=NULL;i++) {
			newHead = newHead->next;
		}
		InsertBeforeList_DuL(newHead, insertList);
		printf("�������������Ϊ��\n");
		link_print1(head);getchar();getchar();
		break;

	case '4':		
		printf("�봴��������������\n");
		printf("����ʼ�����������ĵȴ���\n");
		insertList = (createlist())->next;
		link_print1(insertList);
		getchar();getchar();
		printf("��������������λ�ã�");
		scanf("%d", &index);
		//newHead = (DuLNode*)malloc(sizeof(DuLNode));
		newHead = head;
		for (int i = 0; i < index;i++) {
			newHead = newHead->next;
		}
		InsertAfterList_DuL(newHead, insertList);
		printf("�������������Ϊ��\n");
		link_print1(head);getchar();getchar();
		break;
	case '5': 		
		printf("����������ɾ����λ�ã�");
		scanf("%d", &index);
		//newHead = (DuLNode*)malloc(sizeof(DuLNode));
		newHead = head;
		for (int i = 0; i < index;i++) {
			newHead = newHead->next;
		}
		DeleteList_DuL(newHead, &n);

	case '6':
		link_print1(head);




	default:printf("��������������������");
		break;
	}

	printf("���� y �ͻ����������\n");
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
	while (scanf("%d", &n) == 1)//�����벻Ϊ����ʱ����
	{
		printf("�����벻������ʱ�����\n");

		q = (DuLNode*)malloc(sizeof(DuLNode));
		printf("����������ĵ�%d���ڵ��ֵ:", i);


		if (i == 1) {
			printf("����ĵ�һ���ڵ�Ӧ��Ϊ�սڵ㣻\n");

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
		//����ͷcha�������ж�
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
	printf("��������Ҫ���еĲ�����\n");
	printf("1 ��ʼ������\n");
	printf("2 ɾ����������\n");
	printf("3 ǰ����\n");
	printf("4 �����\n");
	printf("5 ɾ���������������ڵ㣬�ظ���ڵ���¸�ֵΪ����ֵ\n");
	printf("6 ��������\n");


	printf("**************************************************************\n");

}


 link_print1(DuLinkedList  head)
{
	 //if (head == NULL) {
		// prtint("�������Ǹ�������\n");
	 //}
	DuLNode* p_mov ;
	p_mov = head;
	if (p_mov == NULL||p_mov ->next == NULL) {
		printf("������Ϊ������\n");
	}
	else {
		printf("�������Ϊ:\n");
		p_mov = p_mov->next;

		while (p_mov != NULL)//����Ϊ��ǰ�ڵ㣬����ʱ��Ҫ��ʾ��ǰ�ڵ�
		{
			printf("%d\n", p_mov->data);
			p_mov = p_mov->next;

		}
	}

}