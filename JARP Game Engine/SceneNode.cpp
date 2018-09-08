#include "SceneNode.h"



SceneNode::SceneNode() : mChildren(), mParent(nullptr)
{
}


SceneNode::~SceneNode()
{
}

void SceneNode::attachChild(SceneNodePtr child)
{
    child->mParent = this;
    this->mChildren.push_back(std::move(child));
}

SceneNode::SceneNodePtr SceneNode::detachChild(const SceneNode& node)
{
    auto found = std::find_if(this->mChildren.begin(), this->mChildren.end(), [&](SceneNodePtr& p) -> bool { return p.get() == &node; });

    assert(found != this->mChildren.end());

    SceneNodePtr result = std::move(*found);
    result->mParent = nullptr;
    this->mChildren.erase(found);
    return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();
    this->drawCurrent(target, states);
    this->drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto itr = this->mChildren.begin(); itr != mChildren.end(); itr++)
    {
        (*itr)->draw(target, states);
    }
}