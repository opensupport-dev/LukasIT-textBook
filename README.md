# LukasIT-textBook

이 저장소는 루카스아이티(LukasIT)의 교재 관련 자료를 포함하고 있습니다. 아두이노를 활용한 미세먼지 측정 프로젝트와 RC카 프로젝트의 코드, 자료, 그리고 교재 관련 파일들이 정리되어 있습니다.

## 프로젝트 구조

```
.
├── LICENSE
├── README.md
├── LukasIT-textbook/
│   └── ... (교재 관련 PDF 및 이미지 파일)
├── LukasIT_DustMeasuring_Project/
│   ├── DATA-for-Dust-measuring-lecture/
│   │   └── ... (미세먼지 측정 프로젝트 관련 데이터, 이미지, 문서 등)
│   ├── LukasIT_All_final/
│   │   └── LukasIT_All_final.ino (최종 통합 아두이노 스케치)
│   ├── LukasIT_DHT11___/
│   │   └── ... (DHT11 온습도 센서 관련 아두이노 스케치)
│   ├── LukasIT_DSM501A_DustSensor_ugm3/
│   │   └── LukasIT_DSM501A_DustSensor_ugm3.ino (DSM501A 미세먼지 센서 관련 아두이노 스케치)
│   ├── LukasIT_I2CLCD_Address/
│   │   └── LukasIT_I2CLCD_Address.ino (I2C LCD 주소 확인 스케치)
│   ├── LukasIT_I2CLCD_Proj/
│   │   └── ... (I2C LCD 통합 프로젝트 관련 아두이노 스케치)
│   ├── LukasIT_RGBLED/
│   │   └── LukasIT_RGBLED.ino (RGB LED 제어 아두이노 스케치)
│   ├── LukasIT_RGBLED_AnodeType/
│   │   └── LukasIT_RGBLED_AnodeType.ino (RGB LED (애노드 타입) 제어 아두이노 스케치)
│   ├── LukasIT_SerialMonitor/
│   │   └── LukasIT_SerialMonitor.ino (시리얼 모니터 예제 아두이노 스케치)
│   └── LukasIT_SerialMonitor_AnodeType/
│       └── LukasIT_SerialMonitor_AnodeType.ino (시리얼 모니터 (애노드 타입) 예제 아두이노 스케치)
└── LukasIT_RC-Car_Porject/
    ├── LukasIT_RC-Car/
    │   └── Tutorials/
    │       └── ... (RC카 프로젝트 튜토리얼 관련 자료)
    └── ... (RC카 프로젝트 관련 문서 및 부품 리스트)
```

## 각 디렉토리 설명

*   **`LukasIT-textbook/`**:
    루카스아이티 교재의 PDF 파일 및 관련 스크린샷 이미지가 포함되어 있습니다. 이 디렉토리는 주로 교재 자체의 내용을 담고 있습니다.

*   **`LukasIT_DustMeasuring_Project/`**:
    아두이노를 활용한 미세먼지 측정 프로젝트와 관련된 모든 자료를 포함합니다.
    *   **`DATA-for-Dust-measuring-lecture/`**: 미세먼지 측정 강의에 필요한 부품 리스트, 회로도, 데이터시트, 이미지 자료 등 다양한 보조 자료들이 정리되어 있습니다.
    *   **`LukasIT_All_final/`**: 미세먼지 측정 프로젝트의 최종 통합 아두이노 스케치 파일이 있습니다.
    *   **`LukasIT_DHT11___/`**: DHT11 온습도 센서의 사용법과 관련된 다양한 아두이노 예제 스케치들이 포함되어 있습니다.
    *   **`LukasIT_DSM501A_DustSensor_ugm3/`**: DSM501A 미세먼지 센서의 데이터를 읽고 처리하는 아두이노 스케치 예제입니다.
    *   **`LukasIT_I2CLCD_Address/`**: I2C LCD 모듈의 주소를 확인하는 데 사용되는 아두이노 스케치입니다.
    *   **`LukasIT_I2CLCD_Proj/`**: I2C LCD를 활용한 다양한 프로젝트 예제 스케치들이 포함되어 있습니다.
    *   **`LukasIT_RGBLED/`**: RGB LED의 기본적인 제어 방법을 보여주는 아두이노 스케치입니다.
    *   **`LukasIT_RGBLED_AnodeType/`**: 애노드 타입 RGB LED를 제어하는 아두이노 스케치입니다.
    *   **`LukasIT_SerialMonitor/`**: 아두이노 시리얼 모니터의 사용법을 익히기 위한 기본적인 예제 스케치입니다.
    *   **`LukasIT_SerialMonitor_AnodeType/`**: 애노드 타입 시리얼 모니터 예제 스케치입니다.

*   **`LukasIT_RC-Car_Porject/`**:
    아두이노 기반 RC카 프로젝트와 관련된 자료를 포함합니다.
    *   **`LukasIT_RC-Car/`**: RC카 프로젝트의 주요 코드 및 튜토리얼 자료가 포함될 예정입니다.
    *   그 외 RC카 프로젝트 기획서, 부품 리스트 등 문서 파일들이 있습니다.

## 라이선스

이 프로젝트는 `LICENSE` 파일에 명시된 라이선스를 따릅니다.

## 저자 정보

*   **이름**: 박재홍
*   **이메일**: jaehong1972@gmail.com