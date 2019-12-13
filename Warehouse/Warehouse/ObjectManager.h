#pragma once
//|*******|//
//|include|//
//|*******|//



//|*******|//
//|define |//
//|*******|//
#define MAX_DESTINATIONPOINT	(100)//�ړI�n�̍ő吔



// //�I�u�W�F�N�g�}�l�[�W���[//
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
	void AddObj(int type,int x,int y,int sizeX,int sizeY);//�R���e�i�ɃI�u�W�F�N�g������
	static auto Get_Instance() { return instance; };
	bool ClearCheck();
	void Reset();

	auto Get_List() { return m_objContainer; };


private:
	ObjectManager();
	~ObjectManager();


	static ObjectManager* instance;
	Object* m_obj;//�R���e�i�ɓ����悤
	std::list<Object*>* m_objContainer;//�I�u�W�F�N�g�p�R���e�i
	unsigned int _DestinationNum = 0;

	//���C�t���v���C���[�Ɏ������Ȃ�
};

