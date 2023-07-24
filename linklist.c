#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElemType int //���ݵ�����
typedef struct LinkNode{
	ElemType date;
	struct LinkNode* next;
}LNode, *LinkList;
//1����ͷ�ڵ�
LNode * InitList() {
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}
//2��������
void DestroyList(LNode** pL) {//��������L�ĵ�ַ
	LNode * pre = *pL, * p = (*pL)->next;
	while (NULL != p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	*pL = NULL;
}
//���ص�i��Ԫ�ص�ָ��,�����Ԫ�ط���ͷ�ڵ�ָ��
LNode* pEmle(LNode* L, int i) {
	LNode* p = L;
	if (i < 0)
		return NULL;
	for (; p != NULL && i > 0; i--)
	{
		p = p->next;
	}
	return p;
}
//3��ɾ������Ԫ��
bool ListDelete(LNode* L, int i, ElemType* e) {
	int j = 0;
	LNode* p = pEmle(L, i - 1);//pΪ��i-1���ڵ�
	LNode* q = pEmle(L, i);//pΪ��i���ڵ�
	if (p == NULL || q == NULL)
		return false;
	p->next = q->next;
	*e = q->date;
	free(q);
	return true;
}
//4����ʾ������
int ListLength(LNode* L) {
	int j = 0;
	LNode* p = L->next;
	while (p != NULL) {
		j++;
		p = p->next;
	}

	return j;
}
//5����λ����
bool GetElem(LNode* L, int i, ElemType* e) {
	LNode* p = pEmle(L, i);
	if (NULL == p || 0 == i) {
		return false;
	} else {
		*e = p->date;
		return true;
	}
}
//6����ֵ����
int LocateElem(LNode* L, ElemType e) {
	int j = 1;
	LNode* p = L->next;
	while (p != NULL && p->date != e) {
		j++;
		p = p->next;
	}
	if (NULL == p)
		return 0;
	return j;
}
//7����������Ԫ��
bool ListInsert(LNode* L, int i, ElemType e) {
	LNode* p = pEmle(L, i-1);
	if (p) {
		LNode* s = (LNode*)malloc(sizeof(LNode));//����ڵ���Ϊs
		s->next = p->next;
		s->date = e;
		p->next = s;
		return true;
	} else {
		return false;
	}
}
//8��β�巨����Ԫ��
void ListInsertTrail(LNode* L) {
	ElemType e;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	printf("����������Ԫ��ֵ������������ݽ�����\n");
	while (scanf_s("%d", &e)){
		p->next = (LNode*)malloc(sizeof(LNode));
		p = p->next;
		p->date = e;
	}
	p->next = NULL;
}
//9�������
void DispList(LNode* L) {
	int i=1;
	LNode* p = L->next;
	while (p != NULL) {
		printf("a%d: %d\n", i++, p->date);
		p = p->next;
	}
}
//11����
void ListSort(LNode* L) {
	LNode* p = L->next->next , *pre = L, * q;//p��Ҫ�Ƚ�Ԫ�صĽڵ�
	L->next->next = NULL;
	while (p != NULL) {
		pre = L;
		while ((pre->next != NULL) && (p->date > pre->next->date)) {
			pre = pre->next;
		}
		q = pre->next;
		pre->next = p;
		p = p->next;
		pre->next->next = q;
	}

}
//�ж������Ƿ����
bool IsExist(LNode* L) {
	if (NULL == L) {
		return false;
	} else {
		return true;
	}
}
void show() { //��ʾ����
	printf("\n**********************\n");
	printf("1����ʼ������\n");
	printf("2����������\n");
	printf("3��ɾ������Ԫ��\n");
	printf("4����ʾ������\n");
	printf("5��������ĵ�I��Ԫ��ֵ\n");
	printf("6����ֵ����\n");
	printf("7������\n");
	printf("8��β�巨����Ԫ��\n");
	printf("9���������\n");
	printf("11.����\n");
	printf("0���˳�\n");
	printf("**********************\n");
}
int main(void) {
	int k = 1;
	int i;
	int e;
	LinkList L = NULL;
	while (k)
	{
		show();
		printf("ѡ���ܣ�0-9��\n");
		printf("������ѡ��: ");
		rewind(stdin);
		scanf_s("%d", &k);
		e = 0;
		switch (k)
		{
		case 0:
			break;
		case 1://����ͷ�ڵ�
			L = InitList();
			printf("�����ʼ���ɹ�!\n");
			break;
		case 2://��������
			if (IsExist(L))
			{
				DestroyList(&L);
			}
			else
				printf("�������ڣ�\n");
			break;
		case 3://ɾ������Ԫ��
			if (IsExist(L))
			{
				printf("������Ҫɾ��Ԫ�ص�λ�ã�");
				rewind(stdin);
				scanf_s("%d", &i);
				if (ListDelete(L, i, &e))
					printf("ɾ���ɹ���ɾ��Ԫ��ֵΪ: %d\n", e);
				else
					printf("Ҫɾ����Ԫ�ز��ڷ�Χ��\n");
			}
			else
				printf("�������ڣ�\n");
			break;
		case 4://��ʾ������
			if (IsExist(L))
			{
				printf("����Ԫ�ظ���Ϊ��%d\n", ListLength(L));
			}
			else
				printf("�������ڣ�\n");
			break;
		case 5://��λ����
			if (IsExist(L))
			{
				printf("������Ҫ����Ԫ�ص�λ�ã�");
				rewind(stdin);
				scanf_s("%d", &i);
				GetElem(L, i, &e);
				printf("��%d��Ԫ�ص�ֵΪ: %d\n", i, e);
			}
			else
				printf("�������ڣ�\n");
			break;
		case 6://��ֵ����
			if (IsExist(L))
			{
				printf("������Ҫ����Ԫ�ص�ֵ��");
				rewind(stdin);
				scanf_s("%d", &e);
				if (i = LocateElem(L, e)) {
					printf("��Ԫ���������λ��Ϊ��%d", i);
				}
				else {
					printf("��Ԫ�ز�����");
				}
			}
			else
				printf("�������ڣ�\n");
			break;
		case 7://��������Ԫ��
			if (IsExist(L))
			{
				printf("����������Ҫ����Ԫ�ص�λ�ú�ֵ��");
				rewind(stdin);
				scanf_s("%d%d", &i, &e);
				if (!ListInsert(L, i, e))
					printf("����λ�ò��ڷ�Χ��\n");
			}
			else
				printf("�������ڣ�\n");
			break;
		case 8://β�巨����Ԫ��
			if (IsExist(L))
			{
				ListInsertTrail(L);
			}
			else
				printf("�������ڣ�\n");
			break;
		case 9://�������
			if (!IsExist(L))
				printf("�������ڣ�\n");
			else if(!ListLength(L))
				printf("����Ϊ�գ�\n");
			else
				DispList(L);
			break;
		case 11:
			if (ListLength > 1)
			{
				ListSort(L);
			}
			break;
		}
	}

	return 0;
}