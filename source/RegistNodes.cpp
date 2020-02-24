#include "sdv/RegistNodes.h"

#include <ee0/ReflectPropTypes.h>

#include <js/RTTR.h>

RTTR_REGISTRATION
{

// base

rttr::registration::class_<sdv::Node>("sdv::node")
.property("name", &sdv::Node::GetName, &sdv::Node::SetName)
(
	rttr::metadata(ee0::UIMetaInfoTag(), ee0::UIMetaInfo("Name"))
)
;

#define EXE_FILEPATH "sdv/node_rttr_gen.h"
#include "sdv/node_regist_cfg.h"
#undef EXE_FILEPATH

}

namespace sdv
{

void nodes_regist_rttr()
{
}

}