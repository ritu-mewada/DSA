// Infix to postfix conversion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[20];
int top=-1;

void push(char sym) // sym = symbol
{
	stack[++top] = sym;
}

char pop()
{
	if(top==-1)
	  return -1;
	else
	  return stack[top--];
}

int precedence(char sym)
{
	if(sym == '(')
	  return 0;
	if(sym == '+' || sym == '-')
	  return 1;
	if(sym == '*' || sym == '/')
	  return 2;
	if(sym == '^')
	  return 3;	
}

int main()
{
	int i=0;
	char sym,a[50];
	printf("Enter infix expression: ");
	scanf("%s",a);
	printf("Postfix expression: ");
	while(a[i] != '\0')
	{
		// Case-1: element is character/number
		if(isalnum(a[i]))
		   printf("%c",a[i]);
		// Case-2: element is left paranthesis
		else if(a[i] == '(')
		   push(a[i]);
		// Case-3: element is right paranthesis
		else if(a[i] == ')')
		{
			// Popping elements from the stack untill top element of the stack is left paranthesis
			while((sym = pop()) != '(')
			  printf("%c",sym);
		}
		// Case-4: element is operator
		else
		{
			// Checking precedence of the operators
			while(precedence(stack[top]) >= precedence(a[i]) )
			   printf("%c",pop());
			push(a[i]);
		}
		i++;
	}
	// Popping all elements stored in the stack
	while(top != -1)
	  printf("%c",pop());
	return 0;
}
