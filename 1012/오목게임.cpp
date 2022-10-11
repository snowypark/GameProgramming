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
	SetConsoleTitle(" >> 오목 게임 !! << ");	
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
	printf("\t\t\t∥ 오목 게임 입니다!! \n\n");
	printf("\t\t\t∥ 돌을 연속해서 5개를 먼저 놓는 사람의 승리입니다! \n\n");
	printf("\t\t\t∥ 키를 입력하시면 게임이 시작됩니다! \n");
	printf("\t\t\t ==========================================\n\n");

	getch();
	
}



void start_music(){
	
	Beep(300,200);//흰
	Beep(800,200);//눈
    Beep(700,200);//사
	Beep(600,200);//이
	Beep(300,400);//로
	Sleep(400);

}
 
 
void ending_music(){
	Beep(800,300);//종
	Beep(800,300);//소
    Beep(800,600);//리
    
    Beep(800,300);//울
	Beep(800,300);//려
    Beep(800,600);//라
  
	Beep(800,300);//종
	Beep(1000,300);//소
    Beep(600,450);//리
	Beep(700,150);//울
    Sleep(100);
    Beep(800,600);//려
    Sleep(600);
}


void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)

{

    switch(key)

    {

    case 72:

        (*y1)--; //위쪽(상) 방향의화살표키입력

        if(*y1<1) *y1=1; //y좌표의최솟값

        break;

    case 75:

        (*x1)-=2; //왼쪽(좌) 방향의화살표키입력

        if(*x1<1) *x1=1; //x좌표의최솟값

        break;

    case 77:

        (*x1)+=2; //오른쪽(우) 방향의화살표키입력

        if(*x1>x_b) *x1=x_b; //x좌표의최댓값

        break;

    case 80:

        (*y1)++; //아래쪽(하) 방향의화살표키입력

        if(*y1>y_b) *y1=y_b; //y좌표의최댓값

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
	printf("┌");
	for (i = 0; i< 17; i++) printf("-┬");
	printf("-┐\n");

	for (i = 0; i < 17; i++) {
		printf("├");
		for (j = 0; j < 17; j++)
			printf("-┼");
		printf("-┤\n");
	}
	printf("└");
	for (i = 0; i < 17; i++)printf("-┴");
	printf("-┘");
	
   

}

//바둑판위에놓은돌을흑돌과백돌로구분하여출력하는함수

void display_stone(int matrix[][20][20])

{

    int i, x, y;

    char *stone[2]={"○", "●"};

 

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

//번갈아가며 흑백의 바둑돌을 놓는함수game_control

void game_control(void)

{
	
	system("color f0");
    int x=1, y=1, other=0;
    int matrix[2][20][20]={0};
    char key, judge=0;
    char *stone[2]={"○","●"}; 

    do
    {
        gotoxy(1,1);
        draw_check01(18,18); 

        gotoxy(x,y);

        printf("%s", stone[other]);

        display_stone(matrix);

        gotoxy(1,20);

        if(other)

            printf("\n\n \t\t ●차례입니다. \n\n \t\t 방향키로 움직이고 스페이스키를 눌러주세요!!");
           

        else

            printf("\n\n  \t\t ○차례입니다. \n\n \t\t 방향키로 움직이고 스페이스키를 눌러주세요!!");
                   

        key=_getch();

        if(key==27) //esc 종료

            exit(0);

        else if(key==32) //스페이스라면

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
                printf("\t\t 축하합니다!! \n\n\t\t %s님이 승리하셨습니다~! \n",stone[other]);	
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
    int z, c[4]={0}; //현재점에서방향↓↘→↗바둑돌개수
 
    for(i=0;i<2;i++)
    {
        for(x=0;x<16;x++)
        {
            for(y=0;y<16;y++)
            {
                c[0]=0,c[1]=0,c[2]=0,c[3]=0;
                for(z=0;z<5;z++)
                {
                    if(matrix[i][x][y+z]==1) //↓방향이연속개면
                    {
                        c[0]++;
                        if(c[0]==5)
                            return 1;

                    }

                    if(matrix[i][x+z][y+z]==1) //↘방향이연속개면

                    {

                        c[1]++;

                        if(c[1]==5)

                            return 1;

                    }

                    if(matrix[i][x+z][y]==1) //→방향이연속개면

                    {

                        c[2]++;

                        if(c[2]==5)

                            return 1;

                    }

                    if(matrix[i][x+z][y+4-z]==1) //↗방향이연속개면

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


