// 연결리스트.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
using namespace std;

struct NODE
{
	int data; //데이터
	NODE *link; //링크 
};

void INSERT(NODE *prev, int data)
{
	// 삽입 노드 생성
	NODE *InsNode = NULL;
	InsNode = (NODE *)malloc(sizeof(NODE));
	InsNode->data = data;

	// 이전 노드의 링크를 저장
	InsNode->link = prev->link;

	// 이전 노드의 링크에 삽입 노드 주소를 저장
	prev->link = InsNode;
}

void Delete(NODE *prev)
{
	// 삭제 노드
	NODE *DelNode = prev->link;

	// 삭제 노드 링크를 저장
	prev->link = DelNode->link;

	// 삭제 노드를 메모리에서 삭제
	free(DelNode);

}

void TRAVERSE(NODE *pointer)
{
	// 데이터를 출력
	printf("%d", pointer->data);

	// 다음 노드 있으면 재귀 호출
	if (pointer->link != NULL)
		TRAVERSE(pointer->link);

}

int main()
{
	NODE *head = NULL, *prev = NULL;
	head = (NODE *)malloc(sizeof(NODE));
	head->data = 0;
	head->link = NULL;

	prev = head;
	INSERT(prev, 10);
	prev = prev->link;
	INSERT(prev, 20);
	prev = prev->link;
	INSERT(prev, 40);

	printf("리스트 출력:");
	TRAVERSE(head->link);
	printf("\n");

	printf("30 삽입 후 리스트 출력:");
	INSERT(prev, 30);
	TRAVERSE(head->link);
	printf("\n");

	printf("30 삭제 후 리스트 출력:");
	Delete(prev);
	TRAVERSE(head->link);
	printf("\n");

	while (true)
	{
		int user;
		cout << "\n1.입력\n2.제거\n사용하실 메뉴를 입력하시오." << endl;
		cin >> user;
		switch (user)
		{
		case 1:cout << "숫자 입력" << endl;
			cin >> user;
			INSERT(prev, user); TRAVERSE(head->link); break;
		case 2:cout << "숫자 제거" << endl; Delete(prev); TRAVERSE(head->link); break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

