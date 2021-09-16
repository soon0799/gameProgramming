#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void draw_horizontal_slide(int x, int y, int length, char *s);
void draw_vertical_slide(int x, int y, int length, char *s);
void draw_rectangle(int c, int r);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);

int main(void)
{
   char *slide="��", key;
   int x=1, y=1;
   int h_slide_length, v_slide_length;
   printf("�����̵�� ǥ��\n\n");
   printf("���� �����̵���� ����(�ִ� 70)�� \n");
   printf("�Է��ϰ� Enter>");
   scanf("%d", &h_slide_length);
   printf("���� �����̵���� ����(�ִ� 19)�� \n");
   printf("�Է��ϰ� Enter>");
   scanf("%d", &v_slide_length);
   system("cls");

   do
   {
    draw_vertical_slide(1, y, v_slide_length, slide);
    draw_horizontal_slide(x,v_slide_length+3,h_slide_length,slide);
    key=getch();
    move_arrow_key(key, &x, &y, h_slide_length, v_slide_length);
   }while(key!=27);
   return 0;
}
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

void draw_horizontal_slide(int x, int y, int length, char *s)
{
	int real_length=length;
	gotoxy(1, y);
	draw_rectangle(real_length+2, 1);
	gotoxy(x+2, y+1);
	printf("%s", s);
	gotoxy(real_length*2+2, y-1);
	printf("%2d", x);
}

void draw_vertical_slide(int x, int y, int length, char *s)
{
	gotoxy(x, 1);
	draw_rectangle(3, length);
	gotoxy(x+2, y+1);
	printf("%s", s);
	gotoxy(x+6, length+1);
	printf("%2d", y);
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y��ǥ�� �ּҰ�
		break;
	case 75:  //����(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1-1;
		if (*x1<1)	*x1=1; //x��ǥ�� �ּҰ�
		break;
	case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1+1;
		if (*x1>x_b)  *x1=x_b; //x��ǥ�� �ִ밪
		break;
	case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y��ǥ�� �ִ밪
		break;
	default:
		return;
	}
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
