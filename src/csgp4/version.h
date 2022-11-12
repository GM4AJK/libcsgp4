#pragma once

#include <string>

namespace csgp4 {

class version
{
public:
	version();
	virtual ~version();

	static std::string get(void);
};

}; // end namespace csgp4


