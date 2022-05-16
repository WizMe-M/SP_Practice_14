#include <Arduino.h>
#include <SoftwareSerial.h>

#define RX_PIN 0
#define TX_PIN 1

const String ON = "ON";
const String OFF = "OFF";

String received_data;
SoftwareSerial displaySerial(TX_PIN, RX_PIN);

void setup() {
    displaySerial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    //светодиод инвертирован
    digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
    while (displaySerial.available()) {
        char c = displaySerial.read();
        received_data += c;

        // проверяем на совпадение полученной строки с константами и обнуляем при совпадении
        if (received_data == ON) {
            digitalWrite(LED_BUILTIN, LOW);
            received_data = "";
        } else if (received_data == OFF) {
            digitalWrite(LED_BUILTIN, HIGH);
            received_data = "";
        }
    }
}