
#pragma once
#include "AstroObject.h"
#include "..\source\Math.h"
#include <vector>
class AstroObjectsManager final {
public:
	typedef std::vector<AstroObject *> AstroObjectsContainer;

	AstroObjectsManager(const AstroObjectsManager&) = delete;
	void operator=(const AstroObjectsManager&) = delete;

	~AstroObjectsManager();

	static void addObject();
	static void removeObject();
	static void update();
private:
	AstroObjectsContainer container;
	AstroObjectsManager();
	static AstroObjectsManager &getInstance();
};