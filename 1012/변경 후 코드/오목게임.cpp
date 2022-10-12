#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

 

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);
void draw_check01(int c, int r);
void game_control(void );
void display_stone(int matrix[][20][20]);
int judgement(int matrix[][20][20]); 
void intro();
void start_music();
void ending_music();
void clearlogo();


int main(void )

{
	
      
	intro();
	system("cls");	
    game_control();      
    
    
    return 0;

}


void intro(){
	
	start_music();  
	SetConsoleTitle(" >> ���� ���� !! << ");	
	system("mode con:cols=100 lines=40");
	printf("\n\n\n\n\n");
			
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("       ######      ###    ##     ## ########     ######  ########    ###    ########  ########    \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("      ##    ##    ## ##   ###   ### ##          ##    ##    ##      ## ##   ##     ##    ##       \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("      ##         ##   ##  #### #### ##          ##          ##     ##   ##  ##     ##    ##       \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("      ##   #### ##     ## ## ### ## ######       ######     ##    ##     ## ########     ##       \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("      ##    ##  ######### ##     ## ##                ##    ##    ######### ##   ##      ##       \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("      ##    ##  ##     ## ##     ## ##          ##    ##    ##    ##     ## ##    ##     ##       \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	printf("       ######   ##     ## ##     ## ########     ######     ##    ##     ## ##     ##    ##       \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	printf("\n\n\n");
		
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("\t\t\t ==========================================\n");
	printf("\t\t\t�� ���� ���� �Դϴ�!! \n\n");
	printf("\t\t\t�� ���� �����ؼ� 5���� ���� ���� ����� �¸��Դϴ�! \n\n");
	printf("\t\t\t�� Ű�� �Է��Ͻø� ������ ���۵˴ϴ�! \n");
	printf("\t\t\t ==========================================\n\n");

	getch();
	
}



void start_music(){
	
	Beep(300,200);//��
	Beep(800,200);//��
    Beep(700,200);//��
	Beep(600,200);//��
	Beep(300,400);//��
	Sleep(400);

}
 
 
void ending_music(){
	Beep(800,300);//��
	Beep(800,300);//��
    Beep(800,600);//��
    
    Beep(800,300);//��
	Beep(800,300);//��
    Beep(800,600);//��
  
	Beep(800,300);//��
	Beep(1000,300);//��
    Beep(600,450);//��
	Beep(700,150);//��
    Sleep(100);
    Beep(800,600);//��
    Sleep(600);
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

        (*x1)-=2; //����(��) ������ȭ��ǥŰ�Է�

        if(*x1<1) *x1=1; //x��ǥ���ּڰ�

        break;

    case 77:

        (*x1)+=2; //������(��) ������ȭ��ǥŰ�Է�

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

 

void draw_check01(int c, int r)

{
	int i, j;
	printf("��");
	for (i = 0; i< 17; i++) printf("-��");
	printf("-��\n");

	for (i = 0; i < 17; i++) {
		printf("��");
		for (j = 0; j < 17; j++)
			printf("-��");
		printf("-��\n");
	}
	printf("��");
	for (i = 0; i < 17; i++)printf("-��");
	printf("-��");
	
   

}

//�ٵ����������������浹���鵹�α����Ͽ�����ϴ��Լ�

void display_stone(int matrix[][20][20])

{

    int i, x, y;

    char *stone[2]={"��", "��"};

 

    for(i=0;i<2;i++)

        for(x=1;x<20;x++)

            for(y=1;y<20;y++)

            {

                if(matrix[i][x][y]==1)

                {

                    gotoxy(x*2-1, y);

                    printf("%s", stone[i]);

                }

            }

}

//�����ư��� ����� �ٵϵ��� �����Լ�game_control

void game_control(void)

{
	
	system("color f0");
    int x=1, y=1, other=0;
    int matrix[2][20][20]={0};
    char key, judge=0;
    char *stone[2]={"��","��"}; 

    do
    {
        gotoxy(1,1);
        draw_check01(18,18); 

        gotoxy(x,y);

        printf("%s", stone[other]);

        display_stone(matrix);

        gotoxy(1,20);

        if(other)

            printf("\n\n \t\t �������Դϴ�. \n\n \t\t ����Ű�� �����̰� �����̽�Ű�� �����ּ���!!");
           

        else

            printf("\n\n  \t\t �������Դϴ�. \n\n \t\t ����Ű�� �����̰� �����̽�Ű�� �����ּ���!!");
                   

        key=_getch();

        if(key==27) //esc ����

            exit(0);

        else if(key==32) //�����̽����

        {

            matrix[other][(x+1)/2][y]=1;

            judge=judgement(matrix);

            if(judge!=0)

            {
            	
                system("cls");  
				system("color 0f");    
				          
				clearlogo();
    			
                gotoxy(1,20);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("\t\t ==========================================\n");
                printf("\t\t �����մϴ�!! \n\n\t\t %s���� �¸��ϼ̽��ϴ�~! \n",stone[other]);	
				printf("\t\t ==========================================\n");			
   				ending_music();
                
                exit(0);

            }

            other=1-other;

        }

        else if(key>=72)

            move_arrow_key(key, &x, &y, 37, 19);

    }while(1);

}

 

int judgement(int matrix[][20][20])

{
    int i, x, y;
    int z, c[4]={0}; //���������������١�ֹٵϵ�����
 
    for(i=0;i<2;i++)
    {
        for(x=0;x<16;x++)
        {
            for(y=0;y<16;y++)
            {
                c[0]=0,c[1]=0,c[2]=0,c[3]=0;
                for(z=0;z<5;z++)
                {
                    if(matrix[i][x][y+z]==1) //������̿��Ӱ���
                    {
                        c[0]++;
                        if(c[0]==5)
                            return 1;

                    }

                    if(matrix[i][x+z][y+z]==1) //�ٹ����̿��Ӱ���

                    {

                        c[1]++;

                        if(c[1]==5)

                            return 1;

                    }

                    if(matrix[i][x+z][y]==1) //������̿��Ӱ���

                    {

                        c[2]++;

                        if(c[2]==5)

                            return 1;

                    }

                    if(matrix[i][x+z][y+4-z]==1) //�ֹ����̿��Ӱ���

                    {

                        c[3]++;

                        if(c[3]==5)

                            return 1;

                    }

                }

            }

        }

    }

    return 0;

}

void clearlogo() {
	
    system("color 0");  
	printf("\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\t\t #####   ##       #######    ###    ######   \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("\t\t##   ##  ##       ##        ## ##   ##   ##  \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("\t\t##       ##       ##       ##   ##  ##   ##  \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\t\t##       ##       #####    #######  ######   \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\t\t##       ##       ##       ##   ##  ## ##    \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("\t\t##   ##  ##       ##       ##   ##  ##  ##   \n");	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("\t\t #####   #######  #######  ##   ##  ##   ##  \n");
	             
	             
}


