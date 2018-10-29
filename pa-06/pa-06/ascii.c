#include "ascii.h"

void printBattleship(void) {
	printf("");
	
	/*printf("                                               |__\n");
	printf("                                               |\\/\n");
	printf("                                               ---\n");
	printf("                                               / | [\n");
	printf("                                   !           | |||\n");
	printf("             	                _/ |       _ / | -++'\n");
	printf("              	            +  +-- | | -- | -- | _ | -\n");
	printf("                         { /|__|  |\\/\\__|  |--- |||__/\n");
	printf("	                    +---------------___[}-_===_.'____                 /\\\n");
	printf("	                ____`-'||___-{]_|_[}-|         |_[___\\==--            \\/   _\n");
	printf("	 __..._____--==/___]_|__|_____________________________[___\\==--____,------' .7\n");
	printf("	|                                                                  BB - 61 /\n");
	printf("	\\_________________________________________________________________________ |\n");*/
}

void printTitle(void) {
	printf("88                                        88                        88           88               \n");
	printf("88                        ,d      ,d      88                        88           \"\"  8b, dPPYba,   \n");
	printf("88                        88      88      88                        88               88P'    \"8a   \n");
	printf("88,dPPYba,   ,adPPYYba,  MM88MMM MM88MMM  88 ,adPPYba,   ,adPPYba,  88,dPPYba,   88  88       d8   \n");
	printf("88P'    \"8a  \"\"     `Y8   88      88      88 a8P_____88  I8[    \"\"  88P'    \"8a  88  88b,   ,a8\"    \n");
	printf("88       d8  ,adPPPPP88   88      88      88 8PP\"\"\"\"\"\"\"  `\"Y8ba,    88       88  88  88`YbbdP\"'    \n");
	printf("88b,   ,a8\"  88,    ,88   88,     88,     88 \"8b,   ,aa  aa    ]8I  88       88  88  88            \n");
	printf("8Y\"Ybbd8\"'   `\"8bbdP\"Y8   \"Y888   \"Y888   88  `\"Ybbd8\"'  `\"YbbdP\"'  88       88  88  88            \n");
	printf("");

}

void printGameBoard(char board[10][10]) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}

void resetGameBoard(char board[10][10]) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			board[i][j] = '~';
		}
	}
}