#include <SoftwareSerial.h>

#define TX_PIN 10
#define RX_PIN 11

/*
 * HC 06의 TX를 아두이노의 RX핀(Digital 11)에 교차해서 연결
 * HC 06의 RX를 아두이노의 TX핀(Digital 10)에 교차해서 연결
 */

SoftwareSerial bluetoothSerial(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(9600);
  while(!Serial) {
    ; // 시리얼 포트가 연결되기를 기다립니다.
  }

  bluetoothSerial.begin(9600);
}

void loop() {
  if(bluetoothSerial.available()) {
    int receiveData = bluetoothSerial.read(); // 데이터를 읽습니다.
    Serial.write(receiveData); // 읽어온 데이터를 시리얼 모니터에 출력합니다.
  }

  if(Serial.available()) {
    int sendData = Serial.read(); // 시리얼 모니터에서 데이터를 얻습니다.
    bluetoothSerial.write(sendData); // 데이터를 보냅니다.
  }
}
