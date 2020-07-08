#pragma once
//|*******|//
//|include|//
//|*******|//


//|*******|//
//|define |//
//|*******|//


class ReportScore
{
public:
	ReportScore(const ReportScore&) = delete;
	ReportScore& operator=(const ReportScore&) = delete;
	ReportScore(const ReportScore&&) = delete;
	ReportScore& operator=(const ReportScore&&) = delete;

	static void InstanceCrearte();
	static void InstanceDelete();

	
	int GetPlayerSteps() { return m_player_steps; };////歩数取得//
	int GetLife() { return m_life; };////残気取得//
	void SetPlayerSteps(int steps) { m_player_steps = steps; };////歩数更新//
	void SetLife(int life) { m_life = life; };////残気更新//
	void Damage() { m_life--; };////Damage//

	static ReportScore* GetInstance() { return m_pInstance; };

private:
	ReportScore() = default;
	~ReportScore() = default;

	static ReportScore* m_pInstance;
	int m_player_steps = 0;
	int m_life=0;
};


