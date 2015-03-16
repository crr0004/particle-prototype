#ifndef	SPRITE_H
#define	SPRITE_H 1
	#include "Sprite.h"
#endif
#ifndef	RESOURCES_H
#define	RESOURCES_H 1
	#include "res/Resources.h"
#endif
#ifndef	STAGE_H
#define	STAGE_H 1
	#include "Stage.h"
#endif
#ifndef	VECTOR2_H
#define	VECTOR2_H 1
	#include "math/vector2.h"
#endif
#ifndef	ACTOR_H
#define	ACTOR_H 1
	#include "Actor.h"
#endif



class Particle: public oxygine::Sprite {
public:
	Particle();
	void loadSprite(const oxygine::Resources &res);
	oxygine::Sprite *getSprite();
	~Particle();

protected:
	oxygine::VectorT2<float> *mPosition;
	void update(const oxygine::UpdateState &us);
};