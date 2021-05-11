
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define choice 1
int p1;
int p2;
int key;
int wipe[33];
int center;
int control();
int menu();
void init();
void check_key();
void check_win();
void countdown();
void wipeset(int num);
void wipeoutput(int f);
void gotoxy(int x, int y);
void title();
void logo();
void setting();
void play();
void htp();

int main()
{
	init();
	title();
	while (1)
	{
		int code = menu();
		if (code == 0)
		{
			setting();
		}
		else if (code == 1)
		{
			htp();
		}
		else if (code == 2)
		{
			exit(0);
		}
		system("cls");
	}
	return 0;
}

void countdown()
{
	int count;
	for (count = 3; count >= 1; count--)
	{
		gotoxy(58, 14); printf("%d", count); Sleep(1000); system("cls");
	}
	gotoxy(56, 14); printf("START"); Sleep(1000); system("cls");
}

void wipeoutput(int f)
{
	if (wipe[f] == 0)
	{
		printf("ㆍ");
	}
	else if (wipe[f] == 1)
	{
		center = f;
		printf("⊙");
	}
	else if (wipe[f] == 2)
	{
		printf("∽");
	}
	else if (wipe[f] == 3)
	{
		printf("◎");
	}
	else if (wipe[f] == 4)
	{
		printf("§");
	}
}

void wipeset(int num)
{
	int t, q;
	if (num == 2)
	{
		for (t = 0; t <= 33; t++)
		{
			wipe[t] = 0;
			for (q = 1; q <= 5; q++)
			{
				if (t == (16 - q))
					wipe[t] = 2;
				else if (t == (16 + q))
					wipe[t] = 2;
			}
		}
		num = 1;
	}
	if (num == 1)
	{
		wipe[16] = 1;
		wipe[0] = wipe[32] = 4;
		wipe[10] = wipe[22] = 3;
		num = 0;
	}
}

void check_key()
{
	int k;
	if (_kbhit())
	{
		printf("\n\n");
		k = _getch();
		if (k == p1)
		{
			wipe[center] = 2;
			wipe[center - 1] = 1;
			wipe[center - 6] = 2;
			wipe[center + 5] = 3;
			wipe[center - 7] = 3;
			wipe[center + 6] = 0;
		}
		else if (k == p2)
		{
			wipe[center] = 2;
			wipe[center + 1] = 1;
			wipe[center + 6] = 2;
			wipe[center - 5] = 3;
			wipe[center + 7] = 3;
			wipe[center - 6] = 0;
		}
	}
}

void check_win()
{
	int x = 54, y = 12;
	if (wipe[0] == 3)
	{
		system("cls");

		gotoxy(x, y); printf("┏━━━━━━━━━┓");
		gotoxy(x, y+1); printf("┃ 1P 승리 ┃");
		gotoxy(x, y+2); printf("┗━━━━━━━━━┛");

		Sleep(3000);

		system("cls");

		main();
	}
	else if (wipe[32] == 3)
	{
		system("cls");

		gotoxy(x, y); printf("┏━━━━━━━━━┓");
		gotoxy(x, y+1); printf("┃ 2P 승리 ┃");
		gotoxy(x, y+2); printf("┗━━━━━━━━━┛");

		Sleep(3000);

		system("cls");

		main();
		;
	}
}

int control()
{
	int button = _getch();
	if (button == 72) {
		return UP;
	}
	else if (button == 80) {
		return DOWN;
	}
	else if (button == ' ') {
		return choice;
	}
	else
		return 0;
}


void init()
{
	system("title 줄다리기");

	CONSOLE_CURSOR_INFO Cursor;
	Cursor.bVisible = 0; 
	Cursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Cursor);
}


