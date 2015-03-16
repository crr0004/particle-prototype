#include "oxygine-framework.h"
#ifndef	PARTICLE_H
#define	PARTICLE_H 1
	#include "Particle.h"
#endif


#ifdef __S3E__
#include "s3eKeyboard.h"
#endif

using namespace oxygine;

Particle *particle;

//it is our resources
//in real project you would have more than one Resources declarations. It is important on mobile devices with limited memory and you would load/unload them
Resources resources;
Resources resourcesUI;

//extern spStage stage2;


void preinit()
{
	/**
	There are 2 modes of loading and blending/rendering sprites: normal and premultiplied alpha.
	You should set it before loading any assets. 
	Premultiplied mode is more advanced and faster than normal. In this mode RGB pixels of textures premultiplying to alpha when textures are loading and using blend_premultiply_alpha as default Sprites blend option.
	Default value is premultiplied = true
	http://blog.rarepebble.com/111/premultiplied-alpha-in-opengl/

	I set it to false to simplify shaders for UserShaderDemo
	*/

	Renderer::setPremultipliedAlphaRender(false);
}

void init()
{

	//load xml file with resources definition
	resources.loadXML("xmls/res.xml");
	particle = new Particle;
	particle->loadSprite(resources);
	particle->getSprite()->attachTo(getStage());
	/*Change to particles _tests = new TestActor;
	getStage()->addChild(_tests);*/
    
}

void update()
{
	
}

void destroy()
{
	particle->getSprite()->detach();
	resources.free();
	resourcesUI.free();
}