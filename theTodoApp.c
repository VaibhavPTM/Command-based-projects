#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<unistd.h>

int tlength=0;
FILE *fp;  //fp = File open

struct Todo
{
    char title[50];
    char createdAt[50];
   _Bool isComp;
}todos[20];


void AddTodos()
{
    //for ToDo title.
    char userinput[50];
    printf("Type your todo.\n>>");
    scanf("%[^\n]s",userinput);
    strncpy(todos[tlength].title,userinput,50);

    // Add time
    char Todotime[50];
    struct tm* cTime;
    time_t timeS = time(NULL);
    cTime = localtime(&timeS);    
    strftime(Todotime,50,"%Y-%m-%d %H:%M",cTime);
    strcpy(todos[tlength].createdAt,Todotime);

    //set boolan to false
    todos[tlength].isComp=false;
    tlength++;
}

void printTodo(){
    printf("+------+-------------------------------------------------------------------+--------------------+---------------+\n");
    printf("|  id  |\t\t             ToDo Title\t\t                   |     Created At     |   Completed   |\n");
    printf("+------+-------------------------------------------------------------------+--------------------+---------------+\n");
   
    for (int i = 0; i < tlength; i++)
    {
        printf("|%3d   | %-66s|  %10s  | %8s      |\n",i+1,todos[i].title,todos[i].createdAt,(!todos[i].isComp)? "No" : "Yes");
        printf("+------+-------------------------------------------------------------------+--------------------+---------------+\n");
    }
}

void saveToFile()
{
    fp = fopen("todos.bin","w");
    if (!fp)
    {
        printf("We can't save your todo./n");
    }
    else
    {
        for (size_t i = 0; i < tlength; i++)
        {
            fwrite(&todos[i],sizeof(struct Todo),1,fp);
        }
        fclose(fp);
    }
}

void getFileSize()
{
    fseek(fp,0L,SEEK_END);
    unsigned int long size = ftell(fp);
    fseek(fp,0L,SEEK_SET);
    tlength = size/sizeof(struct Todo);
}

void readFromFile()
{
    fp = fopen("todos.bin","r");
    if (!fp)
    {
        printf("We are not able to find any todos file.\n");
    }
    else
    {
        getFileSize();
        for (size_t i = 0; i < tlength; i++)
        {
            fread(&todos[i],sizeof(struct Todo),1,fp);
        }
        fclose(fp);
    }
}

void markAsComplet()
{
    int todoId;
    printf("Enter the id of todo.\n>>");
    scanf("%d",&todoId);
    todoId--;
    if (todoId < 0 || todoId > tlength)
    {
        printf("Invalid Todo ID.\n");
    }
    else
    {
        todos[todoId].isComp = true;
        printf("Your Todo marked as completed.\n");
    }
}

void deletTodo()
{
     int todoId;
    printf("Enter the ID of todo.\n>>");
    scanf("%d",&todoId);
    if (todoId < 0 || todoId > tlength)
    {
        printf("Invalid Todo ID.\n");
    }
    else
    {
        todoId--;
        memmove(todos+todoId,todos + todoId + 1,(tlength - todoId -1)*sizeof(*todos));
        tlength--;
        printf("Your Todo is deleted.\n");
    }
}

void showOptions()
{
    char userChois;
    printf("Enter 'A' for add todo,'D' for delet todo,'C' for mark as complte and 'Q' to quit the app.\n>>");
    userChois = getchar();
    userChois = toupper(userChois);
    getchar(); 
    switch (userChois)
    {
    case 'A':
        AddTodos();
        break;
    case 'D':
        deletTodo();
        break;
    case 'C':
        markAsComplet();
        break;
    case 'Q':
        exit(0);
    default:
        printf("Enter the correct command.\n");
        showOptions();
        break;
    }
    saveToFile();
    system("CLS");
    printTodo();
    getchar();
    showOptions();
}

void isThisFirstTime()
{
    if(access("todos.bin", F_OK) != -1)
    {
        readFromFile();
        system("CLS");
        printTodo();
        showOptions();
    }
    else
    {
        printf("Welcome to the great todo app.\n");
        AddTodos();
        saveToFile();
        system("CLS");
        printTodo();
        showOptions();
    }
    
    
}

int main()
{
    system("CLS");
    printf("\033[32;1m");
    isThisFirstTime();
}
