#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct trump{
	char shape[3];
	char number;
	
};


int main(){
	
	trump card[52];
	char shape[4][3]={"¢¼","¡ß","¢¾","¢À"};
	for(int i=0;i<52;i++){
		if(i<13){
			card[i].number=i+1;
			strcpy(card[i].shape,shape[0]);
		}
		if(i>=13&&i<26){
			card[i].number=i-12;
			strcpy(card[i].shape,shape[1]);
		}
		if(i>=26&&i<39){
			card[i].number=i-25;
			strcpy(card[i].shape,shape[2]);
		}
		if(i>=39&&i<52){
			card[i].number=i-38;
			strcpy(card[i].shape,shape[3]);
		}
	}
	
	int choice[5];
	
	srand(time(NULL));
	for(int k=0;k<5;k++){
		choice[k]=rand()%52+1;
		for(int l=0;l<k;l++){
			if(choice[k]==choice[l]){
			k--;
			break;}
		}
	}
	
	
	for(int q=0;q<5;q++){
		switch(card[choice[q]].number){
			case 1:
				printf("A %s \n",card[choice[q]].shape);
				break;
			case 11:
				printf("J %s \n",card[choice[q]].shape);
				break;
			case 12:
				printf("Q %s \n",card[choice[q]].shape);
				break;
			case 13:
				printf("K %s \n",card[choice[q]].shape);
				break;
			default :
				printf("%d %s \n",card[choice[q]].number,card[choice[q]].shape);
				
			
		}
	}
	
}


