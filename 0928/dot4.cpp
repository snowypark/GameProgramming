#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

 

void draw_horizontal_slide(int x, int y, int length, char *s);
void draw_vertical_slide(int x, int y, int length, char *s);
void draw_rectangle(int c, int r);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);

 
int main(void )

{

    char *slide="��", key;

    int x=1, y=1;

    int h_slide_length, v_slide_length;

 

    printf("�����̵��ǥ��\n\n");

    printf("���򽽶��̵���Ǳ���(�ִ�)��\n");

    printf("�Է��ϰ�Enter>");
    scanf("%d", &h_slide_length);

    printf("���������̵���Ǳ���(�ִ�)��\n");

    printf("�Է��ϰ�Enter>");
   	scanf("%d", &h_slide_length);

    system("cls");

 

    do

    {

        draw_vertical_slide(1, y, v_slide_length, slide);

        draw_horizontal_slide(x, v_slide_length+3, h_slide_length, slide);

        key=_getch();

        move_arrow_key(key, &x, &y, h_slide_length, v_slide_length);

    }while(key!=27);

    return 0;

}

//���򽽶��̵�ٸ�ǥ���ϴ��Լ�draw_horizontal_slide

void draw_horizontal_slide(int x, int y, int length, char *s)

{

    int real_length=length/2; 

    gotoxy(1,y);

    draw_rectangle(real_length+1, 1);

    gotoxy(x+2, y+1);

    printf("%s", s);

    gotoxy(real_length*2+2, y-1);

    printf("%2d", x);

}

//���������̵�ٸ�ǥ���ϴ��Լ�draw_vertical_slide

void draw_vertical_slide(int x, int y, int length, char *s)

{

    gotoxy(x, 1);

    draw_rectangle(1, length);

    gotoxy(x+2, y+1);

    printf("%s", s);

    gotoxy(x+6, length+1);

    printf("%2d", y);

}

//�簢���׸���

void draw_rectangle(int c, int r)

{

    int i, j;

    unsigned char a=0xa6, b[7];

 

    for(i=1;i<7;i++)

        b[i]=0xa0+i;

    printf("%c%c", a, b[3]);

    for(i=0;i<c;i++)

        printf("%c%c", a, b[1]);

 

    printf("%c%c", a, b[4]);

    printf("\n");

    for(i=0;i<r;i++)

    {

        printf("%c%c", a, b[2]);

        for(j=0;j<c;j++)

            printf(" ");

        printf("%c%c", a, b[2]);

        printf("\n");

    }

    printf("%c%c", a, b[6]);

    for(i=0;i<c;i++)

        printf("%c%c", a, b[1]);

    printf("%c%c", a, b[5]);

    printf("\n");

}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)

{

    switch(key)

    {

    case 72:

        (*y1)--; //����(��) ������ȭ��ǥŰ�Է�

        if(*y1<1) *y1=1; //y��ǥ���ּڰ�

        break;

    case 75:

        (*x1)--; //����(��) ������ȭ��ǥŰ�Է�

        if(*x1<1) *x1=1; //x��ǥ���ּڰ�

        break;

    case 77:

        (*x1)++; //������(��) ������ȭ��ǥŰ�Է�

        if(*x1>x_b) *x1=x_b; //x��ǥ���ִ�

        break;

    case 80:

        (*y1)++; //�Ʒ���(��) ������ȭ��ǥŰ�Է�

        if(*y1>y_b) *y1=y_b; //y��ǥ���ִ�

        break;

    default:

        return ;

    }

}

 

void gotoxy(int x, int y)

{

    COORD Pos = { x-1, y-1 };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
