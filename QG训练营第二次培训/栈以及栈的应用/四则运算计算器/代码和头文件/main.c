#include"stack.h"
#include<stdio.h>
#include<string.h>

void TranslateE(char s1[],char s2[]);//����׺���ʽת��Ϊ��׺���ʽ
float ComputeE(char s[]);//�����׺���ʽ

int main (void)
{
	char a[MaxSize],b[MaxSize];
	float f;
	printf("��������ʽ:\n");
	gets(a); 
	printf("��׺���ʽΪ:%s\n",a);
	TranslateE(a,b);
	printf("ת��Ϊ��׺���ʽΪ:%s\n",b);
	f=ComputeE(b); 
	printf("�ñ��ʽ�ļ�����Ϊ:%f\n",f);
	getchar(); 
	return 0;
}

void TranslateE(char str[],char exp[])
{
	SeqStack s;
	char ch;
	DataType e;
	int i=0,j=0;
	InitStack(&s);
	ch=str[i];
	i++;
	while(ch!='\0')          //����ɨ����׺���ʽ�е�ÿ���ַ�
	{
		switch(ch)
		{
		case '(':           //����������,�����ջ
			PushStack(&s,ch);
			break;
		case ')':           //����������,��ջ�еĲ�������ջ,�������������exp��
			while(GetTop(s,&e)&&e!='(')
			{
				PopStack(&s,&e);
				exp[j]=e;
				j++;
			}
			PopStack(&s,&e);//�������ų�ջ
			break;
		case '+':
		case '-':           //�����Ӽ���,��ջ���ַ���ջ,�������������exp��,Ȼ�󽫵�ǰ�������ջ
			while(!StackEmpty(s)&&GetTop(s,&e)&&e!='(')
			{
				PopStack(&s,&e);
				exp[j]=e;
				j++;
			}
			PushStack(&s,ch);
			break;
		case '*':          //�����˳���,�Ƚ�ͬ���������ջ,����������exp��,Ȼ�󽫵�ǰ���������ջ
		case '/':
			while(!StackEmpty(s)&&GetTop(s,&e)&&e=='/'||e=='*')
			{
				PopStack(&s,&e);
				exp[j]=e;
				j++;
			}
			PushStack(&s,ch);
			break;
		case ' ':
			break;
        default:          //����������,�򽫲�����ֱ����������exp��,����������һ���ո�,�����ָ������ַ�
			while(ch>='0'&&ch<='9')
			{
				exp[j]=ch;
				j++;
				ch=str[i];
				i++;
			}
			i--;
			exp[j]=' ';
			j++;
		}
		ch=str[i];//������һ���ַ�
		i++;
	}
	while(!StackEmpty(s))//��ջ������ʣ����������ջ,��������exp��
	{
		PopStack(&s,&e);
		exp[j]=e;
		j++;
	}
	exp[j]='\0';
}

float ComputeE(char a[])//�����׺���ʽ��ֵ
{
	OpStack s;          //����һ��������ջ
	int i=0;
	float x1,x2,value,result;
	s.top=-1;           //��ʼ��ջ
	while(a[i]!='\0')                      //����ɨ���׺���ʽ�е�ÿ���ַ�
	{
		if(a[i]!=' '&&a[i]>='0'&&a[i]<='9')//�����ǰ�ַ��������ַ�,ת��Ϊ����
		{
			value=0;
			while(a[i]!=' ')               //������ǿո�,˵�������ַ�����λ�����ϵ�
			{
				value=10*value+a[i]-'0';
				i++;
			}
			s.top++;
			s.data[s.top]=value;           //����֮�����ֽ�ջ
		}
		else                               //�����ǰ�ַ��������
		{
			switch(a[i])                   //��ջ�е����ֳ�ջ����,Ȼ���õ�ǰ���������������,�ٽ������ջ
			{
			case '+':
				{
					x1=s.data[s.top];
		            s.top--;
			        x2=s.data[s.top];
			        s.top--;
				    result=x1+x2;
				    s.top++;
				    s.data[s.top]=result;
					break;}
			case '-':
				{
					x1=s.data[s.top];
		            s.top--;
			        x2=s.data[s.top];
			        s.top--;
				    result=x2-x1;
				    s.top++;
				    s.data[s.top]=result;
					break;}
			case '*':
				{
					x1=s.data[s.top];
		            s.top--;
			        x2=s.data[s.top];
			        s.top--;
				    result=x1*x2;
				    s.top++;
				    s.data[s.top]=result;
					break;}
			case '/':
				{
					x1=s.data[s.top];
		            s.top--;
			        x2=s.data[s.top];
			        s.top--;
			        if(x1 != 0){
			        result=x2/x1;
				    s.top++;
				    s.data[s.top]=result;
					break;
					} else {
						printf("��������Ϊ0�����ִ���,���Ϊ-1��ʾ���ִ���\n");
					}
				}
			}
			i++;
		}
	}
	if(s.top!=-1)//���ջ����,�������ջ,������
	{
		result=s.data[s.top];
		s.top--;
		if(s.top==-1)
			return result;
		else
		{
			printf("���ʽ����");
			return(-1);
		}
	}
	else return -1;
}



