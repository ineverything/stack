#include"SqStack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int i,size,e,len,pushData,popData;
    SqStack s;
    
		printf("\n------------****------------\n");
    	printf("please enter the operation number \n");
		printf("1.initialize the stack.\n");
    	printf("2.push\n");
        printf("3.pop\n");
        printf("4.stack's length\n");
        printf("5.the top number\n");
        printf("6.empty the stack\n");
        printf("7.to judge whether the stack is empty or not.\n");
        printf("8.destroy\n");
        printf("0.exit");
        printf("\n------------****------------\n");
      
	do
	{
		printf("please enter a number£º");
        scanf_s("%d", &i);
        switch (i)
        {
            case 1: printf("please enter a size:\n");
            		scanf("%d",&size);
					initStack(&s,size);
					break;
            case 2: printf("please enter a data:\n");
            	    scanf("%d",&pushData);
					if(pushStack(&s,pushData))
						printf("push %d into the stack successfully.\n",pushData);
					else
						printf("fail to push the data.\n");
					break;
            case 3: if(popStack(&s,&popData))
						printf("pop %d out the stack successfully.\n",popData);
					else
						printf("fail to pop the top.\n");
					break;
            case 4:stackLength(&s,&len);
					printf("its length = %d\n",len); 
					break;
            case 5: if(getTopStack(&s,&e))
		            	printf("success,top = %d\n",e);
		            else 
		            	printf("fail to get the top\n");
					break;
            case 6:clearStack(&s);
					break;
            case 7: if(isEmptyStack(&s))
						printf("it is a empty stack\n");
					else 
						printf("it is not a empty stack\n"); 
					break;
			case 8:destroyStack(&s);
					break;		
             case 0:printf("end\n"); break;
            default:printf("error,please enter the number between 0 and 8.\n");

        }
    } while (i != 0);
    
    getchar();
	return 0;
}