void htp()
{
	int x = 52, y = 18;
	system("cls");
	logo();
	gotoxy(x + 1, y); printf("-게임 방법-");
	gotoxy(x - 9, y + 1); printf("게임 시작 전 키를 설정할 수 있다");
	gotoxy(x - 12, y + 2); printf("설정한 키를 매우 갈기면 줄이 내게 온다");
	while (1) {
		if (_kbhit()) {
			key = _getch();
			if (key == 27)
				exit(0);
			else
				break;
		}
		gotoxy(x - 7, y + 5); printf("- Press Any Button to Menu -");
		Sleep(700);
		gotoxy(x - 7, y + 5); printf("                            ");
		Sleep(700);
	}
	system("cls");
}


void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void setting()
{
	int x = 50, y = 14;
	system("cls");
	while (1)
	{
		gotoxy(x, y);  printf("1P의 키를 지정합니다.");
		if (_kbhit())
		{
			p1 = _getch();
			if (p1 == 224)
			{
				p1 = _getch();
				if (p1 == UP || p1 == DOWN || p1 == LEFT || p1 == RIGHT)
				{
					gotoxy(x - 10, y); printf("방향키는 허용되지 않습니다. 다른 키를 지정해주세요.");
				} 
				else 
				{
					gotoxy(x - 10, y); printf("특수키는 허용되지 않습니다. 다른 키를 지정해주세요.");
				}
				Sleep(1000);
				system("cls");
				continue;
			}
			else if (p1 == 0)
			{
				p1 = _getch();
				gotoxy(x - 10, y); printf("펑션키는 허용되지 않습니다. 다른 키를 지정해주세요.");
				Sleep(1000);
				system("cls");
				continue;
			}
			else if (p1 == 27)
			{
				gotoxy(x - 13, y); printf("Esc키는 허용되지 않습니다. 다른 키를 지정해주세요.");
				Sleep(1000);
				system("cls");
				continue;
			}
			else
				break;
			
		}

	}

	system("cls");

	while (1)
	{
		gotoxy(x, y);  printf("2P의 키를 지정합니다.");
		if (_kbhit())
		{
			p2 = _getch();
			if (p2 == 224)
			{
				p2 = _getch();
				if (p2 == UP || p2 == DOWN || p2 == LEFT || p2 == RIGHT)
				{
					gotoxy(x - 10, y); printf("방향키는 허용되지 않습니다. 다른 키를 지정해주세요.");
				}
				else
				{
					gotoxy(x - 10, y); printf("특수키는 허용되지 않습니다. 다른 키를 지정해주세요.");
				}
				Sleep(1000);
				system("cls");
				continue;
			}
			else if (p2 == 0)
			{
				gotoxy(x - 10, y); printf("펑션키는 허용되지 않습니다. 다른 키를 지정해주세요.");
				Sleep(1000);
				system("cls");
				continue;
			}
			else if (p2 == 27)
			{
				gotoxy(x - 13, y); printf("Esc키는 허용되지 않습니다. 다른 키를 지정해주세요.");
				Sleep(1000);
				system("cls");
				continue;
			}
			else if (p2 == p1)
			{
				gotoxy(x - 12, y); printf("1P와 키가 동일합니다. 다른 키를 지정해주세요.");
				Sleep(1000);
				system("cls");
				continue;
			}
			else
				break;
		}

	}

	system("cls");

	gotoxy(x-6, y-1);  printf("1P의 키는 %c , 2P의 키는 %c 입니다.", p1, p2);
	gotoxy(x-8, y);  printf("아무 키를 입력하면 게임을 시작합니다.");
	gotoxy(x-6, y+1);  printf("ESC를 누르면 메인으로 돌아갑니다.");
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 27)
			{
				system("cls");
				break;
			}
			else
				play();
		}
	}
	system("cls");
}


