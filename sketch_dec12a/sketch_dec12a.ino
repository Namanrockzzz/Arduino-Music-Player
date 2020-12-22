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

pinMode(8, INPUT_PULLUP);  //Button with internal pull up to previous track
pinMode(2, INPUT_PULLUP); //Button with internal pull up to next track
pinMode(5, INPUT_PULLUP); //Button with internal pull up to play/pause

music.setVolume(6);    //   0 to 7. Set volume level
music.quality(0);        //  Set 1 for 2x oversampling Set 0 for normal
//music.volume(0);        //   1(up) or 0(down) to control volume
//music.play("filename",30); plays a file starting at 30 seconds into the track    
}

void loop()
{ 

    if (digitalRead(2)==HIGH) //Avoid debounce
  debounce1=true;

  if (digitalRead(5)==HIGH)//Avoid debounce
  debounce2=true;

  if (digitalRead(8)==HIGH) //Avoid debounce
  debounce0=true;
  
  if (digitalRead(2)==LOW  && debounce1 == true) //Button 1 Pressed
  {
  if (song_number == 0)
      {
        song_number++;
      }
      song_number++;
      if (song_number==11)
      {song_number=1;}
      Serial.println("KEY PRESSED");
      Serial.print("song_number=");
      Serial.println(song_number);
      debounce1=false;
    
      if (song_number ==1)
      {music.play("1.wav",10);} //Play song 1 from 10th second 
    
      if (song_number ==2)
      {music.play("2.wav",10);} //Play song 2 from 33rd second 
    
      if (song_number ==3)
      {music.play("3.wav",10);} //Play song 3 from start
    
      if (song_number ==4)
      {music.play("4.wav",10);}
      
      if (song_number ==5)
      {music.play("5.wav",10);}  

      if (song_number ==6)
      {music.play("6.wav",10);}

      if (song_number ==7)
      {music.play("7.wav",10);}

      if (song_number ==8)
      {music.play("8.wav",10);}

      if (song_number ==9)
      {music.play("9.wav",10);}

      if (song_number ==10)
      {music.play("10.wav");} 
}

  if (digitalRead(8)==LOW  && debounce0 == true) //Button 1 Pressed
  {
   song_number--;
      if (song_number==0 || song_number==-1)
      {song_number=10;}
      Serial.println("KEY PRESSED");
      Serial.print("song_number=");
      Serial.println(song_number);
      debounce0 = false;
      if (song_number ==1)
      {music.play("1.wav",10);} //Play song 1 from 10th second 
    
      if (song_number ==2)
      {music.play("2.wav",10);} //Play song 2 from 33rd second 
    
      if (song_number ==3)
      {music.play("3.wav",10);} //Play song 3 from start
    
      if (song_number ==4)
      {music.play("4.wav",10);}
      
      if (song_number ==5)
      {music.play("5.wav",10);}  

      if (song_number ==6)
      {music.play("6.wav",10);}

      if (song_number ==7)
      {music.play("7.wav",10);}

      if (song_number ==8)
      {music.play("8.wav",10);}

      if (song_number ==9)
      {music.play("9.wav",10);}

      if (song_number ==10)
      {music.play("10.wav");}
}

  if (digitalRead(5)==LOW  && debounce2 == true) //Button 2 Pressed
  {
    debounce2=false;
  if (song_number == 0)
      {
        song_number++;
        music.play("1.wav",10);
      }
      else
      {
        music.pause();
      }
      Serial.println("PLAY / PAUSE");
  }




  
  if (Serial.available() > 0)
  {
    incoming = Serial.read();
    if (incoming == '0')
    {
      song_number--;
      if (song_number==0 || song_number==-1)
      {song_number=10;}
      Serial.println("KEY PRESSED");
      Serial.print("song_number=");
      Serial.println(song_number);
    
       if (song_number ==1)
      {music.play("1.wav",10);} //Play song 1 from 10th second 
    
      if (song_number ==2)
      {music.play("2.wav",10);} //Play song 2 from 33rd second 
    
      if (song_number ==3)
      {music.play("3.wav",10);} //Play song 3 from start
    
      if (song_number ==4)
      {music.play("4.wav",10);}
      
      if (song_number ==5)
      {music.play("5.wav",10);}  

      if (song_number ==6)
      {music.play("6.wav",10);}

      if (song_number ==7)
      {music.play("7.wav",10);}

      if (song_number ==8)
      {music.play("8.wav",10);}

      if (song_number ==9)
      {music.play("9.wav",10);}

      if (song_number ==10)
      {music.play("10.wav");}
    }
    else if (incoming == '1')
    {
      if (song_number == 0)
      {
        song_number++;
        music.play("1.wav",10);
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
      if (song_number==11)
      {song_number=1;}
      Serial.println("KEY PRESSED");
      Serial.print("song_number=");
      Serial.println(song_number);
    
      if (song_number ==1)
      {music.play("1.wav",10);} //Play song 1 from 10th second 
    
      if (song_number ==2)
      {music.play("2.wav",10);} //Play song 2 from 33rd second 
    
      if (song_number ==3)
      {music.play("3.wav",10);} //Play song 3 from start
    
      if (song_number ==4)
      {music.play("4.wav",10);}
      
      if (song_number ==5)
      {music.play("5.wav",10);}  

      if (song_number ==6)
      {music.play("6.wav",10);}

      if (song_number ==7)
      {music.play("7.wav",10);}

      if (song_number ==8)
      {music.play("8.wav",10);}

      if (song_number ==9)
      {music.play("9.wav",10);}

      if (song_number ==10)
      {music.play("10.wav");}
    }
  }
  incoming=0;
}
