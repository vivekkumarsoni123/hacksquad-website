#include<stdio.h>
#define size 10000
#define empty (-1)

int stack[size];
int top = empty;
void push(int val) {
	if(top == size-1) {
		printf("stack is full\n");
		return;
	}
	else {
		stack[++top] = val;
	}
}
int pop() {
	if(top == empty) {
		return -1 ;
	}
	else {
		return stack[top];
		top--;
	}
}
int Top() {
	if(top == -1) {
		return -1;
	}
	return stack[top];
}
bool isempty() {
	return top == -1;
}
int main() {
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	int ans[n] = {0};
	ans[n-1] = -1;
	push(arr[n-1]);
	for(int i=n-2;i>=0;i--) {
		while(!isempty() && Top() < arr[i]) {
			pop();
		}
		if(!isempty()) ans[i] = stack[top];
		else ans[i] = -1;
		push(arr[i]);
	}
	for(int i=0;i<n;i++) {
		printf("%d ",ans[i]);
	}
}
