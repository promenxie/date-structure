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
//��ʼ��ջ
SqStack* InitStack() {
	SqStack * s =  (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
	return s;
}
//����ջ
void DestoryStack(SqStack** ps) {
	free(*ps);
	*ps = NULL;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack* s) {
	return s->top == -1;
}
//��ջ
bool Push(SqStack* s, ElemType e) {
	if (MaxSize - 1 == s->top)
		return false;
	s->date[++s->top] = e;
	return true;
}
//��ջ
bool Pop(SqStack* s, ElemType* e) {
	if (-1 == s->top)
		return false;
	*e = s->date[s->top--] ;
	return true;
}
//ȡջ��Ԫ��
bool GetTop(SqStack* s, ElemType* e) {
	if (-1 == s->top)
		return false;
	e = s->date[s->top];
	return true;
}
void show() {
	printf("\n------------------------------\n");
	printf("1.��ʼ��ջ********4.��ջ\n");
	printf("2.����ջ**********5.��ջ\n");
	printf("3.�ж�ջ�Ƿ�Ϊ��***6.ȡջ��Ԫ��\n");
	printf("********����0�˳�����*********\n");
	printf("--------------------------------\n");
}
int main(void) {
	SqStack* s = NULL;
	int k = 1;
	ElemType e = 1;
	while (k)
	{
		show();
		printf("�������֣�0-6��ѡ���ܣ�");
		fflush(stdin);
		scanf_s("%d", &k);
		switch (k)
		{
		case 1:
			if (NULL == s) {
				s = InitStack();
				printf("��ʼ���ɹ���\n");
			}
			else {
				printf("����ջ���ڣ������ٺ��ٳ�ʼ����\n");
			}
			break;
		case 2:
			DestoryStack(&s);
			printf("���ٳɹ���\n");
			break;
		case 3:
			if (!s)
			{
				printf("ջ�����ڣ�\n");
					break;
			}
			if (StackEmpty(s))
				printf("ջΪ�գ�");
			else
				printf("ջ��Ϊ�գ�");
			break;
		case 4:
			if (!s)
			{
				printf("ջ�����ڣ�\n");
				break;
			}
			printf("����Ҫѹ��ջ��Ԫ�أ�");
			fflush(stdin);
			scanf_s("%d", &e);
			if (Push(s, e))
				printf("��ջ�ɹ���\n");
			else
				printf("ջ������\n");
			break;
		case 5:
			if (!s)
			{
				printf("ջ�����ڣ�\n");
				break;
			}
			if (Pop(s, &e))
				printf("����ջ��Ԫ��Ϊ��%d\n", e);
			else
				printf("ջΪ�գ�\n");
			break;
		case 6:
			if (!s)
			{
				printf("ջ�����ڣ�\n");
				break;
			}
			if (GetTop(s, &e))
				printf("ջ��Ԫ��Ϊ��%d\n", e);
			else
				printf("ջΪ�գ�\n");
			break;
		}
	}

	return 0;
}