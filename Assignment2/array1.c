#include <stdio.h>

int main() {

	int A[5][5];
	int iR = 0, iC = 0, v = 1; //iR 초기 행 번호, iC 초기 열 번호(행과 열의 증감 기준) v배열에 저장할 값
	int R, C; //배열의 인덱스, 초기 행/열 번호와 비교해서 반복문 종료

	/*=====================*/
	/*=====배열 채우기=====*/
	/*=====================*/
	//n행 1열에서 시작하는 숫자들(5행 제외)
	//v=1~10까지 배열에 저장
	for (iR = 0; iR < 4; iR++) { //iR은 0~3까지 1씩 증가
		R = iR; //행을 초기행으로 초기화
		C = iC; //열을 초기열로 초기화
		for (R = iR; R >= 0; R--) { //R은 초기행부터 0까지 1씩 감소. 반복할 때마다 반복 횟수가 늘어난다
			A[R][C] = v;
			v++;
			C++;
		}
	}

	//배열 초기화 5행부터 시작하는 것들
	//v=11~25까지배열에 저장
	for (iC = 0; iC < 5; iC++) { //iC는 0부터 4까지 반복 (0열~4열)
		R = iR;
		C = iC;
		for (C = iC; C <= iR; C++) { //C는 초기열부터 초기행까지 1씩 증가, 반복할 때마다 반복 횟수가 줄어든다
			A[R][C] = v;
			v++;
			R--;
		}
	}


	/*=====================*/
	/*======배열 출력======*/
	/*=====================*/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}

	return 0;

}
