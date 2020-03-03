#pragma once

#include <texgraph/typedef.h>
#include <texgraph/NodeVarType.h>

namespace texgraph { class Node; }
namespace bp { class Node; class Pin; }

namespace texlab
{

class Evaluator;

class SdAdapter
{
public:
    static void UpdatePropBackFromFront(const bp::Node& front,
        texgraph::Node& back, const Evaluator& eval);

    static texgraph::NodePtr CreateBackFromFront(const bp::Node& front);

    static int TypeBackToFront(texgraph::NodeVarType type);

}; // SOP

}