#include"LinkStack2.h"
#include<stdlib.h>


//初始化栈
Status initLStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
		return ERROR;
	S->count = 0;
	return SUCCESS;
}
//判断栈是否为空	 
Status isEmptyLStack(LinkStack *S)
{	
	if( S->count != 0 )
		return ERROR;  //非空
	else
		return SUCCESS;//空栈 
} 
//得到栈顶元素
Status getTopLStack(LinkStack *S,ElemType *e)
{
	if(isEmptyLStack(S))
		return ERROR;
	*e = S->top->next->data;
	return SUCCESS;
}
//清空栈
Status clearLStack(LinkStack *S)
{
	LinkStackPtr ptem, p = S->top->next;//p指向栈顶元素
	if (!S->top||isEmptyLStack(S))
		return ERROR;
	while (p){						
		ptem = p->next;
		free(p);					//free栈顶元素
		p = ptem;
	}
	S->count = 0;					//计数器归零
	return SUCCESS;
}
//销毁栈
Status destroyLStack(LinkStack *S)
{
	LinkStackPtr ptem, p = S->top->next;
	if (!S->top)
		return ERROR;
	while (isEmptyLStack(S)){			//这里也可以调用清空接口
		ptem = p->next;
		free(p);
		S->top->next = ptem;
		S->count--;
	}
	free(S->top);
	return SUCCESS;
}

Status LStackLength(LinkStack *S,int *length)
{//检测栈长度
	if (!S->top)
		return ERROR;
	*length = S->count;
	return SUCCESS;
}
//入栈
Status pushLStack(LinkStack *S,ElemType data)
{	
	StackNode *p;
	if(!S->top)
		return ERROR;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = S->top->next;
	S->top->next = p;
	S->count++;
	return SUCCESS;
} 
//出栈
Status popLStack(LinkStack *S,ElemType *data)
{
	LinkStackPtr ptem, p = S->top->next;
	if(isEmptyLStack(S))		
		return ERROR;
	*data = p->data;						//出栈的元素存储到 data
	ptem = p->next;
	free(p);
	S->top->next = ptem;
	S->count--;
	return SUCCESS;
}
