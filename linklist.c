#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElemType int //数据的类型
typedef struct LinkNode{
	ElemType date;
	struct LinkNode* next;
}LNode, *LinkList;
//1创建头节点
LNode * InitList() {
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}
//2销毁链表
void DestroyList(LNode** pL) {//传入链表L的地址
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
//返回第i个元素的指针,第零个元素返回头节点指针
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
//3·删除数据元素
bool ListDelete(LNode* L, int i, ElemType* e) {
	int j = 0;
	LNode* p = pEmle(L, i - 1);//p为第i-1个节点
	LNode* q = pEmle(L, i);//p为第i个节点
	if (p == NULL || q == NULL)
		return false;
	p->next = q->next;
	*e = q->date;
	free(q);
	return true;
}
//4·显示链表长度
int ListLength(LNode* L) {
	int j = 0;
	LNode* p = L->next;
	while (p != NULL) {
		j++;
		p = p->next;
	}

	return j;
}
//5·按位查找
bool GetElem(LNode* L, int i, ElemType* e) {
	LNode* p = pEmle(L, i);
	if (NULL == p || 0 == i) {
		return false;
	} else {
		*e = p->date;
		return true;
	}
}
//6·按值查找
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
//7·插入数据元素
bool ListInsert(LNode* L, int i, ElemType e) {
	LNode* p = pEmle(L, i-1);
	if (p) {
		LNode* s = (LNode*)malloc(sizeof(LNode));//插入节点设为s
		s->next = p->next;
		s->date = e;
		p->next = s;
		return true;
	} else {
		return false;
	}
}
//8·尾插法插入元素
void ListInsertTrail(LNode* L) {
	ElemType e;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	printf("请依次输入元素值，输入错误数据结束：\n");
	while (scanf_s("%d", &e)){
		p->next = (LNode*)malloc(sizeof(LNode));
		p = p->next;
		p->date = e;
	}
	p->next = NULL;
}
//9输出链表
void DispList(LNode* L) {
	int i=1;
	LNode* p = L->next;
	while (p != NULL) {
		printf("a%d: %d\n", i++, p->date);
		p = p->next;
	}
}
//11排序
void ListSort(LNode* L) {
	LNode* p = L->next->next , *pre = L, * q;//p需要比较元素的节点
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
//判断链表是否存在
bool IsExist(LNode* L) {
	if (NULL == L) {
		return false;
	} else {
		return true;
	}
}
void show() { //显示功能
	printf("\n**********************\n");
	printf("1·初始化链表\n");
	printf("2·销毁链表\n");
	printf("3·删除数据元素\n");
	printf("4·显示链表长度\n");
	printf("5·求链表的第I个元素值\n");
	printf("6·按值查找\n");
	printf("7·插入\n");
	printf("8·尾插法插入元素\n");
	printf("9·输出链表\n");
	printf("11.排序\n");
	printf("0·退出\n");
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
		printf("选择功能（0-9）\n");
		printf("请输入选项: ");
		rewind(stdin);
		scanf_s("%d", &k);
		e = 0;
		switch (k)
		{
		case 0:
			break;
		case 1://创建头节点
			L = InitList();
			printf("链表初始化成功!\n");
			break;
		case 2://销毁链表
			if (IsExist(L))
			{
				DestroyList(&L);
			}
			else
				printf("链表不存在！\n");
			break;
		case 3://删除数据元素
			if (IsExist(L))
			{
				printf("请输入要删除元素的位置：");
				rewind(stdin);
				scanf_s("%d", &i);
				if (ListDelete(L, i, &e))
					printf("删除成功，删除元素值为: %d\n", e);
				else
					printf("要删除的元素不在范围内\n");
			}
			else
				printf("链表不存在！\n");
			break;
		case 4://显示链表长度
			if (IsExist(L))
			{
				printf("链表元素个数为：%d\n", ListLength(L));
			}
			else
				printf("链表不存在！\n");
			break;
		case 5://按位查找
			if (IsExist(L))
			{
				printf("请输入要查找元素的位置：");
				rewind(stdin);
				scanf_s("%d", &i);
				GetElem(L, i, &e);
				printf("第%d个元素的值为: %d\n", i, e);
			}
			else
				printf("链表不存在！\n");
			break;
		case 6://按值查找
			if (IsExist(L))
			{
				printf("请输入要查找元素的值：");
				rewind(stdin);
				scanf_s("%d", &e);
				if (i = LocateElem(L, e)) {
					printf("该元素在链表的位置为：%d", i);
				}
				else {
					printf("该元素不存在");
				}
			}
			else
				printf("链表不存在！\n");
			break;
		case 7://插入数据元素
			if (IsExist(L))
			{
				printf("请依次输入要插入元素的位置和值：");
				rewind(stdin);
				scanf_s("%d%d", &i, &e);
				if (!ListInsert(L, i, e))
					printf("插入位置不在范围内\n");
			}
			else
				printf("链表不存在！\n");
			break;
		case 8://尾插法插入元素
			if (IsExist(L))
			{
				ListInsertTrail(L);
			}
			else
				printf("链表不存在！\n");
			break;
		case 9://输出链表
			if (!IsExist(L))
				printf("链表不存在！\n");
			else if(!ListLength(L))
				printf("链表为空！\n");
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
