#include <SPI.h>
#include <SD.h>

int seleccion;

File myFile;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  SPI.setModule(0);


  Serial.print("Initializing SD card...");
  pinMode(PA_3, OUTPUT);

  if (!SD.begin(PA_3)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");





  myFile = SD.open("/");

  printDirectory(myFile, 0);

  Serial.println("done!");

}

void loop()
{


  if (Serial.available() > 0) {

    Serial.println("Selecciona la imagen que deseas ver:");
    Serial.println("1---->Para ver a Donkey Kong:");
    Serial.println("1---->Para ver a Link:");
    Serial.println("1---->Para ver a Scorpion:");
    seleccion = Serial.read();
    if (seleccion == '1') {
      Serial.println("Este esss Donkey Kong:");
      imprimirDonkey();
      
    }
    else if (seleccion == 2) {
      imprimirLink();
      
    }
    else if (seleccion == 3) {
      imprimirScorpion();
      
    }
    else {
      Serial.println("Lo siento :( esa opcion no existe");
    }

  }



}

void imprimirLink(void) {
  myFile = SD.open("LINK8B~1.txt");
  if (myFile) {
    Serial.println("LINK8B~1.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

}

void imprimirScorpion(void) {
  myFile = SD.open("SCORPI~1.txt");
  if (myFile) {
    Serial.println("SCORPI~1.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void imprimirDonkey(void) {
  myFile = SD.open("DONKEY~1.txt");
  if (myFile) {
    Serial.println("DONKEY~1.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}



void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}
