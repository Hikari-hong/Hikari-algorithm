#define _CRT_NO_SECURE_WARNINGS
#define MAX_SIZE 100
#include<iostream>
using namespace std;

typedef struct ListArray
{
	int Array[MAX_SIZE];
	int length = 0;
}ListArray;
void Add_First(ListArray* L, int Value)
{
	if (L->length >= 100)
		cout << "Can not add Value in List any more." << endl;
	else
	{
		L->Array[L->length] = Value;
		L->length += 1;
	}
}
void Add_Last(ListArray* L, int Value)
{
	if (L->length >= 100)
	{
		cout << "Can not add Value in List any more." << endl;
		return;
	}
	else
		L->Array[L->length] = Value;
}
void Add(ListArray* L, int Value, int POSITION)
{
	if (L->length >= 100)// 가득 찼는지 검사
	{
		cout << "Can not add Value in List any more." << endl;
		return;
	}
	if (L->length < POSITION)
	{
		Add_Last(L, Value);
		return;
	}
	for (int i = L->length; i > POSITION; i--)
	{
		L->Array[i] = L->Array[i - 1];// 특정 위치부터 한칸씩 뒤로 밀어줌
	}
	L->Array[POSITION] = Value;
	L->length += 1;
}
void Erase(ListArray* L, int POSITION)
{
	if (L->length == 0)
	{
		printf("List is empty.\n");
		return;
	}
	if (POSITION > L->length)
	{
		printf("there is no data\n");
		return;
	}
	for (int i = POSITION - 1; i < L->length - 1; i++)
	{
		L->Array[i] = L->Array[i + 1];
	}
	L->length -= 1;
}
void Array_Clear(ListArray* L)
{
	L->length = 0;
}
void Find_Value(ListArray* L, int VALUE)
{
	for (int i = 0; i < L->length - 1; i++)
		if (L->Array[i] == VALUE)
			cout << "입력값 " << VALUE << "가 " << i << "번째 배열에서 발견됐습니다." << endl;
}
int Replace(ListArray* L, int POSITION, int VALUE)
{
	L->Array[POSITION - 1] = VALUE;
	return 0;
}
void Return_length(ListArray* L)
{
	cout << "List's length is ; " << L->length << endl;
}
void is_Full(ListArray* L)
{
	if (L->length < 100)
		cout << "this List is not FULL" << endl;
	else
		cout << "this List is FULL" << endl;
}
void is_Empty(ListArray* L)
{
	if (L->length < 100)
		cout << "this List is not FULL" << endl;
	else
		cout << "this List is FULL" << endl;
}
void Output(ListArray* L)
{
	for (int i = 0; i < L->length; i++)
		cout << L->Array[i] << " ";
	cout << endl;
}

/*
void main()
{
	ListArray p;

	Add(&p, 10, 0);
	Add(&p, 11, 0);
	Add(&p, 12, 0);
	Add(&p, 13, 0);
	Add(&p, 14, 0);
	Output(&p);
	Find_Value(&p, 12);
}
*/