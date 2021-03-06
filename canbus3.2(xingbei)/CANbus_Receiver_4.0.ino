#include <FlexCAN.h>
CAN_message_t msg;
CAN_message_t inMsg;

// -------------------------------------------------------------
void setup(void)
{
  //for LED onboard Teensy
  pinMode(13, OUTPUT); 
  digitalWrite(13, HIGH); 

  

  Can0.begin();  
  

    msg.ext = 0;
    msg.id = 0x100;
    msg.len = 8;
    msg.buf[0] = 0x00;
    msg.buf[1] = 0x01;
    msg.buf[2] = 0x02;
    msg.buf[3] = 0x03;
    msg.buf[4] = 0x04;
    msg.buf[5] = 0x05;
    msg.buf[6] = 0x06;
    msg.buf[7] = 0x07;

}

void print_msg(CAN_message_t toto) {
  Serial.print("Message id ");
  Serial.println(toto.id);
  for(uint8_t i = 0 ; i< toto.len;i++) {
      Serial.print(toto.buf[i]);
      Serial.print("\t");
    }
    Serial.println();
}


// -------------------------------------------------------------
void loop(void)
{
  
  //RECEIVE MESSAGE
  while(Can0.read(inMsg)) {
    //blink LED so we can see message is received
    pinMode(13, LOW);
    delay(500);
    pinMode(13, HIGH);
    delay(500);
    Serial.println("CANtest - Read bus1");
    Serial.println(inMsg.buf[0]*100+inMsg.buf[1]);
    print_msg(inMsg);
  }
}
