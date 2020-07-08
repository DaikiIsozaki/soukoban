#pragma once
//|*******|//
//|include|//
//|*******|//

//|*******|//
//|define |//
//|*******|//


////ƒV[ƒ“Manager//
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
	void SetEndflag(bool flag) { m_bEnd = flag; };//I—¹”»’f
	bool GetEndflag() { return m_bEnd; };//I—¹”»’f
	void SetMapNomber(int nextmapNo) { _MapNomber = nextmapNo; };
	void NextMapSelect() { _MapNomber++; };

private:
	Manager();
	~Manager() {};

	static Manager* m_instance;
	Scene* _Scene = nullptr;
	int _MapNomber=0;

	bool m_bEnd = false;
};

