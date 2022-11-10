
#include "config.h"
#include "version.h"

#include <sstream>

namespace csgp4 {

version::version()
{}

version::~version()
{}

std::string
version::get(void)
{
	std::stringstream oss;
	std::string gittag = std::string(GIT_TAG);
	oss << LIBCSGP4_VERSION;
	if(gittag.length() > 0) {
		oss << "-" << gittag;
	}
	std::string v = oss.str(); //(LIBCSGP4_VERSION);
	return v;
}

}; // end namespace csgp4




