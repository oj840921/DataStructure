#include "Dictionary.h"
#include <conio.h>


void help() {
	printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-출력 q-종료 =>");
}

// 이진 탐색 트리를 사용하는 영어 사전 프로그램 
void main()
{
	char	command;
	char	word[80];
	char	meaning[200];
	char	partOfSpeech[30];
	Dictionary tree;

	do {
		help();
		command = _getche();
		printf("\n");
		switch (command) {
		case 'i':
			printf("  > 삽입 단어: "); gets_s(word);
			printf("  > 단어 설명: "); gets_s(meaning);
			printf("  > 품사: "); gets_s(partOfSpeech);
			tree.insert(new BinaryNode(word, meaning, partOfSpeech));
			break;
		case 'd':
			printf("  > 삭제 단어: "); gets_s(word);
			tree.remove(word);
			break;
		case 'p':
			tree.printAllWords();
			printf("\n");
			break;
		case 'w':
			printf("  > 검색 단어: "); gets_s(word);
			tree.searchWord(word);
			break;
		case 'm':
			printf("  > 검색 의미: "); gets_s(word);
			tree.searchMeaning(word);
			break;
		}

	} while (command != 'q');
}