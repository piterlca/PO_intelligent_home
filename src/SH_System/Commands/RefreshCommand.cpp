#define VERBOSITY 4

#include "../../../Incl/Smart_house_iface/Adapter.hpp"
#include "../../../Incl/SH_System/SH_System.hpp"
#include "../../../Incl/SH_System/Commands/RefreshCommand.hpp"

RefreshCommand::RefreshCommand(void)
{
#if 4 <= VERBOSITY
	std::cout << "Obj of RefreshCommand has been created\n";
#endif
}

string
RefreshCommand::Execute(string& params)
{
	string UserID = "";
	string ViewID = "";
	string OptionalParameters;

	SH_System* system = this->system;

	Smart_house::Adapter* a = system->FindAdapterByView(UserID, ViewID);

	return a->refresh(OptionalParameters);

}
