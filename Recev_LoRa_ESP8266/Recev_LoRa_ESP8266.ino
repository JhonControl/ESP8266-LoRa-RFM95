// Arduino9x_RX
// -*- mode: C++ -*-
// Example sketch showing how to create a simple messaging client (receiver)
// with the RH_RF95 class. RH_RF95 class does not provide for addressing or
// reliability, so you should only use RH_RF95 if you do not need the higher
// level messaging abilities.
// It is designed to work with the other example Arduino9x_TX

/*--------------------------------------------------------------
  Program:      Comunication RMF96 LoRa & ESP8266 12E - Reception

  Description:  Example of LoRa Reception Communication with the RFM96 Modem with ESP8266 12E,
                set to 915.0 MHz

                Ejemplo de Comunicacion Recepcion LoRa con el Modem RFM96 con ESP8266 12E, 
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

     // The default transmitter power is 13dBm, using PA_BOOST.
    // If you are using RFM95 / 96/97/98 modules using the transmitter pin PA_BOOST, then
    // you can set transmission powers from 5 to 23 dBm:

    rf95.setTxPower(23, false);

}



void loop()
{
  if (rf95.available())
  {
    // Should be a message for us now   
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    
    if (rf95.recv(buf, &len))
    {
      digitalWrite(LED, HIGH);
      RH_RF95::printBuffer("Received: ", buf, len);
      Serial.print("Got: ");
      Serial.println((char*)buf);
       Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);
      
      // Send a reply
      uint8_t data[] = "And hello back to you";
      rf95.send(data, sizeof(data));
      rf95.waitPacketSent();
      Serial.println("Sent a reply");
      digitalWrite(LED, LOW);
    }
    else
    {
      Serial.println("Receive failed");
    }
  }
}
