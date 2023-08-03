#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 20
#define ElemType int

typedef struct
{
	ElemType date[MaxSize];
	int top;
}SqStack;
//初始化栈
SqStack* InitStack() {
	SqStack * s =  (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
	return s;
}
//销毁栈
void DestoryStack(SqStack** ps) {
	free(*ps);
	*ps = NULL;
}
//判断栈是否为空
bool StackEmpty(SqStack* s) {
	return s->top == -1;
}
//进栈
bool Push(SqStack* s, ElemType e) {
	if (MaxSize - 1 == s->top)
		return false;
	s->date[++s->top] = e;
	return true;
}
//出栈
bool Pop(SqStack* s, ElemType* e) {
	if (-1 == s->top)
		return false;
	*e = s->date[s->top--] ;
	return true;
}
//取栈顶元素
bool GetTop(SqStack* s, ElemType* e) {
	if (-1 == s->top)
		return false;
	e = s->date[s->top];
	return true;
}
void show() {
	printf("\n------------------------------\n");
	printf("1.初始化栈********4.进栈\n");
	printf("2.销毁栈**********5.出栈\n");
	printf("3.判断栈是否为空***6.取栈顶元素\n");
	printf("********输入0退出程序*********\n");
	printf("--------------------------------\n");
}
int main(void) {
	SqStack* s = NULL;
	int k = 1;
	ElemType e = 1;
	while (k)
	{
		show();
		printf("输入数字（0-6）选择功能：");
		fflush(stdin);
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:
			if (NULL == s) {
				s = InitStack();
				printf("初始化成功！\n");
			}
			else {
				printf("已有栈存在！请销毁后再初始化。\n");
			}
			break;
		case 2:
			DestoryStack(&s);
			printf("销毁成功！\n");
			break;
		case 3:
			if (!s)
			{
				printf("栈不存在！\n");
					break;
			}
			if (StackEmpty(s))
				printf("栈为空！");
			else
				printf("栈不为空！");
			break;
		case 4:
			if (!s)
			{
				printf("栈不存在！\n");
				break;
			}
			printf("输入要压入栈的元素：");
			fflush(stdin);
			scanf_s("%d", &e);
			if (Push(s, e))
				printf("进栈成功！\n");
			else
				printf("栈已满！\n");
			break;
		case 5:
			if (!s)
			{
				printf("栈不存在！\n");
				break;
			}
			if (Pop(s, &e))
				printf("弹出栈的元素为：%d\n", e);
			else
				printf("栈为空！\n");
			break;
		case 6:
			if (!s)
			{
				printf("栈不存在！\n");
				break;
			}
			if (GetTop(s, &e))
				printf("栈顶元素为：%d\n", e);
			else
				printf("栈为空！\n");
			break;
		}
	}

	return 0;
}