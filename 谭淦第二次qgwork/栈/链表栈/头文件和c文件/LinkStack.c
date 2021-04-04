#include<stdio.h>
#include"D:\c\3120005355谭淦第二次qg作业\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h"
#define _CRT_SECURE_NO_WARNINGS 1

initLStack(LinkStack** s)   //初始化
{	//初始化常操作，用malloc分配内存
	*s = (LinkStack*)malloc(sizeof(LinkStack));
	//每次都要检验是否为空
	if ( *s == NULL)
		return ERROR;
	//当然，你也要把头给初始化掉头
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
		printf("\n兄弟呀，你初始化成功啦\n");
	else
		printf("\n兄弟呀，你初始化失败啦\n");
}
isEmptyLStack(LinkStack* s)  //判断链栈是否为空
{
	if (NULL == s || s->top == NULL || s->top->next != NULL) //栈指针为空或者栈顶指针为空，其中为空 不行
		return ERROR;
	else
		return SUCCESS;
}
void isempty(LinkStack* s)
{
	if (isEmptyLStack(s) == SUCCESS)
		printf("\n兄弟呀，链栈为空呀！\n");
	else if (NULL == s || s->top == NULL)
		printf("\n兄弟呀，你未初始化链栈呀\n");
	else
		printf("\n兄弟呀，链栈不为空\n");
}
getTopLStack(LinkStack* s, ElemType* e)  //得到栈顶元素
{
	//一样老操作，判空
	if (NULL == s || s->top == NULL || s->top->next == NULL)
		return ERROR;
	*e = s->top->next->data;
	return SUCCESS;
}
void gettop(LinkStack* s)
{
	//一步步排除
	ElemType e;
	if (getTopLStack(s, &e) == SUCCESS)
		printf("\n栈顶元素为%d\n", e);
	//符合没初始化的条件
	else if (NULL == s || s->top == NULL)
		printf("\n兄弟呀，你还未初始化\n");
	else
		printf("\n兄弟呀，你这链栈为空\n");
}
clearLStack(LinkStack* s)   //清空栈
{
	LinkStackPtr cur1, cur2;
	//判断是否初始化
	if (NULL == s || s->top == NULL)
		return ERROR;
	//cur1 是准备删除的
	cur1 = s->top->next;
	while (cur1 != NULL)
	{
		//cur2是用来定位下一个cur的 
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
		printf("\n清空完毕\n");
	else
		printf("\n链栈未初始化\n");
}
destroyLStack(LinkStack* s)   //销毁栈
{
	//一样 判空
	if (NULL == s || s->top == NULL)
		return ERROR;
	free(s);
	return SUCCESS;
}
void destroy(LinkStack* s)
{
	
	if (destroyLStack(s) == SUCCESS)
		printf("\n销毁成功\n");
	else
		printf("\n未初始化\n");
}
LStackLength(LinkStack* s, int* length)    //检测栈长度
{
	//判空
	if (NULL == s || s->top == NULL)
		return ERROR;
	*length = s->count;
	return SUCCESS;
}
void length(LinkStack* s)
{
	int len;
	//获取长度
	if (LStackLength(s, &len) == SUCCESS)
		printf("\n链栈长度为%d\n", len);
	else
		printf("\n未初始化\n");
}
pushLStack(LinkStack* s, ElemType data)   //入栈
{
	LinkStackPtr cur = NULL;
	//判空，判断链栈是否为空
	if (NULL == s || s->top == NULL)
		return ERROR;
	//用一指针取存值
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
//输入进栈数据
	printf("\n入栈数据: ");
	fflush(stdin);
	a = scanf_s("%d", &d);
	if (a == 0)
	{
		printf("\n输入错误\n");
		push(s);
	}
	if (pushLStack(s, d) == SUCCESS)
		printf("\n%d兄弟呀，入栈成功\n", d);
	else
		printf("\n兄弟啊，未初始化\n");
}
popLStack(LinkStack* s, ElemType* data)   //出栈
{
	LinkStackPtr cur = NULL;
	//判空
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
		printf("\n%d兄弟呀，出栈成功\n", d);
	else if (NULL == s || s->top == NULL)
		printf("\n兄弟呀 ，妮未初始化\n");
	else
		printf("\n栈为空呢\n");
}


void view() {
	printf("_______________________________________________________________\n");
	printf("|____________________________________________________________|x|\n");
	printf("|                                                              |\n");
	printf("|                  ** 欢迎来到链表栈系统**                     |\n");
	printf("|                                                              |\n");
	printf("|              a              初始化掉链表栈                   |\n");
	printf("|              b              判断栈是否为空                   |\n");
	printf("|              c              得到栈顶的元素                   |\n");
	printf("|              d              清空掉了链表栈                   |\n");
	printf("|              e              销毁掉了链表栈                   |\n");
	printf("|              f              检测链表栈长度                   |\n");
	printf("|              g              输入元素可入栈                   |\n");
	printf("|              h              把一个元素出栈                   |\n");
	printf("|              i              遍历这个链表栈                   |\n");
	printf("|                                                              |\n");
	printf("_______________________________________________________________\n");
}

void wash()
{
	printf("\n");
	system("PAUSE");
	system("cls");
	view();
	printf("\n输入你选择的操作(以输入的第一个字符为准): ");
}
void print(LinkStack* s)
{
	LinkStackPtr p;

	if (NULL == s || s->top == NULL)
		printf("\n未初始化\n");
	else
	{
		printf("\n此时顺序栈数据为:\n");
		for (p = s->top->next; p != 0; p = p->next)
			printf("       【%d】\n", p->data);
	}
}