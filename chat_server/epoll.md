## epoll이란?
- 리눅스에서만 호환성을 갖는다.
- select(), poll() 함수에 비해서 파일 디스크립터의 준비 상태를 알리는 방식에서 더 유연성을 갖는다.
- 방식
  LT(Level triggered) | ET(Edge triggered)
  | ---------- | ---------- |
  상태변화를 감지하고자 하는 파일 디스크립터가 준비되면 무조건 알리는 방식 | 항상 새로 준비된 파일 디스크립터에 대해서만 알리는 방식
- epoll() API 함수
  + epoll_create() 함수
      ```cpp
      #include <sys/epoll.h>
      int epoll_create(int size);
      ```
      성공하면 파일 디스크립터를 리턴하고, 에러가 발생하면 -1을 리턴<br>
      매개변수 size에는 감시할 파일 디스크립터의 수를 명시한다.
      
  + epoll_ctl() 함수
      ```cpp
      #include <sys/epoll.h>
      
      int epoll_ctl(int epfd, int op, int fd, struct epoll_event *ev);
      ```
      성공하면 0을 리턴하고, 에러가 발생하면 -1을 리턴<br>
      op 매개변수<br>
      op | 설명
      | ------- | ---------- |
      EPOLL_CTL_ADD | 관심있는 파일디스크립터를 추가
      EPOLL_CTL_MOD | 기존 파일 디스크립터를 수정
      EPOLL_CTL_DEL | 기존 파일 디스크립터를 관심 목록에서 삭제
      
      epoll_event 구조체<br>
      
       ```cpp
        struct epoll_event{
          uint32_t events;  //epoll 이벤트(비트 마스트)
          epoll_data_t data;   //사용자 데이터
        };
        
        typedef union epoll_data{
          void *ptr;   //사용자 정의 데이터 포인터
          int fd;   //파일 디스크립터
          uint32_t u32;
          uint64_t u64;
        }epoll_data_t;
       ```
      
  + epoll_wait() 함수
      ```cpp
      #include <sys/epoll.h>
      
      int epoll_wait(int edfd, struct epoll_event *evlist, int maxevents, int timeout);
      ```
      성공하면 준비된 파일 디스크립터 수 리턴, 타임아웃인 경우 0을 리턴, 에러가 발생하면 -1을 리턴<br>
      준비된 파일 디스크립터를 배열로 리턴한다. maxevents는 리턴한 배열의 갯수이다.<br>
      timeout 값
      timout | 설명
      | --- | ---------- |
      -1 | 
      0 | 
      0보다 큰 값 |
      
      epoll events 필드 가능한 비트 마스크 
      비트 | 입력 | 리턴 | 설명
      | ----- | --- | --- | ---------- |
      EPOLLIN | O | O | 높은 순위 데이터를 제외한 데이터를 읽을 수 있다.
      EPOLLPRI | O | O | 높은 순위 데이터를 읽을 수 있다.
      EPOLLRDHUP | O | O | 상대편 소켓 shutdown 확인
      EPOLLOUT | O | O | 일반 데이터를 기록할 수 있다.
      EPOLLET | O | X | 에지 트리거를 알림 방식으로 선택 (기본은 레벨트리거)
      EPOLLONESHOT | O | X | 이벤트를 알린 후에 이벤트 감시를 비활성화
      EPOLLERR | X | O | 에러가 발생함
      EPOLLHUP | X | O | 행업 발생
  
<br><br>
