#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
       char data[64];
       struct tagNode *next;
} NODE;
 
NODE *head, *tail, *working;
 
void initList();
void insert(char n[64]);
int count(char n[64]);
void read();

char word[64];
 
void main() {
    initList();
	read();

	printf("Please enter the word to search : ");
	scanf("%s", word);
	count(word);
}
 
void initList() {
	head = NULL;
	tail = NULL;
	working = NULL;
}
 
void insert(char n[64]) {
	working = (NODE *)malloc(sizeof(NODE));
	strncpy(working->data, n, 64);
 
	working->next = NULL;
 
	if ( head == NULL ) {
		head = working;
		tail = working;
		return;
	}
 
	tail->next = working;
	tail = working;
}

int count(char n[64]) {
	int count = 0;

	int num = 0;
 
	working = head;
 
	printf("Indices of %s : ", n);

	while ( working ) {
		num++;
		if (!strcmp(working->data, n)) {
			++count;
			printf("%d ", num);

		}
		working = working->next;
	}
	printf("\nCount of %s : %d\n", n, count);
 
	return count;
}

void read() {
    int word_count = 0, index = 0, sub_index = 0;
    char buff[256], temp[64];
 
    FILE *p_file = fopen("C:\\Users\\River1360\\Desktop\\lyrics\\이 소설의 끝을 다시 써보려 해.txt", "rt");
    if(p_file != NULL) {

        while(fgets(buff, 255, p_file)) {
            sub_index = 0;
            for(index = 0; buff[index] != 0 && buff[index] != '\r' && buff[index] != '\n'; index++) {
                if(buff[index] == ' ' || buff[index] == '.' || buff[index] == ',') {
                    temp[sub_index] = 0;
                    if(strlen(temp) > 0) {
						insert(temp);
                        word_count++;
                        printf("[%3d] : %s\n", word_count, temp);
                    }
                    sub_index = 0;
                } else {
                    temp[sub_index] = buff[index];
                    sub_index++;
                }
            }
 
            if(sub_index > 0) {
                temp[sub_index] = 0;
                if(strlen(temp) > 0) {
					insert(temp);
                    word_count++;
                    printf("[%3d] : %s\n", word_count, temp);
                }
            }
        }
		printf("\n");
 
        fclose(p_file);
    }
}

