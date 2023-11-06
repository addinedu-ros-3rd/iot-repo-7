<div align="center">
<h2>IoT 프로젝트 7조 저장소. 반려동물 자동 사료 배급기</h2>
<h3>[2023] 반려동물 자동 사료 배급기 제작 🏠</h3>
바쁜 일상 속에서 반려동물의 배급시간을 책임질 수 있는 기기, 집게리아입니다!<br> 간편하게 동작시킬 수 있으며
깔끔한 UI로 동시 제어할 수 있습니다 🐟🐶
<br><br>

  ![new](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/ed9bce4f-3552-4c31-b28e-9946b5c4c553)
  
</div>


<br><br>

## 발표자료 및 시연 영상

![image](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/55674360/494cbc6c-4642-47db-b739-fa1210cf7009)

<a href="https://drive.google.com/file/d/11cObL_RTVPlk4tNoNMhSktwqJqhwBYE1/view?usp=sharing" target="_blank">영상 구경하러 가기</a>

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

### 시스템 FLOW
- 시작 -> 초기화 후 사용자가 설정한 배급 시간 및 상태에 따라 동작
- 동작 후 다시 대기
![Screenshot from 2023-11-06 17-20-10](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/dc85bcec-740a-406b-b957-12534c96135f)

### 기능
![image](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/b81ce8ed-e04c-4715-8537-fc97e22ca021)

위 사진의 1개의 가변저항과 2개의 버튼(왼:확인, 오:상태변경)을 이용해서 아래의 알고리즘 구현

![Screenshot from 2023-11-06 17-34-58](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/5850890d-f358-4095-a4fe-7fa6536ed94c)

1.시간 설정
![Screenshot from 2023-11-06 18-12-00](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/3eef8d22-af15-428b-8431-7c90107c2f13)

2.사료량 설정
![Screenshot from 2023-11-06 18-12-37](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/e83665df-6540-414e-b8bd-41f512c339f8)

3.즉시 지급
![Screenshot from 2023-11-06 18-12-59](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/89cf6858-3202-4c2d-b11c-df27cd897bc9)




### GUI 
- GUI를 활용하여 PC와의 Serial 통신을 통해 기기를 동작할 수 있다.
- 그림에 표시된 버튼을 누르게 되면 기기와 연동됨
  ![Screenshot from 2023-11-06 17-53-21](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/9b9bfabe-16dd-49ad-857e-46693ee96f5a)

### 하드웨어
1. 소프트웨어를 통해 만든 프로그램의 물리적 구현
2. 물리적으로 구현된 제품의 컴팩트한 패키지를 위한 고려사항
3. 디자인
<br>

