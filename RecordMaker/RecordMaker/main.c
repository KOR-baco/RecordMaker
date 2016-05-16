/**
 ** 사원번호와 성적을 출력하는 프로그램
 ** 2016, KimYihyun
 ** 구현환경 : vs2010
 ** 사용방법 : 빌드후, cmd.exe 실행 -> cd [실행파일 위치] -> RecordMaker.exe [0~99999]  (예:RecordMaker.exe 1234)
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXMEMBER 100000

typedef struct{		// 사원 정보 구조체.
	int id;
	int score;
}NTinfo;
int staff[MAXMEMBER]={0,}; // 사원 1~99999
int cache[MAXMEMBER]={0,}; // 중복 체크용.
int index = MAXMEMBER - 1; // 남은 사원정보 수.

void PrintStaffId(int id, int score); // 사원id 출력

int main(int argc, char *argv[])
{
	int i,j,k;
	int count;		//실행시 입력받는 [count]
	int myRandom;	//time을 seed로 생성한 난수함수는 범위가 제한적이므로, 2개의 rand()를 이용하여 난수를 생성. 
	NTinfo nt[MAXMEMBER]; //조회된 순서대로 사원 정보 구조체에 저장.
	srand((unsigned int)time(NULL));
	
	// Get argument vector
	if(argc<2){
		printf("숫자를 입력해 주세요 : ");
		scanf("%d",&count);
	}else{
		count = atoi(argv[1]);
	}

	// Exception handling
	if(count>=MAXMEMBER || count<0){
		printf("입력된 숫자가 올바르지 않습니다. (0~99999)\n");
		return 0;
	}

	// Preprocessing
	index = MAXMEMBER - 1;
	for(i=1; i<MAXMEMBER; i++){
		staff[i]=i;
	}

	for(i=1; i<=count; i++){
		myRandom = (rand()%1001)*100 + (rand()%100); // 0 ~ 100000 난수 생성
		nt[i].id = myRandom%index + 1;				 // 남은 index만큼의 난수로 변경
		
		// 방문한 index는 cache를 통해 체크하고, 방문하지 않은 사원의 id 출력.
		// '에라토스테네스의 체'와 유사한 알고리즘.
		for(j=1,k=0; j<MAXMEMBER; j++){
			if(cache[j]==0){
				k++;
			}
			if(k==nt[i].id){
				cache[j]=1;
				nt[i].id = staff[j];
				index--;
				break;
			}
		}
		//if(nt[i].id <= 10) // 주석을 제거하여 범위를 지정하면, 올바르게 동작하는지 확인 가능.
		PrintStaffId(nt[i].id, rand()%100);
	}

	return 0;
}

void PrintStaffId(int id, int score)
{
	printf("NT");
	if(id>=10000);
	else if(id>=1000) printf("0");
	else if(id>=100) printf("00");
	else if(id>=10) printf("000");
	else printf("0000");
	printf("%d %d\n",id,score);
}