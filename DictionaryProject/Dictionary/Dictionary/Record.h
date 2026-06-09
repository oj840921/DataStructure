// Record.h: 사전을 위한 레코드 클래스
#include <cstdio>
#include <cstring>
#define MAX_WORD_SIZE		40
#define MAX_MEANING_SIZE	200
#define MAX_PARTOFSPEECH_SIZE 30

class Record
{
protected:
	char	word[MAX_WORD_SIZE];					// 단어: 키 필드
	char	meaning[MAX_MEANING_SIZE];				// 의미
	char	partOfSpeech[MAX_PARTOFSPEECH_SIZE];	// 품사
	int		searchCount;		// 검색 횟수
public:
	Record(const char* w = "", const char* m = "", const char* pos = "") { set(w, m, pos); }

	void set(const char* w, const char* m, const char* pos = "") 
	{
		strcpy_s(word, w);
		strcpy_s(meaning, m);
		strcpy_s(partOfSpeech, pos);
	}
	void increaseSearchCount() // (3) 조회수를 1 올려주는 버튼(함수) 생성
	{ 
		searchCount++;
	}
	int getSearchCount() 
	{
		return searchCount;
	}

	int compare(Record* n) { return compare(n->word); }
	int compare(char* w) { return strcmp(w, word); }
	int compareMeaning(char* m) { return strcmp(meaning, m); }
	void display() { printf(" %12s [%s] : %-40s\n", word, partOfSpeech, meaning); }
	void copy(Record* n) { set(n->word, n->meaning, n->partOfSpeech); } 
};