제품을 설계 및 패키징 할때 참고한 것 : 영국의 로버 미니
![1959-mini-design](https://github.com/marllinkang/pyqt/assets/146154079/e5037f60-0647-47cc-921f-08f7040c1728)

- **작은 차체에 넓은 실내** 컨셉으로 공간 효율을 극대화 

- 디자인을 위해 기능을 배치한 것이 아닌 필요한 기능을 배치하니 자연스럽게 만들어진 디자인

**1.소프트웨어를 통해 만든 프로그램의 물리적 구현 가능성**

일반적인 물고기 자동급여 제품처럼 원통이 **돌아가며 급여하는 방식**으로 하기엔 **복잡하고 신뢰성이 확보되지 않아** 개, 고양이 급여 제품처럼 모터가 작동되며 **먹이가 떨어지는 방식**을 채택


![1584570092_00](https://github.com/marllinkang/pyqt/assets/146154079/f3f2ee19-dc6c-4a3e-8453-50395dfe2534)|![B](https://github.com/marllinkang/pyqt/assets/146154079/f0773fda-0665-4598-a44c-65fd8b848516)
---|---|
|**돌아가는 방식**|**떨어지는 방식**|

## 사용 재료
|KW11-1 버튼|I2C LCD|메탈기어 디지털 서보모터|ISD1820 녹음 모듈|
|---|---|---|---|
|![200605111532590](https://github.com/marllinkang/pyqt/assets/146154079/2b8a2ca7-cbae-4334-935f-3827a0d0a0e7)|![2068728412_00](https://github.com/marllinkang/pyqt/assets/146154079/24aaad6e-498e-40a0-8faa-fcabbb9fb0ef)|![993113375ACB95090F](https://github.com/marllinkang/pyqt/assets/146154079/008ef437-ba7f-40ae-888a-2c84381f49fb)|![HTB1KapvRXXXXXacXpXXq6xXFXXX6 jpg_640x640Q90 jpg_](https://github.com/marllinkang/pyqt/assets/146154079/eaf5fd04-d358-4e7b-ba82-456a7e58522d)|
|작은 힘으로도 잘 눌리며 납땜도 가능한 KW11-1 버튼 사용 |I2C LCD로 교체 하여 배선을 줄일 수 있었고, 하나의 아두이노로 모든 기능들을 사용 |메탈기어 서보모터로 교체하여<br>신뢰성을 확보| 녹음 모듈과 버튼을 추가하여 급여시 주인의 목소리를 들을 수 있도록 추가|

**2.물리적으로 구현된 제품의 컴팩트한 패키지를 위한 고려사항**

2.1 부품들을 새롭게 설계하는 것이 아닌 기존의 판매하는 부품들을 이용하여야 하므로 자유도에 제약이 있음  또한 아두이노 전원을 컴퓨터에 연결하며 코드를 업데이트 하거나 9V 건전지를 이용할 수 있으므로 아두이노 전원선에 접근이 쉬워야함
	
2.2 보여주기 식이 아닌 일상에서 실사용을 위해 내부 부품들을 잘 고정시켜야 하며 외관에 고품질의 재료를 선택하여 내구성을 높여야함 

2.3 절단면 커팅과 사포질 등 깔끔한 마감을 통해 시각적으로  보이는 제품의 품질 및 신뢰도를 높임


⮕ 결국 사각형 박스모양으로 만드는 것이 구조적으로 가장 튼튼하면서 내부에 부품을 배치하기 좋으며 깔끔하게 만들 수 있다는 현실적인 결론에 도달

## 제작 과정

|전선|3D CAD|종이로 제작|아크릴로 제작|
|---|---|---|---|
|![Screenshot from 2023-11-06 20-47-00](https://github.com/marllinkang/pyqt/assets/146154079/49abca17-752b-4e1f-8e47-0caab7302e7f)|![Screenshot from 2023-11-06 20-48-28](https://github.com/marllinkang/pyqt/assets/146154079/658c735f-ae54-42d3-9c85-56351997675d)|![Screenshot from 2023-11-06 20-50-17](https://github.com/marllinkang/pyqt/assets/146154079/bbf68251-1a55-4cb5-9f4f-b4be5e8bb901)|![Screenshot from 2023-11-06 20-50-45](https://github.com/marllinkang/pyqt/assets/146154079/c0ff502f-6fdd-41d2-80b1-dd0fd12345f1)|
| 기존의 부품들을 이용하여야 하므로 자유도에 제약이 있고, 전선의 길이가 가장 큰 문제여서 수축 튜브를 이용해 최대한 길이를 줄임 |CAD를 이용하여 2가지 모양을 만들어보며 충분히 토의 후 왼쪽의 디자인을 선택| 종이로 제작하여 맞춰보며 수치를 기록| 다시 부품들간에 배치시 문제가 없는지 확인 후 연질 아크릴로 제작|
<br>

## 제작 과정2

![Screenshot from 2023-11-06 21-40-11](https://github.com/marllinkang/pyqt/assets/146154079/903f28f5-bf93-4897-a897-31603dba1c8f)|![Screenshot from 2023-11-06 21-40-24](https://github.com/marllinkang/pyqt/assets/146154079/f1ad5946-2a9f-4729-a6d1-06943c4e1042)
---|---|
<br>

## 제작 과정3

![Screenshot from 2023-11-06 21-42-11](https://github.com/marllinkang/pyqt/assets/146154079/349d3b38-4f06-440f-9096-94ddd16fe4f3)|![Screenshot from 2023-11-06 21-42-31](https://github.com/marllinkang/pyqt/assets/146154079/0521478f-055b-4857-936a-dea466bfa7ac)
---|---|
<br>

## 제작 과정4
![Screenshot from 2023-11-06 21-45-22](https://github.com/marllinkang/pyqt/assets/146154079/8e8147dc-1096-4e16-ae69-cf1df37529b3)|![Screenshot from 2023-11-06 21-45-37](https://github.com/marllinkang/pyqt/assets/146154079/7ecd2c9f-c2d3-41e6-b153-6e8d8ff833a1)
---|---|
<br>

## 제작 과정5
![Screenshot from 2023-11-06 21-47-12](https://github.com/marllinkang/pyqt/assets/146154079/603bcbdf-a2b6-49dd-9ac2-037935b41e38)|![Screenshot from 2023-11-06 21-47-23](https://github.com/marllinkang/pyqt/assets/146154079/a5da98c8-eb28-4ed5-a1b0-00a661f184d6)
---|---|
<br>

## 완성 및 작동 테스트
![Screenshot from 2023-11-06 21-37-50](https://github.com/marllinkang/pyqt/assets/146154079/64672a19-77b0-4ba3-bb05-7648635b5aab)


