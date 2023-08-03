#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int

typedef struct linknode {
	ElemType date;                 //������
	struct linknode* next;         //ָ����
}ListStNode;     
//��ջ�ڵ�����
//����һ����ջ
void InitStack(ListStNode** ps) {
	*ps = (ListStNode*)malloc(sizeof(ListStNode));
	(*ps)->next = NULL;
}
//����ջ
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
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ListStNode* s) {
	return !s->next;
}
//��ջ
void Push(ListStNode* s, ElemType e) {
	ListStNode* p;
	p = (ListStNode*)malloc(sizeof(ListStNode));
	p->date = e;
	p->next = s->next;
	s->next = p;
}
//��ջ
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
//ȡջ��Ԫ��
bool GetTop(ListStNode* s, ElemType* e) {
	if (s->next == NULL)
		return false;
	*e = s->next->date;
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
	ListStNode* s = NULL;
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
				InitStack(&s);
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
			Push(s, e);
			printf("��ջ�ɹ���\n");
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