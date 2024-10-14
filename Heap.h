#pragma once
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} TreeNode;

extern TreeNode* generateMaxHeapTree(int* inputData, int size);
extern void runUserInterface(TreeNode* root);
extern void Print_Heap(TreeNode* root);
extern int InsertMaxHeap(TreeNode* root, int value, int Step);
extern int DeleteMaxHeap(TreeNode* root);
extern void Init_Heap(TreeNode* root);
extern void destroy_heap(TreeNode* h);
extern int is_empty_heap(TreeNode* h);
extern int is_full_heap(TreeNode* h);