#include"D:\c\3120005355̷�Ƶڶ���qg��ҵ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h"
#include<stdio.h>
void main()
{
	LinkStack* sta = NULL;
	char t;

	view();
	printf("\n������ѡ��Ĳ���(������ĵ�һ���ַ�Ϊ׼): ");
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
			printf("\n�������,����������:  ");

		while (getchar() != '\n')
			continue;
	}
	printf("�����Ѿ���������л���ʹ��\n");
	getchar();
}