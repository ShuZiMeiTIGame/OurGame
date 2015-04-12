#include"Tollgate.h"
Tollgate::Tollgate(int level, bool isPassed){
	_level = level;
	_isPassed = isPassed;
}
Tollgate* Tollgate::createTollgate(int level, bool isPassed){
	return new Tollgate(level, isPassed);
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

