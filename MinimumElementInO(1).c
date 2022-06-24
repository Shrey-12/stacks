#include <stdio.h>
#include <stdlib.h>

// main stack to store elements
// auxilary stack to store minimum
struct twoStacks
{
    int *arr;
    int size;
    int top1, top2;
};
struct twoStacks s;

void buildStacks(int n)
{
    s.size = n;
    s.arr = (int *)malloc(s.size * sizeof(int));
    s.top1 = -1;
    s.top2 = s.size;
}

// function to find top element from first stack
int isEmpty1()
{
    if (s.top1 == -1){
        return 1;}
    else{
        return 0;}
}

// function to find top element from second stack
int isEmpty2()
{
    if (s.top2 == s.size)
        return 1;
    else
        return 0;
}

// function to find top element of stack 1
int top1()
{
    if (isEmpty2())
        return 0;
    return s.arr[s.top1];
}

// function to find top element of stack 2
int top2()
{
    if (isEmpty2())
        return 0;
    return s.arr[s.top2];
}

// function to find if stack 1 is full
int isFull1()
{
    if (s.top1 == s.top2 - 1)
        return 1;
    else
        return 0;
}

// function to find if stack 2 is full
int isFull2()
{
    if (s.top1 == s.top2 - 1)
        return 1;
    else
        return 0;
}

// method to push an element x into stack 1
void push1(int x)
{
    // there is at least one empty space for new element
    if (s.top1 < s.top2 - 1)
    {
        s.top1++;
        s.arr[s.top1] = x;
    }
    else
    {
        printf("Stack overflow");
    }
}

// method to push an element x to stack 2
void push2(int x)
{
    // There is at least one empty space for new element
    if (s.top1 < s.top2 - 1)
    {
        s.top2--;
        s.arr[s.top2] = x;
    }
    else
    {
        printf("Stack overflow");
    }
}

// inserts a given element on the top of the stack
void push(int val)
{
    // push the element into the main stack
    push1(val);
    // if auxilary stack is empty, push the given element into it ttoo
    if (isEmpty2())
    {
        push2(val);
    }
    else
    {
        // push the given element into the auxilary stack
        // if it is less that or equal to the current minimum
        if (top2() >= val)
        {
            push2(val);
        }
    }
}
// method to pop an element from first stack
int pop1()
{
    if (!isEmpty1())
    {
        int x = s.arr[s.top1];
        s.top1--;
        return x;
    }
    else
    {
        printf("stack underflow");
    }
}

// method to pop an element from second stack
int pop2()
{
    if (s.top2 < s.size)
    {
        int x = s.arr[s.top2];
        s.top2++;
        return x;
    }
    else
    {
        printf("stack underflow");
    }
}

// Removes the top element from the stack and returns it
int pop()
{
    // removes the top element from the main stack
    int top = top1();
    pop1();

    // removes the top element from the auxilary stack only if it is minimum
    if (top == top2())
    {
        pop2();
    }
    // return the removed element
    return top;
}

int getMin()
{
    return s.arr[s.top2];
}

int main()
{
    buildStacks(20);
    int k;
    while(k){
    printf("\nEnter your choice from the menu:\n(1)push\n(2)pop\n(3)top\n(4)isEmpty\n(5)Find minimum element in O(1) time\n");
    scanf("%d",&k);
    switch(k){
        case 1: 
        printf("Enter ther value you want to push into the stack\t");
        int val;
        scanf("%d",&val);
        push(val);
        break;

        case 2: 
        printf("%d element has been popped out\n",pop());
        break;

        case 3: 
        printf("The top element is %d\n",top1());
        break;

        case 4: 
        if(isEmpty1()){
        printf("The main stack is empty\n");}
        else{
        printf("The entered stack is not empty\n");}
        break;

        case 5: 
        printf("the minimum element is %d",getMin());
        break;
    }
}
}
