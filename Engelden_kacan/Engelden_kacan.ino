#include <NewPing.h>   // Ultrasonik Mesafe Sensörünün kütüphanesi
#define MAX_DISTANCE 200
#define TRIGGER_PIN  A8    // Ses dalga gönderilen kısım
#define ECHO_PIN     A9    // Ses dalga algılanan kısım


int Sag_Motor_Hizi = 5;
int Sol_Motor_Hizi = 7;
int Sag_Motor_ileri = 16;
int Sag_Motor_geri = 17;
int Sol_Motor_ileri = 15;
int Sol_Motor_geri = 14;

int engel_sayısı;
long Mesafe;


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  //Burada pinleri tanımlanır
  pinMode(Sag_Motor_ileri, OUTPUT);
  pinMode(Sag_Motor_geri, OUTPUT);
  pinMode(Sag_Motor_Hizi, OUTPUT);
  pinMode(Sol_Motor_ileri, OUTPUT);
  pinMode(Sol_Motor_geri, OUTPUT);
  pinMode(Sol_Motor_Hizi, OUTPUT);
 
  engel_sayısı = 0;// Robot, kaçınıcı engele geldiğini bilinmek içindir
}

void loop()
{

  ileri();delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 0){
    while (Mesafe > 30 or Mesafe == 0){Mesafe = sonar.ping_cm();}
    dur();
    saga_don();
    engel_sayısı++;
  }
  ////////////////////////////
  
  ileri();delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 1){
    while (Mesafe > 30 or Mesafe == 0){ Mesafe = sonar.ping_cm();}
    dur();
    sola_don();
    engel_sayısı++;
  }
  ////////////////////////////

  ileri();delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 2){
    while (Mesafe > 30 or Mesafe == 0){Mesafe = sonar.ping_cm();}
    dur();
    saga_don();
    engel_sayısı++;
  }
  /////////////////////////////

  ileri();delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 3) {
    while (Mesafe > 30 or Mesafe == 0){Mesafe = sonar.ping_cm();}
    dur();
    saga_don();
    engel_sayısı++;
    }
 ////////////////////////////////////////////
 
  ileri();delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 4) {
    while (Mesafe > 30 or Mesafe == 0){Mesafe = sonar.ping_cm();}
    dur();
    sola_don();
    engel_sayısı++;
    }
  //////////////////////////////////////////

  ileri();delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 5) {
    while (Mesafe > 30 or Mesafe == 0){Mesafe = sonar.ping_cm();}
    dur();
    sola_don();
    engel_sayısı++;
    }
  /////////////////////////////

  ileri();delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 6) {
    while (Mesafe > 30 or Mesafe == 0){Mesafe = sonar.ping_cm();}
    dur();
    saga_don();
    engel_sayısı++;
    }
  /////////////////////////////

  ileri();delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 7) {
    while (Mesafe > 30 or Mesafe == 0){Mesafe = sonar.ping_cm();}
    dur();
    saga_don();
    engel_sayısı++;
    }
  ////////////////////////////////////////////

  ileri();delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 8) {
    while (Mesafe > 30 or Mesafe == 0){Mesafe = sonar.ping_cm();}
    dur();
    sola_don();
    engel_sayısı++;
    }
  /////////////////////////////

  ileri();
  delay(1000);
  Mesafe = sonar.ping_cm();
  if (engel_sayısı == 9) {
    while (Mesafe > 30 or Mesafe == 0){Mesafe = sonar.ping_cm();}
    dur();
    saga_don();
    engel_sayısı++;
    }

}



void ileri()
{
  digitalWrite(Sag_Motor_ileri, 1); digitalWrite(Sag_Motor_geri, 0); analogWrite(Sag_Motor_Hizi, 134);
  digitalWrite(Sol_Motor_ileri, 1); digitalWrite(Sol_Motor_geri, 0); analogWrite(Sol_Motor_Hizi, 130);
}
void dur()
{
  digitalWrite(Sag_Motor_ileri, 0); digitalWrite(Sag_Motor_geri, 0); analogWrite(Sag_Motor_Hizi, 0);
  digitalWrite(Sol_Motor_ileri, 0); digitalWrite(Sol_Motor_geri, 0); analogWrite(Sol_Motor_Hizi, 0);
}
void saga_don()
{
  digitalWrite(Sag_Motor_ileri, 0); digitalWrite(Sag_Motor_geri, 0); analogWrite(Sag_Motor_Hizi, 0);
  digitalWrite(Sol_Motor_ileri, 1); digitalWrite(Sol_Motor_geri, 0); analogWrite(Sol_Motor_Hizi, 74);
  delay(1500);
}
void sola_don()
{
  digitalWrite(Sag_Motor_ileri, 1); digitalWrite(Sag_Motor_geri, 0); analogWrite(Sag_Motor_Hizi, 73);
  digitalWrite(Sol_Motor_ileri, 0); digitalWrite(Sol_Motor_geri, 0); analogWrite(Sol_Motor_Hizi, 0);
  delay(1500);
}
