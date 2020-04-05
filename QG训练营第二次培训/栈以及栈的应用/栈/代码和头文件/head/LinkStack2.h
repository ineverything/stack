#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count; //记录栈中元素个数，也可以将元素个数属性放在LinkStack类型中定义。 
}LinkStack;



//链栈
Status initLStack(LinkStack *S);//初始化栈
Status isEmptyLStack(LinkStack *S);//判断栈是否为空
Status getTopLStack(LinkStack *S,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *S);//清空栈
Status destroyLStack(LinkStack *S);//销毁栈
Status LStackLength(LinkStack *S,int *length);//检测栈长度
Status pushLStack(LinkStack *S,ElemType data);//入栈
Status popLStack(LinkStack *S,ElemType *data);//出栈


#endif 
