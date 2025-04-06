#define DOT_PIN 23   // Button for '.'
#define DASH_PIN 22  // Button for '_'
#define SPACE_PIN 21 // Button for ' '

String morseCode = "";      // Stores the Morse sequence
String decodedWord = "";    // Stores the translated word
int spaceCount = 0;         // Tracks consecutive space presses

void setup() {
  pinMode(DOT_PIN, INPUT);
  pinMode(DASH_PIN, INPUT);
  pinMode(SPACE_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(DOT_PIN) == HIGH) {
    morseCode += "."; // Append dot
    delay(1500);      // Debounce delay
  }

  if (digitalRead(DASH_PIN) == HIGH) {
    morseCode += "_"; // Append dash
    delay(1500);      // Debounce delay
  }

  if (digitalRead(SPACE_PIN) == HIGH) {
    spaceCount++;

    if (spaceCount == 1) {  
      String letter = decodeMorse(morseCode);  // Convert Morse to text
      Serial.println("Morse Code: " + letter);
      if (letter != "?") {
        decodedWord += letter;  // Append to word
      }
      morseCode = "";  // Reset Morse buffer
    } 
    else if (spaceCount == 2) {  
      Serial.println("Word: " + decodedWord); // Print full word
      decodedWord = ""; // Reset word for the next input
      spaceCount = 0; // Reset space counter
    }
    
    delay(1000);  // Debounce delay
  } 
  else {
    spaceCount = 0; // Reset if space is not pressed continuously
  }
}

String decodeMorse(String code) {
  if (code == ".") return "E";
  else if (code == "_") return "T";
  else if (code == "._") return "A";
  else if (code == "..") return "I";
  else if (code == "...") return "S";
  else if (code == "....") return "H";
  else if (code == "..._") return "V";
  else if (code == ".._") return "U";
  else if (code == ".._.") return "F";
  else if (code == "._.") return "R";
  else if (code == "._..") return "L";
  else if (code == ".__") return "W";
  else if (code == ".__.") return "P";
  else if (code == ".___") return "J";
  else if (code == "_..") return "D";
  else if (code == "_...") return "B";
  else if (code == "_.._") return "X";
  else if (code == "_._") return "K";
  else if (code == "_._.") return "C";
  else if (code == "_.__") return "Y";
  else if (code == "__") return "M";
  else if (code == "__.") return "G";
  else if (code == "__..") return "Z";
  else if (code == "___.") return "Q";
  
  // Digits (0-9)
  else if (code == "_____") return "0";
  else if (code == ".____") return "1";
  else if (code == "..___") return "2";
  else if (code == "...__") return "3";
  else if (code == "...._") return "4";
  else if (code == ".....") return "5";
  else if (code == "_....") return "6";
  else if (code == "__...") return "7";
  else if (code == "___..") return "8";
  else if (code == "____.") return "9";

  return "?"; // Unknown code
}
