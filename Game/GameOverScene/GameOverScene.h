//--------------------------------------------------------------------------------------
// File: GameOverScene.h
//
//--------------------------------------------------------------------------------------
#pragma once


// �N���X�̑O���錾
class Game;

// �Q�[���I�[�o�[�V�[��
class GameOverScene
{

	// �N���X�萔�̐錾 -------------------------------------------------
public:


	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// ���̃V�[�����܂ރQ�[���I�u�W�F�N�g�ւ̃|�C���^
	Game* m_pGame;



	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	GameOverScene(Game* pGame);

	// �f�X�g���N�^
	~GameOverScene();

	// ����������
	void Initialize();

	// �X�V����
	void Update(int keyCondition, int keyTrigger);

	// �`�揈��
	void Render();

	// �I������
	void Finalize();

};
