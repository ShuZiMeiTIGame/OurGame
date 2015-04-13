#include"TollgateBody.h"
TollgateBody::TollgateBody(){
}
TollgateBody::TollgateBody(int type, Vec2 pos, std::vector<Vec2>* posArray){
	_type = type;
	_position = pos;
	_posArray = posArray;
}
TollgateBody* TollgateBody::createTollgateBody(int type, Vec2 pos, std::vector<Vec2>* posArray){
	return new TollgateBody(type,pos,posArray);
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
	return _posArray;
}