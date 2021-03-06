#pragma once

#include <ee0/typedef.h>
#include <blueprint/typedef.h>

#include <dag/Graph.h>
#include <texgraph/typedef.h>
#include <texgraph/NodeVarType.h>
#include <node0/typedef.h>

#include <boost/noncopyable.hpp>

#include <vector>
#include <unordered_map>

namespace bp { class Connecting; }

namespace texlab
{

class Evaluator : boost::noncopyable
{
public:
    Evaluator(const ee0::SubjectMgrPtr& sub_mgr);

    // update nodes
    void OnAddNode(const bp::Node& node, const n0::SceneNodePtr& snode,
        bool need_update = true);
    void OnRemoveNode(const bp::Node& node);
    void OnClearAllNodes();

    // update node prop
    void OnNodePropChanged(const bp::NodePtr& node);

    // update node conn
    void OnConnected(const bp::Connecting& conn);
    void OnDisconnecting(const bp::Connecting& conn);
    void OnRebuildConnection();

    auto& GetEval() const { return m_eval; }

    texgraph::NodePtr QueryBackNode(const bp::Node& front_node) const;
    n0::SceneNodePtr QuerySceneNode(const bp::Node& front_node) const;

private:
    void Update();

private:
    dag::Graph<texgraph::NodeVarType> m_eval;

    std::unordered_map<const bp::Node*, texgraph::NodePtr> m_front2back;
    std::unordered_map<const texgraph::Node*, n0::SceneNodePtr> m_back2node;

}; // Evaluator

}