#include<Arduino.h>

int PV = 12; // présence voiture
int FB =14; // FERMER BARRIÉRE
int OB =27; // OUVRIRE BARIIÉRE
int etat=32 ; // code valid or not 

int BF =33 ; // barriére fermer 
int BO =25; // barriére ouver 


void open_br(){ 
    int v_ob =digitalRead(OB);
    //Serial.println("OB = ");
    //Serial.print(v_ob);
    if(v_ob==1){
      digitalWrite(BO, HIGH);
      digitalWrite(BF, LOW);
      
    }
}
void close_br() {
  int v_fb =digitalRead(FB);
     // Serial.println("FB = ");
     // Serial.print(v_fb);
      digitalWrite(BF, HIGH);
      digitalWrite(BO, LOW);
    }

bool check_pv() { 
  int v_pv =digitalRead(PV);
  //Serial.println("PV = ");
  //Serial.print(v_pv);
  
  if(v_pv==0){
    return false ; 
  }
  if(v_pv==1){
    return true ; 
  } 
  else return false ; 
}

void setup() {
  pinMode(PV, INPUT);
  pinMode(FB, INPUT);
  pinMode(OB, INPUT);
  pinMode(etat, INPUT);
  pinMode(BF, OUTPUT);
  pinMode(BO, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}




void loop() {
  
    close_br();
    //Serial.println("barriére fermer ");
    Serial.println(check_pv());
      while(check_pv()){
        Serial.println("car = 1 ");
          delay(4000);
          int code = digitalRead(etat) ; 
           Serial.println(code);
          while(code==0){
             int code = digitalRead(etat) ; 
          }
          Serial.println(code);
          int v_pv =digitalRead(PV);
          Serial.println(v_pv);

          while(check_pv() && (code ==1)) {
            Serial.println("code valid");
            int v_ob =digitalRead(OB);
            Serial.println(v_ob);
              while( check_pv() && (code ==1) && (v_ob==1)){
                open_br();
                Serial.println(" barriére ouver ");
                delay(3000);
                while(check_pv()){
                  delay(2000);
                  int v_pv =digitalRead(PV);
                  Serial.println(v_pv);
                  int code = digitalRead(etat) ; 
                  int v_ob =digitalRead(OB);
                  int v_fb =digitalRead(FB);
                }
                close_br(); 
                Serial.println("barriére fermer ");
             }
          }
      } 
}






/*bool code_isValid(){ 
  int code = digitalRead(etat) ; 
  if(code ==1) { 
   // Serial.println("code valide");
    return true ;
  }
  else return false ;
}*/