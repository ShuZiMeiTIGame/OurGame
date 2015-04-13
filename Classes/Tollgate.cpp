#include"Tollgate.h"
Tollgate::Tollgate(int level, bool isPassed,Vec2 pos){
	_level = level;
	_isPassed = isPassed;
	_pos = pos;
}
Tollgate* Tollgate::createTollgate(int level, bool isPassed,Vec2 pos){
	return new Tollgate(level, isPassed,pos);
}
int Tollgate::getLevel(){
	return _level;
}
void Tollgate::setLevel(int level){
	_level = level;
}
bool Tollgate::isPassed(){
	return _isPassed;
}
Vector<TollgateBody*>* Tollgate::getbodiesArray(){
	return &_bodies;
}
void Tollgate::setBallPosition(Vec2 pos){
	_pos = pos;
}
Vec2 Tollgate::getBallPostion(){
	return _pos;
}
