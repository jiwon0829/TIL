## [Room](https://developer.android.com/training/data-storage/room?hl=ko), 로컬 데이터베이스
Room은 SQLite에 대한 추상화 레이어를 제공하여 원활한 데이터베이스 액세스를 지원하는 동시에 SQLite를 완벽히 활용한다.

<br><br>
### Room 아키텍처 다이어그램
![](https://images.velog.io/images/hanturtle/post/36cb5dc4-c0ad-414b-ac5e-11e4f519bb1f/image.png)<br>
**1. Entity**
데이터베이스 내의 테이블<br>
**2. Data Access Object**
데이터베이스에 액세스하는 데 사용되는 메서드가 포함<br>
**3. Room Database**
데이터베이스 홀더를 포함하며 앱의 지속적인 관계형 데이터의 기본 연결을 위한 기본 액세스 포인트 역할을 함


<br><br>
### build.gradle 파일 설정
build.gradle(Module:)
```java
dependencies {
    def room_version = "2.3.0"
    implementation "androidx.room:room-runtime:$room_version"
    annotationProcessor "androidx.room:room-compiler:$room_version"
}
```
<br><br>
### Entity 정의하기
- 모든 Entity에는 적어도 1개 이상의 PrimaryKey가 필수이다.
- @PrimaryKey(autoGenerate = true)를 사용할 시, 해당 피라미터는 0으로 넣어야 자동 생성 된다.
- @ColumnInfo은 각 속성의 이름을 변수의 이름과 상관없이 임의로 지정할 수 있도록 도와주는 것이다.
```java
@Entity
public class User {
    @PrimaryKey(autoGenerate = true)
    private int id;
    private String name;

    public User(String name){
        this.name = name;
    }


    public void setId(int id){
        this.id = id;
    }
    public int getId(){
        return id;
    }


    public void setName(String name){
        this.name = name;
    }
    public String getName(){
        return name;
    }
```
<br><br>
### DAO 정의하기
- DAO의 함수들은 기본적으로 synchronous하게 동작하지만 Single, LiveData, suspend 등의 키워드를 사용할 시에는 asynchronous하게 동작한다.
- DAO는 interface나 abstract class로 선언이 가능하므로, 구현이 들어간 함수가 필요한 경우에는 abstract class로 정의해서 사용하면 편리하다.
```java
@Dao
public interface UserDAO {
    @Query("SELECT * FROM User")
    LiveData<List<User>>getAll();

    @Query("SELECT * FROM User WHERE id = :mID")
    User getData(int mID);

    @Insert
    void insert(User user);

    @Delete
    void delete(User user);

    @Query("UPDATE User SET name = :mName WHERE id = :mId")
    void dataUpdate(int mId, String mName);

    @Query("DELETE FROM User")
    void clearAll();
}
```
<br><br>
### Database 정의하기
- RoomDatabase를 확장하는 추상 클래스여야한다.
- 주석 내에 데이터베이스와 연결된 항목의 목록을 포함해야한다.
- 인수가 0개이며 @Dao로 주석이 지정된 클래스를 반환하는 추상 메서드를 포함해야한다.
```java
@Database(entities = {User.class}, version = 1, exportSchema = false)
public abstract class UserDB extends RoomDatabase {
    public abstract UserDAO userDAO();
}
```
<br><br>
### Database 사용하기
- 런타임시 Room.databaseBuilder() 또는 Room.inMemoryDatabaseBuilder()를 호출하여 Database 인스턴스를 가져올 수 있다.
```java
private UserDB userDB;
userDB = Room.databaseBuilder(this, UserDB.class,"user_tables").build();
```
<br><br>
