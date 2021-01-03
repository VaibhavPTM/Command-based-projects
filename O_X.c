#include<stdio.h>
#include<conio.h>
char a[9]={'1','2','3','4','5','6','7','8','9'};
int k=0;
int end=1;
void gamename()
{
   printf("\n\n\t\t\ttic tac tie game");
}
void draw()
{
   printf("\n\n\t\t\t---|---|---\n");
   printf("\t\t\t %c | %c | %c\n",a[0],a[1],a[2]);
   printf("\t\t\t---|---|---\n");
   printf("\t\t\t %c | %c | %c\n",a[3],a[4],a[5]);
   printf("\t\t\t---|---|---\n");
   printf("\t\t\t %c | %c | %c\n",a[6],a[7],a[8]);
   printf("\t\t\t---|---|---\n");
}
void getinput()
{
  char pa;
  printf("\n\4enter the position :\n");
  scanf("%c",&pa);
  if(k==0)
  {
    for(int i=0;i<=8;i++)
   {
     if(a[i]==pa)
     {
     a[i]='x';
     k=1;
     break;
     }
   }
  }
  else
  {
    for(int i=0;i<=8;i++)
   {
     if(a[i]==pa)
     {
       a[i]='0';
       k=0;
       break;
     }
   }
  }
}
int gameover()
{
 if((a[0]=='x' &&a[1]=='x' &&a[2]=='x')|| (a[0]=='x' &&a[4]=='x' &&a[8]=='x')||  (a[0]=='x' &&a[3]=='x' &&a[6]=='x') || (a[1]=='x' &&a[4]=='x' &&a[7]=='x')||(a[3]=='x' &&a[4]=='x' &&a[5]=='x')|| (a[2]=='x' &&a[5]=='x' &&a[8]=='x')|| (a[6]=='x' &&a[7]=='x' &&a[8]=='x'))
   return(1);
 else if( (a[0]=='0' &&a[1]=='0' &&a[2]=='0')|| (a[0]=='0' &&a[4]=='0' &&a[8]=='0')||  (a[0]=='0' &&a[3]=='0' &&a[6]=='0') || (a[1]=='0' &&a[4]=='0' &&a[7]=='0')||(a[3]=='0' &&a[4]=='0' &&a[5]=='0')|| (a[2]=='0' &&a[5]=='0' &&a[8]=='0') || (a[6]=='0' && a[7]=='0' && a[8]=='0'))
   return(2);
 else if((a[0]=='x'||a[0]=='0')&&(a[1]=='x'||a[1]=='0')&&(a[2]=='x'||a[2]=='0')&&(a[3]=='x'||a[3]=='0')&&(a[4]=='x'||a[4]=='0')&&(a[5]=='x'||a[5]=='0')&&(a[6]=='x'||a[6]=='0')&&(a[7]=='x'||a[7]=='0')&&(a[8]=='x'||a[8]=='0'))
   return (3);
 else
   return 4;
}
void finel()
{
  int var;
  var=gameover();
  if(var==1)
  {
    printf("\n\4plyer 1 won.");
    end=0;
  }
  else if(var==2)
  {
   printf("\n\4plyer 2 won.");
   end=0;
  }
  else if(var==3)
  {
   printf("\n\4game is draw");
   end=0;
  }
  else;

}
void main()
{
 char c;
 label:
 system("CLS");
 gamename();
 draw();
 while(end)
 {
  getinput();
  system("CLS");
  gamename();
  draw();
  finel();
 }
 printf("\n\4do you want to continue?");
 printf("\n\4if yes press y>> ");
 fflush(stdin);
 scanf("%c",&c);
 if(c=='y' || c=='Y')
 {
 a[0]='1';
 a[1]='2';
 a[2]='3';
 a[3]='4';
 a[4]='5';
 a[5]='6';
 a[6]='7';
 a[7]='8';
 a[8]='9';
 k=0; end=1;
 goto label;
 }
 printf("\n\n*THANK YOU*");

 getch();

} 