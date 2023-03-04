#include <stdio.h>
#include <string.h>
/*
int main(void)
{
	char firstname[25];
	char lastname[25];

	printf("enter your name here please: ");
	// scanf("%s %s", firstname, lastname);
	scanf("%[^\n]s", firstname);
	printf("Hello %s\n", firstname);
	return 0;
} */

// global char block, back

char block;
char back;
char background[10];
char forground[10];

void draw_pyramid(int height);
void pyramid_block(int height);
void color_red();
void color_white();
void color_cyan();
void color_purple();
void color_blue();
void color_yellow();
void color_green();
void color_black();
void color_reset();

int main(void){
	int i;
	int height;
	char signs[21] = {'-', '+', '=', '_', '*', '&', '^', '%', '$', '#', '@', '!', ';', '/', '\\', '?', ',', '<', '>', '.', ' '};
	char fullBlock[] = "\u2588";
	char colors[8][10] = {
		"\033[0;30m", "\033[0;31m", "\033[0;32m", "\033[0;33m", "\033[0;34m", "\033[0;35m", "\033[0;36m", "\033[0;37m" 
	};

	printf("types of blocks\n");
	printf("[");
	for (i = 0; i < 21; i++)
		printf("%4d", i+1);
	printf("]\n");
	printf("[");
	for (i = 0; i  < 21; i++)
		printf("  %c ", signs[i]);
	printf("]\n");

	printf("\nselect the block to build the pyramid: ");
	scanf("%d", &i);
	block = signs[i - 1];

	printf("select a block for background: ");
	scanf("%d", &i);
	back = signs[i - 1];

	printf("Colors\n");
	for (i = 0; i < 8; i++)
	{
		printf("%s", colors[i]);
		printf("%d %s ", i + 1, fullBlock);
	}

	printf("\nselect the color for block: ");
	scanf("%d", &i);
	strcpy(forground, colors[i - 1]);

	printf("select the color for the background: ");
	scanf("%d", &i);
	strcpy(background, colors[i - 1]);

	printf("enter the height[#]: ");
	scanf("%d", &height);

	draw_pyramid(height);
	return 0;
}

void draw_pyramid(int height){
	int i, j, k, n;

	k = 1;
	for (i = 1; i <= height; i++){
		printf("%s", background);
		for(j = 0; j < height - i; j++){
			printf("%c", back);
		}
		printf("%s", forground);
		for (n = 0; n < k; n++)
		{
			printf("%c", block);
		}
		printf("%s", background);
		for (j = 0; j < height -i; j++)
		{
			printf("%c", back);
		}
		printf("\n");
		k += 2;
	}
	color_reset();
}

void pyramid_block(int height)
{
	char block[] = "\u2588";
	char back[] = "\u2591";
	int i, j, k, n;

	k = 1;
	for (i = 1; i <= height; i++){
		for(j = 0; j < height - i; j++){
			printf("%s", back);
		}
		color_yellow();
		for (n = 0; n < k; n++)
		{
			printf("%s", block);
		}
		color_white();
		for (j = 0; j < height -i; j++)
		{
			printf("%s", back);
		}
		printf("\n");
		k += 2;
	
	}
}


void color_red(){
	printf("\033[0;31m");
}

void color_black(){
	printf("\033[0;30m");
}

void color_green(){
	printf("\033[0;32m");
}

void color_yellow(){
	printf("\033[0;33m");
}

void color_blue(){
	printf("\033[0;34m");
}

void color_purple(){
	printf("\033[0;35m");
}

void color_cyan(){
	printf("\033[0;36m");
}

void color_white(){
	printf("\033[0;37m");
}

void color_reset(){
	printf("\033[0m");
}
