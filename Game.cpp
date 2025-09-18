#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>

using namespace std;

const char chick = '&';
const char ship = '$';
const char bullet = '*';
const char egg = 'O';
const char power = '+';
const char bonus = '%';
const char bulletSpeed = '^';

const int h = 15;
const int w = 40;
int sx = w / 2;
int sy = h - 2;
int score = 0;
int life = 3;
int level = 1;
int powerscore;
char arr[h][w];

bool gameover = false;
bool bullets = true;
bool fastbullet = false;
bool Right = false;
bool Left = false;
bool down = false;
bool check = false;
bool check2 = false;
bool invincible = false;

void initialize();
void menu();
void pause();
void instruction();
void control();
void ships();
void enemy();
void display();
void gameOverMessage();

int main() {
	srand(time(0));
	initialize();
	menu();
	char option;
	option = _getch();
	system("cls");
	gameover = false;
	if (!gameover) {
		switch (option) {
		case 'S':
		case 's':
			if (!gameover) {
				while (!gameover) {
					if (_kbhit()) {
						control();
					}
					ships();
					enemy();
					display();
					Sleep(150);
				}
			}
			if (gameover) {
				gameOverMessage();
			}
			break;
		case 'h':
		case 'H':
			break;
		case 'I':
		case 'i':
			instruction();
			break;
		case 'e':
		case 'E':
			gameover = true;
			return 0;
			break;
		default:
			cout << "Invalid Option!" << endl;
			break;
		}

	}
}
void initialize() {
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++) {
			if ((y == 0 || y == h - 1) && (x > 0 && x < w - 1)) {
				arr[y][x] = '#';
			}
			else if ((x == 0 || x == w - 2) && (y >= 0 && y < h)) {
				arr[y][x] = '#';
			}
			else {
				arr[y][x] = ' ';
			}
		}
	}
	if (level == 1) {
		arr[3][30] = chick;
		arr[3][28] = chick;
		arr[3][26] = chick;
		arr[3][24] = chick;
		arr[4][30] = chick;
		arr[4][28] = chick;
		arr[4][26] = chick;
		arr[4][24] = chick;
		arr[5][30] = chick;
		arr[5][28] = chick;
		arr[5][26] = chick;
		arr[5][24] = chick;
	}
	if (level == 2) {
		arr[3][32] = chick;
		arr[3][30] = chick;
		arr[3][28] = chick;
		arr[3][26] = chick;
		arr[3][24] = chick;
		arr[3][22] = chick;
		arr[4][32] = chick;
		arr[4][30] = chick;
		arr[4][28] = chick;
		arr[4][26] = chick;
		arr[4][24] = chick;
		arr[4][22] = chick;
		arr[5][32] = chick;
		arr[5][30] = chick;
		arr[5][28] = chick;
		arr[5][26] = chick;
		arr[5][24] = chick;
		arr[5][22] = chick;
		arr[2][32] = chick;
		arr[2][30] = chick;
		arr[2][28] = chick;
		arr[2][26] = chick;
		arr[2][24] = chick;
		arr[2][22] = chick;

	}
	if (level == 3) {
		arr[3][34] = chick;
		arr[3][32] = chick;
		arr[3][30] = chick;
		arr[3][28] = chick;
		arr[3][26] = chick;
		arr[3][24] = chick;
		arr[3][22] = chick;
		arr[3][20] = chick;
		arr[4][34] = chick;
		arr[4][32] = chick;
		arr[4][30] = chick;
		arr[4][28] = chick;
		arr[4][26] = chick;
		arr[4][24] = chick;
		arr[4][22] = chick;
		arr[4][20] = chick;
		arr[5][34] = chick;
		arr[5][32] = chick;
		arr[5][30] = chick;
		arr[5][28] = chick;
		arr[5][26] = chick;
		arr[5][24] = chick;
		arr[5][22] = chick;
		arr[5][20] = chick;
		arr[6][34] = chick;
		arr[6][32] = chick;
		arr[6][30] = chick;
		arr[6][28] = chick;
		arr[6][26] = chick;
		arr[6][24] = chick;
		arr[6][22] = chick;
		arr[6][20] = chick;
		arr[2][34] = chick;
		arr[2][32] = chick;
		arr[2][30] = chick;
		arr[2][28] = chick;
		arr[2][26] = chick;
		arr[2][24] = chick;
		arr[2][22] = chick;
		arr[2][20] = chick;

	}
}
void menu() {
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t|```````````````````````````````|\n";
	cout << "\t\t\t\t\t| WELCOME TO CHICKEN INVADER GAME! |\n";
	cout << "\t\t\t\t\t|__________________________________|\n";
	cout << "\t\t\t\t\t|                                  |\n";
	cout << "\t\t\t\t\t| Press  S  Start the Game!        |\n";
	cout << "\t\t\t\t\t| Press  H  Check high score       |\n";
	cout << "\t\t\t\t\t| Press  I  Open Instruction       |\n";
	cout << "\t\t\t\t\t| Press  E  Quit the Game!         |\n";
	cout << "\t\t\t\t\t|__________________________________|\n";
}
void instruction() {
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t|```````````````````````````````|\n";
	cout << "\t\t\t\t\t|           INSTRUCTIONS           |\n";
	cout << "\t\t\t\t\t||\n";
	cout << "\t\t\t\t\t|                                  |\n";
	cout << "\t\t\t\t\t|       Press A to move right.     |\n";
	cout << "\t\t\t\t\t|       Press D to move left.      |\n";
	cout << "\t\t\t\t\t|       Press W to move Up.        |\n";
	cout << "\t\t\t\t\t|       Press S to move Down.      |\n";
	cout << "\t\t\t\t\t|       Press Space to Fire.       |\n";
	cout << "\t\t\t\t\t|       Press M to open Menu.      |\n";
	cout << "\t\t\t\t\t||\n";
	cout << "\t\t\t\t\t|       Press Any key to Resume.   |\n";
	cout << "\t\t\t\t\t||\n";
	char c;
	c = _getch();
	system("cls");
	switch (c) {
	case 'M':
	case 'm':
		main();
		break;

	default:
		break;
	}

}
void pause() {
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t|``````````````````````````````````|\n";
	cout << "\t\t\t\t\t|               PAUSE              |\n";
	cout << "\t\t\t\t\t||\n";
	cout << "\t\t\t\t\t|                                  |\n";
	cout << "\t\t\t\t\t|                                  |\n";
	cout << "\t\t\t\t\t|   Press  S  Restart the Game!    |\n";
	cout << "\t\t\t\t\t|   Press  H  Check high score     |\n";
	cout << "\t\t\t\t\t|   Press  I  Open Instruction     |\n";
	cout << "\t\t\t\t\t|                                  |\n";
	cout << "\t\t\t\t\t||\n";
	cout << "\t\t\t\t\t|                                  |\n";
	cout << "\t\t\t\t\t|   Press  R  Resume the Game!     |\n";
	cout << "\t\t\t\t\t||\n";
	char c;
	c = _getch();
	switch (c) {
	case 'I':
	case 'i':
		instruction();
		break;
	case 'S':
	case 's':
		main();
		break;
	case 'H':
	case 'h':
		break;
	}
}
void control() {
	char move;
	move = _getch();
	switch (move) {
	case 'A':
	case 'a':
		if (sx > 1) {
			arr[sy][sx] = ' ';
			sx--;
			arr[sy][sx] = ship;
			if (arr[sy][sx - 1] == chick) {
				if (life > 0) {
					life--;
				}
				else {
					gameover = true;
				}
			}
		}
		break;
	case 'D':
	case 'd':
		if (sx < w - 2) {
			arr[sy][sx] = ' ';
			sx++;
			arr[sy][sx] = ship;
			if (arr[sy][sx + 1] == chick) {
				if (life > 0) {
					life--;
				}
				else {
					gameover = true;
				}
			}
		}
		break;
	case 'W':
	case 'w':
		if (sy > 1) {
			arr[sy][sx] = ' ';
			sy--;
			arr[sy][sx] = ship;
			if (arr[sy - 1][sx] == chick) {
				if (life > 0) {
					life--;
				}
				else {
					gameover = true;
				}
			}
		}
		break;
	case 'S':
	case's':
		if (sy < h - 2) {
			arr[sy][sx] = ' ';
			sy++;
			arr[sy][sx] = ship;
			if (arr[sy + 1][sx] == chick) {
				if (life > 0) {
					life--;
				}
				else {
					gameover = true;
				}
			}
		}
		break;
	case ' ':
		bullets = true;
		break;
	case 'I':
	case 'i':
		instruction();
		break;
	case 'P':
	case 'p':
		pause();
		break;
	default:
		break;
	}
}
void ships() {
	if (bullets) {
		arr[sy - 1][sx] = bullet;
	}
	// Handle egg movement
	for (int y = h - 2; y >= 0; y--) {
		for (int x = 0; x < w; x++) {
			if (arr[y][x] == egg) {
				arr[y][x] = ' '; // Remove egg from current position
				if (y + 1 < h - 1) {
					// Check for collision with ship
					if (arr[y + 1][x] == ship && !invincible) {
						if (life > 0) {
							life--;
						}
						else {
							gameover = true;
						}
					}
					else {
						arr[y + 1][x] = egg; // Move egg down
					}
				}
			}
		}
	}
	for (int y = h - 2; y >= 0; y--) {
		for (int x = 0; x < w; x++) {
			if (arr[y][x] == power) {
				arr[y][x] = ' '; // Remove egg from current position
				if (y + 1 < h - 1) {
					// Check for collision with ship
					if (arr[y + 1][x] == ship) {
						invincible = true;
						fastbullet = false;
						powerscore = score + 10;
					}
					else {
						arr[y + 1][x] = power; // Move egg down
					}
				}
			}
		}
	}
	for (int y = h - 2; y >= 0; y--) {
		for (int x = 0; x < w; x++) {
			if (arr[y][x] == bulletSpeed) {
				arr[y][x] = ' '; // Remove egg from current position
				if (y + 1 < h - 1) {
					// Check for collision with ship
					if (arr[y + 1][x] == ship) {
						fastbullet = true;
						invincible = false;
					}
					else {
						arr[y + 1][x] = bulletSpeed; // Move egg down
					}
				}
			}
		}
	}
	for (int y = h - 2; y >= 0; y--) {
		for (int x = 0; x < w; x++) {
			if (arr[y][x] == bonus) {
				arr[y][x] = ' '; // Remove egg from current position
				if (y + 1 < h - 1) {
					// Check for collision with ship
					if (arr[y + 1][x] == ship) {
						score += 30;
						invincible = false;
						fastbullet = false;
					}
					else {
						arr[y + 1][x] = bonus; // Move egg down
					}
				}
			}
		}
	}
	if (powerscore <= score) {
		invincible = false;
		fastbullet = false;
	}
	// Existing logic for bullets, chickens, and collisions remains unchanged
	if (bullets) {
		arr[sy - 1][sx] = bullet;
	}
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (x == sx && y == sy) {
				arr[y][x] = ship;
			}
			if (arr[y][x] == bullet) {
				arr[y][x] = ' ';
				bullets = false;
				arr[y - 1][x] = bullet;
			}
			if (arr[y][x] == chick && arr[y + 1][x] == bullet) {
				arr[y][x] = ' ';
				arr[y + 1][x] = ' ';
				score += 10;
			}
			if (arr[1][x] == bullet) {
				arr[1][x] = ' ';
			}
			if (arr[sy][sx] == chick) {
				if (life > 0) {
					life--;
				}
				else {
					gameover = true;
				}
			}
			if (arr[h - 2][x] == chick) {
				gameover = true;
			}
		}
	}
	if (fastbullet) {
		bullets = true;
	}
}
void enemy() {
	static bool movingRight = true; // Track direction (right or left)
	static int moveCounter = 0;     // Track number of horizontal moves

	// Move chickens horizontally
	for (int y = h - 1; y >= 0; y--) {
		for (int x = (movingRight ? w - 3 : 1); (movingRight ? x >= 0 : x < w - 2); (movingRight ? x-- : x++)) {
			if (arr[y][x] == chick) {
				// Drop eggs randomly
				if (rand() % 70 == 0 && arr[y + 1][x] == ' ' && arr[y + 1][x] != chick) { // 10% chance to drop an egg
					arr[y + 1][x] = egg;
				}
				if (rand() % 150 == 0 && arr[y + 1][x] == ' ' && arr[y + 1][x] != chick) {
					arr[y + 1][x] = power;
				}
				if (rand() % 100 == 0 && arr[y + 1][x] == ' ' && arr[y + 1][x] != chick) {
					arr[y + 1][x] = bonus;
				}
				if (rand() % 299 == 0 && arr[y + 1][x] == ' ' && arr[y + 1][x] != chick) {
					arr[y + 1][x] = bulletSpeed;
				}
				// Handle chicken movement
				if (movingRight && x + 1 < w - 2) {
					arr[y][x + 1] = chick;
					arr[y][x] = ' ';
				}
				else if (!movingRight && x - 1 > 0) {
					arr[y][x - 1] = chick;
					arr[y][x] = ' ';
				}
			}
		}
	}
	int count = 0;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (arr[y][x] == chick) {
				count++;
			}
		}
	}if (count == 0 && level == 3) {
		gameover = true;
	}
	// Handle direction change at boundaries
	if (movingRight) {
		for (int y = 0; y < h; y++) {
			if (arr[y][w - 3] == chick) { // Rightmost boundary reached
				movingRight = false;
				moveCounter++;
				break;
			}
		}
	}
	else {
		for (int y = 0; y < h; y++) {
			if (arr[y][1] == chick) { // Leftmost boundary reached
				movingRight = true;
				moveCounter++;
				break;
			}
		}
	}

	// Move down after completing one horizontal pass
	if (moveCounter >= 1) {
		for (int y = h - 2; y >= 0; y--) {
			for (int x = 1; x < w - 2; x++) {
				if (arr[y][x] == chick) {
					if (y + 1 < h - 1) {
						arr[y + 1][x] = chick;
						arr[y][x] = ' ';
					}
					else {
						gameover = true; // Chickens reach the bottom
					}
				}
			}
		}
		moveCounter = 0; // Reset counter after moving down
	}
	check = true;
	for (int i = 0; i < h && check; i++) {
		for (int j = 0; j < w && check; j++) {
			if (arr[i][j] == chick) {
				check = false;
			}
		}
	}
}
void gameOverMessage() {
	system("cls");
	cout << "\n\n\n";
	cout << "\t\t\t\t\t--------------------------\n";
	cout << "\t\t\t\t\t      GAME OVER!          \n";
	cout << "\t\t\t\t\t   Your Score: " << score << "      \n";
	cout << "\t\t\t\t\t--------------------------\n";
	cout << "\t\t\t\t\t   Press R to Restart.    \n";
	cout << "\t\t\t\t\t   Press Q to Quit.       \n";
	cout << "\t\t\t\t\t--------------------------\n";
	score = 0;
	char choice = _getch();
	switch (choice) {
	case 'R':
	case 'r':
		main();
		break;
	case 'Q':
	case 'q':
		exit(0);
		break;
	default:
		break;
	}
}

void display() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << "\t\t\t\t\tPress P to Pause." << "\t    Level = " << level << endl;
	system("color 05");
	for (int i = 0; i < h; i++) {
		cout << "\t\t\t\t\t";
		for (int j = 0; j < w; j++) {
			cout << arr[i][j];
		}cout << endl;
	}
	if (check) {
		if (level == 1) {
			level = 2;
		}
		else if (level == 2) {
			level = 3;
		}
		check = false;
		initialize();
	}
	cout << "\t\t\t\t\tScore = " << score << "\t\t    Life = " << life << endl;
	cout << "\t\t\t\t\tPress I for Instructions." << endl;
}