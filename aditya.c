#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Stack
{
int top;
int size;
char* array;
};
struct Stack* form_stack(int size)
{
struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
stack->size = size;
stack->top = -1;
stack->array = (char*) malloc(stack->size * sizeof(char));
return stack;
}
int Check_empty(struct Stack* stack)
{
return stack->top == -1;
}
int Check_full(struct Stack* stack)
{
return stack->top == stack->size - 1;
}
void push(struct Stack* stack, char item)
{
if (Check_full(stack))
return;
stack->array[++stack->top] = item;
}
char pop(struct Stack* stack)
{
if (Check_empty(stack))
return 0;
return stack->array[stack->top--];
}
void reversestring(char str[])
{
int p = strlen(str);
struct Stack* stack = form_stack(p);
int i;
for (i = 0; i < p; i++){
if(str[i]!=' ' || str[i-1]!=' ')
{
push(stack, str[i]);
}
}
for (i = 0; i < p; i++)
{
str[i] = pop(stack);
}

}
void reverse(char* begin, char* end)
{
char temp;
while (begin < end) {
temp = *begin;
*begin++ = *end;
*end-- = temp;
}
}
void change_order(char* s)
{
char* word_begin = s;
char* temp = s;
while (*temp) {
temp++;
if (*temp == '\0') {
reverse(word_begin, temp - 1);
}
else if (*temp == ' ') {
reverse(word_begin, temp - 1);
word_begin = temp + 1;
}
}
reverse(s, temp - 1);
}
int main()
{
char str[2500];
char file_name[100];
char name2[100];
FILE* to_read;
FILE* to_write;
printf("Enter the name of the file to be read: ");
gets(file_name);
to_read=fopen(file_name, "r");
fgets(str,2500,to_read);
reversestring(str);
char* p=str;
change_order(p);
printf("Enter the file name where the text is too be stored: ");
gets(name2);
to_write = fopen(name2, "w+");
fputs(str,to_write);
printf("The string after reversing is: \"%s\" \n", str);
}