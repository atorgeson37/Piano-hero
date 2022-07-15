#include "pitches.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const int buzzerPin = 13;

// establishes the pitches of each note from “pitches.h”
int c[] = {N_C5}; 
int d[] = {N_D5};
int e[] = {N_E5}; 
int f[] = {N_F5};
int g[] = {N_G5}; 

int players = 0;
int Score = 0;
int winner = 0;
int winnerscore = 0;

int duration(500);

const int pbPins[5] = {A4, A3, A2, A1, A0}; // initialize push button pins in an array
const int ledPins[5] = {1,2,3,4,5}; // initialize LED pins in an array

void setup() {
pinMode (pbPins[0], OUTPUT);
pinMode (pbPins[1], OUTPUT);
pinMode (pbPins[2], OUTPUT);
pinMode (pbPins[3], OUTPUT);
pinMode (pbPins[4], OUTPUT);

digitalWrite (pbPins[0], HIGH);
digitalWrite (pbPins[1], HIGH);
digitalWrite (pbPins[2], HIGH);
digitalWrite (pbPins[3], HIGH);
digitalWrite (pbPins[4], HIGH);

pinMode (ledPins[0], OUTPUT);
pinMode (ledPins[1], OUTPUT);
pinMode (ledPins[2], OUTPUT);
pinMode (ledPins[3], OUTPUT);
pinMode (ledPins[4], OUTPUT);

lcd.begin(16,2);
lcd.clear(); //clear LCD before beginning

}

void loop() {

// creates while loop while all buttons are not being pressed (HIGH)
while ((digitalRead (pbPins[0]) == HIGH) and (digitalRead (pbPins[1]) == HIGH) and (digitalRead (pbPins[2]) == HIGH) and (digitalRead (pbPins[3]) == HIGH) and (digitalRead (pbPins[4]) == HIGH)){

// display introduction messages on LCD
lcd.setCursor(0,0);
lcd.print("Welcome to Piano");
lcd.setCursor(0,1);
lcd.print("Hero!");
delay(3000); //delay 3 seconds
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Please select 1");
lcd.setCursor(0,1);
lcd.print("to 5 players by");
delay(2000); // delay 2 seconds
lcd.clear();
lcd.setCursor(0,0);
lcd.print("selecting the");
lcd.setCursor(0,1);
lcd.print("correlating");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("button from left");
lcd.setCursor(0,1);
lcd.print("to right...");
delay(2000);
lcd.clear();
  

}

// set integer players to the value of the corresponding button pressed (increases from 1 to 5 
//from left to right)

if (digitalRead (pbPins[0]) == LOW){
  players = 1;
}
if (digitalRead (pbPins[1]) == LOW){
  players = 2;
}
if (digitalRead (pbPins[2]) == LOW){
  players = 3;
}
if (digitalRead (pbPins[3]) == LOW){
  players = 4;
}
if (digitalRead (pbPins[4]) == LOW){
  players = 5;
}

// display on LCD the number of players chosen
lcd.setCursor(0,0);
lcd.print(players);
lcd.setCursor(3,0);
lcd.print("players");
delay(2000);
lcd.clear();

// display choices of songs
lcd.setCursor(0,0);
lcd.print("Please select");
lcd.setCursor(0,1);
lcd.print("which song:");
delay (3000);
lcd.clear();

// while loop repeats as long as no buttons are being pressed
while ((digitalRead (pbPins[1]) == HIGH) and (digitalRead (pbPins[2]) == HIGH) and (digitalRead (pbPins[3]) == HIGH)){
  
// choices of songs are displayed until a button is pressed 
 lcd.setCursor(0,0);
  lcd.print("Mary had a little lamb:");
  lcd.setCursor(0,1);
  lcd.print("press red");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ode to Joy:");
  lcd.setCursor(0,1);
  lcd.print("press yellow");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Frere Jacques:");
  lcd.setCursor(0,1);
  lcd.print("press green");
  delay(2000);
  lcd.clear();
}
// if the red button is pressed, the function for Mary Had a Little Lamb is called and run
if (digitalRead (pbPins[1]) == LOW){
  MaryHadALittleLamb();
}
// if the yellow button is pressed, the function for Ode to Joy is called and run
if (digitalRead (pbPins[2]) == LOW){
  OdeToJoy();
}
//if the green button is pressed, the function for Frere Jacques is called and run
if (digitalRead (pbPins[3]) == LOW){
 FrereJacques();
}

}




