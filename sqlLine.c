#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
typedef struct 
{
	int date[MaxSize];
	int length;
}SqList;//˳�����
//1������˳���
void InitList(SqList** p){
	if (*p != NULL)
		free(*p);
	*p = (SqList*)malloc(sizeof(SqList));
	(* p)->length = 0;
	printf("�����ɹ�\n");
}
//2������˳���
void DestroyList(SqList **p) {
	free(*p);
	*p = NULL;
	printf("˳��������٣�\n");
}
//3���ж����Ա�ʦ��Ϊ��
int ListEmpty(SqList* L) {	
	if (0 == L->length)
		return 1;
	else
		return 0;
}
//4�������Ա�ĳ���
int ListLength(SqList* L) {
	return L->length;
}

//5�������Ա�ĵ�I��Ԫ��ֵ
void GetElem(SqList* L, int i) {
	if (i > L->length || i < 1)
		printf("��ѯ������Χ��\n");
	else
		printf("��%d��Ԫ����%d\n", i, L->date[i - 1]);
}
//6����ֵ����
void LocateElem(SqList* L, int e) {
	int i;
	int is = 0;
	for (i = 0; i < L->length; i++)
	{
		if (L->date[i] == e) 
		{
			printf("%d���ڵ�λ��Ϊ%d\n", e, i + 1);
			is = 1;
		}
			
	}
	if (0 == is)
		printf("���в�����Ԫ��%d\n");
}
//7������
int ListInsert(SqList* L, int i, int e) {
	int j;
	if (i > L->length + 1)
		return 0;
	for (j = L->length; j >= i; j--)
	{
		L->date[j] = L->date[j - 1];
	}
	L->date[i - 1] = e;
	L->length++;
	return 1;
}
//8��ɾ��
int ListDelete(SqList* L, int j, int* e) {
	if (j > L->length)
		return 0;
	while (j < L->length)
		L->date[j - 1] = L->date[j++];
	L->length--;
	*e = L->date[j - 1];
	return 1;
}
//9��������Ա�
int DispList(SqList* L) {
	int i;
	if (!L->length)
		return 0;
	for (i = 0; i < L->length; i++)
	{
		printf("A%d= %d  \n", i+1, L->date[i]);
	}
	return 1;
}
void show() { //��ʾ����
	printf("\n**********************\n");
	printf("1������˳���\n");
	printf("2������˳���\n");
	printf("3���ж����Ա��Ƿ�Ϊ��\n");
	printf("4�������Ա�ĳ���\n");
	printf("5�������Ա�ĵ�I��Ԫ��ֵ\n");
	printf("6����ֵ����\n");
	printf("7������\n");
	printf("8��ɾ��\n");
	printf("9��������Ա�\n");
	printf("0���˳�\n");
	printf("**********************\n");
}
int main(void) {
	int k = 1;
	int i;
	int e;
	SqList* L = NULL;
	SqList** p = &L;
	
	while (k) 
	{
		show();
		printf("ѡ���ܣ�0-9��\n");
		printf("������ѡ��: ");
		fflush(stdin);
		scanf_s("%d", &k);
		switch (k)
		{
		case 0:
			break;
		case 1:
			InitList(p);
			break;
		case 2:
			if (NULL == L)
			{
				printf("˳������ڣ�\n");
				break;
			}
			DestroyList(p);
			break;
		case 3:
			if (NULL == L)
			{
				printf("˳������ڣ�\n");
				break;
			}
			if (ListEmpty(L))
				printf("˳���Ϊ��\n");
			else
				printf("˳���Ϊ��\n");
			break;
		case 4:
			if (NULL == L)
			{
				printf("˳������ڣ�\n");
				break;
			}
			printf("˳���Ԫ�ظ���Ϊ��%d\n", ListLength(L));
			break;
		case 5:
			if (NULL == L)
			{
				printf("˳������ڣ�\n");
				break;
			}
			printf("������Ԫ������λ��: ");
			fflush(stdin);
			scanf_s("%d", &i);
			GetElem(L, i);
			break;
		case 6:
			if (NULL == L)
			{
				printf("˳������ڣ�\n");
				break;
			}
			fflush(stdin);
			printf("������Ҫ����Ԫ�ص�ֵ��");			
			scanf_s("%d", &e);
			LocateElem(L, e);
			break;
		case 7:
			if (NULL == L)
			{
				printf("˳������ڣ�\n");
				break;
			}
			printf("����������Ҫ����Ԫ�ص�λ�ú�ֵ��");
			fflush(stdin);
			scanf_s("%d%d", &i, &e);
			if (!ListInsert(L, i, e))
				printf("����λ�ò��ڷ�Χ��\n");
			break;
		case 8:
			if (NULL == L)
			{
				printf("˳������ڣ�\n");
				break;
			}
			printf("����������Ҫɾ��Ԫ�ص�λ�ã�");
			fflush(stdin);
			scanf_s("%d", &i);
			if (ListDelete(L, i, &e))
				printf("ɾ���ɹ���ɾ��Ԫ��ֵΪ: %d\n", e);
			else
				printf("Ҫɾ����Ԫ�ز��ڷ�Χ��\n");
			break;
		case 9:
			if (NULL == L)
			{
				printf("˳������ڣ�\n");
				break;
			}
			if (!DispList(L))
				printf("���Ա�Ϊ��\n");
		}
	}
		

}
