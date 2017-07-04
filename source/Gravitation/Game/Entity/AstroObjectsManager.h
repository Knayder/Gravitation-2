#pragma once

#include "AstroObject.h"
#include "..\source\Math.h"
#include <vector>
class AstroObjectsManager final {
public:
	friend class Physics;

	typedef std::vector<AstroObject *> AstroObjectsContainer;

	AstroObjectsManager(const AstroObjectsManager&) = delete;
	void operator=(const AstroObjectsManager&) = delete;

	~AstroObjectsManager();

	static AstroObject * addObject(AstroObject *obj);
	static bool removeObject(const unsigned int &index);
	static bool removeObject(const AstroObject *target);
	static void clear();
	static void update();
private:
	AstroObjectsContainer container;
	AstroObjectsManager();
	static AstroObjectsManager &getInstance();
};