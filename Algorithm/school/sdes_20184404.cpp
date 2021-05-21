#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define BYTE unsigned char

BYTE *Key, P10[10] = { '2', '4', '1', '6', '3', '9', '0', '8', '7', '5' },
		*KeyP10, P8[8] = { '5', '2', '6', '3', '7', '4', '9', '8' }, IP[8] = {
				'1', '5', '2', '0', '3', '7', '4', '6' }, IP_1[8] = { '3', '0',
				'2', '4', '6', '1', '7', '5' }, EP[8] = { '3', '0', '1', '2',
				'1', '2', '3', '0' }, S0[4][4] = { '1', '0', '3', '2', '3', '2',
				'1', '0', '0', '2', '1', '3', '3', '1', '3', '2' }, S1[4][4] = {
				'0', '1', '2', '3', '2', '0', '1', '3', '3', '0', '1', '0', '2',
				'1', '0', '3' }, P4[4] = { '1', '3', '2', '0' }, *result;


void Half(BYTE*, BYTE*, BYTE*);
void Fk(BYTE*, BYTE*, BYTE*);


int main() {

	//key input
	cout << ">>>S-DES<<<" << endl << "키 값을 입력하세요(10Bit)";
	Key = new BYTE[10];
	for (int i = 0; i < 10; i++)
		cin >> Key[i];
	cout<<"key : ";
	for (int i = 0; i < 10; i++)  //check_ok
		cout << Key[i] << " ";
	cout << endl;

	//plaintext input
	BYTE plaintext[8];
	cout << "평문을 입력하세요(8bit)";
	for (int i = 0; i < 8; i++)
		cin >> plaintext[i];
	cout<<"plaintext : ";
	for (int i = 0; i < 8; i++)   //check_ok
		cout << plaintext[i] << " ";
	cout<<endl<<"------------------------------";
	cout <<endl<<endl<<"키를 생성하겠습니다"<<endl;

	//Key -> KeyP10 change
	KeyP10 = new BYTE[10];
	memcpy(KeyP10, Key, sizeof(char) * 10);
	/*cout << "KeyP10 : ";   //check_ok
	for (int i = 0; i < 10; i++)
		cout << KeyP10[i] << " ";
	cout << endl;*/

	for (int i = 0; i < 10; i++) {
		int tmp = P10[i] - '0';
		//cout<<tmp;   //check_ok
		Key[i] = KeyP10[tmp];
	}

	cout << "Key -> P10 : ";   //check_ok
	for (int i = 0; i < 10; i++)
		cout << Key[i] << " ";
	cout << endl;

	//Shift 1bit : Key -> KeyP10
	for (int i = 0; i < 10; i++) {
		if (i == 0)
			KeyP10[4] = Key[i];
		else if (i == 5)
			KeyP10[9] = Key[i];
		else
			KeyP10[i - 1] = Key[i];
	}
	cout << "Shift 1bit : ";   //check_ok
	for (int i = 0; i < 10; i++)
		cout << KeyP10[i] << " ";
	cout << endl;

	//create K1 : 10bit Key10 -> 8bit K1
	BYTE * K1;
	K1 = new BYTE[8];
	for (int i = 0; i < 8; i++) {
		int tmp = P8[i] - '0';
		K1[i] = KeyP10[tmp];
	}


	//Shift 2bit : KeyP10 -> Key
	for (int i = 9; i >= 0; i--) {
		if (i == 6)
			Key[9] = KeyP10[i];
		else if (i == 5)
			Key[8] = KeyP10[i];
		else if (i == 1)
			Key[4] = KeyP10[i];
		else if (i == 0)
			Key[3] = KeyP10[i];
		else {
			Key[i - 2] = KeyP10[i];
		}
	}
	cout << "Shift 2bit : ";   //check_ok
	for (int i = 0; i < 10; i++)
		cout << Key[i] << " ";
	cout << endl;

	cout << "K1 : ";   //check_ok
	for (int i = 0; i < 8; i++)
		cout << K1[i] << " ";
	cout << endl;

	//create K2 : 10bit Key -> 8bit K2
	BYTE * K2;
	K2 = new BYTE[10];
	cout << "K2 : ";
	for (int i = 0; i < 8; i++) {
		int tmp = P8[i] - '0';
		K2[i] = Key[tmp];
		cout << K2[i] << " "; //check_ok
	}
	cout << endl;
	cout<<"------------------------------"<<endl<<endl<<"암호화하겠습니다"<<endl;
	//plaintext -> IP
	BYTE *iptext;
	iptext = new BYTE[8];
	cout << "IP text : ";
	for (int i = 0; i < 8; i++) {
		int tmp = IP[i] - '0';
		iptext[i] = plaintext[tmp];
		cout << iptext[i] << " ";   //check_ok
	}
	cout << endl;

	//half : right, left
	BYTE *right, *left;
	right = new BYTE[4];
	left = new BYTE[4];

	//Fk1
	cout<<"-------------Fk1-------------"<<endl;
	Half(iptext, left, right);
	Fk(left,right,K1);


	BYTE SW[8];
	for(int i=0;i<4;i++){
		SW[i] = right[i];
		SW[i+4] = result[i];
	}
	cout<<"SW : ";
	for(int i=0;i<8;i++)
		cout<<SW[i]<<" ";
	cout<<endl;

	//Fk2
	cout<<"-------------Fk2-------------"<<endl;
	Half(SW,left,right);
	Fk(left,right,K2);

	for(int i=0;i<4;i++){
		SW[i] = result[i];
		SW[i+4] = right[i];
	}
	cout<<"------------------------------"<<endl;
	cout<<"SW : ";
	for(int i=0;i<8;i++)
		cout<<SW[i]<<" ";
	cout<<endl;


	//IP-1
	cout<<"cryptogram : ";
	BYTE cryptogram[8];
	//memcpy(cryptogram, SW, sizeof(char) * 10);
	for(int i=0;i<8;i++){
		int tmp = IP_1[i]-'0';
		cryptogram[i] = SW[tmp];
		cout<<cryptogram[i]<<" ";
	}
	cout<<endl;

	//복호화
	//cryptogram->IP
	cout<<"------------------------------"<<endl<<endl<<"복호화하겠습니다"<<endl;
		BYTE * ipc;
		ipc = new BYTE[8];
		cout << "IP text : ";
		for (int i = 0; i < 8; i++) {
			int tmp = IP[i] - '0';
			ipc[i] = cryptogram[tmp];
			cout << ipc[i] << " ";   //check_ok
		}
		cout << endl;

		//Fk1
		cout<<"-------------Fk2-------------"<<endl;
		Half(ipc, left, right);
		Fk(left,right,K2);


		for(int i=0;i<4;i++){
			SW[i] = right[i];
			SW[i+4] = result[i];
		}
		cout<<"SW : ";
		for(int i=0;i<8;i++)
			cout<<SW[i]<<" ";
		cout<<endl;

		//Fk2
		cout<<"-------------Fk1-------------"<<endl;
		Half(SW,left,right);
		Fk(left,right,K1);

		cout<<"------------------------------"<<endl;
		cout<<"SW : ";
		for(int i=0;i<4;i++){
			SW[i] = result[i];
			SW[i+4] = right[i];
		}
		for(int i=0;i<8;i++)
			cout<<SW[i]<<" ";
		cout<<endl;


		//IP-1
		cout<<"plaintext : ";
		BYTE plaintext2[8];
		//memcpy(cryptogram, SW, sizeof(char) * 10);
		for(int i=0;i<8;i++){
			int tmp = IP_1[i]-'0';
			plaintext2[i] = SW[tmp];
			cout<<plaintext2[i]<<" ";
		}
		cout<<endl;




}

