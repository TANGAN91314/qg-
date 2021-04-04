#include<stdio.h>
#include"D:\c\3120005355̷�Ƶڶ���qg��ҵ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h"
#define _CRT_SECURE_NO_WARNINGS 1

initLStack(LinkStack** s)   //��ʼ��
{	//��ʼ������������malloc�����ڴ�
	*s = (LinkStack*)malloc(sizeof(LinkStack));
	//ÿ�ζ�Ҫ�����Ƿ�Ϊ��
	if ( *s == NULL)
		return ERROR;
	//��Ȼ����ҲҪ��ͷ����ʼ����ͷ
	(*s)->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (NULL == (*s)->top)
		return ERROR;

	(*s)->top->next = NULL;
	(*s)->count = 0;
	return SUCCESS;
}
void init(LinkStack** s)
{
	if (initLStack(s) == SUCCESS)
		printf("\n�ֵ�ѽ�����ʼ���ɹ���\n");
	else
		printf("\n�ֵ�ѽ�����ʼ��ʧ����\n");
}
isEmptyLStack(LinkStack* s)  //�ж���ջ�Ƿ�Ϊ��
{
	if (NULL == s || s->top == NULL || s->top->next != NULL) //ջָ��Ϊ�ջ���ջ��ָ��Ϊ�գ�����Ϊ�� ����
		return ERROR;
	else
		return SUCCESS;
}
void isempty(LinkStack* s)
{
	if (isEmptyLStack(s) == SUCCESS)
		printf("\n�ֵ�ѽ����ջΪ��ѽ��\n");
	else if (NULL == s || s->top == NULL)
		printf("\n�ֵ�ѽ����δ��ʼ����ջѽ\n");
	else
		printf("\n�ֵ�ѽ����ջ��Ϊ��\n");
}
getTopLStack(LinkStack* s, ElemType* e)  //�õ�ջ��Ԫ��
{
	//һ���ϲ������п�
	if (NULL == s || s->top == NULL || s->top->next == NULL)
		return ERROR;
	*e = s->top->next->data;
	return SUCCESS;
}
void gettop(LinkStack* s)
{
	//һ�����ų�
	ElemType e;
	if (getTopLStack(s, &e) == SUCCESS)
		printf("\nջ��Ԫ��Ϊ%d\n", e);
	//����û��ʼ��������
	else if (NULL == s || s->top == NULL)
		printf("\n�ֵ�ѽ���㻹δ��ʼ��\n");
	else
		printf("\n�ֵ�ѽ��������ջΪ��\n");
}
clearLStack(LinkStack* s)   //���ջ
{
	LinkStackPtr cur1, cur2;
	//�ж��Ƿ��ʼ��
	if (NULL == s || s->top == NULL)
		return ERROR;
	//cur1 ��׼��ɾ����
	cur1 = s->top->next;
	while (cur1 != NULL)
	{
		//cur2��������λ��һ��cur�� 
		cur2 = cur1->next;
		free(cur1);
		cur1 = cur2;
	}
	s->top->next = NULL;
	return SUCCESS;
}
void clear(LinkStack* s)
{
	if (clearLStack(s) == SUCCESS)
		printf("\n������\n");
	else
		printf("\n��ջδ��ʼ��\n");
}
destroyLStack(LinkStack* s)   //����ջ
{
	//һ�� �п�
	if (NULL == s || s->top == NULL)
		return ERROR;
	free(s);
	return SUCCESS;
}
void destroy(LinkStack* s)
{
	
	if (destroyLStack(s) == SUCCESS)
		printf("\n���ٳɹ�\n");
	else
		printf("\nδ��ʼ��\n");
}
LStackLength(LinkStack* s, int* length)    //���ջ����
{
	//�п�
	if (NULL == s || s->top == NULL)
		return ERROR;
	*length = s->count;
	return SUCCESS;
}
void length(LinkStack* s)
{
	int len;
	//��ȡ����
	if (LStackLength(s, &len) == SUCCESS)
		printf("\n��ջ����Ϊ%d\n", len);
	else
		printf("\nδ��ʼ��\n");
}
pushLStack(LinkStack* s, ElemType data)   //��ջ
{
	LinkStackPtr cur = NULL;
	//�пգ��ж���ջ�Ƿ�Ϊ��
	if (NULL == s || s->top == NULL)
		return ERROR;
	//��һָ��ȡ��ֵ
	cur = (LinkStackPtr)malloc(sizeof(StackNode));
	cur->data = data;
	cur->next = s->top->next;
	s->top->next = cur;
	s->count++;
	return SUCCESS;
}
void push(LinkStack* s)
{
	ElemType d;
	int a;
//�����ջ����
	printf("\n��ջ����: ");
	fflush(stdin);
	a = scanf_s("%d", &d);
	if (a == 0)
	{
		printf("\n�������\n");
		push(s);
	}
	if (pushLStack(s, d) == SUCCESS)
		printf("\n%d�ֵ�ѽ����ջ�ɹ�\n", d);
	else
		printf("\n�ֵܰ���δ��ʼ��\n");
}
popLStack(LinkStack* s, ElemType* data)   //��ջ
{
	LinkStackPtr cur = NULL;
	//�п�
	if (NULL == s || s->top == NULL || s->count == 0)
		return ERROR;
	cur = s->top->next;
	s->top->next = cur->next;
	*data = cur->data;
	free(cur);
	s->count--;
	return SUCCESS;
}
void pop(LinkStack* s)
{
	ElemType d;

	if (popLStack(s, &d) == SUCCESS)
		printf("\n%d�ֵ�ѽ����ջ�ɹ�\n", d);
	else if (NULL == s || s->top == NULL)
		printf("\n�ֵ�ѽ ����δ��ʼ��\n");
	else
		printf("\nջΪ����\n");
}


void view() {
	printf("_______________________________________________________________\n");
	printf("|____________________________________________________________|x|\n");
	printf("|                                                              |\n");
	printf("|                  ** ��ӭ��������ջϵͳ**                     |\n");
	printf("|                                                              |\n");
	printf("|              a              ��ʼ��������ջ                   |\n");
	printf("|              b              �ж�ջ�Ƿ�Ϊ��                   |\n");
	printf("|              c              �õ�ջ����Ԫ��                   |\n");
	printf("|              d              ��յ�������ջ                   |\n");
	printf("|              e              ���ٵ�������ջ                   |\n");
	printf("|              f              �������ջ����                   |\n");
	printf("|              g              ����Ԫ�ؿ���ջ                   |\n");
	printf("|              h              ��һ��Ԫ�س�ջ                   |\n");
	printf("|              i              �����������ջ                   |\n");
	printf("|                                                              |\n");
	printf("_______________________________________________________________\n");
}

void wash()
{
	printf("\n");
	system("PAUSE");
	system("cls");
	view();
	printf("\n������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼): ");
}
void print(LinkStack* s)
{
	LinkStackPtr p;

	if (NULL == s || s->top == NULL)
		printf("\nδ��ʼ��\n");
	else
	{
		printf("\n��ʱ˳��ջ����Ϊ:\n");
		for (p = s->top->next; p != 0; p = p->next)
			printf("       ��%d��\n", p->data);
	}
}