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


## 프로젝트 목적
  1. 편의성 --> 주인이 바빠서 배급 시간을 놓치는 경우 유용
  2. 반려동물 건강관리 --> 반려 동물의 규칙적인 식습관 
  3. 하드웨어 학습기회 --> 실제 하드웨어 구현을 해보며 하드웨어 지식 확장
  4.<img src="https://github.com/marllinkang/python/assets/146154079/e874250f-f9bb-4936-a6cd-a6828ceb7b89" width="50" height="70"/>
 아두이노 코딩 실력 향상 --> C언어 기반의 아두이노 숙련도 향상
  5. <img src="https://github.com/marllinkang/python/assets/146154079/366692a1-8f42-4045-a1dc-3ab46c19f5da" width="50" height="70"/>직관적이고 편리한 사용법 ---> 사용자의 입장에서 편리성을 향상시키도록 노력

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
- UI 기초 디자인 설계
- 배급기 동작 로직 개발 (배급시간, 배급량 설정 로직)
- serial 통신 연동

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
![Screenshot from 2023-11-06 17-20-10](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/dc85bcec-740a-406b-b957-12534c96135f)

### 기능
- 2개의 버튼으로 동작하며 왼쪽(확인) 오른쪽(상태변경) 버튼으로 이루어져있음
- 오른쪽(상태변경) 버튼을 누르게 되면 배급시간 배급량을 설정하는 상태로 변경
- 사용자가 원하는 시간과 배급량을 왼쪽(확인)버튼을 클릭하여 설정한다
- 그리고 기기 우측의 녹음(왼쪽), 재생(우측) 버튼을 통해 반려동물에게 배급 시간임을 인지하게 한다
![Screenshot from 2023-11-06 17-34-58](https://github.com/addinedu-ros-3rd/iot-repo-7/assets/146153568/5850890d-f358-4095-a4fe-7fa6536ed94c)

### GUI 
- GUI를 활용하여 PC와의 Serial 통신을 통해 기기를 동작할 수 있다.
- 그림에 표시된 버튼을 누르게 되면 기기와 연동됨
    

