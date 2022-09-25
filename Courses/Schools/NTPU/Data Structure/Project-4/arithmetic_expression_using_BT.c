#include <stdio.h>
#include <stdlib.h>


#define MAX_LENGTH 1025

#define MALLOC(p,s) if(!((p) = malloc (s))){printf("Insufficient memory");exit(EXIT_FAILURE);}


typedef struct node * treePointer;
struct node
{
    char data;
    treePointer leftChild;
    treePointer rightChild;
};


typedef struct stack * stackPointer;
struct stack
{
    treePointer data;
    stackPointer link;
} *top = NULL;


typedef struct queue * queuePointer;
struct queue
{
    treePointer data;
    queuePointer link;
} *front, *rear;


treePointer createTree( char [] );

void push( treePointer );

treePointer pop();

void addq( treePointer );

treePointer deleteq();

void inorder( treePointer );

void preorder( treePointer );

void postorder( treePointer );

void levelOrder( treePointer );

void iterInorder( treePointer );

void iterPreorder( treePointer );

void iterPostorder( treePointer );


int main()
{
    int i;
    char X[MAX_LENGTH];
    treePointer node;

    for( i = 0; i < MAX_LENGTH - 1; i++ )
    {
        scanf( "%c", &X[i] );
        if( X[i] == '\n' )
        {
            X[i] = '\0';
            break;
        }
    }

    node = createTree(X);

    printf("\n\nrecursive Inorder : ");
    inorder(node);

    printf("\n\nrecursive Preorder : ");
    preorder(node);

    printf("\n\nrecursive Postorder : ");
    postorder(node);

    printf("\n\nLevelorder : ");
    levelOrder(node);

    printf("\n\niterative Inorder : ");
    iterInorder(node);

    printf("\n\niterative Preorder : ");
    iterPreorder(node);

    printf("\n\niterative Postorder : ");
    iterPostorder(node);

    printf("\n\n\n");
    system("pause");
}

treePointer createTree( char data[] )
{
    int n = 0;
    treePointer currentNode, tempNode, temp;

    MALLOC(currentNode, sizeof(*currentNode));
    currentNode -> data = data[1];
    MALLOC(temp, sizeof(*temp));
    temp -> leftChild = NULL;
    temp -> rightChild = NULL;
    currentNode -> leftChild = temp;
    (currentNode -> leftChild) -> data = data[0];

    for(n = 1; data[n+2] != '\0'; n += 2)
    {
        if(data[n] == '+' || data[n] == '-')
        {
            if(data[n+2] == '+' || data[n+2] == '-')
            {
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                currentNode -> rightChild = temp;
                (currentNode -> rightChild) -> data = data[n+1];
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                temp -> leftChild = currentNode;
                temp -> data = data[n+2];
                currentNode = temp;
            }
            else if(data[n+2] == '*' || data[n+2] == '/')
            {
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                temp -> data = data[n+2];
                tempNode = temp;
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                tempNode -> leftChild = temp;
                (tempNode -> leftChild) -> data = data[n+1];

                for(n += 2; data[n+2] == '*' || data[n+2] == '/'; n += 2)
                {
                    MALLOC(temp, sizeof(*temp));
                    temp -> leftChild = NULL;
                    temp -> rightChild = NULL;
                    tempNode -> rightChild = temp;
                    (tempNode -> rightChild) -> data = data[n+1];
                    MALLOC(temp, sizeof(*temp));
                    temp -> leftChild = NULL;
                    temp -> rightChild = NULL;
                    temp -> data = data[n+2];
                    temp -> leftChild = tempNode;
                    tempNode = temp;
                }

                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                tempNode -> rightChild = temp;
                (tempNode -> rightChild) -> data = data[n+1];
                currentNode -> rightChild = tempNode;
                MALLOC(temp, sizeof(*temp));
                temp -> leftChild = NULL;
                temp -> rightChild = NULL;
                temp -> leftChild = currentNode;
                temp -> data = data[n+2];
                currentNode = temp;
            }
        }
        else if(data[n] == '*' || data[n] == '/')
        {
            MALLOC(temp, sizeof(*temp));
            temp -> leftChild = NULL;
            temp -> rightChild = NULL;
            currentNode -> rightChild = temp;
            (currentNode -> rightChild) -> data = data[n+1];
            MALLOC(temp, sizeof(*temp));
            temp -> leftChild = currentNode;
            temp -> data = data[n+2];
            currentNode = temp;
        }
    }

    MALLOC(temp, sizeof(*temp));
    temp -> leftChild = NULL;
    temp -> rightChild = NULL;
    currentNode -> rightChild = temp;
    (currentNode -> rightChild) -> data = data[n+1];

    return currentNode;
}

void inorder(treePointer ptr)
{
    if(ptr)
    {
        inorder(ptr -> leftChild);
        printf("%c", ptr -> data);
        inorder(ptr -> rightChild);
    }
}

void preorder(treePointer ptr)
{
    if(ptr)
    {
        printf("%c", ptr -> data);
        preorder(ptr -> leftChild);
        preorder(ptr -> rightChild);
    }
}

void postorder(treePointer ptr)
{
    if(ptr)
    {
        postorder(ptr -> leftChild);
        postorder(ptr -> rightChild);
        printf("%c", ptr -> data);
    }
}

void levelOrder(treePointer ptr)
{
    if(!ptr) return;
    addq(ptr);
    for(;;)
    {
        ptr = deleteq();
        if(ptr)
        {
            printf("%c", ptr -> data);
            if(ptr -> leftChild)
                addq(ptr -> leftChild);
            if(ptr -> rightChild)
                addq(ptr -> rightChild);
        }
        else break;
    }
}

void iterInorder(treePointer node)
{
    for(;;)
    {
        for(; node; node = node -> leftChild)
            push(node);
        node = pop();
        if(!node)
            break;
        printf("%c", node -> data);
        node = node -> rightChild;
    }
}

void iterPreorder(treePointer ptr)
{
    for( ; ; )
    {
        for(; ptr; ptr = ptr -> leftChild)
        {
            printf("%c", ptr -> data);
            push(ptr);
        }
        ptr = pop();

        if ( !ptr ) break;
        ptr = ptr -> rightChild;
    }
}

void iterPostorder(treePointer ptr)
{
    treePointer temp = NULL;

    for(;;)
    {
        while(ptr)
        {
            if(ptr -> rightChild)
            {
                push(ptr -> rightChild);
            }
            push(ptr);
            ptr = ptr -> leftChild;
        }

        ptr = pop();
        temp = NULL;
        temp = pop();
        push(temp);

        if(ptr -> rightChild && temp == ptr -> rightChild)
        {
            temp = pop();
            push(ptr);
            ptr = ptr -> rightChild;
        }
        else
        {
            printf("%c", ptr -> data);
            ptr = NULL;
        }

        temp = pop();
        push(temp);
        if(!temp) break;
    }
}


void push(treePointer item)
{
    stackPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp -> data = item;
    temp -> link = top;
    top = temp;
}

treePointer pop()
{
    stackPointer temp = top;
    treePointer item;
    if(!temp)
    {
        return NULL;
    }
    item = temp -> data;
    top = top -> link;
    return item;
}

void addq(treePointer item)
{
    queuePointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data=item;
    temp->link=NULL;
    if(front)
    rear->link = temp;
    else
    front = temp;
    rear=temp;
}

treePointer deleteq()
{
    queuePointer temp = front;
    treePointer item;
    if(!temp)
    {
        return NULL;
    }
    item = temp -> data;
    front = front->link;
    return item;
}