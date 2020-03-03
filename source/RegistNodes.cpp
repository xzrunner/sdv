#include "texlab/RegistNodes.h"

#include <ee0/ReflectPropTypes.h>

#include <js/RTTR.h>

RTTR_REGISTRATION
{

// base

rttr::registration::class_<texlab::Node>("texlab::node")
.property("name", &texlab::Node::GetName, &texlab::Node::SetName)
(
	rttr::metadata(ee0::UIMetaInfoTag(), ee0::UIMetaInfo("Name"))
)
;

#define EXE_FILEPATH "texlab/node_rttr_gen.h"
#include "texlab/node_regist_cfg.h"
#undef EXE_FILEPATH

}

namespace texlab
{

void nodes_regist_rttr()
{
}

}