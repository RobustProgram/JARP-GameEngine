#pragma once

#include <SFML/Graphics.hpp>
#include <assert.h>
#include <memory>
#include <vector>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> SceneNodePtr;

public:
    SceneNode();
    ~SceneNode();

    void attachChild(SceneNodePtr child);
    SceneNodePtr detachChild(const SceneNode& node);

public:
    void update(sf::Time dt);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);

private:
    SceneNode*                mParent;

protected:
    std::vector<SceneNodePtr> mChildren;
};

