#include"TollgateBody.h"
TollgateBody::TollgateBody(){
}
TollgateBody::TollgateBody(int type, Vec2 pos){
	_type = type;
	_position = pos;
}
TollgateBody::TollgateBody(int type, Vec2 pos, int radius){
	_type = type;
	_position = pos;
	_radius = radius;
}
TollgateBody* TollgateBody::createTollgateBody(int type, Vec2 pos){
	return new TollgateBody(type,pos);
}
TollgateBody* TollgateBody::createTollgateCircle(int type, Vec2 pos, int radius){
	return new TollgateBody(type,pos,radius);
}
void TollgateBody::setType(int type){
	_type = type;
}
int  TollgateBody::getType(){
	return _type;
}
void TollgateBody::setPosition(Vec2 pos){
	_position = pos;
}
Vec2 TollgateBody::getPosition(){
	return _position;
}
std::vector<Vec2>* TollgateBody::getPosArray(){
	return &_posArray;
}
void TollgateBody::setRadius(int radius){
	_radius = radius;
}
int TollgateBody::getRadius(){
	return _radius;
}