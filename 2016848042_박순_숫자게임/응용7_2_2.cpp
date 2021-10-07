#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void intro_game(void);
void game_control(void);
int computer_number(int i, int com_array[]);
int user_number(int i, int user_array[]);
void number_display(int i, int com_array[], int user_array[], int sum);
void conclusion(int win);
void gotoxy(int x, int y);
void press_any_key(void);

int main(void)
{
	srand(time(NULL));//랜덤한 난수 값 생성을 위해 
	intro_game();//안내문 출력 
	game_control();
	return 0;
}


void intro_game(void)
{
	system("cls");
	printf("100을 넘어라 게임\n\n");
	printf("컴퓨터와 사용자가 번갈아가며\n");
	printf("숫자를 입력하되 1~10사이의 \n");
	printf("중복되지 않는 숫자를 입력하여 \n\n");
	printf("최초로 100을 넘기면 승자가 됩니다. \n\n");
	printf("컴퓨터가 먼저 시작합니다. \n");
	printf("아무키나 누르면 시작합니다.");
	getch();
}

int computer_number(int i, int com_array[])
{
	int j, number;
	again:;
	number=rand()%10+1;
	for(j=0;j<i;j+=1)
		if (com_array[j]==number)
			goto again;
	com_array[i]=number;
	return com_array[i];
}
// goto 문을 이용한 반복문으로 중복되는 숫자있는지 확인
//  for문을 통해 랜덤한 숫자와 기존 배열의 숫자를 비교후 같은게 있으면 again부터 다시 시작 없다면 랜덤한 숫자를 저장 
// 여기서 받는 파라메터는 지금까지 저장된 숫자의 배열과 저장되있는 숫자의 갯수 

int user_number(int i, int user_array[])
{
	int j, number;
	again:;
	gotoxy(1, 7);
	printf("사용자 숫자 입력후 Enter>");
	scanf("%d", &number);
	for(j=0;j<i;j+=1)
		if (user_array[j]==number)
		{
			gotoxy(1, 8);
			printf("중복된 숫자를 입력했습니다. \n");
			goto again;
		}
	user_array[i]=number;
	return user_array[i];
}
//유저가 숫자를 입력한느 함수 여기도for문으로 배열에 저장되어있는 숫자들과 내가 입력한 숫자를 확인하여 같은 숫자가 있으면 메세지를 출력하고 goto문으로 반복하고 아니라면 배열에 숫자를 저장후에 리턴한다 


void number_display(int i, int com_array[], int user_array[], int sum)
{
	int j;
	gotoxy(1, 2);
	printf("컴퓨터 숫자 : ");
	for(j=0;j<=i;j+=1)
		printf("%2d ", com_array[j]);
	gotoxy(1, 3);
	printf("사용자 숫자 : ");
	for(j=0;j<=i;j+=1)
		if (user_array[j]==0)
			continue;
		else
			printf("%2d ", user_array[j]);
	gotoxy(1, 5);
	printf("현재 합계 : %3d\n", sum);
}
//지금까지의 저장된 숫자들과 합계를 출력하는함수이다 


void conclusion(int check)
{
	if (check==1)
		printf("컴퓨터가 이겼습니다. \n");
	else
		printf("사용자가 이겼습니다. \n");
}



void press_any_key(void)
{
	gotoxy(1, 10);
	printf("아무키나 누르시오..");
	getch();
}
//버퍼를 주는 함 수
 

void game_control(void)
{
	int max=100;
	int com_array[10]={0}, user_array[10]={0}, number;
	int i, sum=0, win; 
	for(i=0;i<10;i+=1)
	{
		system("cls");
		number=computer_number(i, com_array);
		sum+=number;
		number_display(i, com_array, user_array, sum);
		if (max<sum)
		{
			win=1;
			break;
		}
		number=user_number(i, user_array);
		sum+=number;
		number_display(i, com_array, user_array, sum);
		if (max<sum)
		{
			win=2;
			break;
		}
		press_any_key();
	}
	conclusion(win);
}



void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

