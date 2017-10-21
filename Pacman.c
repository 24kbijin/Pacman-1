//Hooman Malekzadeh 9231615
//Pacman
#include <windows.h>
#include <stdio.h>
#include <conio.h>



//For console colours
void *getConsoleFunction(char *name);

BOOL (WINAPI *doSetConsoleTextAttribute)(HANDLE hConsoleOutput, WORD attr);


char *mymap[]={
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
    "@ * * * *  @@@@@@@@@ @@@@@@@@@ * * * *  @",
    "@ @@@@@ @@  * * * * * * * * * * @ @@@@@ @",
    "@*    @ @@ @@@@@@@@@ @@@@@@@@@ @@ @    *@",
    "@ @@@    *    *  *  *  * *     *    @@@ @",
    "@*@@@ @@@@@@@@@@@@@@ @@@@@@@@@@@@@@ @@@*@",
    "@  * *        * * * * * * *         * * @",
    "@  * * @@@@   @@@@@   @@@@@    @@@  * * @",
    "@*@@@ @@@@@@@ @@@@@   @@@@@ @ @@@@@@@@@*@",
    "@*@@@ @@@@@@@               @ @@@@@@@@@*@",
    "@     @  *  * @@@@@ @ @@@@@ *   *  *    @",
    "@*  @*   *  @  @@@@ @ @@@@  @   *  *@  *@",
    "@*@@@@@ @@  * * * *  * * * *   @@ @@@@@*@",
    "@*@@@@@ @@ @@@@@@@@@ @@@@@@@@@ @@ @@@@@*@",
    "@*@@@  ***  @@@@@@  *  @@@@@@  ***  @@@*@",
    "@*@@@ @@@@ @@@@@@@*@*@*@@@@@@@ @@@@ @@@*@",
    "@  *  *  * * * *  * @ *    * * * *   *  @",
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};
int Stars[18][41];//To count the stars and inform the system that the packman ate it
void starcounter()
{
    int i,j,s=0;
    for(i=0; i<18;i++)
    {
        for(j=0;j<41;j++){
        Stars[i][j]=0;
        }
    }
    for(i=0; i<18;i++)
    {
        for(j=0;j<41;j++){
        if(mymap[i][j]=='*')
        Stars[i][j]=1,
        s++;
        }
}
}

