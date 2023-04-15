#ifndef IMGUI_MACHINE_HH
#define IMGUI_MACHINE_HH

#include "ImGuiPart.hh"

#include "TclObject.hh"

#include <map>
#include <string>
#include <vector>

namespace openmsx {

class ImGuiManager;
class MSXMotherBoard;

class ImGuiMachine final : public ImGuiPart
{
public:
	ImGuiMachine(ImGuiManager& manager_)
		: manager(manager_) {}

	void showMenu(MSXMotherBoard* motherBoard) override;
	void paint(MSXMotherBoard* motherBoard) override;

private:
	void paintSelectMachine(MSXMotherBoard* motherBoard);
	const std::vector<std::string>& getAllConfigs();
	const std::string& getTestResult(const std::string& config);
	const TclObject& getConfigInfo(const std::string& config);
	bool printConfigInfo(const std::string& config);

public:
	bool showSelectMachine = false;

private:
	ImGuiManager& manager;
	std::vector<std::string> allConfigsCache;
	std::map<std::string, std::string> testCache;
	std::map<std::string, TclObject> configInfoCache;
	std::string newMachineConfig;
};

} // namespace openmsx

#endif