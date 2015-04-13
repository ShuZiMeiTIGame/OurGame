#include"DrawBody.h"
DrawNode *DrawBody::addDraw(Vec2 a, Vec2 b)
{
	PhysicsBody*lineBody = PhysicsBody::createEdgeSegment(a, b);
	auto drawNode = DrawNode::create();
	drawNode->setPhysicsBody(lineBody);
	return drawNode;
}