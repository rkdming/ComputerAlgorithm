#include <stdio.h>

int main() {
	int C[5][5];

	int v = 1;
	int S = -1; //����ġ ����, ��� �� ���� ����(����)
	int r = 2; //�� �ε���
	int c = 2; //�� �ε���
	int k = 1; //���� �ٲ��ִ� Ű. k��ŭ �����ϰ� ���� �ٲ�

	C[r][c] = v;
	v++;

	while (1) {

		for (int i = 0; i < k; i++) {
			r += S;
			if (r == -1) break; //k�� 5���� ������ -> 5�� �ݺ��ϸ� D[-1][0]�� �����ϰ� �ǹǷ� 4���� �ݺ��ϱ� ���� �극��ũ

			C[r][c] = v;
			v++;
		}

		S = -S;

		if (k > 4) 	break;  //k�� 5�� �Ǹ� �극��ũ

		for (int i = 0; i < k; i++) {
			c += S;
			C[r][c] = v;
			v++;
		}

		k++;
	}

	//�迭 ���
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d\t", C[i][j]);
		}
		printf("\n");
	}


	return 0;
}
