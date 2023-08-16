/*
*
* �ļ����ƣ�kmp.c
* �ļ���ʶ��
* ժ Ҫ���ó���ʵ����KMP�㷨��ģʽƥ��
*
* ��ǰ�汾��1.0
* �� �ߣ�xdlong
* ������ڣ�2023��8��16��
*
* ȡ���汾��
* ԭ���� ��
* ������ڣ�
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
* �������ܣ���next����
* ����������ַ�����ַ
* ��������� next����
* ����ֵ ����
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
	}//��next[i+1]��ֵ
}
//��next����Ľ���
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
	printf("����������");
	scanf("%s", s);
	while (k)
	{
		printf("-----------------------------------\n");
		printf("0���˳���1������ģʽ����2��������������\n");
		printf("-----------------------------------\n");
		printf("��������ѡ���ܣ�0-2����\n");
		scanf("%d", &k);
		switch (k)
		{
		case 0:

			break;
		case 1:
			printf("������ģʽ����");
			scanf("%s", t);
			printf("ģʽ����������λ��Ϊ��%d\n", KMPIndex(s, t)+1);
			break;
		case 2:
			printf("����������");
			scanf("%s", s);
			break;

		}
	}

	return 0;
}