#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

#define MaxSize 50
 
typedef char DataType;
//������ջ����
typedef struct
{
	float data[MaxSize];
	int top;
}OpStack,SeqStack;


///��������
void InitStack(SeqStack *s);//��ʼ��
int StackEmpty(SeqStack s);//�ж�ջ�Ƿ�Ϊ��
int GetTop(SeqStack s,DataType *e);//ȡջ��Ԫ��
int PushStack(SeqStack *s,DataType e);//��ջ
int PopStack(SeqStack *s,DataType *e);//��ջ


#endif 
