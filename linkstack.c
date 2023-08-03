#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int

typedef struct linknode {
	ElemType date;                 //数据域
	struct linknode* next;         //指针域
}ListStNode;     
//链栈节点类型
//创建一个空栈
void InitStack(ListStNode** ps) {
	*ps = (ListStNode*)malloc(sizeof(ListStNode));
	(*ps)->next = NULL;
}
//销毁栈
void DestoryStack(ListStNode** ps) {
	ListStNode* p, *q;
	p = *ps;
	q = p->next;
	if (q)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
	*ps = NULL;
}
//判断栈是否为空
bool StackEmpty(ListStNode* s) {
	return !s->next;
}
//进栈
void Push(ListStNode* s, ElemType e) {
	ListStNode* p;
	p = (ListStNode*)malloc(sizeof(ListStNode));
	p->date = e;
	p->next = s->next;
	s->next = p;
}
//出栈
bool Pop(ListStNode* s, ElemType* e) {
	if (s->next == NULL)
		return false;
	ListStNode* p;
	p = s->next;
	*e = p->date;
	s->next = p->next;
	free(p);
	return true;
}
//取栈顶元素
bool GetTop(ListStNode* s, ElemType* e) {
	if (s->next == NULL)
		return false;
	*e = s->next->date;
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
	ListStNode* s = NULL;
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
				InitStack(&s);
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
			Push(s, e);
			printf("进栈成功！\n");
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