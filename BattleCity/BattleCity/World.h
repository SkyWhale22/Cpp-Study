#pragma once
class World
{
private:
	static World* m_pWorld;
	World();
	~World();
public:

	static World* GetInstance()
	{
		if (m_pWorld == nullptr)
			m_pWorld = new World();

		return m_pWorld;
	}

	void FreeInstance() { delete m_pWorld; }
};

