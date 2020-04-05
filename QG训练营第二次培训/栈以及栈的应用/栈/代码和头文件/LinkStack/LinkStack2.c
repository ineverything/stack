#include"LinkStack2.h"
#include<stdlib.h>


//��ʼ��ջ
Status initLStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
		return ERROR;
	S->count = 0;
	return SUCCESS;
}
//�ж�ջ�Ƿ�Ϊ��	 
Status isEmptyLStack(LinkStack *S)
{	
	if( S->count != 0 )
		return ERROR;  //�ǿ�
	else
		return SUCCESS;//��ջ 
} 
//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *S,ElemType *e)
{
	if(isEmptyLStack(S))
		return ERROR;
	*e = S->top->next->data;
	return SUCCESS;
}
//���ջ
Status clearLStack(LinkStack *S)
{
	LinkStackPtr ptem, p = S->top->next;//pָ��ջ��Ԫ��
	if (!S->top||isEmptyLStack(S))
		return ERROR;
	while (p){						
		ptem = p->next;
		free(p);					//freeջ��Ԫ��
		p = ptem;
	}
	S->count = 0;					//����������
	return SUCCESS;
}
//����ջ
Status destroyLStack(LinkStack *S)
{
	LinkStackPtr ptem, p = S->top->next;
	if (!S->top)
		return ERROR;
	while (isEmptyLStack(S)){			//����Ҳ���Ե�����սӿ�
		ptem = p->next;
		free(p);
		S->top->next = ptem;
		S->count--;
	}
	free(S->top);
	return SUCCESS;
}

Status LStackLength(LinkStack *S,int *length)
{//���ջ����
	if (!S->top)
		return ERROR;
	*length = S->count;
	return SUCCESS;
}
//��ջ
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
//��ջ
Status popLStack(LinkStack *S,ElemType *data)
{
	LinkStackPtr ptem, p = S->top->next;
	if(isEmptyLStack(S))		
		return ERROR;
	*data = p->data;						//��ջ��Ԫ�ش洢�� data
	ptem = p->next;
	free(p);
	S->top->next = ptem;
	S->count--;
	return SUCCESS;
}
