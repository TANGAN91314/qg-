#include"../head/calculator.h"
#include<stdio.h>
#include<stdlib.h>

// 符号栈
Status initsymbol(LinkSymbolStack *s)
{
	s->top= (LinkSymbolPtr)malloc(sizeof(SymbolNode));
	if (!s->top)
		return ERROR;
	s->top = NULL;
	s->count = 0;
	return SUCCESS;

}
Status isEmptysymbol(LinkSymbolStack *s)
{
	if (s->count == 0)
		return SUCCESS;
	else
		return ERROR;
}
Status getTopsymbol(LinkSymbolStack *s, char *e)
{
	*e = s->top->symbol;
	printf("%d\n",*e);
}
Status clearsymbol(LinkSymbolStack *s)
{
	if (s->count < 0||s->count==0)
	{
		printf("无法清除空链表或未定义链表\n");
		return ERROR;
	}
	else
	{

		free(s->top);
		initLStack(s);
		printf("清除链表成功\n");
		return SUCCESS;
	}

}
Status destroysymbol(LinkSymbolStack *s)   //销毁栈
{
	int clr;
	if (s->count < 0)
	{
		printf("无法销毁未初始化的链表\n");
		return ERROR;
	}
	else
	{
		free(s);
	}
	return SUCCESS;
}
Status symbolLength(LinkSymbolStack *s, int *length)    //检测栈长度
{
	if (s->count <= 0)
	{
		printf("空栈或者为定义\n");
		return ERROR;
	}
		
	*length = s->count;
	printf("长度为%d\n", *length);

}
Status pushsymbol(LinkSymbolStack *s, char data)  //入栈
{
	if (s->top != NULL && s->count < 0)
	{
		return ERROR;
	}
	SymbolNode *sym = (SymbolNode*)malloc(sizeof(SymbolNode));//创建新节点
	sym->symbol = data;                
	sym->next = s->top;                                     //入栈操作
	s->top = sym;                                             //栈顶
	(s->count)++;                  //记录栈长度

}
Status popsymbol(LinkSymbolStack *s, char *data)   //出栈
{
	if (s->count == 0)
	{
		return ERROR;
		printf("是空栈/n");
	}
	if (s->top != NULL && s->count < 0)
	{
		return ERROR;
	}
   SymbolNode *topnode = s->top;        //定义一个指向栈顶的指针
   *data = topnode->symbol;              ///////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!
   s->top = s->top->next;           //栈顶指针下移一位
   free(topnode);                    //释放内存
   (s->count)--;           //记录栈长度
   return SUCCESS;
}


void Inits(LinkSymbolPtr mystack)//调用initlstack初始化栈，未初始化时count居然为负数
{
	if (initLStack(mystack))
		printf("成功初始化链栈\n");
	else
		printf("初始化失败\n");
}

void pushs(LinkSymbolPtr mystack)//调用pushlstack入栈
{

	char data;
	printf("请输入数据\n");
	scanf_s("%d",&data);
	if (pushLStack(mystack, data))
		printf("成功入栈，数据为%d\n", data);
	else
		printf("入栈失败,可能没有初始化\n");
}
char pops(LinkSymbolPtr mystack)  //调用poplstack来出栈
{
	char sym;

	if (popsymbol(mystack, &sym)) 
	{
		//printf("debugout :%c ", sym);
	
		return sym;
	}
	else
		printf("error\n");
}
void judge(int a)
{
	if (a)
		printf("是\n");
	else
		printf("不是\n");
}


//                数字栈
Status initLStack(LinkStack *s)   //初始化
{
	s->top= (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top)
		return ERROR;
	s->top = NULL;
	s->count = 0;
	return SUCCESS;

}
Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if (s->count == 0)
		return SUCCESS;
	else
		return ERROR;
}
Status getTopLStack(LinkStack *s, ElemType *e)  //得到栈顶元素
{
	*e = s->top->data;
	printf("%d\n",*e);
}
Status clearLStack(LinkStack *s)   //清空栈
{
	if (s->count < 0||s->count==0)
	{
		printf("无法清除空链表或未定义链表\n");
		return ERROR;
	}
	else
	{

		free(s->top);
		initLStack(s);
		printf("清除链表成功\n");
		return SUCCESS;
	}

}
Status destroyLStack(LinkStack *s)   //销毁栈
{
	int clr;
	if (s->count < 0)
	{
		printf("无法销毁未初始化的链表\n");
		return ERROR;
	}
	else
	{
		free(s);
	}
	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	if (s->count <= 0)
	{
		printf("空栈或者为定义\n");
		return ERROR;
	}
		
	*length = s->count;
	printf("长度为%d\n", *length);

}
Status pushLStack(LinkStack *s, ElemType data)   //入栈
{
	if (s->top != NULL && s->count < 0)
	{
		return ERROR;
	}
	StackNode *node = (LinkStackPtr*)malloc(sizeof(StackNode));//创建新节点
	node->data = data;                
	node->next = s->top;                                     //入栈操作
	s->top = node;                                             //栈顶
	(s->count)++;                  //记录栈长度

}
Status popLStack(LinkStack *s, ElemType *data)   //出栈
{
	if (s->count == 0)
	{
		return ERROR;
	}
	if (s->top != NULL && s->count < 0)
	{
		return ERROR;
	}
   StackNode *topnode = s->top;        //定义一个指向栈顶的指针
   *data = topnode->data;
   s->top = s->top->next;           //栈顶指针下移一位
   free(topnode);                    //释放内存
   (s->count)--;           //记录栈长度
   return SUCCESS;
}


void Init(LinkStackPtr mystack)//调用initlstack初始化栈，未初始化时count居然为负数
{
	if (initLStack(mystack))
		printf("成功初始化链栈\n");
	else
		printf("初始化失败\n");
}

void push(LinkStackPtr mystack)//调用pushlstack入栈
{

	ElemType data;
	printf("请输入数据\n");
	scanf_s("%d",&data);
	if (pushLStack(mystack, data))
		printf("成功入栈，数据为%d\n", data);
	else
		printf("入栈失败,可能没有初始化\n");
}
double pop(LinkStackPtr mystack)  //调用poplstack来出栈
{
	ElemType data;
	if (popLStack(mystack, &data))
		return data;
	else
		printf("error\n");
}

/***************************************************************/