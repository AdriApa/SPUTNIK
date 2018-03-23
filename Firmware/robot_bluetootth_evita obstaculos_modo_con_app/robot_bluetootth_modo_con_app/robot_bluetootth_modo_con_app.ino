#include <NewPing.h>
NewPing pollo(3,4); // Triger=8, Echo=9.
int distancia;
int opcion;
char dato;
int Va=250;
int Vb=250;

void setup() {
  pinMode(6,OUTPUT);//MOTOR 1
  pinMode(7,OUTPUT);//MOTOR 1
  pinMode(8,OUTPUT);//MOTOR 2
  pinMode(9,OUTPUT);//MOTOR 2
   
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    dato=Serial.read();
    Serial.print(dato);
    switch(dato){
     case('W'):{
      opcion=0;
      break;
     }
     case('w'):{
      opcion=1;
      break;
     }
    }
   if(opcion==0){//sonnar
    distancia=pollo.ping_cm();
  Serial.println(distancia);
  if(pollo.ping_cm()>=20){
        analogWrite(10,250);
        digitalWrite(6,1);
        digitalWrite(7,0);  
        //MOTOR 2 
        analogWrite(11,250);
        digitalWrite(8,1);
        digitalWrite(9,0);
        delay(20);
        //distancia=pollo.ping_cm();
   }
   if(pollo.ping_cm()<20){
   analogWrite(10,255);
   digitalWrite(6,0);
   digitalWrite(7,1);  
        //MOTOR 2 
   analogWrite(11,250);
   digitalWrite(8,1);
   digitalWrite(9,0);
   delay(400);
  }  
   }
  
  if(opcion==1){
    
    
    switch (dato) {
      case ('F'): {    //Adelante
         //MOTOR 1
  analogWrite(10,Va);
  digitalWrite(6,1);
  digitalWrite(7,0);  
 //MOTOR 2 
  analogWrite(11,Vb);
  digitalWrite(8,1);
  digitalWrite(9,0);    
          break;
        }
   case('I'): { //MOV.ADELANTE DERECHA
    //motor derecha 
     analogWrite(10,80);
     digitalWrite(6,1);
     digitalWrite(7,0);
    //motor izquierda
     analogWrite(11,Va);
     digitalWrite(8,1);
     digitalWrite(9,0);
     break;
   }
   
   case('G'): { //MOV.ADELANTE IZQUIERDA
    //motor derecha 
     analogWrite(10,Va);
     digitalWrite(6,1);
     digitalWrite(7,0);
    //motor izquierda
     analogWrite(11,80);
     digitalWrite(8,0);
     digitalWrite(9,1);
     break;
  }
      case ('B'): {    //Atrás
          //MOTOR 1
  analogWrite(10,Va);
  digitalWrite(6,0);
  digitalWrite(7,1); 
 //MOTOR 2
  analogWrite(11,Vb);
  digitalWrite(8,0);
  digitalWrite(9,1);
          break;
          }
      
      
      case ('L'): {       //IZQUIERDA
          //MOTOR 1
  analogWrite(10,Va);
  digitalWrite(6,1);
  digitalWrite(7,0);
 //MOTOR 2
  analogWrite(11,0);
  digitalWrite(8,1);
  digitalWrite(9,0);
          break;
        }
      case ('R'): {     //DERECHA
          //MOTOR 1
  analogWrite(10,0);
  digitalWrite(6,1);
  digitalWrite(7,0);
 //MOTOR 2
  analogWrite(11,Vb);
  digitalWrite(8,1);
  digitalWrite(9,0);
          break;
  case('J'): { //MOV.ATRAS DERECHA
    //motor derecha 
     analogWrite(10,80);
     digitalWrite(6,0);
     digitalWrite(7,1);
    //motor izquierda 
     analogWrite(11,Vb);
     digitalWrite(8,0);
     digitalWrite(9,1);
     break;
   }

   case('H'): { //MOV.ATRAS IZQUIERDA
    //motor derecha 
     analogWrite(10,Va);
     digitalWrite(6,0);
     digitalWrite(7,1);
    //motor izquierda 
     analogWrite(11,80);
     digitalWrite(8,1);
     digitalWrite(9,0);
     break;
   }
        }
        case ('X'): {    //MICHAEL JACKSON
          //MOTOR 1
  analogWrite(10,Va);
  digitalWrite(6,1);
  digitalWrite(7,0);
 //MOTOR 2
  analogWrite(11,Vb);
  digitalWrite(8,0);
  digitalWrite(9,1);
  delay(2000);
        }
         case ('x'): {    //MICHAEL JACKSON
          //MOTOR 1
  analogWrite(10,Va);
  digitalWrite(6,1);
  digitalWrite(7,0);
 //MOTOR 2
  analogWrite(11,Vb);
  digitalWrite(8,0);
  digitalWrite(9,1);
  delay(2000);
        }
        case ('S'): {
          analogWrite (10,0);
          analogWrite (11,0);
          //stop
        }
    }
    }
  }
}

   
      
          
          
        
    
  


//FUNCIONES DE USUARIO

//void adelante( ){
 
//}

