#include <stdio.h>

// ==============================================
// 양수 10진수의 변환
// ==============================================

//10진수 -> 2진수 변환
int* DecToBin(int A) { //함수의 매개변수 타입이 int이지만 input은 long long 타입이다
						//하지만 input이 32비트 범위 내이기 때문에 데이터가 손실되지 않음
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


//10진수 -> 8진수 변환
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


//10진수 -> 16진수 변환
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
// 음수 10진수의 변환
// ==============================================

//10진수 -> 2진수 변환
int* NDecToBin(int A) {
	int* Bin;
	int O[32];
	static int T[32];
	int i;
	int c;

	//10진수 -> 2진수 변환
	Bin = DecToBin(A); 

	//1의 보수
	for (i = 0; i < 32; i++) {
		O[i] = 1 - Bin[i];	
	}

	c = 1; //캐리
	for (i = 0; i < 32; i++) { //1 더해서 2의 보수 취하기. 최하위 비트는 Bin[0], O[0], T[0]임, 프린트 할 때 역순으로 하는 이유
		T[i] = 1;
		if (O[i] == c)
			T[i] = 0;
		c *= O[i];
	}

	return T;

}

//10진수 -> 8진수 변환
int* NDecToOct(int A) {
	int* Bin; //2의 보수 저장
	static int Oct[11] = { 0, };
	int i;
	int I = 0;
	int value;

	//10진수 -> 2의 보수
	Bin = NDecToBin(A); 

	//2의 보수 3자리 -> 8진수 한 자리로 바꾸기
	for (i = 0; i < 30; i += 3) { 
		value = Bin[i + 2] * 4 + Bin[i + 1] * 2 + Bin[i] * 1;
		Oct[I] = value;
		I++;
	}

	//32비트이기 때문에 마지막 두 비트는 따로 저장
	value = Bin[31] * 2 + Bin[30] * 1; 
	Oct[I] = value;

	return Oct;
}

//10진수 -> 16진수 변환
char* NDecToHex(int A) {
	static char Hex[8] = { '0', '0', '0', '0', '0', '0', '0', '0' };
	char value[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	int* Bin;
	int v;
	int I = 0;

	//2의 보수 받아오기
	Bin = NDecToBin(A);

	//2의 보수 4 자리 -> 16진수 한 자리
	for (int i = 0; i < 32; i += 4) {
		v = Bin[i + 3] * 8 + Bin[i + 2] * 4 + Bin[i + 1] * 2 + Bin[i] * 1;
		Hex[I] = value[v];
		I++;

	}

	return Hex;
}

// ==============================================
// 2진수, 8진수, 16진수 출력 함수
// ==============================================

void printBin(int* bin) {
	printf("2진수 : ");
	for (int i = 31; i >= 0; i--) {
		printf("%d", bin[i]);
		if (i % 4 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}

void printOct(int* oct) {
	printf("8진수 : ");
	for (int i = 10; i >= 0; i--) {
		printf("%d", oct[i]);
		if (i % 3 == 0)
			printf(" ");
	}
	printf("\n");
}

void printHex(char* hex) {
	printf("16진수 : ");
	for (int i = 7; i >= 0; i--) {
		printf("%c", hex[i]);
		if (i % 2 == 0)
			printf(" ");
	}
	printf("\n");
}


// ==============================================
// 메인 함수
// ==============================================
int main(void) {
	long long input;
	int min = -2147483647;  //min을 -2147483647로 선언한 이유 : 단항 연산자 -는 양수를 음수로 바꾸는 것.
							//양수의 최대 표현 범위는 2147483647이기 때문에
							//2147483648을 음수로 바꾸려고 하면 오류가 나기 때문에 후에 1을 감소 시킴
	int max = 2147483647;
	int* bin;
	char* hex;
	int* oct;

	min--; //min 1 감소

	printf("==2진수, 8진수, 16진수 변환기==\n\n");

	printf("정수를 입력하세요 : ");
	scanf("%lld", &input);

	if (input > max || input < min) {
		printf("표현 범위를 넘어선 숫자입니다\n");
	}
	else {
		
		printf("\n%lld의 변환 값은\n", input);

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

