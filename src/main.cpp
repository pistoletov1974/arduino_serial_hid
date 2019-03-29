#include <Arduino.h>
#include <Keyboard.h>
 
 String s;

void setup() {
  // put your setup code here, to run once:
    delay(500);
    Keyboard.begin();
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(7,OUTPUT);
    delay(100);
    digitalWrite(7,LOW);
    Serial1.begin(19200
    );
    delay(2000);
    Serial1.println("just start port");
    //Keyboard.println("rhbljzghbve;");
        delay(1);
   



    /*

    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(45);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.println("cmd");
    Keyboard.write(KEY_RETURN);
    delay(200);u
    Keyboard.println("genoslav");
      Keyboard.releaseAll();
    delay(1000);
    digitalWrite(2,HIGH);
    delay(1);
    digitalWrite(3,HIGH);
    delay(50000);
    Keyboard.println(" on-of complete");
    
      Keyboard.releaseAll();
    digitalWrite(2,LOW);
    delay(1);
    digitalWrite(3,LOW);
    Keyboard.println(" on-of complete");
      Keyboard.releaseAll(); */
}

void loop() {
  // put your main code here, to run repeatedly:

   if (Serial1.available()>0) {

      s = Serial1.readString(); 
      digitalWrite(7,HIGH);

   } else
   {
     digitalWrite(7,LOW);
   }
   
   
    if  (s.length()>1)  Serial1.println(s);
    if (s.indexOf("usb_on")!=-1)
       {
         Serial1.println("usb_on");
         digitalWrite(2,HIGH);
         delay(1);
         digitalWrite(3,HIGH);
       s="";
       }



    if (s.indexOf("usb_off")!=-1)
       {
         digitalWrite(3,LOW);
         delay(1);
         digitalWrite(2,LOW);
        s="";
        }
    
   if ((s.indexOf("pwd")!=-1))
    {
        
        Serial1.println("rhbljzghbve;");
        Keyboard.println("rhbljzghbve;");
        delay(1);
        Keyboard.write(KEY_RETURN);
        Keyboard.releaseAll();
        s="";
   } else s="";


}