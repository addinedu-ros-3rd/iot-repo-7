
**수정 필요**   *완료한 내용은 ✅와 ~~취소선~~ 붙이기*
1. 사료나오는 동영상으로 업그레이드
2. 옆커버 깐 채로 내부 보이는 사진
3. 사료배출구가 보이는 사진
4. ~~동영상 낚시 없애기~~ ✅   
5. 전체시스템 구성도
6. ~~State diagram~~ ( + Sequence diagram )✅
7. 하드웨어 부분을 줄일 필요가 있음
8. 소프트웨어 리뷰과정 추가 
9. 초반에 생각했던 것들( 압력센서 ) 설계에 추가.
10. 아쉬웠던 점 / 향후계획(업그레이드 할 내용들 - 반려견 음성인식)
---


<div align="center">
<h2>IoT 프로젝트 7조 저장소. 반려동물 자동 사료 배급기</h2>
<h3>[2023] 반려동물 자동 사료 배급기 제작 🏠</h3>
바쁜 일상 속에서 반려동물의 배급시간을 책임질 수 있는 기기, 집게리아입니다!<br> 간편하게 동작시킬 수 있으며
깔끔한 UI로 동시 제어할 수 있습니다 🐟🐶
<br><br>

  ![new](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/ed9bce4f-3552-4c31-b28e-9946b5c4c553)
  
</div>


<br><br>

## 시연 영상

<a href="https://drive.google.com/file/d/11cObL_RTVPlk4tNoNMhSktwqJqhwBYE1/view?usp=sharing">
	<img src="https://img.freepik.com/free-vector/minimal-white-style-video-player-template-design_1017-25481.jpg?w=1380&t=st=1699332158~exp=1699332758~hmac=b96fa1a5b3bb8f973569ae6f45d1a6cc2cb439b527b46db5dec55262dc69a29f">
</a>


<br><br>

## 구현 기능

|기본 기능|디스플레이|음성 녹음 및 재생|PC 연동|
|---|---|---|---|
|![image](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/e021b891-b250-446d-9b14-0fef2a2e2c61)|![image](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/19808eeb-5bb7-43bd-98e7-5b5410f711a6)|![image](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/a13a614f-3c2f-45f9-90fa-d3b4ccea3d3e)|![image](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/5743f81a-7101-4cb7-b6c6-f0834148c85c)|
|배급 시간 설정 기능 <br> 배급량 조절 기능	<br> 즉시 배급 기능 |기본 기능들을 확인 및 설정 가능 <br> 버튼과 가변저항을 디스플레이와 연동 |배급할 때 녹음된 음성 출력 <br> 녹음버튼과 재생버튼을 연동 |Serial 통신을 통해 pc로 제어 가능 <br> pyQt로 GUI 제작|

<br><br>



## 프로젝트 개요
  - 팀명 : 밥 조
  - 팀원 : 이충한 강병철 이수민
  - 기간 : 23.10.23 ~ 23.10.30
  - 기술 키워드 : <img src="https://img.shields.io/badge/PySerial-000000?style=for-the-badge&logo=serial&logoColor=white"> 
<img src="https://img.shields.io/badge/PyQt-41CD52?style=for-the-badge&logo=Qt&logoColor=white"> <img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"> <img src="https://img.shields.io/badge/python-3776AB?style=for-the-badge&logo=python&logoColor=white"> <img src="https://img.shields.io/badge/Arduino-00878F?style=for-the-badge&logo=Arduino&logoColor=white">

<br>

## 프로젝트 목적
  1. ⭐  **편의성** ⮕ 주인이 바빠서 배급 시간을 놓치는 경우 유용
  2. ⭐  **반려동물 건강관리** ⮕ 반려 동물의 규칙적인 식습관 
  3. ⭐  **하드웨어 학습기회** ⮕ 실제 하드웨어 구현을 해보며 하드웨어 지식 확장
  4. ⭐  **아두이노 코딩 실력 향상** ⮕ C언어 기반의 아두이노 숙련도 향상
  5. ⭐  **직관적이고 편리한 사용법** ⮕ 사용자의 입장에서 편리성을 향상시키도록 노력

<br>

