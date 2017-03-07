/*******************************
Name: Omid Azodi
Professor: Dr. Xin Ye
Class: CS542
Date: 03/07/2017
Homework: HWK4 (Adapter Design Pattern)
How to compile: g++ adapter.cpp -std=c++11
********************************/

#include <iostream>
#include <string>

using namespace std;

//Base class to implement MediaAdapter
class MediaPlayer {
public:
  virtual void play(string audioType, string fileName) = 0;
};

//New class to play different types of files that MediaPlayer could not handle
class AdvancedMediaPlayer {
public:
  virtual void playVlc(string fileName) = 0;
  virtual void playMp4(string fileName) = 0;
};

//Vlc file type can be implemented
class VlcPlayer : public AdvancedMediaPlayer {
public:
  void playVlc(string fileName) {
    cout << "Playing vlc file. Name: " + fileName << endl;
  }
  void playMp4(string fileName) {
    cout << "Vlc player cannot play mp4." << endl;
  }
};

//Mp4 file type can be implemented
class Mp4Player : public AdvancedMediaPlayer {
public:
  void playVlc(string fileName) {
    cout << "Mp4 player cannot play vlc." << endl;
  }
  void playMp4(string fileName) {
    cout << "Playing mp4 file. Name: " + fileName << endl;
  }
};

//MediaAdapter allows the new file types to be played, based on the audioPlayer that can play mp3,vlc, and mp4.
class MediaAdapter: public MediaPlayer{
private: 
  AdvancedMediaPlayer* advancedMediaPlayer; 
public:
  void play(string audioType, string fileName)
  {
    if (audioType == "vlc") {
      advancedMediaPlayer = new VlcPlayer();
      advancedMediaPlayer->playVlc(fileName);
    }
    else if (audioType == "mp4")
      {
	advancedMediaPlayer = new Mp4Player();
	advancedMediaPlayer->playMp4(fileName);
      }
  } 

};

//AudioPlayer allows there to be only one play function, not allowing client to see which class is calling the play function. 
class AudioPlayer : public MediaPlayer {
private:
  //MediaAdapter used to call the play function, and abstracts function calls from vlc and mp4 play functions.
  MediaAdapter* mediaAdapter = new MediaAdapter();
public:
  void play(string audioType, string fileName) {
    if (audioType == "mp3") {
      cout << "Playing mp3 file. Name: " + fileName << endl;
    }
    else if (audioType == "vlc" || audioType == "mp4") {
    mediaAdapter->play(audioType, fileName);
    }
    else {
      cout << "Invalid media. " + audioType + " format not supported" << endl;
    }
  }
};

int main() {
  //We have one audioPlayer which allows us to play any file type that is supported, by only calling one play function.
  AudioPlayer *audioPlayer = new AudioPlayer();
  audioPlayer->play("mp3", "beyond the horizon.mp3");
  audioPlayer->play("mp4", "alone.mp4");
  audioPlayer->play("vlc", "far far away.vlc");
  audioPlayer->play("avi", "mind me.avi");
}

