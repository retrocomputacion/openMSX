// $Id$

#include "RomPageNN.hh"


RomPageNN::RomPageNN(Device* config, const EmuTime &time, Rom *rom, byte pages)
	: MSXDevice(config, time), Rom16kBBlocks(config, time, rom)
{
	int bank = 0;
	for (int page = 0; page < 4; page++) {
		if (pages & (1 << page)) {
			setRom(page, bank++);
		} else {
			setBank(page, unmappedRead);
		}
	}
}

RomPageNN::~RomPageNN()
{
}

