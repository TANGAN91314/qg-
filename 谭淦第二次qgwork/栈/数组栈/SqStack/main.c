#include<stdio.h>
#include "..\3120005355̷�Ƶڶ���qg��ҵ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h"
int main() {
	SqStack* sta = NULL;
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
			printf("\n�������,����������:  ");

		while (getchar() != '\n')
			continue;
	}
	printf("�����Ѿ���������л���ʹ��\n");
	getchar();
}
