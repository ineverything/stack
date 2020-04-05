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
	int	count; //��¼ջ��Ԫ�ظ�����Ҳ���Խ�Ԫ�ظ������Է���LinkStack�����ж��塣 
}LinkStack;



//��ջ
Status initLStack(LinkStack *S);//��ʼ��ջ
Status isEmptyLStack(LinkStack *S);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *S,ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *S);//���ջ
Status destroyLStack(LinkStack *S);//����ջ
Status LStackLength(LinkStack *S,int *length);//���ջ����
Status pushLStack(LinkStack *S,ElemType data);//��ջ
Status popLStack(LinkStack *S,ElemType *data);//��ջ


#endif 
