#pragma once
//|*******|//
//|include|//
//|*******|//

//|*******|//
//|define |//
//|*******|//


////�V�[��Manager//
class Manager
{
public:
	Manager(const Manager&) = delete;
	Manager& operator=(const Manager&) = delete;
	Manager(const Manager&&) = delete;
	Manager& operator=(const Manager&&) = delete;


	static void InstanceCreate();
	static void InstanceDelete();

	void Init();
	void Uninit();
	void Update();
	void Draw();
	void SceneChange(Scene* nextScene);
	static Manager* GetInstance() { return m_instance; };
	void SetEndflag(bool flag) { m_bEnd = flag; };//�I�����f
	bool GetEndflag() { return m_bEnd; };//�I�����f
	void SetMapNomber(int nextmapNo) { m_mapNomber = nextmapNo; };
	void NextMapSelect() { m_mapNomber++; };

private:
	Manager();
	~Manager() {};

	static Manager* m_instance;
	Scene* m_scene = nullptr;
	int m_mapNomber=0;

	bool m_bEnd = false;
};

