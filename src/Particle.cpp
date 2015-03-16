#ifndef	PARTICLE_H
#define	PARTICLE_H 1
	#include "Particle.h"
#endif
#include <stdio.h>

const float accerlation = 0.08f;

Particle::Particle(){

}

Particle::~Particle(){
	delete mPosition;
}

void Particle::update(const oxygine::UpdateState &us){
	mPosition->x = (us.time / 1000.0f) + 400;
	mPosition->y = (us.time / 1000.0f) * us.time / 1000.0f;
	//mPosition->x = (accerlation) * us.time;
	setPosition(*mPosition);
}


void Particle::loadSprite(const oxygine::Resources &res){
	setAnchor(0.5f, 0.5f);
	setResAnim(res.getResAnim("square"));
	mPosition = new oxygine::VectorT2<float>(oxygine::getStage()->getWidth()/2.0f, 0.0f);
	setPosition(*mPosition);
}

oxygine::Sprite* Particle::getSprite(){
	return (Sprite*)this;
}