void logo()
{
	int x = 28, y = 11;
	printf("\n\n\n\n");
	gotoxy(x, y - 4);  printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	gotoxy(x, y - 3);  printf("┃ @@@@@@@                       @@   @       @             ┃\n");
	gotoxy(x, y - 2);  printf("┃    @                         @     @       @             ┃\n");
	gotoxy(x, y - 1);  printf("┃    @   @   @ @@@@@   @@@@@ @@@@@   @       @  @@@@  @ @@@┃\n");
	gotoxy(x, y);      printf("┃    @   @   @ @   @   @   @   @      @  @  @  @    @  @   ┃\n");
	gotoxy(x, y + 1);  printf("┃    @   @@@@@ @@@@@   @@@@@   @       @@ @@    @@@@ @ @   ┃\n");
	gotoxy(x, y + 2);  printf("┃                  @                                       ┃\n");
	gotoxy(x, y + 3);  printf("┃              @@@@@                            Version 1.0┃\n");
	gotoxy(x, y + 4);  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

}


int menu()
{
	logo();
	int x = 54, y = 18;
	gotoxy(x - 2, y); printf("> 게임 시작");
	gotoxy(x, y + 1); printf("게임 방법");
	gotoxy(x, y + 2); printf("게임 종료");
	while (1)
	{
		int s = control();
		switch (s)
		{
		case UP: {
			if (y > 18) {
				gotoxy(x - 2, y); printf(" ");
				gotoxy(x - 2, --y); printf(">");
			}
			else if (y == 18) {
				gotoxy(x - 2, y); printf(" ");
				gotoxy(x - 2, y = 20); printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 20) {
				gotoxy(x - 2, y); printf(" ");
				gotoxy(x - 2, ++y); printf(">");
			}
			else if (y == 20) {
				gotoxy(x - 2, y); printf(" ");
				gotoxy(x - 2, y = 18); printf(">");
			}
			break;
		}
		case choice:
			return y - 18;
		}
	}
}


void title()
{
	int x = 28, y = 11; 
	printf("\n\n\n\n");
	gotoxy(x, y - 4);  printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"); Sleep(100);
	gotoxy(x, y - 3);  printf("┃ @@@@@@@                       @@   @       @             ┃\n"); Sleep(100);
	gotoxy(x, y - 2);  printf("┃    @                         @     @       @             ┃\n"); Sleep(100);
	gotoxy(x, y - 1);  printf("┃    @   @   @ @@@@@   @@@@@ @@@@@   @       @  @@@@  @ @@@┃\n"); Sleep(100);
	gotoxy(x, y);      printf("┃    @   @   @ @   @   @   @   @      @  @  @  @    @  @   ┃\n"); Sleep(100);
	gotoxy(x, y + 1);  printf("┃    @   @@@@@ @@@@@   @@@@@   @       @@ @@    @@@@ @ @   ┃\n"); Sleep(100);
	gotoxy(x, y + 2);  printf("┃                  @                                       ┃\n"); Sleep(100);
	gotoxy(x, y + 3);  printf("┃              @@@@@                            Version 1.0┃\n"); Sleep(100);
	gotoxy(x, y + 4);  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"); Sleep(500);
	while (1) {
		if (_kbhit()) {
			key = _getch();
			if (key == 27) 
				exit(0);
			else
				break;
		}
		gotoxy(46, 18); printf("- Press Any Button to Menu -");
		Sleep(700);
		gotoxy(46, 18); printf("                            ");
		Sleep(700);
	}
	system("cls");
}



void play()
{
	int f;
	int v = 1;

	system("cls");

	for (f = 0; f <= 33; f++)
	{
		if (v == 1)
		{
			countdown();
			wipeset(2);
			gotoxy(24, 12); printf("1P : %c", p1);
			gotoxy(88, 12); printf("2P : %c", p2);
			gotoxy(58, 13); printf("▼");
			gotoxy(58, 15); printf("▲");
			gotoxy(24, 14); printf("  ");
			v = 0;
		}
		wipeoutput(f);
		if (f == 32)
		{
			check_key();
			check_win();
			gotoxy(24, 14); printf("  ");
			f = -1;
		}
	}
}