#include"D:\c\3120005355谭淦第二次qg作业\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h"
#include<stdio.h>
void main()
{
	LinkStack* sta = NULL;
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
				wash();
				break;
			case'b':
				isempty(sta);
				wash();
				break;
			case'c':
				gettop(sta);
				wash();
				break;
			case'd':
				clear(sta);
				wash();
				break;
			case'e':
				destroy(sta);
				sta = NULL;
				wash();
				break;
			case'f':
				length(sta);
				wash();
				break;
			case'g':
				push(sta);
				wash();
				break;
			case'h':
				pop(sta);
				wash();
				break;
			case'i':
				print(sta);
				wash();
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