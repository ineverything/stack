#include"stack.h"
#include<stdio.h>
#include<string.h>

void TranslateE(char s1[],char s2[]);//将中缀表达式转化为后缀表达式
float ComputeE(char s[]);//计算后缀表达式

int main (void)
{
	char a[MaxSize],b[MaxSize];
	float f;
	printf("请输入表达式:\n");
	gets(a); 
	printf("中缀表达式为:%s\n",a);
	TranslateE(a,b);
	printf("转换为后缀表达式为:%s\n",b);
	f=ComputeE(b); 
	printf("该表达式的计算结果为:%f\n",f);
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
	while(ch!='\0')          //依此扫描中缀表达式中的每个字符
	{
		switch(ch)
		{
		case '(':           //遇到左括号,将其进栈
			PushStack(&s,ch);
			break;
		case ')':           //遇到右括号,将栈中的操作数出栈,并将其存入数组exp中
			while(GetTop(s,&e)&&e!='(')
			{
				PopStack(&s,&e);
				exp[j]=e;
				j++;
			}
			PopStack(&s,&e);//将左括号出栈
			break;
		case '+':
		case '-':           //遇到加减号,将栈顶字符出栈,并将其存入数组exp中,然后将当前运算符进栈
			while(!StackEmpty(s)&&GetTop(s,&e)&&e!='(')
			{
				PopStack(&s,&e);
				exp[j]=e;
				j++;
			}
			PushStack(&s,ch);
			break;
		case '*':          //遇到乘除号,先将同级运算符出栈,并存入数组exp中,然后将当前的运算符进栈
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
        default:          //遇到操作数,则将操作数直接送入数组exp中,并在其后添加一个空格,用来分隔数字字符
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
		ch=str[i];//读入下一个字符
		i++;
	}
	while(!StackEmpty(s))//将栈中所有剩余的运算符出栈,送入数组exp中
	{
		PopStack(&s,&e);
		exp[j]=e;
		j++;
	}
	exp[j]='\0';
}

float ComputeE(char a[])//计算后缀表达式的值
{
	OpStack s;          //定义一个操作数栈
	int i=0;
	float x1,x2,value,result;
	s.top=-1;           //初始化栈
	while(a[i]!='\0')                      //依次扫描后缀表达式中的每个字符
	{
		if(a[i]!=' '&&a[i]>='0'&&a[i]<='9')//如果当前字符是数字字符,转换为数字
		{
			value=0;
			while(a[i]!=' ')               //如果不是空格,说明数字字符是两位数以上的
			{
				value=10*value+a[i]-'0';
				i++;
			}
			s.top++;
			s.data[s.top]=value;           //处理之后将数字进栈
		}
		else                               //如果当前字符是运算符
		{
			switch(a[i])                   //将栈中的数字出栈两次,然后用当前的运算符进行运算,再将结果入栈
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
						printf("除数不能为0，出现错误,结果为-1表示出现错误\n");
					}
				}
			}
			i++;
		}
	}
	if(s.top!=-1)//如果栈不空,将结果出栈,并返回
	{
		result=s.data[s.top];
		s.top--;
		if(s.top==-1)
			return result;
		else
		{
			printf("表达式错误");
			return(-1);
		}
	}
	else return -1;
}



