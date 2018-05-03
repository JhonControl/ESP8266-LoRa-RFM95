# LoRa Communication ESP8266 12E with Radios RFM95

Version 1.0   Date 02-05-2018   [PDAControl](http://pdacontrolen.com)

![alt text](http://pdacontroles.com/wp-content/uploads/2018/05/ESP8266_RFM95_1-.png "ESP-LoRa")

## Description

Basic Communication LoRa Using 2 Modules ESP8266 and 2 Radios LoRa RFM95 to 915.0 MHz.

Contains 2 Folders:

* Recev_LoRa_ESP8266: Sample Reception

* Transm_LoRa_ESP8266: Example of Transmission



## Descripción
Comunicación básica LoRa Utilizando 2 Modulos ESP8266 y 2 Radios LoRa RFM95 a 915.0 MHz.

Contiene 2 Carpetas:

* Recev_LoRa_ESP8266:  Ejemplo de Recepcion

* Transm_LoRa_ESP8266: Ejemplo de Transmision



## Librerias / Libraries

  
 * [RH_RF95.h library  PaulStoffregen/RadioHead]( https://github.com/PaulStoffregen/RadioHead) - RFM96 Library  
 
 * [examples](https://github.com/PaulStoffregen/RadioHead/tree/master/examples).
  
 
 * [Adafruit adafruit/RadioHead](https://github.com/adafruit/RadioHead) - RFM96 Library 
 
 * [examples](https://github.com/adafruit/RadioHead/tree/master/examples).  

Thanks for contributing 



# Materials / Materiales


* [2 ESP8266 12E NodeMCU](http://s.click.aliexpress.com/e/b6QNZfy) - Module Espressif
* [2 Radio RFM95 ,in my case 915.0 MHz ](http://s.click.aliexpress.com/e/Be2rrvB) - Radio LoRa
* [2 white PCBs Adapters for ESP8266 12E/F](http://s.click.aliexpress.com/e/mAIA6mA) - PCB's
* 2 Protoboard
* Wire antenna, UTP cable, calculate length below



## Mounting / Montaje
![alt text](http://pdacontroles.com/wp-content/uploads/2018/03/LoRA_esp8266_PDAControl_2.jpg "mounting")

## Connections / Conexiones

```
   ESP8266      -  RFM95/96
	Gpio15/D8   - NSS
	Gpio13/D7   - MOSI
	Gpio12/D6   - MISO
	Gpio14/D5   - SCK
	Gpio05/D1   - DIO0
	Gpio02/D4   - DIO1
	Gpio16/D0   - RST
	VCC         - 3.3V
	GND         - GND
```
        


# Documentation / Documentación 
* Read Considerations, Recommendations and Suggestions complete documentation of the project in [Communication LoRa ESP8266 & Radio RFM95 #1](http://pdacontrolen.com/comunication-lora-esp8266-radio-rfm95-1/). 

* Leer Consideraciones, Recomendaciones y sugerencias documentacion Completa del proyecto en  [Comunicación LoRa ESP8266 & Radio RFM95 #1](http://pdacontroles.com/comunicacion-lora-esp8266-radio-rfm96-1/). 

# Donations / Donaciones 
Collaborate this project and other projects in [PDAControl](http://pdacontrolen.com)  via [Paypal](https://www.paypal.me/pdacontrol). 

Respalde este proyecto y otros proyectos en [PDAControl](http://pdacontrolen.com)  mediante [Paypal](https://www.paypal.me/pdacontrol).

[![Support via PayPal](https://cdn.rawgit.com/twolfson/paypal-github-button/1.0.0/dist/button.svg)](https://www.paypal.me/pdacontrol)

# More about PDAControl / Mas sobre PDAControl
* [PDAControl English](http://pdacontrolen.com). 
* [PDAControl Español](http://pdacontroles.com). 
* [PDAControl Youtube Channel](https://www.youtube.com/channel/UCv1D6zrC0ZL0PSgM6tdEpPg/videos). 
* [Jhon_Control Twitter](https://twitter.com/Jhon_Control). 

