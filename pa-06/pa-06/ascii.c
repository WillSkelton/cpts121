#include "ascii.h"

void printTitle(void) {

	printf("Welcome to...");

	Sleep(2000);

	system("cls");

	printf("88                                        88                        88           88               \n");
	printf("88                        ,d      ,d      88                        88           \"\"  8b, dPPYba,   \n");
	printf("88                        88      88      88                        88               88P'    \"8a   \n");
	printf("88,dPPYba,   ,adPPYYba,  MM88MMM MM88MMM  88 ,adPPYba,   ,adPPYba,  88,dPPYba,   88  88       d8   \n");
	printf("88P'    \"8a  \"\"     `Y8   88      88      88 a8P_____88  I8[    \"\"  88P'    \"8a  88  88b,   ,a8\"    \n");
	printf("88       d8  ,adPPPPP88   88      88      88 8PP\"\"\"\"\"\"\"  `\"Y8ba,    88       88  88  88`YbbdP\"'    \n");
	printf("88b,   ,a8\"  88,    ,88   88,     88,     88 \"8b,   ,aa  aa    ]8I  88       88  88  88            \n");
	printf("8Y\"Ybbd8\"'   `\"8bbdP\"Y8   \"Y888   \"Y888   88  `\"Ybbd8\"'  `\"YbbdP\"'  88       88  88  88            \n");
	
	Sleep(2500);
	system("cls");

}

void printBorder(int size, int length) {

	switch (size) {
	case 1:
		for (int i = 0; i < length; ++i) {
			printf("-");
		}
		printf("\n");
		break;
	case 2:
		for (int i = 0; i < length; ++i) {
			printf("=");
		}
		printf("\n");
		break;
	}

}


