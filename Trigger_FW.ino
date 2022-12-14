#include <GyverTimers.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//unsigned long startMillis;  //some global variables available anywhere in the program
//unsigned long currentMillis;
//const unsigned long period = 1000;  //the value is a number of milliseconds

const unsigned char sourcecode [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x3f, 0x38, 0x00, 0x0c, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x3f, 0x38, 0x00, 0x0c, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x3f, 0x00, 0x1f, 0x3c, 0x60, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x3f, 0x00, 0x1f, 0x3c, 0x60, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc7, 0xe6, 0x33, 0xc6, 0x7c, 0x3c, 0x67, 0xe3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x33, 0xe6, 0x7c, 0x3c, 0x67, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x33, 0xe6, 0x7c, 0x3c, 0x67, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x3c, 0xe1, 0xfc, 0x0c, 0x67, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x3c, 0xe1, 0xfc, 0x0c, 0x67, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x00, 0x07, 0x9c, 0x30, 0x67, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x00, 0x07, 0x9c, 0x30, 0x67, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x30, 0xff, 0xe3, 0x3c, 0x60, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x30, 0xff, 0xe3, 0x3c, 0x60, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x33, 0x39, 0x9c, 0xcc, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x33, 0x39, 0x9c, 0xcc, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x39, 0x80, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x39, 0x80, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x39, 0x80, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xf0, 0x7e, 0x00, 0xe7, 0xe3, 0x30, 0x19, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xf0, 0x7e, 0x00, 0xe7, 0xe3, 0x30, 0x19, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3e, 0x61, 0xff, 0x38, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3e, 0x61, 0xff, 0x38, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc1, 0xff, 0xc0, 0xff, 0xff, 0xc0, 0x7f, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc1, 0xff, 0xc0, 0xff, 0xff, 0xc0, 0x7f, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0xf3, 0xe6, 0x7f, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0xf3, 0xe6, 0x7f, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x04, 0x63, 0xf3, 0xfe, 0x7f, 0xff, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0e, 0x66, 0x03, 0x3e, 0x1c, 0xf3, 0x87, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0e, 0x66, 0x03, 0x1e, 0x18, 0xf3, 0x87, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xf1, 0xf9, 0xc0, 0x07, 0x80, 0xc3, 0x9e, 0x70, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xf1, 0xf9, 0xc0, 0x07, 0x80, 0xc3, 0x9e, 0x70, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xce, 0x66, 0x3c, 0x00, 0x63, 0xf0, 0x67, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xce, 0x66, 0x3c, 0x00, 0x63, 0xf0, 0x67, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xf9, 0xfc, 0x39, 0x9f, 0x33, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xf9, 0xfc, 0x39, 0x9f, 0x33, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0x86, 0x0c, 0xe7, 0x87, 0xf0, 0x1e, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0x86, 0x0c, 0xe7, 0x83, 0xf0, 0x1e, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0x86, 0x0c, 0x67, 0x83, 0xf0, 0x1e, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0xcc, 0x38, 0x7c, 0x30, 0x61, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0xcc, 0x38, 0x7c, 0x30, 0x61, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xcc, 0xff, 0xe3, 0xf3, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xcc, 0xff, 0xe3, 0xf3, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x0c, 0xe6, 0x03, 0x3f, 0x80, 0x7c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x0c, 0xe6, 0x03, 0x3f, 0x80, 0x7c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xf1, 0x9f, 0xc0, 0x3e, 0x03, 0xff, 0xff, 0x8c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xf1, 0x9f, 0xc0, 0x3e, 0x03, 0xff, 0xff, 0x8c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x07, 0x9c, 0xcc, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x07, 0x9c, 0xcc, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x07, 0x98, 0xcc, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x0c, 0x00, 0x60, 0x3c, 0x66, 0x7f, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x0c, 0x00, 0x60, 0x3c, 0x66, 0x7f, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x33, 0x39, 0xe0, 0x3c, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x33, 0x39, 0xe0, 0x3c, 0x07, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x3f, 0xe7, 0x83, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x3f, 0xe7, 0x83, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x0f, 0x38, 0x1c, 0x33, 0xf9, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x0f, 0x38, 0x1c, 0x33, 0xf9, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x03, 0xff, 0xff, 0xf3, 0x80, 0x73, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xe6, 0x03, 0xff, 0xff, 0xf3, 0x80, 0x73, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc7, 0xe6, 0x03, 0xff, 0xff, 0xf3, 0x80, 0x73, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x30, 0xe6, 0x63, 0xfc, 0x7f, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x30, 0xe6, 0x63, 0xfc, 0x7f, 0xf3, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x33, 0x3e, 0x00, 0xfc, 0x7e, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x33, 0x3e, 0x00, 0xfc, 0x7e, 0x0c, 0x00, 0x00, 0x00, 0x00
};

