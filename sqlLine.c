#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
typedef struct 
{
	int date[MaxSize];
	int length;
}SqList;//顺序表定义
//1·创建顺序表
void InitList(SqList** p){
	if (*p != NULL)
		free(*p);
	*p = (SqList*)malloc(sizeof(SqList));
	(* p)->length = 0;
	printf("创建成功\n");
}
//2·销毁顺序表
void DestroyList(SqList **p) {
	free(*p);
	*p = NULL;
	printf("顺序表已销毁！\n");
}
//3·判断线性表师父为空
int ListEmpty(SqList* L) {	
	if (0 == L->length)
		return 1;
	else
		return 0;
}
//4·求线性表的长度
int ListLength(SqList* L) {
	return L->length;
}

//5·求线性表的第I个元素值
void GetElem(SqList* L, int i) {
	if (i > L->length || i < 1)
		printf("查询超出范围！\n");
	else
		printf("第%d个元素是%d\n", i, L->date[i - 1]);
}
//6·按值查找
void LocateElem(SqList* L, int e) {
	int i;
	int is = 0;
	for (i = 0; i < L->length; i++)
	{
		if (L->date[i] == e) 
		{
			printf("%d所在的位置为%d\n", e, i + 1);
			is = 1;
		}
			
	}
	if (0 == is)
		printf("表中不存在元素%d\n");
}
//7·插入
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
//8·删除
int ListDelete(SqList* L, int j, int* e) {
	if (j > L->length)
		return 0;
	while (j < L->length)
		L->date[j - 1] = L->date[j++];
	L->length--;
	*e = L->date[j - 1];
	return 1;
}
//9·输出线性表
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
void show() { //显示功能
	printf("\n**********************\n");
	printf("1·创建顺序表\n");
	printf("2·销毁顺序表\n");
	printf("3·判断线性表是否为空\n");
	printf("4·求线性表的长度\n");
	printf("5·求线性表的第I个元素值\n");
	printf("6·按值查找\n");
	printf("7·插入\n");
	printf("8·删除\n");
	printf("9·输出线性表\n");
	printf("0·退出\n");
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
		printf("选择功能（0-9）\n");
		printf("请输入选项: ");
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
				printf("顺序表不存在！\n");
				break;
			}
			DestroyList(p);
			break;
		case 3:
			if (NULL == L)
			{
				printf("顺序表不存在！\n");
				break;
			}
			if (ListEmpty(L))
				printf("顺序表为空\n");
			else
				printf("顺序表不为空\n");
			break;
		case 4:
			if (NULL == L)
			{
				printf("顺序表不存在！\n");
				break;
			}
			printf("顺序表元素个数为：%d\n", ListLength(L));
			break;
		case 5:
			if (NULL == L)
			{
				printf("顺序表不存在！\n");
				break;
			}
			printf("请输入元素所在位置: ");
			fflush(stdin);
			scanf_s("%d", &i);
			GetElem(L, i);
			break;
		case 6:
			if (NULL == L)
			{
				printf("顺序表不存在！\n");
				break;
			}
			fflush(stdin);
			printf("请输入要查找元素的值：");			
			scanf_s("%d", &e);
			LocateElem(L, e);
			break;
		case 7:
			if (NULL == L)
			{
				printf("顺序表不存在！\n");
				break;
			}
			printf("请依次输入要插入元素的位置和值：");
			fflush(stdin);
			scanf_s("%d%d", &i, &e);
			if (!ListInsert(L, i, e))
				printf("插入位置不在范围内\n");
			break;
		case 8:
			if (NULL == L)
			{
				printf("顺序表不存在！\n");
				break;
			}
			printf("请依次输入要删除元素的位置：");
			fflush(stdin);
			scanf_s("%d", &i);
			if (ListDelete(L, i, &e))
				printf("删除成功，删除元素值为: %d\n", e);
			else
				printf("要删除的元素不在范围内\n");
			break;
		case 9:
			if (NULL == L)
			{
				printf("顺序表不存在！\n");
				break;
			}
			if (!DispList(L))
				printf("线性表为空\n");
		}
	}
		

}