void Half(BYTE* str, BYTE* left, BYTE* right) {   //check_ok
	for(int i=0;i<4;i++) {
		left[i] = str[i];
		right[i] = str[i+4];
	}
}

void Fk(BYTE* left, BYTE* right, BYTE* K){
	// E/P
	BYTE eptext[8];
	cout<<"EP : ";
	for(int i=0;i<8;i++){
		int tmp = EP[i]-'0';
		eptext[i] = right[tmp];
		cout<<eptext[i]<<" ";   //check_ok
	}
	cout<<endl;

	//XOR => K, eptext
	BYTE Xor[8];
	for(int i=0;i<8;i++){
		if(K[i]=='0' && eptext[i]=='0')
			Xor[i] = '0';
		else if(K[i]=='1' && eptext[i]=='1')
			Xor[i] ='0';
		else
			Xor[i]='1';
	}
	cout<<"Xor : ";   //check_ok
	for(int i=0;i<8;i++)
		cout<<Xor[i]<<" ";
	cout<<endl;

	//S-box
	int line, row;   //행, 열
	int a = Xor[0]-'0';
	int b = Xor[3]-'0';
	line = (2*a) + b;
	cout<<"line ("<<a<<","<<b<<") = "<<line<<endl;   //check_ok
	a = Xor[1]-'0';
	b = Xor[2]-'0';
	row  = (2*a) + b;
	cout<<"row ("<<a<<","<<b<<") = "<<row;  ///check_ok
	BYTE s0 = S0[line][row];
	cout<<endl<<"s0 : "<<s0<<endl;   //check_ok

	a = Xor[4]-'0';
	b = Xor[7]-'0';
	line = (2*a) + b;
	cout<<"line ("<<a<<","<<b<<") = "<<line<<endl;   //check_ok
	a = Xor[5]-'0';
	b = Xor[6]-'0';
	row  = (2*a) + b;
	cout<<"row ("<<a<<","<<b<<") = "<<row;  ///check_ok
	BYTE s1 = S1[line][row];
	cout<<endl<<"s1 : "<<s1<<endl;   //check_ok

	BYTE s[4];
	if(s0 == '0'){
		s[0]='0';
		s[1]='0';
	}
	else if(s0=='1'){
		s[0]='0';
		s[1]='1';
	}
	else if(s0=='2'){
		s[0]='1';
		s[1]='0';
	}
	else if(s0 =='3'){
		s[0]='1';
		s[1]='1';
	}

	if(s1 == '0'){
		s[2]='0';
		s[3]='0';
	}
	else if(s1=='1'){
		s[2]='0';
		s[3]='1';
	}
	else if(s1=='2'){
		s[2]='1';
		s[3]='0';
	}
	else if(s1 =='3'){
		s[2]='1';
		s[3]='1';
	}


	cout<<"s : ";   //check_ok
	for(int i=0;i<4;i++)
		cout<<s[i]<<" ";
	cout<<endl;

	//s->p4
	BYTE p4text[4];
	for(int i=0;i<4;i++){
		int tmp = P4[i]-'0';
		p4text[i] = s[tmp];
	}
	cout<<"p4 : ";   //check_ok
	for(int i=0;i<4;i++)
		cout<<p4text[i]<<" ";
	cout<<endl;


	//result : xor(p4text,left)
	result = new BYTE[4];
	cout<<"result : ";   //check_ok
	for(int i=0;i<4;i++){
		if( p4text[i]=='0' && left[i]=='0')
			result[i] = '0';
		else if(p4text[i]=='1' && left[i]=='1')
			result[i] = '0';
		else
			result[i] = '1';
	cout<<result[i]<<" ";
	}
	cout<<endl;
}
