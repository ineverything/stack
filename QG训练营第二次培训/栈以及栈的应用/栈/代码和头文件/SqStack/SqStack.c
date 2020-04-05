#include"SqStack.h"
#include<stdio.h>
#include<stdlib.h> 

//基于数组的顺序栈
//初始化栈
Status initStack(SqStack *s,int sizes)					
{														//指向结构体的指针 通过它来访问结构体 
    s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));  //分配存储空间
    if(s->elem == NULL) 
		return OVERFLOW;     							//判断上一步分配存储空间是否成功
    s->top = -1;            								//置S为空栈，为-1即表示栈为空栈
    s->size = sizes; 
	printf("成功建立一个长度为%d的栈\n",sizes);       								//栈的空间初始容量值
    return SUCCESS;      
}
//判断栈是否为空
Status isEmptyStack(SqStack *s)				
{
    if(s->top == -1)
        return SUCCESS;
    else
        return ERROR;
}
	//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e)
{
	if (s->top == -1)
		return ERROR;
    else{
		*e = s->elem[s->top];
		return SUCCESS;	
	}
}
//清空栈
Status clearStack(SqStack *s)
{
	s->top = -1;
	s->size = 0;
	return SUCCESS;
}
//销毁栈
Status destroyStack(SqStack *s)
{	
	free(s->elem);	//释放栈空间
	s->top =-1;	//将栈顶和栈底置为NULL
	s->size = 0;	//存储空间置为0
	return SUCCESS;
}
//检测栈长度
Status stackLength(SqStack *s,int *length)
{	
	*length = s->size;
	return SUCCESS;
}
//入栈
Status pushStack(SqStack *s,ElemType data)
{
	int i;
	if (s->top == (s->size )- 1) 
	   return ERROR;
	else{
		s->top++;
		s->elem[s->top] = data;
		return SUCCESS;
	}
	
}
//出栈
Status popStack(SqStack *s,ElemType *data)
{
	if (s->top == -1)
		return ERROR;	
 	else{
 	 *data = s->elem[s->top];
 	 s->top--;
     return SUCCESS; 
    }   
}
