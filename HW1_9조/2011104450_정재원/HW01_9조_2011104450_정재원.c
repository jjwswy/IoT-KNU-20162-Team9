#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word_count {			// ��ũ�� ����Ʈ�� �����ϱ� ���� ����ü ����
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



	FILE *fp = fopen("C:\\hello.txt", "r");		// ������ �����ش�
	while ( feof(fp) == 0 )		// ������ ���� �����ϸ� 0�� �ƴѰ��� ��ȯ�Ͽ� while�� Ż��
	{

		fscanf(fp, "%s", name);

		s_insert(&head, name);		// ���� ���� �о�ͼ� name�� �����Ѵ�

	}
	fclose(fp);		// ������ �ݾ��ش�




	printf("�˻��� �ܾ �Է��ϼ���:");
	scanf("%s", s_word);


	while (head)
	{
		strcpy(serch, head->name);	// ��Ʈ���� strcpy �Լ��� �̿��Ͽ� �����Ѵ�


		char *ptr = strstr(serch, s_word);     // s_word�� ���Ե� ���ڿ� �˻�, ������ ��ȯ

		while (ptr != NULL)              // �˻��� ���ڿ��� ���� ������ �ݺ�
		{

			ptr = strstr(ptr + 1, s_word);  // �����Ϳ� 1�� ���Ͽ� s_word �������� �˻�
			s_count++;			// ī���͸� �������� �༭ ������ �ܾ ����� ��Ÿ���ش�
			index[a] = head->num;		// �˻��� �ܾ��� ��� ����Ʈ�� ��Ÿ��
			a++;
		}

		head = head->link;		// ������ ����� ������ �˻��ǰ� �������
	}

	printf("�˻� ���ڿ� '%s'�� %d �� �ֽ��ϴ�.\n", s_word, s_count);
	printf("�˻��� �ܾ��� ����Ʈ��");
	for (a = 0; a < s_count; a++)
	{
		printf("%d ��° ", index[a]);
	}
	printf("�Դϴ�.");





	system("PAUSE");
	return 0;
}


void s_insert(word **head, char *name)
{

	int num = 1;
	word *tmp;
	word *find = *head;

	tmp = (word*)malloc(sizeof(word));      //�����Ҵ�
	strcpy(tmp->name, name);            // tmp�� ������ �ڷḦ ����
	tmp->link = NULL;


	if (*head == NULL)		// ��尡 ������ ó�� ���� �����Ͱ� ��尡 �ȴ�
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
			if (find->link == NULL)		// ��ũ�� NULL�̸� ������ ����̹Ƿ� tmp�� ������ �ش�
			{
				find->link = tmp;
				tmp->num = num;			// ���� ����Ʈ�� ��� ������ ��Ÿ����
				break;
			}
			else
			find = find->link;		// ���� ����Ʈ�� ������ ���� �̵�

		}

	}


}
