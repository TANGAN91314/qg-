#include<stdio.h>
#include "..\3120005355谭淦第二次qg作业\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\SqStack.h"
int main() {
	SqStack* sta = NULL;
	char t;
	view();
	printf("\n输入你选择的操作(以输入的第一个字符为准): ");
	while ((t = getchar()) != 'j')
	{
		if (t == '\n')
			continue;
		if ('a' <= t && t <= 'i')
		{
			switch (t)
			{
			case'a':
				init(&sta);
				wsg();
				break;
			case'b':
				isempty(sta);
				wsg();
				break;
			case'c':
				gettop(sta);
				wsg();
				break;
			case'd':
				clear(sta);
				wsg();
				break;
			case'e':
				destroy(sta);
				sta = NULL;
				wsg();
				break;
			case'f':
				length(sta);
				wsg();
				break;
			case'g':
				push(sta);
				wsg();
				break;
			case'h':
				pop(sta);
				wsg();
				break;

			}
		}
		else
			printf("\n输入错误,请重新输入:  ");

		while (getchar() != '\n')
			continue;
	}
	printf("程序已经结束，感谢你的使用\n");
	getchar();
}
