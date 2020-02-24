#pragma once

#include "sdv/Node.h"

namespace sdv
{

void nodes_regist_rttr();

namespace node
{

#define EXE_FILEPATH "sdv/node_def_gen.h"
#include "sdv/node_regist_cfg.h"
#undef EXE_FILEPATH

}

}