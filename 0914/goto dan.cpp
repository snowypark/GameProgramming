#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void)
{	
	
	for(int dan=1;dan<=9;dan++){
		for(int i=1;i<=9;i++){
			gotoxy(10*dan,i+3);
			printf("%d*%d=%2d",dan,i,dan*i);
		}
	}
	
	
	
	printf("\n");
	return 0;

}


void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
