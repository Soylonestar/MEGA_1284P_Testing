# MEGA_1284P_Testing

## Purpose and Reason
This is my personal project on getting to know how to work the Mega-1284P board. There is no limit what I'll do with it. <br/>
It can be from lighting an LED to trying an LCD and sending USART data to it via I2C protocol, etc. It can be anything. <br/>
Of course all of this will be documented and explained as to what I did with updates...

## Testing/Updates
7/8/24 <br/>
Found some useful links for linking LCD with I2C to the boards...my main problem is knowing what address to set LCD (I think...) and how to write into it so that it does
whatever I ask it to...that's the hard part...<br/>

Helpful Links: <br/>
[Video about LCD I2C communication](https://youtu.be/QyoLxOkJcKY?si=hDH9KWU8DHB1WgvR) <br/>
[MEGA_1284P DataSheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATmega164A_PA-324A_PA-644A_PA-1284_P_Data-Sheet-40002070B.pdf) <br/>

UPDATE: <br/>
Continuing on working on the MEGA-1284P Code...<br/>

The programming cable connections are as follows for the Atmel-ICE: <br/>
1) Pin 1 to TCK <br /> 
2) Pin 2 to GND <br />
3) Pin 3 to TDO <br />
4) Pin 4 to VCC <br />
5) Pin 5 to TMS <br />
6) Pin 6 to RESET <br /> 
7) ---- <br />
8) ---- <br />
9) Pin 9 to TDI <br />
10) Pin 0 to GND <br />




