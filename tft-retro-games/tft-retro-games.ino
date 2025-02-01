#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>
#define MINPRESSURE 200
#define MAXPRESSURE 1000

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define ORANGE  0xFD20

const int XP=8,XM=A2,YP=A3,YM=9; //240x320 ID=0x9341
const int TS_LEFT=106,TS_RT=927,TS_TOP=76,TS_BOT=893;


int s = 0;          //start var
int a = 1;          //pause var
int x = 95;         //paddle pos var
int positionX = 120;//ball X position
int positionY = 240;//ball Y position
int speedX = 0;     //ball speed
int speedY = 0;     //ball speed
int k = 0;          //floor1
int l = 0;          //floor2
int i = 0;          //floor3
int h = 0;          //floor4
int B = 0;          //start breakout var
int f = 0;          //exit var
int P = 0;          //pong var
int g = 0;          //score var
int y2 = 250;       //the ball should not pass this
int r = 1;          // pong start var
int v = 0;          // pong start var


TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_GFX_Button left_btn, right_btn, pause_btn, start_btn, breakout_btn, pong_btn, exit_btn;

int pixel_x, pixel_y;  
bool Touch_getXY(void)
{
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);    
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);
    digitalWrite(XM, HIGH);
    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    if (pressed) {
        pixel_x = map(p.x, TS_LEFT, TS_RT, 0, tft.width());
        pixel_y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
    }
    return pressed;
}

void setup()
{
    Serial.begin(9600);
    uint16_t ID = tft.readID();
    Serial.print("TFT ID = 0x");
    Serial.println(ID, HEX);
    Serial.println("Calibrate for your Touch Panel");
    if (ID == 0xD3D3) ID = 0x9486; 
    tft.begin(ID);
    tft.setRotation(0);            
    tft.fillScreen(BLACK);
    left_btn.initButton(&tft, 40, 290, 75, 50, BLACK, BLACK, WHITE, "<-", 3);
    right_btn.initButton(&tft, 200, 290, 75, 50, BLACK, BLACK, WHITE, "->", 3);
    pause_btn.initButton(&tft, 220, 10, 40, 20, BLACK, BLACK, WHITE, "-", 3);
    start_btn.initButton(&tft, 120, 150, 150, 50, BLACK, BLACK, BLACK, "", 3);
    breakout_btn.initButton(&tft, 120, 50, 150, 50, BLACK, BLACK, BLACK, "", 3);
    pong_btn.initButton(&tft, 120, 100, 100, 50, BLACK, BLACK, BLACK, "", 3);
    exit_btn.initButton(&tft, 20, 10, 40, 20, BLACK, BLACK, WHITE, "x", 3);
    exit_btn.drawButton(false);
    pong_btn.drawButton(false);
    breakout_btn.drawButton(false);
    start_btn.drawButton(false);
    pause_btn.drawButton(false);
    left_btn.drawButton(false);
    right_btn.drawButton(false);
}

//---------------------------------------------drawrect----------------------------------


 void drawrect() {                          // make the round rects
  tft.fillRoundRect(0, 30, 59, 10, 3, RED);
  tft.fillRoundRect(60, 30, 59, 10, 3, RED);
  tft.fillRoundRect(120, 30, 59, 10, 3, RED);
  tft.fillRoundRect(180, 30, 59, 10, 3, RED);
  
  tft.fillRoundRect(0, 41, 59, 10, 3, ORANGE);
  tft.fillRoundRect(60, 41, 59, 10, 3, ORANGE);
  tft.fillRoundRect(120, 41, 59, 10, 3, ORANGE);
  tft.fillRoundRect(180, 41, 59, 10, 3, ORANGE);

  tft.fillRoundRect(0, 52, 59, 10, 3, YELLOW);
  tft.fillRoundRect(60, 52, 59, 10, 3, YELLOW);
  tft.fillRoundRect(120, 52, 59, 10, 3, YELLOW);
  tft.fillRoundRect(180, 52, 59, 10, 3, YELLOW);
  
  tft.fillRoundRect(0, 63, 59, 10, 3, GREEN);
  tft.fillRoundRect(60, 63, 59, 10, 3, GREEN);
  tft.fillRoundRect(120, 63, 59, 10, 3, GREEN);
  tft.fillRoundRect(180, 63, 59, 10, 3, GREEN);
 }
 



