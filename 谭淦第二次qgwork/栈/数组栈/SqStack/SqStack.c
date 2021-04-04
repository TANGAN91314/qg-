#include<stdio.h>
#include "..\3120005355谭淦第二次qg作业\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\SqStack.h"


initStack(SqStack** s, int sizes) {
	//为栈开辟空间，空间当然是 sizes个里元素咯
	//开辟的空间大小用 *sizes来定
	*s = (SqStack*)malloc(sizeof(SqStack));

	(*s)->elem = (int*)malloc(sizeof(int) * sizes);

	//把sizes的长度言正名顺地赋值给sizes
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
	printf("\n所构建顺序栈的最大空间: ");
	fflush(stdin);
	k = scanf("%d", &num);
	if (k <= 0||k>999999999)
	{
		printf("\n输入错误\n");
		init(s);
	}
	else if (num <= 0)
	{
		printf("\n最大空间不能低于1\n");
		init(s);
	}
	if ((yn = initStack(s, num)) == SUCCESS)
	{
		printf("\n初始化成功\n");
		printf("\n%d", (*s)->top);
	}
	else
		printf("\n初始化失败\n");
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
		printf("\n栈不为空\n");
	else if (NULL == s)
		printf("\n未初始化\n");
	else
		printf("\n栈为空\n");
}

//得到顶栈的元
getTopStack(SqStack* s, ElemType* e) {
	//什么情况都要先判断元素是否为空
	if (NULL == s || s->top == -1)
		return ERROR;
	else {
		if (s->elem != NULL) {
			*e = s->elem[s->top];
			printf("%d", s->top);
			printf("\n兄弟，当前栈顶元素为%d\n", *e);
			return SUCCESS;
		}
		//获取相关的元素
		else("兄弟，还没有赋值\n");
		return ERROR;
	}
}
void gettop(SqStack* s)
{
	ElemType e;
	Status yn;

	if ((yn = getTopStack(s, &e)) == SUCCESS)
		printf("\n得到栈顶元素%d\n", e);
	else if (NULL == s)
		printf("\n未初始化\n");
	else
		printf("\n栈为空\n");
}

clearStack(SqStack* s) {
	//首先判断栈中元素是否为空
	if (s->elem == NULL) {
		return ERROR;
	}
	else {
		if (s->top == -1) {
			return SUCCESS;
		}
		// 把s->top 弄成-1；
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
		printf("\n**************清空成功**************\n");
	}
	else
		printf("\n兄弟，你还没有初始化呢\n");
}
destroyStack(SqStack* s) {
	//又是同样的操作，先判断数组栈中元素是否为空
	if (s->elem == NULL) {
		return ERROR;
	}
	//如果数组栈不为空，请清除里面元素 free了他 再叫他等于null；
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
		printf("\n兄弟，你摧毁成功了呢\n");
	}
	else
	{
		printf("兄弟你还没有初始化数组栈呢\n");
	}

}

stackLength(SqStack* s, int* length) {
	if (s == NULL||s->elem==NULL) {
		return ERROR;
	}
	else {
		//记得要注意，&s 因为传入的也是指针
		*length = s->top;
		// 为什么要length＋1 呢？因为 top起始时候是从-1 开始的呢
		//printf("当前栈的长度为%d\n", *length + 1);
		return SUCCESS;
	}
}

void length(SqStack* s) {
	int len;
	Status yn;
	if ((yn = stackLength(s, &len)) == SUCCESS) {
		printf("兄弟，该数组栈的长度为%d\n", len + 1);		
	}
	else
	{
		printf("\n兄弟，你的栈还没有初始化呢\n");
	}
}

pushStack(SqStack* s, ElemType data) {
	//哈哈，老样子，先判断是否是空
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
	printf("\n兄弟，请输入入栈数据\n");
	fflush(stdin);
	a = scanf("%d", &data);
	if (a == 0) {
		printf("兄弟阿，你输入错误啦");
		push(s);
	}
	if (yn = pushStack(s,data) == SUCCESS) {
		printf("\n 兄弟呀，%d入栈成功\n",data);
	}
	else if (s == NULL) {
		printf("\n还没有初始化\n");
	}
	else
	{
		printf("兄弟呀，你的栈满了呀！\n");
	}
}

popStack(SqStack* s, ElemType* data)   //出栈
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
		printf("\n%d出栈成功\n", data);
	else if (NULL == s)
		printf("\n未初始化\n");
	else
		printf("\n栈为空\n");
}












void view() {
	printf("_______________________________________________________________\n");
	printf("|____________________________________________________________|x|\n");
	printf("|                                                              |\n");
	printf("|                  ** 欢迎来到数组栈系统**                     |\n");
	printf("|                                                              |\n");
	printf("|              a              初始化掉数组栈                   |\n");
	printf("|              b              判断栈是否为空                   |\n");
	printf("|              c              得到栈顶的元素                   |\n");
	printf("|              d              清空掉了数组栈                   |\n");
	printf("|              e              销毁掉了数组栈                   |\n");
	printf("|              f              检测数组栈长度                   |\n");
	printf("|              g              输入元素可入栈                   |\n");
	printf("|              h              把一个元素出栈                   |\n");
	printf("|              i              退出数组栈系统                   |\n");
	printf("|                                                              |\n");
	printf("_______________________________________________________________\n");
}

void wsg()
{
	printf("\n");
	system("PAUSE");
	system("cls");
	view();
	printf("\n输入你选择的操作(以输入的第一个字符为准): ");
}
print(SqStack* s)
{
	int i;

	if (NULL == s)
		printf("\n未初始化\n");
	else if (s->top == -1)
		printf("\n栈为空\n");
	else
	{
		printf("\n此时顺序栈数据为:\n");
		for (i = s->top; i >= 0; i--)
			printf("      (:  %d   :)   \n", s->elem[i]);
	}
}