// function to play play Mary Had a Little Lamb
void MaryHadALittleLamb(){
// sequence is set to the order of LED’s that is required to light up to play the song
const byte sequence[25] = {2,1,0,1,2,2,2,1,1,1,2,4,4,2,1,0,1,2,2,2,1,1,2,1,0};
winner = 0;
winnerscore = 0;

// display a message that the game is about to begin
lcd.setCursor(0,0);
lcd.print("Get ready!");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Begin!");
delay (500);
lcd.clear();

for (int p=1; p<players+1; p++){ // will repeat for the amount of players selected
int Score = 500; // score begins at 500 
 for (int i=0; i<25; i++) // indexes through the values in the LED sequence
{
 
int j = sequence[i]; // j is set to the value at position [i] in the sequence
digitalWrite (ledPins[j], HIGH); // light up LED correlated with value of j
while (digitalRead (pbPins[j]) != LOW) // loops until the correct button is pressed
{

// following if loops decrease score by 10 if an incorrect button is pressed
    if (digitalRead (pbPins[0]) == LOW) // first button is pressed
    {
      tone(13, c[0], duration); // plays pitch c for set duration by sending info to pin 13(buzzer pin)
      Score = Score - 10; // decrease score
      delay(50);
// delays to ensure points are decreased only once when the wrong button is pressed
  }
    if (digitalRead (pbPins[1]) == LOW)
    {
      tone(13, d[0], duration); // play pitch d for set duration by sending info to pin 13
      Score = Score - 10;
      delay(50);
    }
    if (digitalRead (pbPins[2]) == LOW)
    {
      tone(13, e[0], duration); // play pitch e for set duration by sending info to pin 13
      Score = Score - 10;
      delay(50);
    }
    if (digitalRead (pbPins[3]) == LOW)
    {
      tone(13, f[0], duration); // play pitch f for set duration by sending info to pin 13
      Score = Score - 10;
      delay(50);
    }
    if (digitalRead (pbPins[4]) == LOW)
    {
      tone(13, g[0], duration); // play pitch g for set duration by sending info to pin 13
      Score = Score - 10;
      delay(50);
    }
}
if (digitalRead(pbPins[0]) == LOW) { //Reads button state when pressed
    for (int Note = 0; Note < 1; Note++) {
      tone(13, c[Note], duration); //Plays note on pin 13, where the Buzzer is connected     
  }
  }
  if (digitalRead(pbPins[1]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, d[Note], duration); 
    }
  }
  if (digitalRead(pbPins[2]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, e[Note], duration);
    }
  }
  if (digitalRead(pbPins[3]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, f[Note], duration);
    }
  }
  if (digitalRead(pbPins[4]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, g[Note], duration);
    }
  }
digitalWrite (ledPins[j], LOW); // turn off LED before looping
delay(400); // delay for 400 milliseconds 
}   
 
  // If the score is higher than the winnerscore, set winnerscore to score and winner to player 
  // number (p)
  if(Score>winnerscore){ 
    winnerscore = Score;
    winner = p;
  }
// display good job message
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Good job");
  lcd.setCursor(0,1);
  lcd.print("player ");
  lcd.setCursor(8,1);
  lcd.print(p);
  delay (2000);
  lcd.clear();

// display player’s score
  lcd.setCursor(0,0);
  lcd.print("Your score was:");
  lcd.setCursor(0,1);
  lcd.print(Score);
  delay(3000);
  lcd.clear();

// if there are more players, display message indicating it is the next player’s turn
  if (p+1 < players){
    lcd.setCursor(0,0);
    lcd.print("Next player…");
  }
}

// display who the player is and what their score was
lcd.clear();
lcd.setCursor(0,0);
lcd.print("The winner is");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PLAYER ");
lcd.setCursor(8,0);
lcd.print(winner);
lcd.setCursor(0,1);
lcd.print("Score: ");
lcd.setCursor(8,1);
lcd.print(winnerscore);

delay(10000); // delay for 10 seconds
lcd.clear(); // clear LCD

}


void OdeToJoy(){
// structure the same as previous except for LED sequence

// LED sequence set to correct pattern of LED’s needed to play song
const byte sequence[30] = {2,2,3,4,4,3,2,1,0,0,1,2,2,1,1,2,2,3,4,4,3,2,1,0,0,1,2,1,0,0};
winner = 0;
winnerscore = 0;

lcd.setCursor(0,0);
lcd.print("Get ready!");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Begin!");
delay (500);
lcd.clear();

for (int p=1; p<players+1; p++){
int Score = 500;
  for (int i=0; i<30; i++) 
{
 
int j = sequence[i];
digitalWrite (ledPins[j], HIGH);
while (digitalRead (pbPins[j]) != LOW)
{
    if (digitalRead (pbPins[0]) == LOW) 
    {
      tone(13, c[0], duration);
      Score = Score - 10;
      delay(50);
  }
    if (digitalRead (pbPins[1]) == LOW)
    {
      tone(13, d[0], duration);
      Score = Score - 10;
      delay(50);
    }
    if (digitalRead (pbPins[2]) == LOW)
    {
      tone(13, e[0], duration);
      Score = Score - 10;
      delay(50);
    }
    if (digitalRead (pbPins[3]) == LOW)
    {
      tone(13, f[0], duration);
      Score = Score - 10;
      delay(50);
    }
    if (digitalRead (pbPins[4]) == LOW)
    {
      tone(13, g[0], duration);
      Score = Score - 10;
      delay(50);
    }
}
if (digitalRead(pbPins[0]) == LOW) { //Reads button state when pressed
    for (int Note = 0; Note < 1; Note++) {
      tone(13, c[Note], duration); //Plays note on pin 6, where the Buzzer is connected     
  }
  }
  if (digitalRead(pbPins[1]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, d[Note], duration); 
    }
  }
  if (digitalRead(pbPins[2]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, e[Note], duration);
    }
  }
  if (digitalRead(pbPins[3]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, f[Note], duration);
    }
  }
  if (digitalRead(pbPins[4]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, g[Note], duration);
    }
  }
