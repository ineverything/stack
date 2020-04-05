#include"stack.h"
#include<stdio.h>

void InitStack(SeqStack *s)//初始化
{
	s->top=0;//把栈顶指针置为0
}


int StackEmpty(SeqStack s)//判断栈是否为空
{
	if(s.top==0)//判断栈顶指针是否为0
		return 1;
	else
		return 0;
}


int GetTop(SeqStack s,DataType *e)//取栈顶元素
{
	if(s.top<=0)//在取栈顶元素之前,判断栈是否为空
	{
		printf("栈已为空!\n");
		return 0;
	}
	else
	{
		*e=(char)s.data[s.top-1];//取栈顶元素
		return 1;
	}
}


int PushStack(SeqStack *s,DataType e)//入栈
{
	if(s->top>=MaxSize)//判断栈是否满了
	{
		printf("栈已满,不能进栈!\n");
		return 0;
	}
	else
	{
		s->data[s->top]=e;//e元素进栈
		s->top++;//修改栈顶指针
		return 1;
	}
}


int PopStack(SeqStack *s,DataType *e)//出栈
{
	if(s->top==0)
	{
		printf("栈已空,不能出栈!\n");
		return 0;
	}
	else
	{
		s->top--;
		*e=(char)s->data[s->top];
		return 1;
	}
}

