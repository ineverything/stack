#include"SqStack.h"
#include<stdio.h>
#include<stdlib.h> 

//���������˳��ջ
//��ʼ��ջ
Status initStack(SqStack *s,int sizes)					
{														//ָ��ṹ���ָ�� ͨ���������ʽṹ�� 
    s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));  //����洢�ռ�
    if(s->elem == NULL) 
		return OVERFLOW;     							//�ж���һ������洢�ռ��Ƿ�ɹ�
    s->top = -1;            								//��SΪ��ջ��Ϊ-1����ʾջΪ��ջ
    s->size = sizes; 
	printf("�ɹ�����һ������Ϊ%d��ջ\n",sizes);       								//ջ�Ŀռ��ʼ����ֵ
    return SUCCESS;      
}
//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s)				
{
    if(s->top == -1)
        return SUCCESS;
    else
        return ERROR;
}
	//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e)
{
	if (s->top == -1)
		return ERROR;
    else{
		*e = s->elem[s->top];
		return SUCCESS;	
	}
}
//���ջ
Status clearStack(SqStack *s)
{
	s->top = -1;
	s->size = 0;
	return SUCCESS;
}
//����ջ
Status destroyStack(SqStack *s)
{	
	free(s->elem);	//�ͷ�ջ�ռ�
	s->top =-1;	//��ջ����ջ����ΪNULL
	s->size = 0;	//�洢�ռ���Ϊ0
	return SUCCESS;
}
//���ջ����
Status stackLength(SqStack *s,int *length)
{	
	*length = s->size;
	return SUCCESS;
}
//��ջ
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
//��ջ
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
