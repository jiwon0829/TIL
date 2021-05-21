#include <stdio.h>
#include <math.h>

/*20164385 컴퓨터공학과 오영우
  20164404 컴퓨터공학과 한지원 */

int EEA(int a, int b);

int main() {
	int p = 29;
	int q = 31;
	int e = 571;
	int m = 115;   //데이터

	printf(">>RSA 알고리즘 <<\n");
	printf("p = %d, q = %d, e = %d의 값을 갖고있다.\n\n", p, q, e);
	printf("B는 공개키와 개인키를 생성한다.\n");
	//n 구하기   n = p * q
	int n = p * q;
	printf("n : %d\n", n);

	//d 구하기   (e * d) mod Φ(n) = 1
	int d;
	int pi = (p - 1) * (q - 1);   //Φ(n) = (p-1) * (q-1)
	printf("pi : %d\n", pi);
	/*for (int i = 2; i < pi; i++) {   //확장 유클리드 호제법 사용하지 않은 소스
	 if ((e * i) % pi == 1)
	 d = i;
	 }*/
	d = EEA(e, pi);   //확장 유클리드 호제법 사용

	printf("d : %d\n\n", d);

	printf("공개키 = (%d, %d), 개인키 = (%d, %d)\n", n, e, n, d);
	printf("B는 공개키를 A에게 준다.\n\n");
	//암호화
	//라이브러리 함수 사용하면 주석 문장과 같음
	//long long C = ((long long)pow(m, e) % n);
	//printf("암호문 : %lld\n", C);
	int C = 1;
	for (int i = 0; i < e; i++) {
		C *= m;
		C %= n;
	}
	printf("A가 암호화할 데이터 : %d\n", m);
	printf("암호문 : %d\n", C);

	//복호화
	//long long M = ((long long) pow(C, d) % n);
	//printf("복호문 : %lld\n", M);
	int M = 1;
	for (int i = 0; i < d; i++) {
		M *= C;
		M %= n;
	}
	printf("암호문을 받은 B가 해독한다.\n\n");
	printf("복호문 : %d", M);
}

int EEA(int a, int b) {
	printf("\n>>확장 유클리드 호제법 <<\n");
	int tmpa = a, tmpb = b;  //ab 받는거
	int acnt = 1, acnt1 = 0;   //a의 개수를 저장하는 값
	int bcnt = 0, bcnt1 = 1;   //b의 개수를 저장하는 값
	int tmp = 0, c = 0, cnt =0;
	while (tmpb) {
		if (cnt)
			printf("(x = %5d,  y = %5d) -> %5d = ", bcnt1, acnt1, tmpa);

		c = tmpa / tmpb;
		tmp = tmpa;
		tmpa = tmpb;
		tmpb = tmp - tmpb * c;
		tmp = acnt;
		acnt = acnt1;
		acnt1 = tmp - acnt1 * c;
		tmp = bcnt;
		bcnt = bcnt1;
		bcnt1 = tmp - bcnt1 * c;
		if (cnt)
			printf("%5d * %5d + %5d\n", c, tmpa, tmpb);
		cnt++;

	}
	printf("\n>>확장 유클리드 호제법 결과<<\n");
	printf("(x = %5d, y = %5d) -> %5d = %5d * %5d + %5d * %5d\n", bcnt, acnt, tmpa, b, bcnt,bcnt1, acnt);

	return acnt;
}