float vbus = 0.0;
float current = 0.0;

int upbutton;
int downbutton;
int leftbutton;
int rightbutton;
int exebutton;
int checkflag = LOW;
int tempcheck = 0;
int vcheck = 0;

int vertical = 0;
int horizontal = 0;

void setup()
{
  //Serial.begin(9600);
  analogReference(EXTERNAL);//5.0V Vref
  Timer1.setFrequency(50); 
  Timer1.enableISR();
  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  oled.clearDisplay();
  //startMillis = millis();
  
  pinMode(13, INPUT_PULLUP);//UP
  pinMode(12, INPUT_PULLUP);//DOWN
  pinMode(11, INPUT_PULLUP);//LEFT
  pinMode(10, INPUT_PULLUP);//RIGHT
  pinMode(9, INPUT_PULLUP);//EXECUTE
  pinMode(7, OUTPUT);digitalWrite(7, LOW);//18V
  pinMode(6, OUTPUT);digitalWrite(6, LOW);//15V
  pinMode(5, OUTPUT);digitalWrite(5, LOW);//12V
  pinMode(4, OUTPUT);digitalWrite(4, HIGH);//9V
  pinMode(3, OUTPUT);digitalWrite(3, LOW);//5V
  //oled.begin(SSD1306_SWITCHCAPVCC, 0x3D); //or 0x3C
}


void loop()
{
  upbutton = digitalRead(13);
  downbutton = digitalRead(12);
  leftbutton = digitalRead(11);
  rightbutton = digitalRead(10);
  exebutton = digitalRead(9);

  optionselect();
  execution();
  displaypage();
}

void optionselect(){
  if(upbutton == LOW){
    delay(200);
    vertical++;
    if(vertical > 4) vertical = 0;
  }
  if(downbutton == LOW){
    delay(200);
    vertical--;
    if(vertical < 0) vertical = 4;
  }
  if(leftbutton == LOW){
    delay(200);
    horizontal--;
    if(horizontal < 0) horizontal = -1;
  }
  if(rightbutton == LOW){
    delay(200);
    horizontal++;
    if(horizontal > 1) horizontal = 1;
  }
}

void execution(){
  if(exebutton == LOW){
    delay(200);
    displaypage();
    if(vertical == 0){
      digitalWrite(7, LOW);//18V
      digitalWrite(6, LOW);//15V
      digitalWrite(5, LOW);//12V
      digitalWrite(4, HIGH);//9V Enable
      digitalWrite(3, LOW);//5V
    }
    else if(vertical == 1){
      digitalWrite(7, LOW);//18V
      digitalWrite(6, LOW);//15V
      digitalWrite(5, HIGH);//12V Enable
      digitalWrite(4, LOW);//9V
      digitalWrite(3, LOW);//5V
    }
    else if(vertical == 2){
      digitalWrite(7, LOW);//18V
      digitalWrite(6, HIGH);//15V Enable
      digitalWrite(5, LOW);//12V
      digitalWrite(4, LOW);//9V
      digitalWrite(3, LOW);//5V
    }
    else if(vertical == 3){
      digitalWrite(7, HIGH);//18V Enable
      digitalWrite(6, LOW);//15V
      digitalWrite(5, LOW);//12V
      digitalWrite(4, LOW);//9V
      digitalWrite(3, LOW);//5V
    }
    else if(vertical == 4){
      //20V Enable
      digitalWrite(7, LOW);//18V
      digitalWrite(6, LOW);//15V
      digitalWrite(5, LOW);//12V
      digitalWrite(4, LOW);//9V
      digitalWrite(3, LOW);//5V
    }
    tempcheck = vertical;
    delay(300);
    /*if(vbus > 8 && vbus < 10) vcheck = 0;
    else if(vbus > 10 && vbus < 13) vcheck = 1;
    else if(vbus > 13 && vbus < 16) vcheck = 2;
    else if(vbus > 16 && vbus < 19) vcheck = 3;
    else if(vbus > 19 && vbus < 21) vcheck = 4;

    if(tempcheck == vcheck) checkflag = LOW;
    else checkflag = HIGH;*/
  }
}

