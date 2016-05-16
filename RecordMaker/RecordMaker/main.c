/**
 ** �����ȣ�� ������ ����ϴ� ���α׷�
 ** 2016, KimYihyun
 ** ����ȯ�� : vs2010
 ** ����� : ������, cmd.exe ���� -> cd [�������� ��ġ] -> RecordMaker.exe [0~99999]  (��:RecordMaker.exe 1234)
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXMEMBER 100000

typedef struct{		// ��� ���� ����ü.
	int id;
	int score;
}NTinfo;
int staff[MAXMEMBER]={0,}; // ��� 1~99999
int cache[MAXMEMBER]={0,}; // �ߺ� üũ��.
int index = MAXMEMBER - 1; // ���� ������� ��.

void PrintStaffId(int id, int score); // ���id ���

int main(int argc, char *argv[])
{
	int i,j,k;
	int count;		//����� �Է¹޴� [count]
	int myRandom;	//time�� seed�� ������ �����Լ��� ������ �������̹Ƿ�, 2���� rand()�� �̿��Ͽ� ������ ����. 
	NTinfo nt[MAXMEMBER]; //��ȸ�� ������� ��� ���� ����ü�� ����.
	srand((unsigned int)time(NULL));
	
	// Get argument vector
	if(argc<2){
		printf("���ڸ� �Է��� �ּ��� : ");
		scanf("%d",&count);
	}else{
		count = atoi(argv[1]);
	}

	// Exception handling
	if(count>=MAXMEMBER || count<0){
		printf("�Էµ� ���ڰ� �ùٸ��� �ʽ��ϴ�. (0~99999)\n");
		return 0;
	}

	// Preprocessing
	index = MAXMEMBER - 1;
	for(i=1; i<MAXMEMBER; i++){
		staff[i]=i;
	}

	for(i=1; i<=count; i++){
		myRandom = (rand()%1001)*100 + (rand()%100); // 0 ~ 100000 ���� ����
		nt[i].id = myRandom%index + 1;				 // ���� index��ŭ�� ������ ����
		
		// �湮�� index�� cache�� ���� üũ�ϰ�, �湮���� ���� ����� id ���.
		// '�����佺�׳׽��� ü'�� ������ �˰���.
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
		//if(nt[i].id <= 10) // �ּ��� �����Ͽ� ������ �����ϸ�, �ùٸ��� �����ϴ��� Ȯ�� ����.
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