## 역할 분담
#### 이충한
###### 총괄
- 하드웨어 설계
- 3d CAD로 밥통 설계
- 배선 최적화
- 하드웨어 최소화를 위해 병철님 압박하기
- 음성모듈 기능 추가 
- UI 업그레이드 
- LCD 버튼 로직 업그레이드

#### 이수민
###### 소프트웨어 팀장
- PyQt를 활용한 UI 기초 디자인 설계
- 배급시간, 배급량 설정 기능 개발
- PC와 serial 통신 연동
- 시스템 FLOW 설계

#### 강병철
###### 하드웨어 팀장
- 하드웨어 설계 및 구현
- 데이터 흐름 구체화
- 하드웨어 및 전장 담당
- 소프트웨어로 사용되는 기능들을 확인한 뒤, 물리적으로 구현하기위해 아두이노를 포함하여 배선들을 연결해보고 전선 길이를 최소화
- 버튼과 LCD 모터를 배치하며 컴팩트한 사이즈를 구현하고 최적의 위치와 모양을 찾기위해 지속적인 수정
- 프로토타입을 제작 후 실제 사용을 전제로 하여 제작



</br>
</br>

## 소프트웨어

### 시스템 FLOW
- 시작 -> 초기화 후 사용자가 설정한 배급 시간 및 상태에 따라 동작
- 동작 후 다시 대기
  
![Screenshot from 2023-11-07 14-45-41](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/3d47413b-dec2-4138-a635-aad1697abc94)



### 주요 기능
![image](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/b81ce8ed-e04c-4715-8537-fc97e22ca021)

위 사진의 1개의 가변저항과 2개의 버튼(왼:확인, 오:상태변경)을 이용해서 아래의 알고리즘 구현

- 확인 버튼 : ok 기능

- Mode 버튼 : 아래 그림의 상태 변경 기능

- 가변 저항 : 값 조절 기능
  
![Screenshot from 2023-11-07 10-38-08](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/18dd80d9-b86e-4e97-bbb7-6dd4c7bd2f74)


1.시간 설정

![Screenshot from 2023-11-07 10-39-44](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/9b314d0f-37fa-4e50-8260-60283704d044)


2.사료량 설정

![Screenshot from 2023-11-07 10-40-19](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/b611f506-9d2a-4c53-a802-b47e4711fc2a)


3.즉시 지급

![Screenshot from 2023-11-07 10-40-43](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/cd5bfec9-7c95-4d4d-81ff-69d6c0f12491)





### GUI 
- GUI를 활용하여 PC와의 Serial 통신을 통해 기기를 동작할 수 있다.
- 그림에 표시된 버튼을 누르게 되면 기기와 연동됨
![Screenshot from 2023-11-07 10-39-02](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/d27244d2-8025-42a2-8607-c67993ce20d4)

<br>
<br>

## 하드웨어

1. 소프트웨어를 통해 만든 프로그램의 물리적 구현
2. 물리적으로 구현된 제품의 컴팩트한 패키지를 위한 고려사항
3. 디자인

<br>


	
**제품을 설계 및 패키징 할때 참고한 것 : 영국의 로버 미니**
	
