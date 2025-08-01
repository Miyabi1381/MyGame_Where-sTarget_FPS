//--------------------------------------------------------------------------------------
// File: GameOverScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GameOverScene.h"
#include "Game/Game.h"


// �R���X�g���N�^
GameOverScene::GameOverScene(Game* pGame)
	: m_pGame{ pGame }
{

}

// �f�X�g���N�^
GameOverScene::~GameOverScene()
{

}

// ����������
void GameOverScene::Initialize()
{

}

// �X�V����
void GameOverScene::Update(int keyCondition, int keyTrigger)
{
	// �Q�[���N���A�����ꍇ
	if (true)
	{

	}

	// �X�y�[�X�L�[�������ꂽ��
	if (keyTrigger & PAD_INPUT_10)
	{
		// �Q�[���v���C�V�[����
		m_pGame->RequestSceneChange(Game::SceneID::GAMEPLAY);
	}
}

// �`�揈��
void GameOverScene::Render()
{
	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GameOver�V�[��");
}

// �I������
void GameOverScene::Finalize()
{

}

