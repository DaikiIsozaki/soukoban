//|*******|//
//|include|//
//|*******|//
#include"Object.h"
#include"Player.h"
#include"Box.h"
#include"Wall.h"
#include"Destination.h"
#include "HitMove.h"
#include"ObjectManager.h"

HitMove* HitMove::instance = nullptr;

void HitMove::InstanceCreate()
{
	if (instance == nullptr)
	{
		instance = new HitMove;
	}
}

void HitMove::InstanceDelete()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

bool HitMove::Hit(Object * baseObj)
{
	bool bHit=false;

	for (auto search = ObjectManager::Get_Instance()->Get_List()->begin();
		search != ObjectManager::Get_Instance()->Get_List()->end(); search++)
	{
		if (baseObj->Get_PosX() == search._Ptr->_Myval->Get_PosX() &&
			baseObj->Get_PosY() == search._Ptr->_Myval->Get_PosY())
		{
			if (search._Ptr->_Myval != baseObj)
			{
				bHit = true;
			}
		}
	}

	return bHit;
}

//‚ ‚½‚Á‚Ä‚½‚ç“®‚©‚·–½—ß‚ðo‚·
bool HitMove::MoveThis(Object * baseObj, int moveX, int moveY)
{
	bool bMove = true;
	for (auto search = ObjectManager::Get_Instance()->Get_List()->begin();
		search != ObjectManager::Get_Instance()->Get_List()->end(); search++)
	{
		if (baseObj->Get_PosX()+moveX == search._Ptr->_Myval->Get_PosX() &&
			baseObj->Get_PosY()+moveY == search._Ptr->_Myval->Get_PosY())
		{
			search._Ptr->_Myval->Move(moveX, moveY);
			bMove = false;
			if (search._Ptr->_Myval->Get_Type() == DESTINATION)
			{
				if(search._Ptr->_Myval->GetHitbool()==false)//” ‚Æ–Ú“I’n‚ªd‚È‚Á‚Ä‚¢‚é‚Æ‚«‚Ì‚·‚è”²‚¯–hŽ~
				bMove = true;
			}
		}
	}

	if (bMove)
		baseObj->Move(moveX, moveY);

	return bMove;
}

bool HitMove::MoveOther(Object * baseObj, int moveX, int moveY)
{
	bool bMove = true;
	for (auto search = ObjectManager::Get_Instance()->Get_List()->begin();
		search != ObjectManager::Get_Instance()->Get_List()->end(); search++)
	{
		if (baseObj->Get_PosX() + moveX == search._Ptr->_Myval->Get_PosX() &&
			baseObj->Get_PosY() + moveY == search._Ptr->_Myval->Get_PosY())
		{
			bMove = false;
			
			if (search._Ptr->_Myval->Get_Type() == DESTINATION )
			{
				bMove = true;
			}
		}
	}

	return bMove;
}