![1959-mini-design](https://github.com/marllinkang/pyqt/assets/146154079/e5037f60-0647-47cc-921f-08f7040c1728)



- **작은 차체에 넓은 실내** 컨셉으로 공간 효율을 극대화 

- 디자인을 위해 기능을 배치한 것이 아닌 필요한 기능을 배치하니 자연스럽게 만들어진 디자인

<br>

**1.소프트웨어를 통해 만든 프로그램의 물리적 구현 가능성**

일반적인 물고기 자동급여 제품처럼 원통이 **돌아가며 급여하는 방식**으로 하기엔 **복잡하고 신뢰성이 확보되지 않아** 개, 고양이 급여 제품처럼 모터가 작동되며 **먹이가 떨어지는 방식**을 채택


**떨어지는 방식**|**돌아가는 방식**
---|---|
|![1584570092_00](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/1cbfffc5-880b-4b81-8a6c-8876f41d43f4)|![B](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/791e1e8b-490d-4fd4-a3c6-5cca0fff0508)|

<br>

**2. 물리적으로 구현된 제품의 컴팩트한 패키지를 위한 고려사항**

2.1 부품들을 새롭게 설계하는 것이 아닌 기존의 판매하는 부품들을 이용하여야 하므로 자유도에 제약이 있음  

2.2 아두이노 전원을 컴퓨터에 연결하며 코드를 업데이트 하거나 9V 건전지를 이용할 수 있으므로 아두이노 전원선에 접근이 쉬워야함
	
2.3 보여주기 식이 아닌 일상에서 실사용을 위해 내부 부품들을 잘 고정시켜야 하며 외관에 고품질의 재료를 선택하여 내구성을 높여야함 

2.4 절단면 커팅과 사포질 등 깔끔한 마감을 통해 시각적으로  보이는 제품의 품질 및 신뢰도를 높임


⮕ 결국 사각형 박스모양으로 만드는 것이 구조적으로 가장 튼튼하면서 내부에 부품을 배치하기 좋으며 깔끔하게 만들 수 있다는 현실적인 결론에 도달

<br> 


### 사용 재료
|KW11-1 버튼|I2C LCD|메탈기어 디지털 서보모터|ISD1820 녹음 모듈|
|---|---|---|---|
|![200605111532590](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/7f8743c7-e069-4964-b279-7504bb2bce6a)|![2068728412_00](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/28facf5c-7c4d-4818-8751-b4bd09280835)|![993113375ACB95090F](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/3d6fc4b8-68b1-4fe4-bb73-a3348b457955)|![HTB1KapvRXXXXXacXpXXq6xXFXXX6 jpg_640x640Q90 jpg_](https://github.com/marllinkang/pyqt/assets/146154079/eaf5fd04-d358-4e7b-ba82-456a7e58522d)|
|작은 힘으로도 잘 눌리며 납땜도 가능한 KW11-1 버튼 사용 |I2C LCD로 교체 하여 배선을 줄일 수 있었고, 하나의 아두이노로 모든 기능들을 사용 |메탈기어 서보모터로 교체하여 신뢰성을 확보| 녹음 모듈과 버튼을 추가하여 급여시 주인의 목소리를 들을 수 있도록 추가|

<br>

### 제작 과정1

|전선|3D CAD|종이로 제작|아크릴로 제작|
|---|---|---|---|
|![Screenshot from 2023-11-06 20-47-00](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/fc0a15f3-c1f3-4da2-9be8-af0cba73e0f7)|![Screenshot from 2023-11-06 20-48-28](https://github.com/marllinkang/pyqt/assets/146154079/658c735f-ae54-42d3-9c85-56351997675d)|![Screenshot from 2023-11-06 20-50-17](https://github.com/marllinkang/pyqt/assets/146154079/bbf68251-1a55-4cb5-9f4f-b4be5e8bb901)|![Screenshot from 2023-11-06 20-50-45](https://github.com/marllinkang/pyqt/assets/146154079/c0ff502f-6fdd-41d2-80b1-dd0fd12345f1)|
| 기존의 부품들을 이용하여야 하므로 자유도에 제약이 있고, 전선의 길이가 가장 큰 문제여서 수축 튜브를 이용해 최대한 길이를 줄임 |CAD를 이용하여 2가지 모양을 만들어보며 충분히 토의 후 왼쪽의 디자인을 선택| 종이로 제작하여 맞춰보며 수치를 기록| 다시 부품들간에 배치시 문제가 없는지 확인 후 연질 아크릴로 제작|

<br>


### 제작 과정2

![Screenshot from 2023-11-07 10-15-50](https://github.com/marllinkang/pyqt/assets/146154079/ae6f1a50-7ec7-474a-8a54-ffdd0a37c547)|![Screenshot from 2023-11-07 10-37-08](https://github.com/marllinkang/pyqt/assets/146154079/a2d33444-7bbc-453f-b49e-6a134c10e8c8)
---|---|
<br>

### 제작 과정3

![Screenshot from 2023-11-07 10-11-38](https://github.com/marllinkang/pyqt/assets/146154079/ff8d66a4-a6df-4371-8e56-620de856affe)|![Screenshot from 2023-11-07 10-24-47](https://github.com/marllinkang/pyqt/assets/146154079/fcfe5582-90b1-4001-8a82-2c536f150b8f)
---|---|
<br>


### 완성 및 작동 테스트
![Screenshot from 2023-11-06 21-37-50](https://github.com/marllinkang/pyqt/assets/146154079/64672a19-77b0-4ba3-bb05-7648635b5aab)


### 아쉬운 점

### 향후 계획
