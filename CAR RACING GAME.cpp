#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class CAR
{
    int x,y;
public:
    CAR(int a,int b)
    {
        x=a;
        y=b;
    }
    void display()
    {
        gotoxy(x,y);
        cout<<"#";
        gotoxy(0,0);
    }
    void move_left()
    {
        if(x==41)
            return;
        gotoxy(x,y);
        cout<<" ";
        x--;
        display();
    }
    void move_right()
    {
        if(x==43)
            return;
        gotoxy(x,y);
        cout<<" ";
        x++;
        display();
    }
    void move_down()
    {
        gotoxy(x,y);
        cout<<" ";
        if(y==25)
            y=0;
        y++;
        display();
    }
    int operator==(CAR C)
    {
        if(x==C.x &&y==C.y)
            return 1;
        return 0;
    }

};
void draw_roads()
{
    int x,y;
    for(y=0;y<=25;y++)
    {
        gotoxy(40,y);
        cout<<"|";
        gotoxy(44,y);
        cout<<"|";
    }
}
void display_score(int s,int l)
{
    cout<<"\tSCORE:"<<s<<"\tLEVEL:"<<l;
}
int main()
{
    char choice;
    int level=1,score=0;
    draw_roads();
    CAR mycar(42,25),c1(41,0),c2(42,8),c3(43,16);
    mycar.display();
    c1.display();
    c2.display();
    c3.display();

    while(1)
    {

        score++;
        if(score%50==0)
            level++;
        display_score(score,level);
        Sleep(500-level*100);
        c1.move_down();
        c2.move_down();
        c3.move_down();
        if(mycar==c1 ||mycar==c2 ||mycar==c3)
            break;
        choice='p';
        if(kbhit())
            choice=getch();
        switch(choice)
        {
            case'a':mycar.move_left();
            break;
            case'd':mycar.move_right();
            break;
            case'q':return 0;
            break;
        }
    }
    cout<<"\n\n\tGAME OVER!!!";
    cout<<"\n\n\tTRY AGAIN!!!\n";
}
