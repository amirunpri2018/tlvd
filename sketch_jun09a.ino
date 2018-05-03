#include <NewPing.h>

#define echo 6//mengirim sinyal
#define trig 5//menerima sinyal

NewPing ultra(trig, echo);

int buzzer = 7;
int hijau = 2;
int kuning = 3;
int merah = 4;
int tomsis = 8;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(merah, OUTPUT);
  pinMode(tomsis, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  LampuHijauKuning();
  LampuMerah();
}

void LampuHijauKuning() {
  digitalWrite(hijau, HIGH);
  delay(5000);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, HIGH);
  delay(2000);
  digitalWrite(kuning, LOW);
}

void LampuMerah() {
  digitalWrite(merah, HIGH);
  int temp = ultra.ping_cm();
  for (int i = 1; i < 29; i++) {
    Serial.print("Jarak: ");
    int val = ultra.ping_cm();
    Serial.println(val);
    if ((val < 9) && (i == 1))
      detected();
    else if ((val < 9) && (val != temp))
      detected();
    else
      delay(250);
  }
  digitalWrite(merah, LOW);
}
  
void buzz(int time) {
  digitalWrite(buzzer, HIGH);
  delay(time);
  digitalWrite(buzzer, LOW);
  delay(time);
}

void detected() {
  digitalWrite(tomsis, HIGH);
  delay(100);
  digitalWrite(tomsis, LOW);
  buzz(150);
}
