#pragma once

#include "texlab/Node.h"

namespace texlab
{

void nodes_regist_rttr();

namespace node
{

#define EXE_FILEPATH "texlab/node_def_gen.h"
#include "texlab/node_regist_cfg.h"
#undef EXE_FILEPATH

}

}