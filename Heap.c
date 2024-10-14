#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

//힙 초기화 함수
void Init_Heap(TreeNode* root) {
    root->size = 0;
}

//메모리 해제 함수
void destroy_heap(TreeNode* h) {
    free(h);
}

//힙이 비어있는지 확인하는 함수
int is_empty_heap(TreeNode* h) {
    return (h->size == 0);

}

//힙이 가득차 있는지 확인하는 함수
int is_full_heap(TreeNode * h) {
    return (h->size == (MAX_SIZE - 1));

}

//힙의 노드 출력 함수
void Print_Heap(TreeNode* root) {
    for (int i = 0; i < root->size; i++) {
        printf("%d ", root->data[i]);
    }
    printf("\n");
}

// 최대 값 노드 추가 함수
int InsertMaxHeap(TreeNode* root, int value, int Step) {
    if (root->size >= MAX_SIZE) {
        printf("힙 가득 참\n");
        return 0;
    }

    int index = root->size; 
    root->data[index] = value; 
    root->size++; 

    int move = 0; 
    if (Step) {
        Print_Heap(root); 
    }

    while (index > 0) {
        int parent = (index - 1) / 2;
        if (root->data[parent] < root->data[index]) { 
            int temp = root->data[parent];
            root->data[parent] = root->data[index];
            root->data[index] = temp;
            index = parent;
            move++;

            if (Step) {

                Print_Heap(root); 
            }
        }
        else {
            break;
        }
    }


    return move; 
}

// 최대 값 노드 삭제 함수
int DeleteMaxHeap(TreeNode* root) {
    if (root->size == 0) { 

        printf("힙 비어있음\n");
        return 0;
    }

    root->data[0] = root->data[root->size - 1]; 
    root->size--; 

    int index = 0;
    int moves = 0;
    Print_Heap(root); 

    while (index * 2 + 1 < root->size) {
        int leftChild = index * 2 + 1; 
        int rightChild = index * 2 + 2; 
        int largerChild = leftChild; 

        if (rightChild < root->size && root->data[rightChild] > root->data[leftChild]) {
            largerChild = rightChild;
        }

        if (root->data[index] < root->data[largerChild]) {
            int temp = root->data[index];
            root->data[index] = root->data[largerChild];
            root->data[largerChild] = temp;

            index = largerChild;
            moves++;

            Print_Heap(root); 
        }
        else {
            break; 
        }
    }


    return moves;
}

//힙 트리의 레벨별 출력하는 함수
void display_heap(TreeNode* root) {
    if (root->size == 0) { 
        printf("힙 비어있음.\n");
        return;
    }

    int level = 0; 
    int count = 1; 
    int index = 0; 

    printf("트리 레벨별 출력 \n");
    while (index < root->size) {
        printf("[%d] ", level + 1);

        for (int i = 0; i < count && index < root->size; i++) {
            printf("%d ", root->data[index]);
            index++;
        }
        printf("\n");

        level++;
        count *= 2;
    }
}

//사용자의 입력을 받아 원하는 기능을 수행하는 함수
void runUserInterface(TreeNode* root) {
    char choice;
    int value, move;

    while (1) {
        for (int i = 0; i < 15; i++) {
            printf("ㅡ");
        }
		printf("\n");
        printf(" ㅣ  i : 노드 추가       ㅣ \n");
        printf(" ㅣ  d : 노드 삭제       ㅣ \n");
        printf(" ㅣ  p : 레벨별 출력     ㅣ\n");
        printf(" ㅣ  c : 종료            ㅣ\n");
        for (int i = 0; i < 15; i++) {
            printf("ㅡ");
        }
		printf("\n");

        printf("메뉴 입력: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'i':
            printf("추가할 값 입력: ");
            scanf("%d", &value);
            move = InsertMaxHeap(root, value, 1);
            printf("노드 이동 횟수: %d\n", move);
            break;

        case 'd':
            move = DeleteMaxHeap(root);
            printf("노드 이동 횟수: %d\n", move);
            break;

        case 'p':
            display_heap(root);
            break;

        case 'c':
            printf("프로그램 종료.\n");
            return;

        default:
            printf("잘못된 입력.\n");
        }
    }
}

//힙 트리를 생성하는 함수
TreeNode* generateMaxHeapTree(int inputData[], int size) {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    Init_Heap(root);

    for (int i = 0; i < size; i++) {
        InsertMaxHeap(root, inputData[i], 0);
    }

    return root;
}