int move()
{
         HANDLE hCon;
   hCon=GetStdHandle(STD_OUTPUT_HANDLE);

   doSetConsoleTextAttribute=getConsoleFunction("SetConsoleTextAttribute");

   SetConsoleTitle("Pacman By Hooman Malekzadeh");

    int i,j,c,x,y;
    int sc=0;//star counter. 98 Stars Total
    static gx,gy;//First ghost position
    int g2x,g2y;//Second Ghost Position
    int g3x,g3y;//Third Ghost Position
    int g4x,g4y;//Fourth Ghost Position
    gx= 20;
    gy= 9;
    g2x= 19;
    g2y= 9;
    g3x= 18;
    g3y= 9;
    g4x=21;
    g4y= 9;
    x=y=1;
    gotoxy(x,y);
    putchar('P');
    gotoxy(gx,gy);
    (*doSetConsoleTextAttribute)(hCon,12);
    putchar('G');
    gotoxy(g2x,g2y);
    (*doSetConsoleTextAttribute)(hCon,12);
    putchar('G');
    gotoxy(g3x,g3y);
    (*doSetConsoleTextAttribute)(hCon,12);
    putchar('G');
    gotoxy(g4x,g4y);
    (*doSetConsoleTextAttribute)(hCon,12);
    putchar('G');
    starcounter();
    for(;sc<98;){
        if((gx==x) && (gy==y))//Ghost 1 Catches Pacman
        {
            return -1;
        }
        if((g2x==x) && (g2y==y)) //Ghost 2 catches pacman
        {
            return -1;
        }
        if((g3x==x) && (g3y==y)) //Ghost 3 catches pacman
        {
            return -1;
        }
        if((g4x==x) && (g4y==y)) //Ghost 4 catches pacman
        {
            return -1;
        }
        else{
        c=getch();
        if(c=='j'){
            //Ghost 1 Moves Left
            if(mymap[gy][gx-1]!='@'){
            if(mymap[gy][gx]!='*')
            {
            gotoxy(gx,gy);
            putchar(' ');
            }
            gotoxy(--gx,gy);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[gy][gx]=='*'){
                if(Stars[gy][gx]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(gx,gy);
            putchar('*');
                }
                if(Stars[gy][gx]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(gx,gy);
            putchar(' ');
                }
           }

        }
        //Ghost 3 moves Right
        if(mymap[g3y][g3x+1]!='@'){
            if(mymap[g3y][g3x]!='*')
            {
            gotoxy(g3x,g3y);
            putchar(' ');
            }
            gotoxy(++g3x,g3y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g3y][g3x]=='*'){
                if(Stars[g3y][g3x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g3x,g3y);
            putchar('*');
                }
                if(Stars[g3y][g3x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g3x,g3y);
            putchar(' ');
                }
           }
        }
        }
        if(c=='a'){
            //Pacman Moves Left
            if(mymap[y][x-1]=='*' && (Stars[y][x-1]==1))
            sc++,
            Stars[y][x-1]=0;
            if(mymap[y][x-1]!='@')
            gotoxy(x,y),
            putchar(' '),
            gotoxy(--x,y),
            (*doSetConsoleTextAttribute)(hCon,14),
            putchar('P'),
            Sleep(50);
            //Ghost 2 Moves Right
            if(mymap[g2y][g2x+1]!='@'){
            if(mymap[g2y][g2x]!='*')
            {
            gotoxy(g2x,g2y);
            putchar(' ');
            }
            gotoxy(++g2x,g2y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g2y][g2x]=='*'){
                if(Stars[g2y][g2x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g2x,g2y);
            putchar('*');
                }
                if(Stars[g2y][g2x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g2x,g2y);
            putchar(' ');
                }
           }
        }
        //Ghost 4 Moves Left
            if(mymap[g4y][g4x-1]!='@'){
            if(mymap[g4y][g4x]!='*')
            {
            gotoxy(g4x,g4y);
            putchar(' ');
            }
            gotoxy(--g4x,g4y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g4y][g4x]=='*'){
                if(Stars[g4y][g4x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g4x,g4y);
            putchar('*');
                }
                if(Stars[g4y][g4x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g4x,g4y);
            putchar(' ');
                }
           }

        }
            }
        if(c=='i'){
            //Ghost 1 Moves Up
          if(mymap[gy-1][gx]!='@'){
            if(mymap[gy][gx]!='*')
            {
            gotoxy(gx,gy);
            putchar(' ');
            }
            gotoxy(gx,--gy);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[gy][gx]=='*'){
                if(Stars[gy][gx]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(gx,gy);
            putchar('*');
                }
                if(Stars[gy][gx]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(gx,gy);
            putchar(' ');
                }
           }
        }
        //Ghost 3 Moves Down
            if(mymap[g3y+1][g3x]!='@'){
            if(mymap[g3y][g3x]!='*')
            {
            gotoxy(g3x,g3y);
            putchar(' ');
            }
            gotoxy(g3x,++g3y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g3y][g3x]=='*'){
                if(Stars[g3y][g3x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g3x,g3y);
            putchar('*');
                }
                if(Stars[g3y][g3x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g3x,g3y);
            putchar(' ');
                }
           }
        }
        }
        if(c=='w'){
          //Pacman Moves Up
            if(mymap[y-1][x]=='*' && Stars[y-1][x]==1)
            sc++,
            Stars[y-1][x]=0;
            if(mymap[y-1][x]!='@')
            gotoxy(x,y),
            putchar(' '),
            gotoxy(x,--y),
            (*doSetConsoleTextAttribute)(hCon,14),
            putchar('P'),
            Sleep(50);
            //Ghost 2 Moves Down
            if(mymap[g2y+1][g2x]!='@'){
            if(mymap[g2y][g2x]!='*')
            {
            gotoxy(g2x,g2y);
            putchar(' ');
            }gotoxy(g2x,++g2y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g2y][g2x]=='*'){
                if(Stars[g2y][g2x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g2x,g2y);
            putchar('*');
                }
                if(Stars[g2y][g2x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g2x,g2y);
            putchar(' ');
                }
           }
            }
            //Ghost 4 Moves Up
          if(mymap[g4y-1][g4x]!='@'){
            if(mymap[g4y][g4x]!='*')
            {
            gotoxy(g4x,g4y);
            putchar(' ');
            }
            gotoxy(g4x,--g4y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g4y][g4x]=='*'){
                if(Stars[g4y][g4x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g4x,g4y);
            putchar('*');
                }
                if(Stars[g4y][g4x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g4x,g4y);
            putchar(' ');
                }
           }
        }
            }
        if(c=='l'){
            //Ghost 1 Moves Right
        if(mymap[gy][gx+1]!='@'){
            if(mymap[gy][gx]!='*')
            {
            gotoxy(gx,gy);
            putchar(' ');
            }
            gotoxy(++gx,gy);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[gy][gx]=='*'){
                if(Stars[gy][gx]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(gx,gy);
            putchar('*');
                }
                if(Stars[gy][gx]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(gx,gy);
            putchar(' ');
                }
           }
        }
        //Ghost 3 moves left
        if(mymap[g3y][g3x-1]!='@'){
            if(mymap[g3y][g3x]!='*')
            {
            gotoxy(g3x,g3y);
            putchar(' ');
            }
            gotoxy(--g3x,g3y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g3y][g3x]=='*'){
                if(Stars[g3y][g3x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g3x,g3y);
            putchar('*');
                }
                if(Stars[g3y][g3x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g3x,g3y);
            putchar(' ');
                }
           }

        }
        }
        if(c=='d'){
       //Pacman Moves Right
        if(mymap[y][x+1]=='*' && (Stars[y][x+1]==1))
            sc++,
            Stars[y][x+1]=0;
            if(mymap[y][x+1]!='@')
              gotoxy(x,y),
            putchar(' '),
            gotoxy(++x,y),
            (*doSetConsoleTextAttribute)(hCon,14),
            putchar('P'),
            Sleep(50);
          //Ghost 2 Moves Left
            if(mymap[g2y][g2x-1]!='@'){
            if(mymap[g2y][g2x]!='*')
            {
            gotoxy(g2x,g2y);
            putchar(' ');
            }
            gotoxy(--g2x,g2y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g2y][g2x]=='*'){
                if(Stars[g2y][g2x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g2x,g2y);
            putchar('*');
                }
                if(Stars[g2y][g2x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g2x,g2y);
            putchar(' ');
                }
           }
        }
            //Ghost 4 Moves Right
        if(mymap[g4y][g4x+1]!='@'){
            if(mymap[g4y][g4x]!='*')
            {
            gotoxy(g4x,g4y);
            putchar(' ');
            }
            gotoxy(++g4x,g4y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g4y][g4x]=='*'){
                if(Stars[g4y][g4x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g4x,g4y);
            putchar('*');
                }
                if(Stars[g4y][g4x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g4x,g4y);
            putchar(' ');
                }
           }
        }
        }
        if(c=='k'){
            //Ghost 1 Moves Down
            if(mymap[gy+1][gx]!='@'){
            if(mymap[gy][gx]!='*')
            {
            gotoxy(gx,gy);
            putchar(' ');
            }
            gotoxy(gx,++gy);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[gy][gx]=='*'){
                if(Stars[gy][gx]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(gx,gy);
            putchar('*');
                }
                if(Stars[gy][gx]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(gx,gy);
            putchar(' ');
                }
           }
            }
            //Ghost 3 Moves Up
             if(mymap[g3y-1][g3x]!='@'){
            if(mymap[g3y][g3x]!='*')
            {
            gotoxy(g3x,g3y);
            putchar(' ');
            }
            gotoxy(g3x,--g3y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g3y][g3x]=='*'){
                if(Stars[g3y][g3x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g3x,g3y);
            putchar('*');
                }
                if(Stars[g3y][g3x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g3x,g3y);
            putchar(' ');
                }
           }
        }

        }
        if(c=='s'){
          //Pacman Moves Down
             if(mymap[y+1][x]=='*' && Stars[y+1][x]==1)
            sc++,
            Stars[y+1][x]=0;
            if(mymap[y+1][x]!='@')
            gotoxy(x,y),
            putchar(' '),
            gotoxy(x,++y),
            (*doSetConsoleTextAttribute)(hCon,14),
            putchar('P'),
            Sleep(50);
            //Ghost 2 Moves Up
            if(mymap[g2y-1][g2x]!='@'){
            if(mymap[g2y][g2x]!='*')
            {
            gotoxy(g2x,g2y);
            putchar(' ');
            }
            gotoxy(g2x,--g2y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g2y][g2x]=='*'){
                if(Stars[g2y][g2x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g2x,g2y);
            putchar('*');
                }
                if(Stars[g2y][g2x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g2x,g2y);
            putchar(' ');
                }
           }
        }
        //Ghost 4 Moves Down
            if(mymap[g4y+1][g4x]!='@'){
            if(mymap[g4y][g4x]!='*')
            {
            gotoxy(g4x,g4y);
            putchar(' ');
            }
            gotoxy(g4x,++g4y);
            (*doSetConsoleTextAttribute)(hCon,12);
            putchar('G');
            Sleep(50);
            if( mymap[g4y][g4x]=='*'){
                if(Stars[g4y][g4x]==1){
            (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g4x,g4y);
            putchar('*');
                }
                if(Stars[g4y][g4x]==0){
                    (*doSetConsoleTextAttribute)(hCon,14);
            gotoxy(g4x,g4y);
            putchar(' ');
                }
           }
            }
            }


        }
}
return 1;
}
void Print_map()
{
    HANDLE hCon;
   int i,j;

   hCon=GetStdHandle(STD_OUTPUT_HANDLE);
   doSetConsoleTextAttribute=getConsoleFunction("SetConsoleTextAttribute");

    for(i=0;i<18;i++){
        for(j=0; j<41;j++){
            if(mymap[i][j]=='@')
        (*doSetConsoleTextAttribute)(hCon,4),
             putchar(219);
             if(mymap[i][j]=='*')
         (*doSetConsoleTextAttribute)(hCon,14),
             putchar('*');
             if(mymap[i][j]==' ')
            (*doSetConsoleTextAttribute)(hCon,13),
             putchar(mymap[i][j]);             }
     putchar('\n');
    }
}
int main() {

   HANDLE hCon;
   int i,j;
   int w;

   hCon=GetStdHandle(STD_OUTPUT_HANDLE);
   doSetConsoleTextAttribute=getConsoleFunction("SetConsoleTextAttribute");
    Print_map();
    (*doSetConsoleTextAttribute)(hCon,10),
    printf("Welcome To Pacman!!\nMade By Hooman Malekzadeh\n");
    (*doSetConsoleTextAttribute)(hCon,13),
    printf("Ghost movements: j=left\tk=down\tl=right\ti=up\t\n");
    (*doSetConsoleTextAttribute)(hCon,14),
    printf("Pacman movements: a=left s=down  d=right  w=up");
   w = move();
   system("cls");
   if(w == -1){
       (*doSetConsoleTextAttribute)(hCon,12),
   printf("You Lost!!");
   }
   else{
 (*doSetConsoleTextAttribute)(hCon,15);
   printf("You Won!!");
   }
   int c;
   printf("\nPress e to end the game");
   for(;;){
   c=getch();
   if(c =='e')
   break;
   }
}

void *getConsoleFunction(char *name) {//colour function
   static HMODULE kernel32=(HMODULE)0xffffffff;
   if(kernel32==0)
      return NULL;
   if(kernel32==(HMODULE)0xffffffff) {
      kernel32=LoadLibrary("kernel32.dll");
      if(kernel32==0)
         return 0;
   }
   return GetProcAddress(kernel32,name);
}

void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ;
}
