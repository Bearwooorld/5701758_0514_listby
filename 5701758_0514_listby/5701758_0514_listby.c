#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

init(ArrayListType* L) {
	L->size = 0;
}

int error(char* message) {
	fprintf(stderr, "%s\n", message);
}

int is_full(ArrayListType* L) {
	/*if (L->size >= MAX_LIST_SIZE) return 1;
	else 0;*/
	return (L->size == MAX_LIST_SIZE);
}

void insert(ArrayListType* L, int pos, element item) {
	int count = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = L->size - 1; i >= pos; i = i - 1) {
			L->array[i + 1] = L->array[i];
			count++;
		}
		L->array[pos] = item; // *************
		L->size = L->size + 1;
	}
	printf("삽입 완료, 데이터 이동횟수 : %d", count);
}

void insert_last(ArrayListType* L, element item) {
	if (L->size == MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert_first(ArrayListType* L, element item) {
	insert(L, 0, item);
}

void clear(ArrayListType* L) {
	init(L);
}

element get_entry(ArrayListType* L, int pos) {
	if (pos > 0 && pos < L->size)
		return L->array[pos];
	else
		error("위치 오류");
}

int get_length(ArrayListType* L) {
	return L->size;
}

int is_empty(ArrayListType* L) {
	return (L->size == 0);
}

void print_list(ArrayListType* L) {
	printf("[LIST]");
	for (int i = 0; i < L->size; i++) {
		printf("<%2d>", L->array[i]);
	}
	printf("\n");
}

element delete(ArrayListType* L, int pos) {
	int count = 0;
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	else {
		element item = L->array[pos];
		for (int i = pos; i < (L->size - 1); i++) {
			L->array[i] = L->array[i + 1];
			count++;
		}
		L->size = L->size - 1;
		printf("삭제 완료 , 데이터 이동 횟수 : %d", count);
		return item;
	}
}

int main() {

	ArrayListType list;
	int choice, in;
	int pos1 = 0;
	int pos2 = 0;
	init(&list);

	while (1) {
		printf("\n메뉴 : \n");
		printf("1. 리스트에 추가\n");
		printf("2. 리스트에서 삭제\n");
		printf("3. 리스트 출력\n");
		printf("0. 프로그램 종료\n");
		printf("선택 : ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			if (is_full(&list)) {
				printf("리스트가 꽉 찼습니다. \n");
			}
			else {
				printf("숫자를 입력하세요 : ");
				scanf_s("%d", &in);
				printf("추가할 위치를 입력하세요 : ");
				scanf_s("%d", &pos1);
				insert(&list, pos1, in);
			}
			break;
		case 2:
			if (is_empty(&list)) {
				printf("리스트가 비어있습니다.\n");
			}
			else {
				printf("삭제할 위치를 입력하세요 : ");
				scanf_s("%d", &pos2);
				delete(&list, pos2);
			}
			break;
		case 3:
			print_list(&list);
			break;
		case 0:
			exit(0);
		default:
			printf("잘못된 선택입니다.\n");
			break;
		}
	}

	/*insert(&list, 0, 10); print_list(&list);
	insert(&list, 0, 20); print_list(&list);
	insert(&list, 0, 30); print_list(&list);
	insert_last(&list, 0, 20); print_list(&list);
	delete(&list, 0); print_list(&list);*/
}