// $Id$

#ifndef CARTRIDGESLOTMANAGER_HH
#define CARTRIDGESLOTMANAGER_HH

#include "noncopyable.hh"
#include <string>
#include <memory>

namespace openmsx {

class MSXMotherBoard;
class CartCmd;
class HardwareConfig;

class CartridgeSlotManager : private noncopyable
{
public:
	explicit CartridgeSlotManager(MSXMotherBoard& motherBoard);
	~CartridgeSlotManager();

	static int getSlotNum(const std::string& slot);

	void createExternalSlot(int ps);
	void createExternalSlot(int ps, int ss);
	void removeExternalSlot(int ps);
	void removeExternalSlot(int ps, int ss);
	void testRemoveExternalSlot(int ps, const HardwareConfig& allowed) const;
	void testRemoveExternalSlot(int ps, int ss, const HardwareConfig& allowed) const;

	int getSpecificSlot(int slot, int& ps, int& ss,
	                    const HardwareConfig& hwConfig);
	int getAnyFreeSlot(int& ps, int& ss, const HardwareConfig& hwConfig);
	int getFreePrimarySlot(int& ps, const HardwareConfig& hwConfig);
	int useExternalSlot(int ps, int ss, const HardwareConfig& hwConfig);
	void freeSlot(int slot);

	bool isExternalSlot(int ps, int ss, bool convert) const;

private:
	int getSlot(int ps, int ss) const;

	struct Slot {
		Slot();
		~Slot();
		bool exists() const;
		bool used(const HardwareConfig* allowed = NULL) const;

		int ps;
		int ss;
		std::auto_ptr<CartCmd> command;
		const HardwareConfig* config;
	};
	static const int MAX_SLOTS = 16 + 4;
	Slot slots[MAX_SLOTS];
	MSXMotherBoard& motherBoard;
	const std::auto_ptr<CartCmd> cartCmd;
	friend class CartCmd;
};

} // namespace openmsx

#endif
