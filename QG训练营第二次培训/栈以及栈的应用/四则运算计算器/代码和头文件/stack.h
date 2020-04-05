#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

#define MaxSize 50
 
typedef char DataType;
//操作数栈定义
typedef struct
{
	float data[MaxSize];
	int top;
}OpStack,SeqStack;


///函数声明
void InitStack(SeqStack *s);//初始化
int StackEmpty(SeqStack s);//判断栈是否为空
int GetTop(SeqStack s,DataType *e);//取栈顶元素
int PushStack(SeqStack *s,DataType e);//入栈
int PopStack(SeqStack *s,DataType *e);//出栈


#endif 
