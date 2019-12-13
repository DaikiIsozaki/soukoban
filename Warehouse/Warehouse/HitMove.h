#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//

class HitMove
{
public:
	HitMove() {};
	~HitMove() {};

	void InstanceCreate();
	void InstanceDelete();
	bool Hit(Object* baseObj);
	bool MoveThis(Object* baseObj,int moveX,int moveY);
	bool MoveOther(Object* baseObj, int moveX, int moveY);

	static HitMove* Get_Instance() { return instance; };


private:
	static HitMove* instance;
	int m_steps = 0;
};

