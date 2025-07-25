#include "GamePlayScene.h"


// �R���X�g���N�^
GamePlayScene::GamePlayScene(Game* pGame)
	: m_ghWheresTarget{ -1 }
	, m_AIM{}
	, m_target{}
	, m_pGame{ pGame }
	, m_gameState{}
{
}


// �f�X�g���N�^
GamePlayScene::~GamePlayScene()
{
}


// ����������
void GamePlayScene::Initialize()
{
	// �G�̓ǂݍ���
	m_ghWheresTarget = LoadGraph(L"Resources/Textures/Where's_Target.png");

	// �Ə��̏�����
	Vector2D startPosition = Vector2D{ Screen::CENTER_X, Screen::CENTER_Y };
	m_AIM.Initialize(startPosition);

	// �^�[�Q�b�g�̏�����
	Vector2D position = Vector2D{ static_cast<float>(GetRand(Screen::WIDTH - Target::SIZE)), static_cast<float>(GetRand(Screen::HEIGHT - Target::SIZE)) };
	m_target.Initialize(position);

}


// �X�V����
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// �Ə��̍X�V
	m_AIM.Update(keyCondition, keyTrigger);

	// �^�[�Q�b�g�̍X�V
	m_target.Update();
}


// �`�揈��
void GamePlayScene::Render()
{
	// �Ə��̕`��
	m_AIM.Render(m_ghWheresTarget);

	// �^�[�Q�b�g�̕`��
	m_target.Render(m_ghWheresTarget);
}


// �I������
void GamePlayScene::Finalize()
{
	// �Ə��̏I��
	m_AIM.Finalize();

	// �^�[�Q�b�g�̏I��
	m_target.Finalize();
}


// �Q�[���N���A�����ׂ�֐�
bool GamePlayScene::IsGameClear()
{
	return false;
}


// �Q�[���I�[�o�[�����ׂ�֐�
bool GamePlayScene::IsGameOver()
{
	return false;
}
