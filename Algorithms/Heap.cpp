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

	// 힙의 가장 끝에 데이터 추가
	heap[++heap_count] = data;

	// 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 올리는 부분
	int child = heap_count;
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}

}

int pop_heap() {

	// 힙의 가장 첫번째 원소를 반환
	// 힙의 가장 앞만 보고 있다!
	int result = heap[1];

	// 첫번째 원소를 힙의 가장 끝에 원소와 바꾸고
	// 가장 끝은 이제 쓰지 않을 예정이니 heap_count를 내려준다.
	swap(&heap[1], &heap[heap_count]);
	heap_count--;

	// 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 내리는 부분
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

	int arr[TEST_ARRAY_SIZE]; // heap에 이용할 자료들
	int ans_arr[TEST_ARRAY_SIZE]; // 검증에 사용할 자료들

	srand(time(NULL));

	int test_case;
	int correct = 0;

	for (test_case = 1; test_case <= TOTAL_TEST_CASE; ++test_case) {

		// 같은지 확인하는 변수
		bool is_equal = true;

		// 자료들 입력
		for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
			arr[i] = rand() % 2000 + 1; // 1 ~ 2000 사이의 난수 생성
			ans_arr[i] = arr[i];
		}

		// heap 정렬
		for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
			push(arr[i]);
		}
		for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
			arr[i] = pop_heap();
		}

		// 정답 생성
		// greater<int>()는 내림차순을 위해서 사용
		// sort(ans_arr, ans_arr+TEST_ARRAY_SIZE)만 사용하면 오름차순이 됨
		sort(ans_arr, ans_arr + TEST_ARRAY_SIZE, greater<int>());

		// 정답과 힙정렬 결과 비교
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