#include <stdio.h>

int main() {
	int C[5][5];

	int v = 1;
	int S = -1; //스위치 변수, 행과 열 증감 관리(방향)
	int r = 2; //행 인덱스
	int c = 2; //열 인덱스
	int k = 1; //방향 바꿔주는 키. k만큼 전진하고 방향 바꿈

	C[r][c] = v;
	v++;

	while (1) {

		for (int i = 0; i < k; i++) {
			r += S;
			if (r == -1) break; //k가 5까지 증가함 -> 5번 반복하면 D[-1][0]에 접근하게 되므로 4번만 반복하기 위해 브레이크

			C[r][c] = v;
			v++;
		}

		S = -S;

		if (k > 4) 	break;  //k가 5가 되면 브레이크

		for (int i = 0; i < k; i++) {
			c += S;
			C[r][c] = v;
			v++;
		}

		k++;
	}

	//배열 출력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d\t", C[i][j]);
		}
		printf("\n");
	}


	return 0;
}
