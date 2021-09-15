// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0   // set to 0 to disable debug output
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s);

void readin(int* t, int* b1, int* b2, int* b3, int* b4, int* b5, int* b6, int* b7, 
int* b8, int* b9, int* b10, int* b11, int* b12, int* lsx, int* lsy, int* rsx, int* rsy);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i, j, k, move;
	wordCount = readWords(wordlist, argv[1]);

	if (!DEBUG) {
		printf("Read %d words from %s \n", wordCount, argv[1]);
		// add code to print the words to the screen here for part 1
		for(i = 0; i < wordCount; i++){
			printf("%s,", wordlist[i]);
			}
		printf("\n");
		}

// most of your code for part 2 goes here. Don't forget to include the ncurses library
initscr();
	int height = 20, loc, stop = 0, pv = 10, pcy, pcx, cx = 16, cy = 0, t, b1 = 0, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, lsx, lsy, rsx, rsy, past[80], count = 0;
	for(i = 0; k < wordCount; i++){
		for(j = 0; j < 5; j++){
			if(k < wordCount){
				mvprintw(i, j*15, "%15s", wordlist[k]);
				k++; 
				refresh();
			}
		}

	}
	mvprintw(cy, cx, "<"); //print the first time

	refresh();
	
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4, &lsx, &lsy, &rsx, &rsy);
	while(1){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4, &lsx, &lsy, &rsx, &rsy);
			//Movement Functions
		if(rsx < 100 && rsx > -100 && rsy < 100 && rsy > -100)
				move = 1;
		if(rsy < -100 && cy-1 >= 0 && move){
			move = 0;
			cy -= 1;
		}
		if(rsy > 100 && cy+1 <= 16 && move){
			cy += 1;
			move = 0;
		}
		if(rsx < -100 && cx-15 > 0 && move){
			move = 0;
			cx -= 15;
		}
		if(rsx > 100 && cy + 15 < 75 && move){
			move = 0;
			cx += 15;
		}
		mvprintw(pcy, pcx, " ");
		pcy = cy;
		pcx = cx;
		mvprintw(cy, cx, "<");
		refresh();
		
		//Figure out stuff
		
		if(b1 && !stop && pv < 80){
			loc = cy * 5 + ((cx - 16) / 15);
			mvprintw(height, pv, wordlist[loc]);
			pv += strlen(wordlist[loc]);
			mvprintw(20, pv++, " ");
			refresh();
			stop = 1;
			past[count] = strlen(wordlist[loc]) + 1;
			count++;
		}
		if(b4 && !stop && pv < 80){
			loc = cy * 5 + ((cx - 16) / 15);
			mvprintw(height, pv, wordlist[loc]);
			pv += strlen(wordlist[loc]);
			refresh();	
			stop = 1;
			past[count] = strlen(wordlist[loc]);
			count++;
		}
		if(b3 && !stop){
			if(count >= 1){
				for(i = 0; i <= past[count-1]; i++){
					mvprintw(height,pv - i , " ");
				}
				pv -= past[--count];
				stop = 1;
				refresh();
			}
		}
		if(b2 && !stop){
		height++;
		stop = 1;
		for(i = 10;i < count;i++){
			past[i]=0;
		}
		pv = 10;
		}
		if(!b1 && !b2 && !b3 && !b4){
			stop = 0;
		}
	}
	endwin();
    return 0;
	}

int readWords(char* w1[MAXWORDS], char* filename){
	
	FILE* inFile = NULL;
	int j = 0;
	int t, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, lsx, lsy, rsx, rsy; //Buttons
	
	inFile = fopen(filename, "r");
	if(inFile == NULL){
		printf("Could not open file %s.\n", filename);
	}
	do{
		char tempStr[WORDLEN];
		fscanf(inFile, "%s\n", tempStr);
		trimws(tempStr);
		w1[j] = (char*) malloc((WORDLEN) * sizeof(char));
		strcpy(w1[j], tempStr);
		j++;
	} while((!feof(inFile)));
	return j;
}

void trimws(char* s){
	int i = 0;
	int exit = 0;
	for(i = 0; i < WORDLEN; i++){
		if((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && !exit){
			s[i] = '\0';
			exit = 1;
		}
	}
}
void readin(int* t, int* b1, int* b2, int* b3, int* b4, int* b5, int* b6, int* b7,
 int* b8, int* b9, int* b10, int* b11, int* b12, int* lsx, int* lsy, int* rsx, int* rsy){
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, 
	&b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8, &b9, &b10, &b11, &b12, &lsx, &lsy, &rsx, &rsy);
	
}

