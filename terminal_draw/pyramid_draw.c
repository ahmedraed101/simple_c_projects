#include <stdio.h>
#include <string.h>


char block;
char back;
char background[10];
char forground[10];

void draw_pyramid(int height);
void pyramid_block(int height);
void color_reset();

int main(void){
	int i;
	int height;
	char signs[21] = {'-', '+', '=', '_', '*', '&', '^', '%', '$', '#', '@', '!', ';', '/', '\\', '?', ',', '<', '>', '.', ' '};
	char fullBlock[] = "\u2588";
	// more in here: https://www.w3schools.com/charsets/ref_utf_block.asp
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


void color_reset(){
	printf("\033[0m");
}
