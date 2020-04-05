#include"LinkStack2.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i,pushData,len,topData;
	int popData=0;
	LinkStack S;
	printf("\n------------****------------\n");
    printf("please enter the operation number.\n");
	printf("1.initialize the stack.\n");
    printf("2.push.\n");
    printf("3.pop.\n");
    printf("4.the stack'length.\n");
    printf("5.the top number.\n");
    printf("6.empty the stack.\n");
    printf("7.to judge whether or not it is a empty stack.\n");
    printf("8.destory.\n");
    printf("0.exit");
    printf("\n------------****------------\n");
      
	do{
		printf("please enter a number£º");
        scanf("%d", &i);
        
        switch (i){
            case 1: initLStack(&S);
            		printf("create a new stack successful.\n"); 
				    break;
            case 2: printf("please enter a data:\n");
            	    scanf("%d",&pushData);
					if( pushLStack(&S,pushData) )
						printf("push %d into the stack successfully.\n",pushData);
					break;
            case 3: if( popLStack(&S,&popData) ) 
						printf("pop %d out the stack successfully.\n",popData);
					else
						printf("fail to pop the top.\n");
					break;
            case 4:if(LStackLength(&S,&len) )
						printf("its length = %d\n",len);
					else 
						printf("fail to get it.\n"); 
					break;
            case 5: if(getTopLStack(&S,&topData) )
		            	printf("success,topData = %d\n",topData);
		            else 
		            	printf("fail to get the top\n");
					break;
            case 6:if( clearLStack(&S) )
            			printf("success.\n");
            		else
            			printf("error.\n");
					break;
            case 7: if(isEmptyLStack(&S))
						printf("it is a empty stack\n");
					else 
						printf("it is not a empty stack\n"); 
					break;
			case 8:if(destroyLStack(&S) )
						printf("success.\n");
					else
						printf("error.\n");
					break;		
            case 0:printf("end\n");
			 		 break;
            default: printf("error,please enter a number between 0 and 8.\n");
        }
        
    } while (i != 0);
    
    getchar();
	return 0;
}
