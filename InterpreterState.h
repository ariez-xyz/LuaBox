#include "pch.h"

#ifndef InterpreterState_H
#define InterpreterState_H

#include <string>

class LuaState {
public:
	Platform::String^ result;
};

extern LuaState luaState;

#endif
