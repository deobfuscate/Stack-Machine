#include <stdio.h>
#include <stdlib.h>

struct stack {
	int *data;
	int size;
	int capacity;
};

struct stack* MakeStack(int initialCapacity) {
	struct stack *newStack = (struct stack*)malloc(sizeof(struct stack)*1);
	newStack->size = 0;
	newStack->capacity = initialCapacity;
	newStack->data = (int*)malloc(sizeof(int)*initialCapacity);
	return newStack;
}

void Grow(struct stack *stackPtr) {
	int newCap = stackPtr->capacity*2;
	int newData[newCap];
	stackPtr->data = realloc(stackPtr->data, sizeof(int)*newCap);
	stackPtr->capacity = newCap;
}

void Push(struct stack *stackPtr, int data) {
	if (stackPtr->size >= stackPtr->capacity) {
		//printf("Stack is full! Growing stack...\n");
		Grow(stackPtr);
	}
	stackPtr->data[stackPtr->size] = data;
	stackPtr->size++;
}

int Pop(struct stack *stackPtr) {
	if(stackPtr->size>0) {
		stackPtr->size--;
		return stackPtr->data[stackPtr->size];
	}
	else {
		return -1;
	}
}