// $Id$

#ifndef PANASONICRAM_HH
#define PANASONICRAM_HH

#include "MSXMemoryMapper.hh"

namespace openmsx {

class PanasonicMemory;

class PanasonicRam : public MSXMemoryMapper
{
public:
	PanasonicRam(MSXMotherBoard& motherBoard, const XMLElement& config);

	virtual void writeMem(word address, byte value, const EmuTime& time);
	virtual byte* getWriteCacheLine(word start) const;

	template<typename Archive>
	void serialize(Archive& ar, unsigned version);

private:
	PanasonicMemory& panasonicMemory;
};

REGISTER_MSXDEVICE(PanasonicRam, "PanasonicRam");

} // namespace openmsx

#endif
