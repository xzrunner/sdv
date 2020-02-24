#include "sdv/NodePreview.h"
#include "sdv/Node.h"
#include "sdv/Evaluator.h"
#include "sdv/RegistNodes.h"
#include "sdv/PinType.h"
#include "sdv/Blackboard.h"

#include <ee3/WorldTravelOP.h>
#include <blueprint/NodeHelper.h>

#include <SM_Matrix2D.h>
#include <unirender/Blackboard.h>
#include <unirender/RenderContext.h>
#include <painting0/RenderContext.h>
#include <painting2/Blackboard.h>
#include <painting2/RenderContext.h>
#include <painting2/RenderTarget.h>
#include <painting2/RenderSystem.h>
#include <painting2/RenderTargetCtx.h>
#include <painting2/WindowContext.h>
#include <painting2/WindowCtxRegion.h>
#include <painting2/Shader.h>
#include <painting3/RenderSystem.h>
#include <painting3/MaterialMgr.h>
#include <painting3/PerspCam.h>
#include <node2/RenderSystem.h>
#include <node3/RenderSystem.h>
#include <renderpipeline/RenderMgr.h>
#include <renderpipeline/IRenderer.h>
#include <sd/Node.h>
#include <sd/Image.h>
#include <tessellation/Painter.h>

namespace sdv
{

NodePreview::NodePreview()
{
    //m_cam = std::make_shared<pt3::PerspCam>(
    //    sm::vec3(0, 2, -2), sm::vec3(0, 0, 0), sm::vec3(0, 1, 0)
    //);
}

void NodePreview::Draw(const Evaluator& eval, const bp::Node& node, const n2::RenderParams& rp) const
{
    auto back_node = eval.QueryBackNode(node);
    if (!back_node) {
        return;
    }

    auto img = back_node->GetImage();
    if (!img) {
        return;
    }

    auto tex = img->GetTexture();
    if (!tex) {
        return;
    }

    auto mt4 = sm::mat4(bp::NodeHelper::CalcPreviewMat(node, rp.GetMatrix()));
    const auto scale = mt4.GetScale();
    const float hw = scale.x * 0.5f;
    const float hh = scale.y * 0.5f;
    const auto pos = mt4.GetTranslate();
    const float vertices[] = {
        pos.x - hw, pos.y - hh,
        pos.x + hw, pos.y - hh,
        pos.x + hw, pos.y + hh,
        pos.x - hw, pos.y + hh,
    };

    auto& st = node.GetStyle();
    auto& rt_mgr = pt2::Blackboard::Instance()->GetRenderContext().GetRTMgr();
    auto tw = st.width / rt_mgr.WIDTH;
    auto th = st.width / rt_mgr.HEIGHT;
    const float texcoords[] = {
        0, 0,
        tw, 0,
        tw, th,
        0, th
    };
    pt2::RenderSystem::DrawTexQuad(vertices, texcoords, tex->TexID(), 0xffffffff);
}

}