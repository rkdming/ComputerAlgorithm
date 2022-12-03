#include <stdio.h>

// ==============================================
// ��� 10������ ��ȯ
// ==============================================

//10���� -> 2���� ��ȯ
int* DecToBin(int A) { //�Լ��� �Ű����� Ÿ���� int������ input�� long long Ÿ���̴�
						//������ input�� 32��Ʈ ���� ���̱� ������ �����Ͱ� �սǵ��� ����
	static int Bin[32] = { 0, };
	int i;
	if (A > 0) {
		for (i = 0; A != 0; i++) {
			Bin[i] = A % 2;
				A = A / 2;
		}
		
	}
	
	return Bin;
}


//10���� -> 8���� ��ȯ
int* DecToOct(int A) {
	static int Oct[11] = { 0, };
	int i = 0;
	int R = 0;

	while (1) {
		R = A % 8;
		Oct[i] = R;
		i++;
		A = A / 8;
		if (A == 0)
			break;
	}
	
	return Oct;
}


//10���� -> 16���� ��ȯ
char* DecToHex(int A) {
	static char Hex[8] = { '0', '0', '0', '0', '0', '0', '0', '0' };
	char value[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	int i = 0;
	int R = 0;

	while (1) {
		R = A % 16;
		Hex[i] = value[R];
		A = A / 16;
		i++;
		if (A == 0)
			break;
	}


	return Hex;
}

// ==============================================
// ���� 10������ ��ȯ
// ==============================================

//10���� -> 2���� ��ȯ
int* NDecToBin(int A) {
	int* Bin;
	int O[32];
	static int T[32];
	int i;
	int c;

	//10���� -> 2���� ��ȯ
	Bin = DecToBin(A); 

	//1�� ����
	for (i = 0; i < 32; i++) {
		O[i] = 1 - Bin[i];	
	}

	c = 1; //ĳ��
	for (i = 0; i < 32; i++) { //1 ���ؼ� 2�� ���� ���ϱ�. ������ ��Ʈ�� Bin[0], O[0], T[0]��, ����Ʈ �� �� �������� �ϴ� ����
		T[i] = 1;
		if (O[i] == c)
			T[i] = 0;
		c *= O[i];
	}

	return T;

}

//10���� -> 8���� ��ȯ
int* NDecToOct(int A) {
	int* Bin; //2�� ���� ����
	static int Oct[11] = { 0, };
	int i;
	int I = 0;
	int value;

	//10���� -> 2�� ����
	Bin = NDecToBin(A); 

	//2�� ���� 3�ڸ� -> 8���� �� �ڸ��� �ٲٱ�
	for (i = 0; i < 30; i += 3) { 
		value = Bin[i + 2] * 4 + Bin[i + 1] * 2 + Bin[i] * 1;
		Oct[I] = value;
		I++;
	}

	//32��Ʈ�̱� ������ ������ �� ��Ʈ�� ���� ����
	value = Bin[31] * 2 + Bin[30] * 1; 
	Oct[I] = value;

	return Oct;
}

//10���� -> 16���� ��ȯ
char* NDecToHex(int A) {
	static char Hex[8] = { '0', '0', '0', '0', '0', '0', '0', '0' };
	char value[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	int* Bin;
	int v;
	int I = 0;

	//2�� ���� �޾ƿ���
	Bin = NDecToBin(A);

	//2�� ���� 4 �ڸ� -> 16���� �� �ڸ�
	for (int i = 0; i < 32; i += 4) {
		v = Bin[i + 3] * 8 + Bin[i + 2] * 4 + Bin[i + 1] * 2 + Bin[i] * 1;
		Hex[I] = value[v];
		I++;

	}

	return Hex;
}

// ==============================================
// 2����, 8����, 16���� ��� �Լ�
// ==============================================

void printBin(int* bin) {
	printf("2���� : ");
	for (int i = 31; i >= 0; i--) {
		printf("%d", bin[i]);
		if (i % 4 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}

void printOct(int* oct) {
	printf("8���� : ");
	for (int i = 10; i >= 0; i--) {
		printf("%d", oct[i]);
		if (i % 3 == 0)
			printf(" ");
	}
	printf("\n");
}

void printHex(char* hex) {
	printf("16���� : ");
	for (int i = 7; i >= 0; i--) {
		printf("%c", hex[i]);
		if (i % 2 == 0)
			printf(" ");
	}
	printf("\n");
}


// ==============================================
// ���� �Լ�
// ==============================================
int main(void) {
	long long input;
	int min = -2147483647;  //min�� -2147483647�� ������ ���� : ���� ������ -�� ����� ������ �ٲٴ� ��.
							//����� �ִ� ǥ�� ������ 2147483647�̱� ������
							//2147483648�� ������ �ٲٷ��� �ϸ� ������ ���� ������ �Ŀ� 1�� ���� ��Ŵ
	int max = 2147483647;
	int* bin;
	char* hex;
	int* oct;

	min--; //min 1 ����

	printf("==2����, 8����, 16���� ��ȯ��==\n\n");

	printf("������ �Է��ϼ��� : ");
	scanf("%lld", &input);

	if (input > max || input < min) {
		printf("ǥ�� ������ �Ѿ �����Դϴ�\n");
	}
	else {
		
		printf("\n%lld�� ��ȯ ����\n", input);

		if (input >= 0) {
			
			bin = DecToBin(input);
			
			oct = DecToOct(input);
			
			hex = DecToHex(input);
			
		}
		else {
			
			input = -input;

			bin = NDecToBin(input);
			
			oct = NDecToOct(input);
			
			hex = NDecToHex(input);
			
		}

		printBin(bin);
		printOct(oct);
		printHex(hex);
		
	}

	return 0;
}

