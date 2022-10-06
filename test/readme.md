## M:N (다대다) 관계 
M:N의 관계는 실제 테이블로 설계할 수 없음.


관계형 데이터베이스는 테이블이라는 정형화된 구조를 가지는 방식이어서 확장이 불가능.


M:N 관계를 해결하기 위해서, 실제 테이블 설계에서 매핑(mapping) 테이블을 이용.
= 두 테이블 중간에서 필요한 정보를 양쪽으로 끌어서 쓰는 구조


****매핑 테이블의 특징**** 
- 이전에 다른 테이블이 먼저 존재해야만 함
- 주로 명사가 아닌 '동사'나 '히스토리'에 대한 데이터를 보관하는 용도
- 중간에 양쪽의 PK를 참조하는 형태


****JPA에서의 M:N 처리****
* @ManyToMany 이용 (각 엔티티와의 매핑 테이블이 자동 생성되는 방식의 처리)
* 별도의 엔티티 설계 후, @ManyToOne 이용

<br/>

### 1. 직접 매핑 테이블 설계 및 직접 관계 연결하는 방식 이용
*@EnableJpaAuditing 자동시간처리*


****리뷰 = 매핑 테이블)****
Review Class


회원이 영화에 대해서 "평점을 준다" -> 행위에 중점

movie, member(영화, 회원)의 pk를 fk로 가짐 (@ManyToOne)


****파일 업로드)****
MovieImage Class
: 리뷰와 같은 방식으로 단방향 참조 처리, @Query(left join)


***생성은 기존 방식과 동일함***

<br/>

### 2. 필요한 데이터 처리
* 목록 화면에서 영화 제목(Movie Class), 이미지 하나(MovieImage Class), 영화 리뷰의 평점/리뷰 개수(Review Class) 를 같이 출력


@Query 방식 
```
movie (1) - movieimage (N) - review join
```


위 같이 join 하면 비효율적으로 여러번 실행됨
> 1 X N X N 


-> 이미지를 1개로 줄여서 처리
> 1 X 1 X N 

= 맨위의 이미지만 가져옴 


* 특정 영화 조회 화면에서 영화(Movie Class)와 영화의 이미지들(MovieImage Class), 리뷰의 평균점수/리뷰개수(Review Class)를 같이 출력

92번 영화의 이미지가 2개, 리뷰개수가 4개 일 때
```
@Query("select m, mi, avg(coalesce(r.grade,0), count(r)" 
       + "from Movie m left outer join MovieImage mi on mi.movie = m" 
       + " where m.mno = :mno group by mi")
```


* 리뷰(Review Class)에 대한 정보에는 회원(Member Class)의 이메일이나 닉네임과 같은 정보를 같이 출력 
@EntityGraph, 서브쿼리 활용
: 엔티티의 특정한 속성을 같이 로딩하도록 표시하는 어노테이션
일반적으로 연관관계의 Fetch 속성 값은 LAZY로 지정하지만, 특정 기능을 수행할 때만 EAGER로딩을 할 수 있도록 지정할 수 있음 

- attributePaths : 로딩 설정을 변경하고 싶은 속성의 이름을 배열로 명시
- type : @EntityGraph 를 어떤 방식으로 적용할 것인지를 설정
```
ex) @EntityGraph(attributePaths={"member"}, type = EntityGraph.EntityGraphType.FETCH)
```


주의) M:N 관계에서 명사에 해당하는 객체를 삭제할 때 매핑 테이블에서도 삭제해야 함
해당 회원의 리뷰를 먼저 삭제하고, 해당 회원의 정보를 삭제하는 순서로 진행
-> 한 트랜잭션으로 처리해야하기 위해 @Transactional , @Commit 

<br/>

### 3. 파일 업로드
Tomcat 실행, 파일 업로드 관련 설정 추가 필요
***MutipartFile 배열로 받아 여러 파일 정보를 처리***

파일 저장 고려사항
- 동일한 파일이름 문제 -> 시간 값 파일을 이름에 추가하거나, UUID 등 고유한 값을 만들어서 사용
- 동일한 폴더에 파일들이 쌓이는 문제 -> 일반적으로 년/월/일 폴더를 생성하여 한 곳에 쌓이는 것을 방지함


***파일 확장자 체크 MultipartFile의 getContentType() 으로 가능***


* 섬네일 처리
원본 이미지를 그대로 보여주면 데이터를 많이 소비하기 때문에 섬네일 처리 후 이용(파일 크기가 매우 작음)
       * Thumbnailator 라이브러리 이용 : 적은 양의 코드만으로 이용해서 제작 가능, 비율 조정 편리



* 파일 삭제
원본파일과 함께 섬네일 파일도 같이 삭제해야 함

<br/>

## 영화/ 리뷰 프로젝트 적용
### 1. 영화 등록
****DTO****
MovieDTO 안에 MovieImageDTO List 가 포함되게 작성(1:N 관계)


****Service****
DTO -> Entity 변환
한번에 두가지 종류의 객체를 반환해야하므로 Map 타입 이용


Entity로 변환시킨 객체를 꺼내서 각각 레파지토리로 넣어 저장


****Controller****
movieService와 연결


html 생략

<br/>

### 2. 영화 목록
****DTO****
영화, 리뷰 M:N 관계에서 쿼리 처리 결과 값들을 담을 파라미터 추가
double avg, int reviewCnt ...


****Service****
JPA를 통해서 나오는 엔티티 객체들과 Double, Long 등의 값을 MovieDTO로 변환하는 entitiesToDto() 를 추가해야함


entitiesToDto()
> - Movie entity
> - List<MovieImage> entity
> - Double타입의 평점평균
> - Long 타입의 리뷰개수


****Controller, html 생략****

<br/>

### 3. 조회 페이지와 영화 리뷰
MovieRepository 에서 가져오는 것들을 가공할 필요가 있음.
(이미지 개수 만큼 Movie 객체가 만들어짐)

-> Movie, avg, reviewCnt는 맨 앞의 값을 가져오고, MovieImage는 result.forEach를 이용하여 List에 add 하는 방식으로 가져옴


나머지는 이전 실습과 비슷한 방식으로 생략

<br/>

### 4. 영화 리뷰 처리

리뷰 리스트 조회, 등록, 수정, 삭제 .. 댓글 실습과 비슷한 방식으로 생략 