//---------------------------------------gameGUI--------------------------------------------------


void gameGUI() {  // check if gameGUI already has run
  if ( f == 0) {                        
  tft.setCursor(0, 160);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("PLEASE CHOOSE A GAME");
  tft.setCursor(50, 40);
  tft.setTextSize(3);
  tft.setTextColor(RED);
  tft.print("BREAKOUT");
  tft.setCursor(90, 90);
  tft.setTextSize(3);
  tft.setTextColor(ORANGE);
  tft.print("PONG");
  
  }


    bool down = Touch_getXY();
    breakout_btn.press(down && breakout_btn.contains(pixel_x, pixel_y));
    pong_btn.press(down && pong_btn.contains(pixel_x, pixel_y));
    

    if (breakout_btn.justReleased())
        breakout_btn.drawButton();

        if (pong_btn.justReleased())
            pong_btn.drawButton();
  
        if (breakout_btn.justPressed()) { // check if buttons pressed
            breakout_btn.drawButton(true);
            tft.fillScreen(BLACK);
            B = 1; 
            f = 1;
            }

        if (pong_btn.justPressed()) { // check if buttons pressed
            pong_btn.drawButton(true);
            tft.fillScreen(BLACK);
            P = 1;
            f = 1;
            r = 1;
           }
        
}




 
//----------------------------------------------pong-------------------------------------------



 void pong() {
   if (P == 1) { // if P = 1 start pong
      B = 0;
  if ( r == 1) { // if r = 1 dont start game till v = 1
   speedX = 0;
   speedY = 0;
  tft.setCursor(60,140);
  tft.setTextSize(4);
  tft.setTextColor(GREEN);
  tft.print("START");
  }
 }
  
  if ( v == 1) {  // if start is pressed, start game
    tft.fillScreen(BLACK);
    speedX = 1;
    speedY = -1;
    v = 0;
    r = 0;
    exit_btn.drawButton(true);
    exit_btn.drawButton(false);
    left_btn.drawButton(true);
    right_btn.drawButton(true);
    left_btn.drawButton(false);
    right_btn.drawButton(false);
  }
  
  tft.fillRect(0 ,50, 400, 3, WHITE); //make two lines for the game area
  tft.fillRect(0 ,260, 400, 3, WHITE);
  tft.fillCircle(positionX, positionY, 4, BLACK); //undraw the ball
  
 
  if(positionX < 0){ //ball go right if positionX < 0
    speedX = 1;
  }
  if(positionX > tft.width()){ //ball go left if positionY > screens width
    speedX = -1;
  }
  if(positionY < 50){ //ball go down if positionY < 50
    speedY = 1;
  }
  if(positionY > 260){ //ball go up if positionY > 260 
    speedY = -1;
  }
  if (positionY == 220 && (positionX >= x && positionX <= x + 50)) { //if ball hit paddle on y level 220 and between x level x and x+50 the ball bounces off the paddle
    speedY = -1;
    
    if ( speedX == 1) { //check if the ball should go left or right after hitting the paddle
         speedX = 1;
    } else {
          speedX = -1;
    }
    
    g = g+1;                                //score count
    tft.fillRect( 110 ,10, 40, 40, BLACK);
    tft.setCursor(110, 20);
    tft.setTextSize(3);
    tft.setTextColor(WHITE);
    if (positionY < 250 ) { // add score
    tft.print(g);
    } else {
    tft.print(0);
    }
  }

  if (positionY >= y2 ) { // check if the ball has gone past the paddle and into y2
    speedX = 0;
    speedY = 0;
    tft.setCursor(15, 100);
    tft.setTextSize(4);
    tft.setTextColor(RED);
    tft.print("GAME OVER");
    tft.setCursor(60, 150);
    tft.setTextSize(3);
    tft.setTextColor(GREEN);
    tft.print("RESTART");
  }
  

  positionX = positionX + speedX;
  positionY = positionY + speedY;
  tft.fillCircle(positionX, positionY, 4, WHITE); //draw the ball
  tft.fillRect( x ,220, 50, 10, WHITE);           //draw the paddle
  
    bool down = Touch_getXY();
    left_btn.press(down && left_btn.contains(pixel_x, pixel_y));
    right_btn.press(down && right_btn.contains(pixel_x, pixel_y));
    start_btn.press(down && start_btn.contains(pixel_x, pixel_y));
    exit_btn.press(down && exit_btn.contains(pixel_x, pixel_y));

    
    if (left_btn.justReleased()) //check if buttons been pressed
        left_btn.drawButton();

    if (right_btn.justReleased())
        right_btn.drawButton();

    if (start_btn.justReleased())
        start_btn.drawButton();

    if (exit_btn.justReleased())
        exit_btn.drawButton();

    if (start_btn.justPressed()) {
        start_btn.drawButton(true);
    }
    

        if (start_btn.justPressed()) { //if start_btn (restart button) had been pressed, start the game over again
        start_btn.drawButton(true);
        tft.fillScreen(BLACK);
        speedX = 1;
        speedY = 1;
        g = g - g; // reset g
        v = 1;
        positionX = 35;
        positionY = 35;
        exit_btn.drawButton(true);
        exit_btn.drawButton(false);
        left_btn.drawButton(true);
        right_btn.drawButton(true);
        left_btn.drawButton(false);
        right_btn.drawButton(false);
        
    }
    
    if (left_btn.justPressed()) { //if left button pressed, move the paddel 20pixels to the left
        left_btn.drawButton(true);
        tft.fillRect( x ,220, 50, 10, BLACK);
        if (x < 0) {  //dont move the paddle if it is on the egde of the display
             x = x + 0;
       }     else {  // check if the paddle is in the screen
             x = x - 20;
       }
    }
    
    if (right_btn.justPressed()) { //if right button pressed, move the paddel 20pixels to the right
        right_btn.drawButton(true);
        tft.fillRect( x ,220, 50, 10, BLACK);
        if (x > 190) {  //dont move the paddle if it is on the egde of the display
             x = x - 0;
       }     else {  // check if the paddle is in the screen
             x = x + 20;
       }   
    }
    
            if (exit_btn.justPressed()) { // check if buttons pressed
             r = 0;
             P = 0;
             B = 0;
             a = 1;
            exit_btn.drawButton(true);
            tft.fillScreen(BLACK);
            tft.fillRect(0 ,50, 400, 3, BLACK); //make two lines for the game area
            tft.fillRect(0 ,260, 400, 3, BLACK);
            tft.fillCircle(positionX, positionY, 4, BLACK); //undraw the ball
            tft.fillRect( x ,220, 50, 10, BLACK);           //draw the paddle
            speedX = 0;
            speedY = 0;
            f = 0;
            gameGUI();
          
}
 }
 


 //-------------------------------------------------------BREAKOUT-------------------------------------------------------------

