#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word_count {			// 링크드 리스트로 연결하기 위해 구조체 만듬
	char name[10];
	int num;
	struct word_count *link;
}word;


int main()
{
	word *head = NULL;
	int i;
	char name[20];
	char s_word[20];
	int a = 0;
	int* index = (int*)malloc(sizeof(int));


	char serch[20];
	int s_count = 0;



	FILE *fp = fopen("C:\\hello.txt", "r");		// 파일을 열어준다
	while ( feof(fp) == 0 )		// 파일의 끝에 도달하면 0이 아닌값을 반환하여 while문 탈출
	{

		fscanf(fp, "%s", name);

		s_insert(&head, name);		// 파일 값을 읽어와서 name에 저장한다

	}
	fclose(fp);		// 파일을 닫아준다




	printf("검색할 단어를 입력하세요:");
	scanf("%s", s_word);


	while (head)
	{
		strcpy(serch, head->name);	// 스트링은 strcpy 함수를 이용하여 복사한다


		char *ptr = strstr(serch, s_word);     // s_word가 포함된 문자열 검색, 포인터 반환

		while (ptr != NULL)              // 검색된 문자열이 없을 때까지 반복
		{

			ptr = strstr(ptr + 1, s_word);  // 포인터에 1을 더하여 s_word 다음부터 검색
			s_count++;			// 카운터를 증가시켜 줘서 동일한 단어가 몇개인지 나타내준다
			index[a] = head->num;		// 검색한 단어의 노드 리스트를 나타냄
			a++;
		}

		head = head->link;		// 헤드부터 노드의 끝까지 검색되게 만들어줌
	}

	printf("검색 문자열 '%s'는 %d 개 있습니다.\n", s_word, s_count);
	printf("검색한 단어의 리스트는");
	for (a = 0; a < s_count; a++)
	{
		printf("%d 번째 ", index[a]);
	}
	printf("입니다.");





	system("PAUSE");
	return 0;
}


void s_insert(word **head, char *name)
{

	int num = 1;
	word *tmp;
	word *find = *head;

	tmp = (word*)malloc(sizeof(word));      //동적할당
	strcpy(tmp->name, name);            // tmp에 삽입할 자료를 넣음
	tmp->link = NULL;


	if (*head == NULL)		// 헤드가 없으면 처음 들어가는 데이터가 헤드가 된다
	{
		*head = tmp;
		tmp->num = num;
		return 0;
	}
	else
	{
		while (1)
		{
			num++;
			if (find->link == NULL)		// 링크가 NULL이면 마지막 노드이므로 tmp와 연결해 준다
			{
				find->link = tmp;
				tmp->num = num;			// 연결 리스트의 노드 순서를 나타낸다
				break;
			}
			else
			find = find->link;		// 연결 리스트의 마지막 노드로 이동

		}

	}


}
