#include "GamePlayScene.h"
#include "Game/Game.h"


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
	// �^�[�Q�b�g�̍X�V
	m_target.Update();

	// �Ə��̍X�V
	m_AIM.Update(keyCondition, keyTrigger);
	
	// �Փ˔���
	CheckEnemyColliedWithPlayerBullet();

	// �Q�[���N���A����
	if (IsGameClear())
	{
		// �Q�[���I�[�o�[�V�[����
		m_pGame->RequestSceneChange(Game::SceneID::GAMEOVER);
	}
	else if (IsGameOver())
	{
		// �Q�[���I�[�o�[�V�[����
		m_pGame->RequestSceneChange(Game::SceneID::GAMEOVER);
	}
}


// �`�揈��
void GamePlayScene::Render()
{
	// �^�[�Q�b�g�̕`��
	m_target.Render(m_ghWheresTarget);

	// �f�o�b�O�����蔻��(���[������)
	RECT targetBox = m_target.GetBoundingBox();
	DrawBox(targetBox.left, targetBox.top, targetBox.right, targetBox.bottom, GetColor(255, 0, 0), FALSE);

	// �Ə��̕`��
	m_AIM.Render(m_ghWheresTarget);
	DrawFormatString(10, 30, GetColor(255, 255, 255), L"�Q�[���v���C�V�[��");

}


// �I������
void GamePlayScene::Finalize()
{
	// �^�[�Q�b�g�̏I��
	m_target.Finalize();

	// �Ə��̏I��
	m_AIM.Finalize();

}


// �Q�[���N���A�����ׂ�֐�
bool GamePlayScene::IsGameClear()
{
	// �^�[�Q�b�g�����񂾂�N���A
	if (!m_target.IsActive()) return true;

	return false;
}


// �Q�[���I�[�o�[�����ׂ�֐�
bool GamePlayScene::IsGameOver()
{
	return false;
}



// �^�[�Q�b�g�ƒe(���e�G�t�F�N�g)�Ƃ̏Փ˔���
void GamePlayScene::CheckEnemyColliedWithPlayerBullet()
{
	// ���e�G�t�F�N�g�̎Q��
	PointOfImpact& pointOfImpact = m_AIM.GetPointOfImpact();

	// ���e�G�t�F�N�g�̂���A�N�e�B�u�Ȃ画�肵�Ȃ�
	if (!pointOfImpact.IsActive()) return;

	// �^�[�Q�b�g����A�N�e�B�u�Ȃ画�肵�Ȃ�
	if (!m_target.IsActive()) return;

	// ���ꂼ��̋�`���擾
	RECT pointRect = pointOfImpact.GetBoundingBox();
	RECT targetRect = m_target.GetBoundingBox();

	// �Փ˔���
	RECT result;
	if (IntersectRect(&result, &pointRect, &targetRect))
	{
		// �������Ă�����^�[�Q�b�g������
		m_target.OnHit();
	}
}