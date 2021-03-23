# Bitset(비트셋)이란?
- 클래스 템플릿은 일련의 항목 또는 조건에 대한 플래그를 유지하는 간단한 방법을 제공하는 고정 된 비트 수로 구성 된 시퀀스를 저장하는 개체의 형식을 설명한다. 
- 채워지는 것은 true로 1이며, 채워지지 않는 것은 false이며 0이다. 
- 일반적으로 각 요소는 1bit만 차지한다.
- bitset의 크기는 컴파일 타임에 고정된다. 따라서, 공간 할당을 최적화하고 동적 크기 조정을 허용하는 클래스의 경우 vector<bool> 사용을 고려하자
<br><br>
## 사용법
  | 설명
---------- | ------------------------------ 
헤더파일 | #include <bitset> 
선언 | bitset<할당할 비트 수> 변수명 
[n] | 인덴스 n 비트가 0인지 1인지 검사 
count | bitset 중에서 1인 비트의 개수를 반환 
size | bitset의 크기를 반환 
test | 비트 값 반환 
any | bitset 중 하나라도 1이면 1(true)을 반환, 모두 0이면 0(false)을 반환 
none | bitset 중 1이 하나도 없다면 none, 모두 0이면 1(true)을 반환 
all | 모든 비트가 1이면 1(true), 그렇지 않으면 0(false)을 반환 
set | 전체 비트를 1로 세팅 
reset | 전체 비트를 0으로 리셋 
flip | 전체 비트 토글. (0은 1로, 1은 0으로) 
to_string() | 전체 비트를 string화 시킨다 
to_ulong() | 전체 비트를 unsigned long의 값으로 바꾼다 
to_ullong() | 전체 비트를 unsigned long long 값으로 바꾼다 
operator&=<br>operator|=<br>operator^=<br>operator~ | AND, OR, XOR, NOT 비트 연산을 수행 
operator<<=<br>operator>>=<br>operator<<<br>operator>> | left, right shift 연산을 수행 
  
  
<br><br>
  
- 자세한 예제는 Microsoft-bitset 링크를 누르면 확인할 수 있음
  
> 참고 사이트 : [Microsoft-bitset](https://docs.microsoft.com/ko-kr/cpp/standard-library/bitset?view=msvc-160), [cplusplus-bitset](http://www.cplusplus.com/reference/bitset/bitset/)  
  