void displaypage(){
  if(horizontal == 0)  mainpage();
  else if(horizontal == 1) sourcecodepage();
  else if(horizontal == -1) cautionpage();
}

void sourcecodepage(){
  oled.clearDisplay(); // clear display
  oled.setTextSize(1);          // text size
  oled.setTextColor(WHITE, BLACK);     // text color
  oled.drawBitmap(0, 0, sourcecode, 128, 64, WHITE);
  oled.display(); 
}

void mainpage(){
  oled.clearDisplay();
  oled.setTextSize(1); 
  oled.setTextColor(WHITE, BLACK);
  //oled.drawRoundRect(0, 0, 128, 64, 4, WHITE);
  
  oled.setCursor(0, 0);
  if(vbus < 1) oled.println("POWER DISCONNECTED");
  else{
    oled.print("POWER CONNECTED");

    oled.setCursor(0, 26);
    if(checkflag == LOW) oled.print("PDV SUPPORTED");
    else oled.print("PDV NOT SUPPORTED");
  }
  
  
  oled.setCursor(0, 16);
  if(vertical == 0) oled.print("TRIGGER: 9.00V");
  else if(vertical == 1) oled.print("TRIGGER:12.00V");
  else if(vertical == 2) oled.print("TRIGGER:15.00V");
  else if(vertical == 3) oled.print("TRIGGER:18.00V");
  else if(vertical == 4) oled.print("TRIGGER:20.00V");

  oled.setCursor(0, 40);
  if(vbus < 10) oled.print("VOLTAGE: ");
  else oled.print("VOLTAGE:");
  oled.print(vbus);oled.print("V");

  oled.setCursor(0, 50);
  oled.print("CURRENT: ");
  oled.print(current);oled.print("A");
  
  oled.display();
}

void cautionpage(){
  oled.clearDisplay();
  oled.setTextSize(1); 
  oled.setTextColor(WHITE, BLACK);
  oled.setCursor(0, 0);
  
  oled.print("CAUTION              ");
  oled.println();
  printline();
  nextline(0, 8);
  oled.print("POWER Max. :25.0V 3A ");
  nextline(0, 10);
  oled.print("MCU VOLTAGE: 5.0V    ");
  nextline(0, 10);
  oled.print("OVP NOT SUPPORTED  ");
  nextline(0, 16);
  oled.print("DESIGNED BY SOBER LAM");
  oled.display();
}

void printline(){
  for (int y = oled.getCursorY(); y<= oled.getCursorY(); y++){
    for (int x=0; x<127; x++){
      oled.drawPixel(x, y, WHITE); 
      }
  }
}

void nextline(int x, int yoffset){
  oled.setCursor(x, oled.getCursorY()+yoffset);
}

/*void arrow(){
  oled.setCursor(30, oled.getCursorY());
  oled.print(" <<-");
  //oled.invertDisplay(true);
}*/

void oledDisplayCenter(String text) {
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;
  oled.setTextColor(WHITE, BLACK);
  //oled.setTextSize(2);
  oled.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);

  oled.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
  oled.print(text); // text to display
  //oled.display();
}

ISR(TIMER1_A) {
  vbus = 0;
  current = 0;
  for (int i = 0; i < 25; i++){
    vbus = vbus + ((analogRead(A0) * 5.0) / 1024) / 0.2424;
  }
  //vbus = ((analogRead(A0) * 5.0) / 1024) / 0.2424;// ~24K/99K
  vbus = vbus / 25;
  if(vbus < 4) vbus = 0;
  else if(vbus > 20.5) vbus = 0;
  for (int i = 0; i < 25; i++){
    current = current + (analogRead(A2) * 5.0) / 1024;;
  }
  current = current / 25;
  //Serial.println(current);
  current = (2.45 - current) / 0.49;// 500mV/A
  if(current < 0.03 || vbus == 0) current = 0;
  

  if(vbus > 8 && vbus < 10) vcheck = 0;
  else if(vbus > 10 && vbus < 13) vcheck = 1;
  else if(vbus > 13 && vbus < 16) vcheck = 2;
  else if(vbus > 16 && vbus < 19) vcheck = 3;
  else if(vbus > 19 && vbus < 21) vcheck = 4;
  if(tempcheck == vcheck) checkflag = LOW;
  else checkflag = HIGH;
  

  /*as = current / 36000;
  ah = ah + as;
  ws = (vbus * current) / 36000;
  wh = wh + ws;
  if(vbus < 4){
    ah = 0;
    wh = 0;
  }*/
}
