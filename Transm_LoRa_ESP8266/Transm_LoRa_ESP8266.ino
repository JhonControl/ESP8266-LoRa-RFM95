// LoRa 9x_TX
// -*- mode: C++ -*-
// Example sketch showing how to create a simple messaging client (transmitter)
// with the RH_RF95 class. RH_RF95 class does not provide for addressing or
// reliability, so you should only use RH_RF95 if you do not need the higher
// level messaging abilities.
// It is designed to work with the other example LoRa9x_RX

/*--------------------------------------------------------------
  Program:      Comunication RMF96 LoRa & ESP8266 12E - Transmission

  Description:   Example Communication LoRa Transmission  with the RFM96 Modem with ESP8266 12E,
                 set to 915.0 MHz

                 Ejemplo de Comunicacion Transmision LoRa con el Modem RFM96 con ESP8266 12E, 
                 ajustado a 915.0 MHz

  
  Hardware:     ESP8266 12E NodeMCU Lolin .
                Modem RFM96 - HopeRF electronics
             
                
  Software:     Arduino IDE v1.8.3
  
  Date:         7 Mar 2018
   
  Modified or Created:       PDAControl   http://pdacontroles.com   http://pdacontrolen.com

  Complete Tutorial English:            http://pdacontrolen.com/comunication-lora-esp8266-radio-rfm95-1/  
  Tutorial Completo Español             http://pdacontroles.com/comunicacion-lora-esp8266-radio-rfm96-1/

  Based: RH_RF95.h library              https://github.com/PaulStoffregen/RadioHead/tree/master/examples
          Adafruit                      https://github.com/adafruit/RadioHead/tree/master/examples

         RH_RF95.h API                  http://www.airspayce.com/mikem/arduino/RadioHead/RH__RF95_8h_source.html                             
 
--------------------------------------------------------------*/


#include <SPI.h>
#include <RH_RF95.h>


#define RFM95_CS 15
#define RFM95_RST 16
#define RFM95_INT 5

#define RF95_FREQ 915.0

#define LED 2


RH_RF95 rf95(RFM95_CS, RFM95_INT);

// Singleton instance of the radio driver
//RH_RF95 rf95(RFM95_CS, RFM95_INT);

void setup() 
{

  pinMode(LED, OUTPUT);
  digitalWrite(LED,HIGH);   
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);
  Serial.begin(9600);
  delay(100);

  Serial.println();

  Serial.println("Gateway Module starting…");

  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

  while (!rf95.init()) {

    Serial.println("LoRa radio init failed");

    while (1);

  }

  Serial.println("LoRa radio init OK!");

  if (!rf95.setFrequency(RF95_FREQ)) {

    Serial.println("setFrequency failed");

    while (1);

  }

  Serial.print("Set Freq to: ");  
  Serial.println(RF95_FREQ);  
  rf95.setTxPower(23, false);

}


int16_t packetnum = 0;  // packet counter, we increment per xmission

void loop()
{
  Serial.println("Sending to rf95_server");
  // Send a message to rf95_server
  
  char radiopacket[32] = "PDAControl - #      ";
  itoa(packetnum++, radiopacket+13, 10);
  Serial.print("Sending "); Serial.println(radiopacket);
  radiopacket[31] = 0;
  
  Serial.println("Sending..."); delay(10);
  rf95.send((uint8_t *)radiopacket, 20);
  
  digitalWrite(LED, HIGH);

  Serial.println("Waiting for packet to complete..."); delay(10);
  rf95.waitPacketSent();
  // Now wait for a reply
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);

  Serial.println("Waiting for reply..."); delay(10);
  if (rf95.waitAvailableTimeout(1000))
  { 
    // Should be a reply message for us now   
    if (rf95.recv(buf, &len))
   {
      Serial.print("Got reply: ");
      Serial.println((char*)buf);
      Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);    
    }
    else
    {
      Serial.println("Receive failed");
    }
  }
  else
  {
    Serial.println("No reply, is there a listener around?");
  }
  
  delay(1000);
    digitalWrite(LED, LOW);
}