digitalWrite (ledPins[j], LOW);
delay(400);
}   
 
  
  if(Score>winnerscore){
    winnerscore = Score;
    winner = p;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Good job");
  lcd.setCursor(0,1);
  lcd.print("player ");
  lcd.setCursor(8,1);
  lcd.print(p);
  delay (2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Your score was:");
  lcd.setCursor(0,1);
  lcd.print(Score);
  delay(3000);
  lcd.clear();

  if (p+1 < players){
    lcd.setCursor(0,0);
    lcd.print("Next player…");
  }
}
lcd.clear();
lcd.setCursor(0,0);
lcd.print("The winner is");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PLAYER ");
lcd.setCursor(8,0);
lcd.print(winner);
lcd.setCursor(0,1);
lcd.print("Score: ");
lcd.setCursor(8,1);
lcd.print(winnerscore);

delay(10000);
lcd.clear();

}


void FrereJacques(){
// structure the same as previous except for the LED sequence

// LED sequence set to correct pattern of LED’s needed to play song
const byte sequence[32] = {0,1,2,0,0,1,2,0,2,3,4,2,3,4,4,4,4,3,2,0,4,4,4,3,2,0,0,4,0,0,4,0};
winner = 0;
winnerscore = 0;

lcd.setCursor(0,0);
lcd.print("Get ready!");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Begin!");
delay (500);
lcd.clear();

for (int p=1; p<players+1; p++){
int Score = 500;
  for (int i=0; i<32; i++) 
{
 
int j = sequence[i];
digitalWrite (ledPins[j], HIGH);
while (digitalRead (pbPins[j]) != LOW)
{
    if (digitalRead (pbPins[0]) == LOW) 
    {
      tone(13, c[0], duration);
      Score = Score - 10;
      delay(50);
  }
    if (digitalRead (pbPins[1]) == LOW)
    {
      tone(13, d[0], duration);
      Score = Score - 10;
      delay(50);
    }
    if (digitalRead (pbPins[2]) == LOW)
    {
      tone(13, e[0], duration);
      Score = Score - 10;
      delay(50);
    }
    if (digitalRead (pbPins[3]) == LOW)
    {
      tone(13, f[0], duration);
      Score = Score - 10;
      delay(50);
    }
    if (digitalRead (pbPins[4]) == LOW)
    {
      tone(13, g[0], duration);
      Score = Score - 10;
      delay(50);
    }
}
if (digitalRead(pbPins[0]) == LOW) { //Reads button state when pressed
    for (int Note = 0; Note < 1; Note++) {
      tone(13, c[Note], duration); //Plays note on pin 6, where the Buzzer is connected     
  }
  }
  if (digitalRead(pbPins[1]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, d[Note], duration); 
    }
  }
  if (digitalRead(pbPins[2]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, e[Note], duration);
    }
  }
  if (digitalRead(pbPins[3]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, f[Note], duration);
    }
  }
  if (digitalRead(pbPins[4]) == LOW) {
    for (int Note = 0; Note < 1; Note++) {
      tone(13, g[Note], duration);
    }
  }
digitalWrite (ledPins[j], LOW);
delay(400);
}   
 
  
  if(Score>winnerscore){
    winnerscore = Score;
    winner = p;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Good job");
  lcd.setCursor(0,1);
  lcd.print("player ");
  lcd.setCursor(8,1);
  lcd.print(p);
  delay (2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Your score was:");
  lcd.setCursor(0,1);
  lcd.print(Score);
  delay(3000);
  lcd.clear();

  if (p+1 < players){
    lcd.setCursor(0,0);
    lcd.print("Next player…");
  }
}
lcd.clear();
lcd.setCursor(0,0);
lcd.print("The winner is");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PLAYER ");
lcd.setCursor(8,0);
lcd.print(winner);
lcd.setCursor(0,1);
lcd.print("Score: ");
lcd.setCursor(8,1);
lcd.print(winnerscore);

delay(10000);
lcd.clear();

}
