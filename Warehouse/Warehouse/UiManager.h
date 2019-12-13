#pragma once
//|*******|//
//|include|//
//|*******|//

//|*******|//
//|define |//
//|*******|//


class UiManager
{
public:
	UiManager(const UiManager&) = delete;
	UiManager& operator=(const UiManager&) = delete;
	UiManager(const UiManager&&) = delete;
	UiManager& operator=(const UiManager&&) = delete;

	static void InstanceCreate();
	static void InstanceDelete();

	void Init();
	void Uninit();
	void SetSceneType(int state) { _SceneType = state; };
	void Update();
	void Draw();

	static UiManager* GetInstance() { return m_instance; };

private:
	UiManager() {};
	~UiManager() {};

	static UiManager* m_instance;
	TitleUi* m_titleUi;
	StageSelectUi* m_stageSelectUi;
	GameUi* m_gameUi;
	ResultUi* m_resultUi;
	GameEndUi* m_gameendUi;
	int _SceneType=0;
};

