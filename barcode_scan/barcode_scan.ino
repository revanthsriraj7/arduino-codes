#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
String barcodes[6];  // Array to store 6 barcodes
int Count = 0;  // Variable to track the number of barcodes scanned
int once = 1;
String state[6];
String year[6];
String gbs[6];
String batchno[6];
String balloon[6];
String diameter[6];
String length[6];
String sequence[6];

void setup() {
  Serial.begin(9600);
  SerialBT.begin("STENT DATA");
}

void loop() {
  if (SerialBT.available()) {
    String vial_scan = SerialBT.readString();  // Read the barcode from Bluetooth

    if (Count < 6) {
      barcodes[Count] = vial_scan;  // Store the barcode in the array
      Count++;  
      Serial.print("Barcode stored: ");
      Serial.println(vial_scan);  // Print the scanned barcode
    } else {
      SerialBT.print("stop");
    }
  }
  /*if (Count == 6){
  for (int i = 0; i < 6; i++) {
    Serial.print("Barcode ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(barcodes[i]);
    Count = 6;
  }
 }*/

  String vial1 = barcodes[0];
  String vial2 = barcodes[1];
  String vial3 = barcodes[2];
  String vial4 = barcodes[3];
  String vial5 = barcodes[4];
  String vial6 = barcodes[5];

  state[0] = vial1[0];
  state[1] = vial2[0];
  state[2] = vial3[0];
  state[3] = vial4[0];
  state[4] = vial5[0];
  state[5] = vial6[0];

  year[0] = vial1.substring(1,3);
  year[1] = vial2.substring(1,3);
  year[2] = vial3.substring(1,3);
  year[3] = vial4.substring(1,3);
  year[4] = vial5.substring(1,3);
  year[5] = vial6.substring(1,3);

  gbs[0] = vial1.substring(3,5);
  gbs[1] = vial2.substring(3,5);
  gbs[2] = vial3.substring(3,5);
  gbs[3] = vial4.substring(3,5);
  gbs[4] = vial5.substring(3,5);
  gbs[5] = vial6.substring(3,5);

  batchno[0] = vial1.substring(5,8);
  batchno[1] = vial2.substring(5,8);
  batchno[2] = vial3.substring(5,8);
  batchno[3] = vial4.substring(5,8);
  batchno[4] = vial5.substring(5,8);
  batchno[5] = vial6.substring(5,8);

  balloon[0] = vial1[8];
  balloon[1] = vial2[8];
  balloon[2] = vial3[8];
  balloon[3] = vial4[8];
  balloon[4] = vial5[8];
  balloon[5] = vial6[8];

  diameter[0] = vial1.substring(9,12);
  diameter[1] = vial2.substring(9,12);
  diameter[2] = vial3.substring(9,12);
  diameter[3] = vial4.substring(9,12);
  diameter[4] = vial5.substring(9,12);
  diameter[5] = vial6.substring(9,12);

  length[0] = vial1.substring(12,15);
  length[1] = vial2.substring(12,15);
  length[2] = vial3.substring(12,15);
  length[3] = vial4.substring(12,15);
  length[4] = vial5.substring(12,15);
  length[5] = vial6.substring(12,15);

  sequence[0] = vial1.substring(15,18);
  sequence[1] = vial2.substring(15,18);
  sequence[2] = vial3.substring(15,18);
  sequence[3] = vial4.substring(15,18);
  sequence[4] = vial5.substring(15,18);
  sequence[5] = vial6.substring(15,18);

  if(Count == 6){
    Serial.print("state: ");
    for(int i =0; i<6; i++){
      Serial.print(state[i]);
      Serial.print(", ");
    }

    Serial.println(" ");
    Serial.print("year: ");
    for(int i =0; i<6; i++){
      Serial.print(year[i]);
      Serial.print(", ");
    }

    Serial.println(" ");
    Serial.print("batch storification: ");
    for(int i =0; i<6; i++){
      Serial.print(gbs[i]);
      Serial.print(", ");
   }

   Serial.println(" ");
    Serial.print("batch number: ");
    for(int i =0; i<6; i++){
      Serial.print(batchno[i]);
      Serial.print(", ");
   }

   Serial.println(" ");
    Serial.print("balloon type: ");
    for(int i =0; i<6; i++){
      Serial.print(balloon[i]);
      Serial.print(", ");
   }

   Serial.println(" ");
    Serial.print("diameter: ");
    for(int i =0; i<6; i++){
      Serial.print(diameter[i]);
      Serial.print(", ");
   }

   Serial.println(" ");
    Serial.print("length: ");
    for(int i =0; i<6; i++){
      Serial.print(length[i]);
      Serial.print(", ");
   }

   Serial.println(" ");
    Serial.print("sequence no.: ");
    for(int i =0; i<6; i++){
      Serial.print(sequence[i]);
      Serial.print(", ");
   }
    Count = 7;
  }
}
