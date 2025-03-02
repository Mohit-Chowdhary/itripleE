#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int size;
    int top;
    int max;
    int min;
    int* arr;
} Stack;

Stack* createStack(int size){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->max=INT_MIN;
    stack->min=INT_MAX;
    stack->size=size;
    stack->top=-1;
    stack->arr=(int*)malloc(sizeof(int)*size);
    return stack;
}

void pushStack(Stack* stack,int value){
    if(stack->size>stack->top+1){
        stack->top++;
        stack->arr[stack->top]=value;

        stack->max=stack->max>value?stack->max:value;
        stack->min=stack->min<value?stack->min:value;

    }
    else{
        printf("Stack overflow, cannot push %d onto stack.",value);
    }
}

int popStack(Stack* stack){
    int value=INT_MIN;
    if(stack->top>-1){
        value=stack->arr[stack->top];
        stack->top--;

        if(value==stack->min || value==stack->max){
            stack->min=INT_MAX;
            stack->max=INT_MIN;
            for(int i=0;i<stack->top;i++){
                
                stack->max=stack->max>value?stack->max:value;
                stack->min=stack->min<value?stack->min:value;

            }
        }
    }
    else{
        printf("\nStack underflow, cannot pop from empty stack.");
    }
    return value;
}

int topStack(Stack* stack){
    int value=INT_MIN;
    if(stack->top==-1){
        printf("Stack underflow");
    }
    else{
        value=stack->arr[stack->top];
    }
    return value;
}

int minStack(Stack* stack){
    return stack->min;
}

int maxStack(Stack* stack){
    return stack->max;
}

int main(){
    int terminate=6;

    printf("Create the stack, enter size of the stack: ");
    int size;
    scanf("%d",&size);
    Stack* stack=createStack(size);

    do{
        printf("\n\nHello, please select one of the following:\n"
                "1) Push element\n"
                "2) Pop element\n"
                "3) View Top\n"
                "4) Min element\n"
                "5) Max element\n"
                "6) Quit\n\n");
        
        scanf("%d",&terminate);

        if(terminate==1){
            int value;
            printf("Enter element to push: ");
            scanf("%d",&value);
            pushStack(stack,value);
        }

        else if(terminate==2){
            int value=popStack(stack);
            if(value!=INT_MIN){
                printf("Stack popped: %d\n",value);
            }
        }

        else if(terminate==3){
            int value=topStack(stack);
            if(value!=INT_MIN){
                printf("Top element is %d.\n",value);
            }
        }

        else if(terminate==4){
            int value=minStack(stack);
            if(value!=INT_MAX){
                printf("Min element is %d.\n",value);
            }
        }
        else if(terminate==5){
            int value=maxStack(stack);
            if(value!=INT_MIN){
                printf("Max element is %d.\n",value);
            }
        }

        else if(terminate==6){
            printf("Terminationg the program.\n");
        }

        else{
            printf("Invalid option, try again.\n");
        }

    }while(terminate!=6);
}