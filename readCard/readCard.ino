#include <SPI.h>
#include <MFRC522.h>
#include <EEPROM.h>
#define SS_PIN D4
#define RST_PIN D2
int address = 0;
byte value;
MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance of the class
void setup() {
   Serial.begin(9600);
   SPI.begin();       // Init SPI bus
   mfrc522.PCD_Init(); // Init MFRC522
   Serial.println("RFID reading UID");
   if ( mfrc522.PICC_IsNewCardPresent())
    {
        if ( mfrc522.PICC_ReadCardSerial())
        {
           Serial.print("New master card\n");
           Serial.print("Tag UID:");
           for (byte i = 0; i < mfrc522.uid.size; i++) {
                  Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                  Serial.print(mfrc522.uid.uidByte[i], DEC);
            }
            Serial.println();
            mfrc522.PICC_HaltA();
        }
    }
    EEPROM.begin(512);
    EEPROM.write(0, mfrc522.uid.uidByte[0]);
    EEPROM.write(1, mfrc522.uid.uidByte[1]);
    EEPROM.write(2, mfrc522.uid.uidByte[2]);
    EEPROM.write(3, mfrc522.uid.uidByte[3]);  
}
void loop() {
  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();

  // advance to the next address of the EEPROM
  address = address + 1;

  // there are only 512 bytes of EEPROM, from 0 to 511, so if we're
  // on address 512, wrap around to address 0
  if (address == 4) {
    address = 0;
  }
  delay(1000);
  //Serial.end();
}