void breakout() {

  if (B == 1) { // if B = 1 start breakout
      P = 0;
  
  if ( a == 1) { // if a = 1 pause game til start is pressed
   speedX = 0;
   speedY = 0;
  tft.setCursor(60,140);
  tft.setTextSize(4);
  tft.setTextColor(GREEN);
  tft.print("START");
  }
 }
  
  if ( s == 1) {    // if start is pressed start game
    tft.fillScreen(BLACK);
    drawrect();
    speedX = 1;
    speedY = -1;
    s = 0;
    a = 0;
    P = 0;
    pause_btn.drawButton(true);
    pause_btn.drawButton(false);
    exit_btn.drawButton(true);
    exit_btn.drawButton(false);
    left_btn.drawButton(true);
    right_btn.drawButton(true);
    left_btn.drawButton(false);
    right_btn.drawButton(false);
  }
 
  if (h <= 4)   {   
  if ( positionX >= 0 && positionX <= 60 && positionY == 40 ) { //check if box has been hit
    tft.fillRoundRect(0, 30, 59, 10, 3, BLACK);
    speedY = 1;
    h = h + 1;   //line four
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }

  if ( positionX >= 60 && positionX <= 120 && positionY == 40 ) { //check if box has been hit
    tft.fillRoundRect(60, 30, 59, 10, 3, BLACK);
    speedY = 1;
    h = h + 1;   //line four
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }

  if ( positionX >= 120 && positionX <= 180 && positionY == 40 ) {  //check if box has been hit
    tft.fillRoundRect(120, 30, 59, 10, 3, BLACK);
    speedY = 1;
    h = h + 1;   //line four
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }

  if ( positionX >= 180 && positionX <= 240 && positionY == 40 ) { //check if box has been hit
    tft.fillRoundRect(180, 30, 59, 10, 3, BLACK);
    speedY = 1;
    h = h + 1;   //line four
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }
                      //next row
  }
  if (i <= 4)   { 
  if ( positionX >= 0 && positionX <= 60 && positionY == 51 ) { //check if box has been hit
    tft.fillRoundRect(0, 41, 59, 10, 3, BLACK);
    speedY = 1;
    i = i + 1;   //line three
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }

  if ( positionX >= 60 && positionX <= 120 && positionY == 51 ) { //check if box has been hit
    tft.fillRoundRect(60, 41, 59, 10, 3, BLACK);
    speedY = 1;
    i = i + 1;   //line three
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }

  if ( positionX >= 120 && positionX <= 180 && positionY == 51 ) { //check if box has been hit
    tft.fillRoundRect(120, 41, 59, 10, 3, BLACK);
    speedY = 1;
    i = i + 1;   //line three
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }

  if ( positionX >= 180 && positionX <= 240 && positionY == 51 ) { //check if box has been hit
    tft.fillRoundRect(180, 41, 59, 10, 3, BLACK);
    speedY = 1;
    i = i + 1;   //line three
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  } 
  }              //next row
  if (l <= 4)   {              
  if ( positionX >= 0 && positionX <= 60 && positionY == 62 ) { //check if box has been hit
    tft.fillRoundRect(0, 52, 59, 10, 3, BLACK);
    speedY = 1;
    l = l + 1;   //line two
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }

  if ( positionX >= 60 && positionX <= 120 && positionY == 62 ) { //check if box has been hit
    tft.fillRoundRect(60, 52, 59, 10, 3, BLACK);
    speedY = 1;
    l = l + 1;   //line two
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }

  if ( positionX >= 120 && positionX <= 180 && positionY == 62 ) { //check if box has been hit
    tft.fillRoundRect(120, 52, 59, 10, 3, BLACK);
    speedY = 1;
    l = l + 1;   //line two
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }

  if ( positionX >= 180 && positionX <= 240 && positionY == 62 ) { //check if box has been hit
    tft.fillRoundRect(180, 52, 59, 10, 3, BLACK);
    speedY = 1;
    l = l + 1;   //line two
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  } 
}
  if (k <= 4)   {                   // next row

    if ( positionX >= 0 && positionX <= 60 && positionY == 73 ) { //check if box has been hit
    tft.fillRoundRect(0, 63, 59, 10, 3, BLACK);
    speedY = 1;
    k = k + 1;   //line one
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  } 

  if ( positionX >= 60 && positionX <= 120 && positionY == 73 ) { //check if box has been hit
    tft.fillRoundRect(60, 63, 59, 10, 3, BLACK);
    speedY = 1;
    k = k + 1;   //line one
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  } 

   if ( positionX >= 120 && positionX <= 180 && positionY == 73 ) { //check if box has been hit
    tft.fillRoundRect(120, 63, 59, 10, 3, BLACK);
    speedY = 1;
    k = k + 1;   //line one
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }   

  if ( positionX >= 180 && positionX <= 240 && positionY == 73 ) { //check if box has been hit
    tft.fillRoundRect(180, 63, 59, 10, 3, BLACK);
    speedY = 1;
    k = k + 1;   //line one
    if ( speedX == 1) { 
         speedX = 1;
    } else {
          speedX = -1;
    }
  }                    
  }

  
  tft.fillRect(x, 260, 50, 10, WHITE); // draw paddle
  tft.fillCircle(positionX, positionY, 4, BLACK); //undraw ball
  positionX = positionX + speedX;
  positionY = positionY + speedY;
  tft.fillCircle(positionX, positionY, 4, WHITE); //draw the ball

  if(positionX < 0){ //ball go right if positionX < 0
    speedX = 1;
  }
  if(positionX > tft.width()){ //ball go left if positionY > screens width
    speedX = -1;
  }
  if(positionY < 0){ //ball go down if positionY < 0
    speedY = 1;
  }
  if (positionY == 260 && (positionX >= x && positionX <= x + 50)) { //if ball hit paddle on y level 260 and between x level x and x+50 the ball bounces off the paddle
    speedY = -1;
    
    if ( speedX == 1) { //check if the ball should go left or right after hitting the paddle
         speedX = 1;
    } else {
          speedX = -1;
    }
  }
  if (positionY == 280) {  // end game if ball is under y 280
    tft.fillScreen(BLACK);
    pause_btn.drawButton(true);
    pause_btn.drawButton(false);
    exit_btn.drawButton(true);
    exit_btn.drawButton(false);
    left_btn.drawButton(true);
    right_btn.drawButton(true);
    left_btn.drawButton(false);
    right_btn.drawButton(false);
    speedX = 0;
    speedY = 0;
    k = 0;
    l = 0;
    i = 0;
    h = 0;
    positionY = 240;
    positionX = 120;
    tft.setCursor(40,140);
    tft.setTextSize(4);
    tft.setTextColor(GREEN);
    tft.print("RESTART");
    tft.setCursor(15,80);
    tft.setTextSize(4);
    tft.setTextColor(RED);
    tft.print("GAME OVER");
  }
  if ( h == 5) {           //if all boxes are hit, end game
    tft.fillScreen(WHITE);
    h = 0;
  }
  
  
  bool down = Touch_getXY();
    left_btn.press(down && left_btn.contains(pixel_x, pixel_y));
    right_btn.press(down && right_btn.contains(pixel_x, pixel_y));
    pause_btn.press(down && pause_btn.contains(pixel_x, pixel_y));
    start_btn.press(down && start_btn.contains(pixel_x, pixel_y));
    exit_btn.press(down && exit_btn.contains(pixel_x, pixel_y));

    if (start_btn.justReleased())
        start_btn.drawButton();

    if (pause_btn.justReleased())
        pause_btn.drawButton();

    if (left_btn.justReleased())
        left_btn.drawButton();

    if (right_btn.justReleased())
        right_btn.drawButton();

    if (exit_btn.justReleased())
        exit_btn.drawButton();
        
        if (start_btn.justPressed()) {
            start_btn.drawButton(true); //check if buttons pressed
              s = 1;     
        }

        if (pause_btn.justPressed()) {
            pause_btn.drawButton(true);
           a = 1;  
           
       }
       
        if (left_btn.justPressed()) {
            left_btn.drawButton(true);
            tft.fillRect(x, 260, 50, 10, BLACK);
             if (x < 0) { //if paddle is at end of display, dont move it
             x = x + 0;
       }     else { //move the paddle
             x = x - 20;
       }
            
   }
        if (right_btn.justPressed()) {
            right_btn.drawButton(true);
            tft.fillRect(x, 260, 50, 10, BLACK);
            if (x > 190) { //if paddle is at end of display, dont move it
             x = x - 0;
       }     else {  //move the paddle
             x = x + 20;
       }
            
   }

         if (exit_btn.justPressed()) { // check if buttons pressed
            exit_btn.drawButton(true);
            tft.fillScreen(BLACK);
            P = 0;
            r = 0;
            B = 0;
            k = 0;
            l = 0;
            i = 0;
            h = 0;
            a = 1;
            f = 0;
            speedX = 0;
            speedY = 0;
            tft.fillRect(x, 260, 50, 10, BLACK); // draw paddle
            tft.fillCircle(positionX, positionY, 4, BLACK); //undraw ball
            gameGUI();
          
}
}


  //-------------------------------------------void loop-------------------------------------------

  
void loop() {
  
  gameGUI();

  if ( P == 0 && B == 0) { // if none of the buttons is pressed, keep gameGUI up.
    f = 0;
    gameGUI();
  }

  if ( P == 1) { // if button P is pressed, start pong
    pong();
  }
  if ( B == 1) { // if button B is pressed, Start breakout
    breakout();
  }
}
