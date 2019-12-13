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

	
	int GetPlayerSteps() { return m_player_steps; };////�����擾//
	int GetLife() { return m_life; };////�c�C�擾//
	void SetPlayerSteps(int steps) { m_player_steps = steps; };////�����X�V//
	void SetLife(int life) { m_life = life; };////�c�C�X�V//
	void Damage() { m_life--; };////Damage//

	static ReportScore* GetInstance() { return m_pInstance; };

private:
	ReportScore() {};
	~ReportScore() = default;

	static ReportScore* m_pInstance;
	int m_player_steps = 0;;
	int m_life=0;
};


