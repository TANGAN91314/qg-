#include<stdio.h>
#include "..\3120005355̷�Ƶڶ���qg��ҵ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h"


initStack(SqStack** s, int sizes) {
	//Ϊջ���ٿռ䣬�ռ䵱Ȼ�� sizes����Ԫ�ؿ�
	//���ٵĿռ��С�� *sizes����
	*s = (SqStack*)malloc(sizeof(SqStack));

	(*s)->elem = (int*)malloc(sizeof(int) * sizes);

	//��sizes�ĳ���������˳�ظ�ֵ��sizes
	(*s)->size = sizes;
	(*s)->top = -1;
	if ((*s)->top == -1) {
		return SUCCESS;
	}
	return ERROR;
}
void init(SqStack ** s) {
	int num, k;
	Status yn;
	printf("\n������˳��ջ�����ռ�: ");
	fflush(stdin);
	k = scanf("%d", &num);
	if (k <= 0||k>999999999)
	{
		printf("\n�������\n");
		init(s);
	}
	else if (num <= 0)
	{
		printf("\n���ռ䲻�ܵ���1\n");
		init(s);
	}
	if ((yn = initStack(s, num)) == SUCCESS)
	{
		printf("\n��ʼ���ɹ�\n");
		printf("\n%d", (*s)->top);
	}
	else
		printf("\n��ʼ��ʧ��\n");
}

isEmptyStack(SqStack* s) {
	if (NULL == s || s->top == -1)
		return ERROR;
	return SUCCESS;

}
void isempty(SqStack* s)
{
	Status yn;

	if ((yn = isEmptyStack(s)) == SUCCESS)
		printf("\nջ��Ϊ��\n");
	else if (NULL == s)
		printf("\nδ��ʼ��\n");
	else
		printf("\nջΪ��\n");
}

//�õ���ջ��Ԫ
getTopStack(SqStack* s, ElemType* e) {
	//ʲô�����Ҫ���ж�Ԫ���Ƿ�Ϊ��
	if (NULL == s || s->top == -1)
		return ERROR;
	else {
		if (s->elem != NULL) {
			*e = s->elem[s->top];
			printf("%d", s->top);
			printf("\n�ֵܣ���ǰջ��Ԫ��Ϊ%d\n", *e);
			return SUCCESS;
		}
		//��ȡ��ص�Ԫ��
		else("�ֵܣ���û�и�ֵ\n");
		return ERROR;
	}
}
void gettop(SqStack* s)
{
	ElemType e;
	Status yn;

	if ((yn = getTopStack(s, &e)) == SUCCESS)
		printf("\n�õ�ջ��Ԫ��%d\n", e);
	else if (NULL == s)
		printf("\nδ��ʼ��\n");
	else
		printf("\nջΪ��\n");
}

clearStack(SqStack* s) {
	//�����ж�ջ��Ԫ���Ƿ�Ϊ��
	if (s->elem == NULL) {
		return ERROR;
	}
	else {
		if (s->top == -1) {
			return SUCCESS;
		}
		// ��s->top Ū��-1��
		else
		{
			s->top = -1;
			return SUCCESS;
		}
	
	}
}

void clear(SqStack* s) {
	Status yn;
	if ((yn = clearStack(s)) == SUCCESS) {
		printf("\n**************��ճɹ�**************\n");
	}
	else
		printf("\n�ֵܣ��㻹û�г�ʼ����\n");
}
destroyStack(SqStack* s) {
	//����ͬ���Ĳ��������ж�����ջ��Ԫ���Ƿ�Ϊ��
	if (s->elem == NULL) {
		return ERROR;
	}
	//�������ջ��Ϊ�գ����������Ԫ�� free���� �ٽ�������null��
	else
	{
		free(s->elem);
		s->elem = NULL;
		return SUCCESS;
	}
}

void destroy(SqStack *s) {
	Status yn;
	if ((yn = destroyStack(s)) == SUCCESS) {
		printf("\n�ֵܣ���ݻٳɹ�����\n");
	}
	else
	{
		printf("�ֵ��㻹û�г�ʼ������ջ��\n");
	}

}

stackLength(SqStack* s, int* length) {
	if (s == NULL||s->elem==NULL) {
		return ERROR;
	}
	else {
		//�ǵ�Ҫע�⣬&s ��Ϊ�����Ҳ��ָ��
		*length = s->top;
		// ΪʲôҪlength��1 �أ���Ϊ top��ʼʱ���Ǵ�-1 ��ʼ����
		//printf("��ǰջ�ĳ���Ϊ%d\n", *length + 1);
		return SUCCESS;
	}
}

void length(SqStack* s) {
	int len;
	Status yn;
	if ((yn = stackLength(s, &len)) == SUCCESS) {
		printf("�ֵܣ�������ջ�ĳ���Ϊ%d\n", len + 1);		
	}
	else
	{
		printf("\n�ֵܣ����ջ��û�г�ʼ����\n");
	}
}

pushStack(SqStack* s, ElemType data) {
	//�����������ӣ����ж��Ƿ��ǿ�
	if (s == NULL || s->top == s->size - 1)
		return ERROR;
	s->top++;
	*(s->elem + s->top) = data;
	return SUCCESS;
}
void push(SqStack *s) {
	ElemType data;
	Status yn;
	int a;
	printf("\n�ֵܣ���������ջ����\n");
	fflush(stdin);
	a = scanf("%d", &data);
	if (a == 0) {
		printf("�ֵܰ��������������");
		push(s);
	}
	if (yn = pushStack(s,data) == SUCCESS) {
		printf("\n �ֵ�ѽ��%d��ջ�ɹ�\n",data);
	}
	else if (s == NULL) {
		printf("\n��û�г�ʼ��\n");
	}
	else
	{
		printf("�ֵ�ѽ�����ջ����ѽ��\n");
	}
}

popStack(SqStack* s, ElemType* data)   //��ջ
{
	if (NULL == s || s->top == -1)
		return ERROR;
	*data = s->elem[s->top];
	s->top--;
	return SUCCESS;
}
void pop(SqStack* s)
{
	ElemType data;
	Status yn;

	if ((yn = popStack(s, &data)) == SUCCESS)
		printf("\n%d��ջ�ɹ�\n", data);
	else if (NULL == s)
		printf("\nδ��ʼ��\n");
	else
		printf("\nջΪ��\n");
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
	printf("|              i              �˳�����ջϵͳ                   |\n");
	printf("|                                                              |\n");
	printf("_______________________________________________________________\n");
}

void wsg()
{
	printf("\n");
	system("PAUSE");
	system("cls");
	view();
	printf("\n������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼): ");
}
print(SqStack* s)
{
	int i;

	if (NULL == s)
		printf("\nδ��ʼ��\n");
	else if (s->top == -1)
		printf("\nջΪ��\n");
	else
	{
		printf("\n��ʱ˳��ջ����Ϊ:\n");
		for (i = s->top; i >= 0; i--)
			printf("      (:  %d   :)   \n", s->elem[i]);
	}
}
