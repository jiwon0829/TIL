## 단위 테스트 코드
### 장점
- 단위 테스트는 개발단계 초기에 문제를 발견하게 도와준다.
- 단위 테스트는 개발자가 나중에 코드를 리팩토링하거나 라이브러리 업그레이드 등에서 기존 기능이 올바르게 작동하는지 확인할 수 있다.
- 단위 테스트는 기능에 대한 불확실성을 감소시킬 수 있다.
- 단위 테스트는 시스템에 대한 실제 문서를 제공한다. 즉, 단위 테스트 자체가 문서로 사용할 수 있다.
<br><br><br>
### 테스트 메소드 실행 설정
![](https://images.velog.io/images/hanturtle/post/d60021cd-d9f7-44f1-8a4b-ff99bfc876fc/image.png)<br>
Preferences -> Build, Execution,Deployment -> Build Tools -> Gradle -> **Run tests using : IntelliJ IDEA**
<br><br><br>
### 테스트 코드 작성 예시
#### HelloController.java
```java
@GetMapping("/hello")
public String hello(){
	return "hello";
}

@GetMapping("/hello/dto")
public HelloResponseDto helloResponseDto(@RequestParam("name") String name, @RequestParam("amount") int amount){
	return new HelloResponseDto(name, amount);
}
```
<br><br>
#### HelloResponseDto.java
```java
private final String name;
private final int amount;
```
<br><br>
#### HelloResponseDtoTest.java
```java
@Test
public void 롬북_기능_테스트(){
  //given
  String name = "test";
  int amount = 1000;

  //when
  HelloResponseDto dto = new HelloResponseDto(name, amount);

  //then
  assertThat(dto.getName()).isEqualTo(name);
  assertThat(dto.getAmount()).isEqualTo(amount);
}
```
1. assertThat
	- assertj라는 테스트 검증 라이브러리의 검증 메소드
    - 검증하고 싶은 대상을 메소드 인자로 받음
    - 메소드 체이닝이 지원되어 isEqualTo와 같이 메소드를 이어 사용 가능
2. isEqualTo
	- assertj의 동등 비교 메소드
    - assertThat에 있는 값과 isEqualTo의 값을 비교해서 같을때만 성공
> **Junit vs assertj (assertj의 장점)**<br>- CoreMatchers와 달리 추가적으로 라이브러리가 필요하지 않음<br>- 자동완성이 좀 더 확실하게 지원 됨

<br><br>
#### HelloControllerTest.java
```java
@RunWith(SpringRunner.class)
@WebMvcTest(controllers = HelloController.class)
public class HelloControllerTest {
    @Autowired
    private MockMvc mvc;

    @Test
    public void hello가_리턴된다() throws Exception{
        String hello = "hello";

        mvc.perform(get("/hello")).andExpect(status().isOk()).andExpect(content().string(hello));
    }
    
    @Test
    public void helloDto가_리턴된다() throws Exception{
        String name = "hello";
        int amount = 1000;

        mvc.perform(get("/hello/dto").param("name", name).param("amount", String.valueOf(amount)))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.name", is(name)))
                .andExpect(jsonPath("$.amount", is(amount)));
    }
}
```
1. @RunWith(SpringRunner.class)
	- 테스트를 진행할 때 JUnit에 내장된 실행자 외에 다른 실행자를 실행
    - 여기서는 SpringRunner라는 스프링 실행자를 사용
    - 즉, 스프링 부트 테스트와 JUnit 사이에 연결자 역할을 함
2. @WebMvcTest(controllers = HelloController.class)
	- @Controller, @ControllerAdvice 등을 사용 가능
    - @Service, @Component, @Repository 등은 사용 불가
3. @Autowired
	- 스프링이 관리하는 Bean(스프링 컨테이너가 생성한 객체들)을 주입받는다.
4. private MockMvc mvc
	- 웹 API를 테스트할 때 사용
    - 스프링 MVC 테스트의 시작점
    - 이 클래스를 통해 HTTP, GET, POST 등에 대한 API 테스트를 할 수 있음
5. mvc.perform(get("/hello"))
	- MockMvc를 통해 /hello 주소로 HTTP GET 요청을 함
    - 체이닝이 지원되어 아래와 같이 여러 검증 기능을 이어서 선언 가능
6. .andExpect(status().isOk())
	- mvc.perform의 결과를 검증
    - HTTP Header의 Status를 검증
    - OK(200)인지 아닌지 상태 검증
7. .andExpect(content().string(hello))
	- mvc.perform의 결과를 검증
    - 응답 본문의 내용 검증
8. param
	- API 테스트할 때 사용될 요청 피라미터를 설정
    - 값은 String만 허용
9. jsonPath
	- JSON 응답값을 필드별로 검증할 수 있는 메소드
    - $를 기준으로 필드명을 명시
<br><br><br>
> 참고 도서 : 스프링부트와 AWS로 혼자 구현하는 웹 서비스
<br><br>
