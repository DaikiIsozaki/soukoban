#pragma once
//|*******|//
//|include|//
//|*******|//



//|*******|//
//|define |//
//|*******|//
#define MAX_DESTINATIONPOINT	(100)//目的地の最大数



// //オブジェクトマネージャー//
class ObjectManager
{
public:
	ObjectManager(const ObjectManager&) = delete;
	ObjectManager& operator=(const ObjectManager&) = delete;
	ObjectManager(const ObjectManager&&) = delete;
	ObjectManager& operator=(const ObjectManager&&) = delete;

	static void InstanceCreate();
	static void InstanceDelete();
	void Init();
	void Uninit();
	void Update();
	void Draw();
	void AddObj(int type,int x,int y,int sizeX,int sizeY);//コンテナにオブジェクトを入れる
	static auto Get_Instance() { return instance; };
	bool ClearCheck();
	void Reset();

	auto Get_List() { return m_objContainer; };


private:
	ObjectManager();
	~ObjectManager();


	static ObjectManager* instance;
	Object* m_obj;//コンテナに入れるよう
	std::list<Object*>* m_objContainer;//オブジェクト用コンテナ
	unsigned int _DestinationNum = 0;

	//ライフをプレイヤーに持たせない
};

