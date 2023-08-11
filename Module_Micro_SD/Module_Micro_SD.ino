#include <SPI.h>
#include <SD.h>
const int CS = 4;
File dataku;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Membaca SDcard...");
  if (!SD.begin(CS))
  {
    Serial.println("GAGAL/SDcard rusak!");
    while (1);
  }
  Serial.println("Berhasil");
}

void loop() {
  // put your main code here, to run repeatedly:
  dataku = SD.open("datasdcard.txt", FILE_WRITE);
  if (dataku){
    dataku.println("");
    dataku.print("Data Tersimpan");
    dataku.close();
  }
  else{
    Serial.println(" | Gagal Tersimpan!");
  }
}
