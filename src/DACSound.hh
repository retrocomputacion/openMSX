// $Id$

// This class implements the an 8 bit unsigned DAC to produce sound
// This are used in Konami's Synthesizer, Majutsushi (Mah Jong 2)RC 765
// And for SIMPL 

#ifndef __DACSOUND_HH__
#define __DACSOUND_HH__

#include "openmsx.hh"
#include "SoundDevice.hh"
#include "EmuTime.hh"
#include "RealTime.hh"


class DACSound : public SoundDevice
{
	public:
		DACSound(short maxVolume, int typicalFreq, const EmuTime &time); 
		virtual ~DACSound(); 
	
		void reset(const EmuTime &time);
		byte readDAC(const EmuTime &time);
		void writeDAC(byte value, const EmuTime &time);
		
		//SoundDevice
		void setInternalVolume(short newVolume);
		void setSampleRate(int sampleRate);
		int* updateBuffer(int length);
		
	private:
		void insertSample(short sample, const EmuTime &time);
		void getNext();
		
		static const int BUFSIZE = 4096;
		static const int CENTER = 0x80;
	
		EmuTime emuDelay;
		EmuTime currentTime, nextTime, prevTime, lastTime;
		int currentValue, nextValue, delta, tmpValue;
		int timeUnit, left, currentLength;
		byte lastValue;
		short volTable[256];
		struct {
			int sample;
			EmuTime time;
		} buffer[BUFSIZE];
		int readIndex;
		int writeIndex;
		int* buf;
};
#endif
