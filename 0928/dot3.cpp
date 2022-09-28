#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void draw_circle(int x, int y, int c, int r);
void draw_horizontal_slide(int x, int y, int slideX, int length, char* s);
void draw_vertical_slide(int x, int y, int length, char* s);
void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b);
void gotoxy(int x, int y);
void draw_rectangle_for_h(int x, int y, int c, int r);
void draw_horizontal_slide(int x, int y, int slideX, int length, char* s);
void draw_rectangle_for_v(int c, int r);
//void draw_rectangle_main(int c, int r);
void draw_rectangle_main(int x, int y, int c, int r);

int main(void)
{
	char* slide = "■", key;
	int x = 1, y = 1;
	int h_slide_length, v_slide_length;
	printf("슬라이드바 표시\n\n");
	printf("수평 슬라이드바의 길이(최대 70)를\n");
	printf("입력하고 Enter>");
	scanf("%d", &h_slide_length);
	//h_slide_length = 20;
	printf("수직 슬라이드바의 길이(최대 19)를\n");
	printf("입력하고 Enter>");
	scanf("%d", &v_slide_length);
	//v_slide_length = 19;
	system("cls");

	y = v_slide_length;
	do
	{
		draw_vertical_slide(1, y, v_slide_length, slide);
		draw_horizontal_slide(7, v_slide_length + 3, x, h_slide_length, slide);
		draw_rectangle_main(7, 1, h_slide_length/2 + 1, v_slide_length);
		//draw_circle(x, y, h_slide_length / 2 + 1, v_slide_length);
		draw_circle(8, v_slide_length + 1, x, y);
		key = getch();
		move_arrow_key(key, &x, &y, h_slide_length / 2 + 1, v_slide_length);

	} while (key != 27);

	return 0;
}


void draw_rectangle_main(int x, int y, int c, int r)
{
	int i, j;
	int count = 2;
	unsigned char a = 0xa6;
	unsigned char b[7];

	gotoxy(x, y);
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]);
	for (i = 0; i < c * 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	//for (i = 0; i < r + 2; i++)
	for (i = 0; i < r ; i++) {
		//gotoxy(8, count++);
		gotoxy(x, y + i + 1);
		printf("%c%c", a, b[2]);
		for (j = 0; j < c*2; j++)
			printf(" ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	gotoxy(x, y + r + 1);
	printf("%c%c", a, b[6]);
	for (i = 0; i < c * 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");

}

void draw_horizontal_slide(int x, int y, int slideX, int length, char* s)
{
	int real_length = length / 2;
	gotoxy(1, y);
	draw_rectangle_for_h(x, y, real_length + 1, 1);
	gotoxy(x + slideX*2, y + 1);
	printf("%s", s);
	//gotoxy(real_length * 2 + 2, y - 1);
	//printf("%2d", x);
}

void draw_vertical_slide(int x, int y, int length, char* s)
{
	gotoxy(x, 1);
	draw_rectangle_for_v(1, length);
	gotoxy(x + 2, y + 1);
	printf("%s", s);
	//gotoxy(x + 6, length + 1);
	//printf("%2d", y);
}

void draw_rectangle_for_v(int c, int r)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]);
	for (i = 0; i < c + 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	for (i = 0; i < r; i++)
	{
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("   ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}
	printf("%c%c", a, b[6]);
	for (i = 0; i < c + 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}

//void draw_rectangle_for_h(int c, int r)
void draw_rectangle_for_h(int x, int y, int c, int r)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	gotoxy(x, y);
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]);
	for (i = 0; i < c * 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	for (i = 0; i < r; i++)
	{
		gotoxy(x, y+i+1);
		printf("%c%c", a, b[2]);
		for (j = 0; j < c * 2; j++)
			printf(" ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	gotoxy(x, y + r+1);
	printf("%c%c", a, b[6]);
	for (i = 0; i < c * 2; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}

void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b)
{
	switch (key)
	{
	case 72:
		*y1 = *y1 - 1;
		if (*y1 < 1)
			*y1 = 1;
		break;
	case 75:
		*x1 = *x1 - 1;
		if (*x1 < 1)
			*x1 = 1;
		break;
	case 77:
		*x1 = *x1 + 1;
		if (*x1 > x_b)
			*x1 = x_b;
		break;
	case 80:
		*y1 = *y1 + 1;
		if (*y1 > y_b)
			*y1 = y_b;
		break;
	default:
		return;
	}
}

void draw_circle(int x, int y, int c, int r)
{
	//for (int i = x + 9; i <= 10; i -= 2)
	for (int i = 0 ; i < c*2; i += 2)
	{
		//for (int j = y + 1; j <= 2; j--)
		for (int j = 0 ; j < y - r; j++)
		{
			gotoxy(x + i, y - j);
			printf("○");
		}
	}
	gotoxy(1, 20);
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
