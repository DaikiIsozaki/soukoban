#pragma once
//|*******|//
//|include|//
//|*******|//



//|*******|//
//|define |//
//|*******|//

class GameLoop
{
public:
	GameLoop(const GameLoop&) = delete;
	GameLoop& operator=(const GameLoop&) = delete;
	GameLoop(const GameLoop&&) = delete;
	GameLoop& operator=(const GameLoop&&) = delete;

	static void Create();
	static void Delete();
	void Loop();
	void Init();
	void Uninit();
	void Update();
	void Draw();
	static auto Get_Instance() { return m_instance; };

	

private:
	GameLoop() = default;
	~GameLoop() = default;

	static GameLoop* m_instance;
	
};

