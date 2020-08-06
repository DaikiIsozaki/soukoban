//|*******|//
//|include|//
//|*******|//
#include"Object.h"
#include"Player.h"
#include"Box.h"
#include"Wall.h"
#include"Destination.h"
#include "ThirdWheel.h"
#include "ObjectManager.h"
#include "HitMove.h"

//インスタンス初期化
ObjectManager* ObjectManager::m_instance = nullptr;

ObjectManager::ObjectManager()
{

	m_objContainer = new std::list<Object*>;
}

ObjectManager::~ObjectManager()
{
	delete m_objContainer;
	m_objContainer = nullptr;
}

void ObjectManager::InstanceCreate()
{
	if (m_instance == nullptr)
	{
		m_instance = new ObjectManager;
	}
}

void ObjectManager::InstanceDelete()
{
	if (m_instance != nullptr)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

void ObjectManager::Init()
{
	for (auto obj : *m_objContainer)
	{
		obj->Init();
	}
}

void ObjectManager::Uninit()
{
	for (auto obj : *m_objContainer)
	{
		obj->Uninit();
		delete obj;
		obj = nullptr;
	}

	m_objContainer->clear();

}

void ObjectManager::Update()
{
	for (auto obj : *m_objContainer)
	{
		obj->Update();

	}
}

void ObjectManager::Draw()
{
	for (auto obj : *m_objContainer)
	{
		obj->Draw();
	}
}

 void ObjectManager::AddObj(int type, int x, int y, int sizeX, int sizeY)
{
	
	switch (type)
	{
	case NON:
		break;
	case PLAYER:
		m_obj = new Player;
		m_obj->Create(x, y,sizeX,sizeY);
		break;
	case BOX:
		m_obj =new Box;
		m_obj->Create(x, y, sizeX, sizeY);
		break;
	case WALL:
		m_obj = new Wall;
		m_obj->Create(x, y, sizeX, sizeY);
		break;
	case DESTINATION:
		m_obj = new Destination;
		m_obj->Create(x, y, sizeX, sizeY);
		m_destinationNum++;
		break;
	case THIRDWHEEL:
		m_obj = new ThirdWheel;
		m_obj->Create(x, y, sizeX, sizeY);
		break;
	}
	m_objContainer->push_back(m_obj);
	
}

 bool ObjectManager::ClearCheck()
 {
	 bool bPoint = false;
	 bool bBox = false;
	 for (auto cp : *m_objContainer)//cp…ClearPoint
	 {
		 if (cp->Get_Type() == DESTINATION )
		 {
			 if (cp->GetHitbool())
				 continue;
			 else
				 return false;
		 }
		 else
		 {
			 continue;
		 }
	 }
	 
	 bPoint = true;

	 for (auto box : *m_objContainer)
	 {
		 if (box->Get_Type() == BOX)
		 {
			 if (box->GetHitbool())
				 continue;
			 else
				 return false;
		 }
		 else
		 {
			 continue;
		 }
	 }

	 bBox = true;

	 if (bPoint == true && bBox == true)
		 return true;
 }

 void ObjectManager::Reset()
 {
	for (auto obj : *m_objContainer)
	{
		obj->Uninit();
		delete obj;
		obj = nullptr;
	}
	m_objContainer->clear();
 }





 

