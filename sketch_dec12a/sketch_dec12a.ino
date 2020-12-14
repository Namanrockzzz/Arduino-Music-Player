#include "SD.h" //Lib to read SD card
#include "TMRpcm.h" //Lib to play auido
#include "SPI.h" //SPI lib for SD card

#define SD_ChipSelectPin 10 //Chip select is pin number 4
TMRpcm music; //Lib object is named "music"

char incoming=0;

int song_number=0;
boolean debounce1=true;
boolean debounce2=true;
boolean debounce0=true;
boolean play_pause;

void setup(){
music.speakerPin = 9; //Auido out on pin 9
Serial.begin(9600); //Serial Com for debugging 
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}

pinMode(8, INPUT_PULLUP);
pinMode(2, INPUT_PULLUP); //Button 1 with internal pull up to chage track
pinMode(3, INPUT_PULLUP); //Button 2 with internal pull up to play/pause
pinMode(3, INPUT_PULLUP); //Button 2 with internal pull up to fast forward

music.setVolume(6);    //   0 to 7. Set volume level
music.quality(1);        //  Set 1 for 2x oversampling Set 0 for normal
//music.volume(0);        //   1(up) or 0(down) to control volume
//music.play("filename",30); plays a file starting at 30 seconds into the track    
}

void loop()
{ 
  if (Serial.available() > 0)
  {
    incoming = Serial.read();
    if (incoming == '0')
    {
      song_number--;
      if (song_number==0 || song_number==-1)
      {song_number=4;}
      Serial.println("KEY PRESSED");
      Serial.print("song_number=");
      Serial.println(song_number);
    
      if (song_number ==1)
      {music.play("1.wav");} //Play song 1 from 10th second 
    
      if (song_number ==2)
      {music.play("2.wav");} //Play song 2 from 33rd second 
    
      if (song_number ==3)
      {music.play("3.wav");} //Play song 3 from start
    
      if (song_number ==4)
      {music.play("4.wav");} //Play song 4 from 25th second   
    }
    else if (incoming == '1')
    {
      if (song_number == 0)
      {
        song_number++;
        music.play("1.wav");
      }
      else
      {
        music.pause();
      }
      Serial.println("PLAY / PAUSE");
    }
    else if (incoming == '2')
    {
      if (song_number == 0)
      {
        song_number++;
      }
      song_number++;
      if (song_number==5)
      {song_number=1;}
      Serial.println("KEY PRESSED");
      Serial.print("song_number=");
      Serial.println(song_number);
    
      if (song_number ==1)
      {music.play("1.wav",10);} //Play song 1 from 10th second 
    
      if (song_number ==2)
      {music.play("2.wav",33);} //Play song 2 from 33rd second 
    
      if (song_number ==3)
      {music.play("3.wav");} //Play song 3 from start
    
      if (song_number ==4)
      {music.play("4.wav",25);} //Play song 4 from 25th second   
    }
  }
  incoming=0;
}
