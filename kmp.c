/*
*
* 文件名称：kmp.c
* 文件标识：
* 摘 要：该程序实现了KMP算法的模式匹配
*
* 当前版本：1.0
* 作 者：xdlong
* 完成日期：2023年8月16日
*
* 取代版本：
* 原作者 ：
* 完成日期：
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
* 函数介绍：求next数组
* 输入参数：字符串地址
* 输出参数： next数组
* 返回值 ：无
*/
void GetNext(char* str, int next[]) {
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (i < strlen(str) - 1) 
	{
		if (-1 == j || str[i] == str[j]) 
		{
			next[++i] = ++j;
		}
		else 
		{
			j = next[j];
		}
	}//求next[i+1]的值
}
//求next数组改进版
void GetNextval(char* str, int nextval[]) {
	int i = 0;
	int j = -1;
	nextval[0] = -1;
	while (i < strlen(str) - 1)
	{
		if (-1 == j || str[i] == str[j])
		{
			nextval[++i] = ++j;
			if (str[i] == str[j])
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j];
		}
	}
}
int KMPIndex(char* s, char* t) {
	int i = 0;
	int j = 0;
	int n = (int)strlen(t);
	int *next = (int *)malloc(n * sizeof(int));
	next[0] = -1;
	next[1] = 0;
	GetNextval(t, next);
	while (s[i] != '\0' && j < n)
	{
		if (j == -1 || s[i] == t[j]){
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == n) 
	{
		return i - j;
	}
	else 
	{
		return -1;
	}
}

int main() {
	int k = 1;
	char s[50], t[10];
	printf("输入主串：");
	scanf("%s", s);
	while (k)
	{
		printf("-----------------------------------\n");
		printf("0·退出，1·查找模式串，2·重新输入主串\n");
		printf("-----------------------------------\n");
		printf("输入数字选择功能（0-2）！\n");
		scanf("%d", &k);
		switch (k)
		{
		case 0:

			break;
		case 1:
			printf("请输入模式串：");
			scanf("%s", t);
			printf("模式串在主串的位置为：%d\n", KMPIndex(s, t)+1);
			break;
		case 2:
			printf("输入主串：");
			scanf("%s", s);
			break;

		}
	}

	return 0;
}