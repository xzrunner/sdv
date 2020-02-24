#pragma once

#include <sd/typedef.h>
#include <sd/NodeVarType.h>

namespace sd { class Node; }
namespace bp { class Node; class Pin; }

namespace sdv
{

class Evaluator;

class SdAdapter
{
public:
    static void UpdatePropBackFromFront(const bp::Node& front,
        sd::Node& back, const Evaluator& eval);

    static sd::NodePtr CreateBackFromFront(const bp::Node& front);

    static int TypeBackToFront(sd::NodeVarType type);

}; // SOP

}