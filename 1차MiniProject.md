# **기존 소스 분석**

### Bus Reservation System

버스 예약 시스템

![BusReservationSystem.png](https://www.interviewbit.com/blog/wp-content/uploads/2021/12/Bus-Ticketing-768x466.png)

This system is built on the concept of booking bus tickets in advance. The user can check the bus schedule, book tickets, cancel reservations, and check the bus status board using this system. When purchasing tickets, the user must first enter the bus number, after which the system will display the entire number of bus seats along with the passengers’ names, and the user must then enter the number of tickets, seat number, and person’s name.We will be using arrays, if-else logic, loop statements, and various functions like login(), cancel(), etc. to implement the project.

/*
이 시스템은 버스 티켓을 미리 예약하는 개념을 기반으로 합니다. 사용자는 이 시스템을 이용하여 버스 시간표 확인, 티켓 예매, 예약 취소, 버스 현황 게시판을 확인할 수 있습니다. 승차권을 구매할 때 먼저 버스 번호를 입력해야 버스의 전체 좌석 수와 승객의 이름이 표시되고 사용자는 승차권 번호, 좌석 번호, 사람 이름을 입력해야 합니다. 배열, if-else 논리, 루프 문 및 login(), cancel() 등과 같은 다양한 함수를 사용하여 프로젝트를 구현합니다.
*/

---

## **BUS RESERVATION SYSTEM IN C PROGRAMMING WITH SOURCE CODE**

This system is based on a concept to reserve bus tickets. From this system, the user can view bus list, book tickets, cancel bookings and check bus status board.While booking tickets, the user has to enter bus number then the system displays total bus sea...

## ****소스 코드로 프로그래밍하는 C의 버스 예약 시스템****

이 시스템은 버스 티켓을 예약하는 개념을 기반으로 합니다. 이 시스템에서 사용자는 버스 목록을 보고, 티켓을 예약하고, 예약을 취소하고 버스 상태 게시판을 확인할 수 있습니다. 티켓을 예약하는 동안 사용자는 버스 번호를 입력해야 하며, 시스템은 총 버스를 표시합니다...

---

## 오류 확인 ( 목표 )

1. 로그인 3회 실패시, 4회 실패로 출력됨
2. 보기에 없는 값을 입력시(scanf 프로그램 종료됨
3. 예약시, 빈 좌석 표시(Empty) 문자열이 겹쳐서 출력됨(예약자名 <5
4. 예약 성공시, 좌석 현황 표시에서 form 밀림 현상(” \t “
5. 예약된 좌석에 중복 예약시, 이전 예약자 정보 삭제됨
6. 예약된 좌석에 중복 예약시, 남은 좌석 수는 줄어들음
7. Switch(case3 예약 취소로 진입시, 버스 리스트 화면이 아닌, 최초 화면 그대로 표시됨
8. 취소할 좌석이 없어도, Switch(case3 예약 취소로 진입이 허용됨
9. 취소할 좌석이 없어도, 해당 좌석을 취소시, 예약이 취소됨
10. 예약 취소에 성공하여도, 남은 좌석 수가 고정되어 있음
11. Switch(case4 진입시, 버스 리스트 화면이 아닌, 화면이 표시되지 않음

---

# Project (문제 해결 및 새로 작성)

- 헤더 파일, 기능별 함수 파일 분리
- 버스 행선지, 가격 정보 배열을, 이중 포인터 사용하여 메모리를 절약
- 버스 총 대수, 버스 좌석 수를 정적 전역 변수로 선언
- 로그인시 필요한 user, password 변수를 메모리 동적 할당으로, 메모리 절약
- 로그인시 동적 할당된 user, password 변수의 메모리 크기를 define 선언하여, size 변경에 용이
- 파일 부재로 fopen 실패시, 모두 빈 자리로 새로이 파일 생성
- 예약된 좌석은 예약 불가 추가
- 만석 버스 경우 예약 불가 추가
- 빈 좌석을 예약 취소 불가 추가
- 공석 버스 경우 예약 취소 불가 추가

---

# 추후 업데이트 예정

- 버스 정보를 구조체로 관리
- 예약자 성명 등의 정보를 파일로 관리
- 예약자 정보로 VIP || Membership || 국가 유공자 등 별로, 할인 정도를 설정
- 출발 시간별 예약 범위
- 출발지 변경 예약
- 파일명별 case 관리를, 파일명 배열로 선언하여 코드 단축
- 출력 글에, 색을 추가하는 시각 효과
- 예약자별 티켓 관리

---

# 질문 사항

- Switch(case 입력값 오류시, case1로 무한 반복 현상
- 좌석 현황 출력에서 “ FULL “ 출력시 “ \t “ 밀림 현상

---


---

