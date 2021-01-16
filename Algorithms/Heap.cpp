#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <functional>

#define HEAP_SIZE 256
#define TOTAL_TEST_CASE 100
#define TEST_ARRAY_SIZE 20

using namespace std;

int heap[HEAP_SIZE];
int heap_count = 0;

void swap(int* a, int* b) {
	int tmp = *a; *a = *b; *b = tmp;
}

void init_heap() {
	heap_count = 0;
}

int size() {
	return heap_count;
}

void push(int data) {

	// ���� ���� ���� ������ �߰�
	heap[++heap_count] = data;

	// �Ʒ��� ������ child�� parent�� ���ϸ鼭 �˸��� ��ġ�� �ϳ��� �ø��� �κ�
	int child = heap_count;
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}

}

int pop_heap() {

	// ���� ���� ù��° ���Ҹ� ��ȯ
	// ���� ���� �ո� ���� �ִ�!
	int result = heap[1];

	// ù��° ���Ҹ� ���� ���� ���� ���ҿ� �ٲٰ�
	// ���� ���� ���� ���� ���� �����̴� heap_count�� �����ش�.
	swap(&heap[1], &heap[heap_count]);
	heap_count--;

	// �Ʒ��� ������ child�� parent�� ���ϸ鼭 �˸��� ��ġ�� �ϳ��� ������ �κ�
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heap_count) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	while (child <= heap_count && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= heap_count) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}

	return result;
}

/*
int main() {

	int arr[TEST_ARRAY_SIZE]; // heap�� �̿��� �ڷ��
	int ans_arr[TEST_ARRAY_SIZE]; // ������ ����� �ڷ��

	srand(time(NULL));

	int test_case;
	int correct = 0;

	for (test_case = 1; test_case <= TOTAL_TEST_CASE; ++test_case) {

		// ������ Ȯ���ϴ� ����
		bool is_equal = true;

		// �ڷ�� �Է�
		for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
			arr[i] = rand() % 2000 + 1; // 1 ~ 2000 ������ ���� ����
			ans_arr[i] = arr[i];
		}

		// heap ����
		for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
			push(arr[i]);
		}
		for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
			arr[i] = pop_heap();
		}

		// ���� ����
		// greater<int>()�� ���������� ���ؼ� ���
		// sort(ans_arr, ans_arr+TEST_ARRAY_SIZE)�� ����ϸ� ���������� ��
		sort(ans_arr, ans_arr + TEST_ARRAY_SIZE, greater<int>());

		// ����� ������ ��� ��
		for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
			if (ans_arr[i] != arr[i]) {
				is_equal = false;
				break;
			}
		}

		if (is_equal) correct++;

	}

	printf("Total: %d / %d\n", correct, TOTAL_TEST_CASE);

	return 0;
}
*/