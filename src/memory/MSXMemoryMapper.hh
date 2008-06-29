// $Id$

#ifndef MSXMEMORYMAPPER_HH
#define MSXMEMORYMAPPER_HH

#include "MSXDevice.hh"
#include <memory>

namespace openmsx {

class XMLElement;
class MSXMapperIO;
class CheckedRam;

class MSXMemoryMapper : public MSXDevice
{
public:
	MSXMemoryMapper(MSXMotherBoard& motherBoard, const XMLElement& config);
	virtual ~MSXMemoryMapper();

	virtual void reset(const EmuTime& time);
	virtual void powerUp(const EmuTime& time);
	virtual byte readMem(word address, const EmuTime& time);
	virtual void writeMem(word address, byte value, const EmuTime& time);
	virtual const byte* getReadCacheLine(word start) const;
	virtual byte* getWriteCacheLine(word start) const;
	virtual byte peekMem(word address, const EmuTime& time) const;

	template<typename Archive>
	void serialize(Archive& ar, unsigned version);

protected:
	/** Converts a Z80 address to a RAM address.
	  * @param address Index in Z80 address space.
	  * @return Index in RAM address space.
	  */
	unsigned calcAddress(word address) const;

	std::auto_ptr<CheckedRam> checkedRam;

private:
	MSXMapperIO* mapperIO;
	unsigned nbBlocks;
};

REGISTER_MSXDEVICE(MSXMemoryMapper, "MemoryMapper");
REGISTER_BASE_NAME_HELPER(MSXMemoryMapper, "MemoryMapper");

} // namespace openmsx

#endif
