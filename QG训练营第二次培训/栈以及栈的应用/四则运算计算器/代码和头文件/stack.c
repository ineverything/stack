#include"stack.h"
#include<stdio.h>

void InitStack(SeqStack *s)//��ʼ��
{
	s->top=0;//��ջ��ָ����Ϊ0
}


int StackEmpty(SeqStack s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s.top==0)//�ж�ջ��ָ���Ƿ�Ϊ0
		return 1;
	else
		return 0;
}


int GetTop(SeqStack s,DataType *e)//ȡջ��Ԫ��
{
	if(s.top<=0)//��ȡջ��Ԫ��֮ǰ,�ж�ջ�Ƿ�Ϊ��
	{
		printf("ջ��Ϊ��!\n");
		return 0;
	}
	else
	{
		*e=(char)s.data[s.top-1];//ȡջ��Ԫ��
		return 1;
	}
}


int PushStack(SeqStack *s,DataType e)//��ջ
{
	if(s->top>=MaxSize)//�ж�ջ�Ƿ�����
	{
		printf("ջ����,���ܽ�ջ!\n");
		return 0;
	}
	else
	{
		s->data[s->top]=e;//eԪ�ؽ�ջ
		s->top++;//�޸�ջ��ָ��
		return 1;
	}
}


int PopStack(SeqStack *s,DataType *e)//��ջ
{
	if(s->top==0)
	{
		printf("ջ�ѿ�,���ܳ�ջ!\n");
		return 0;
	}
	else
	{
		s->top--;
		*e=(char)s->data[s->top];
		return 1;
	}
}

