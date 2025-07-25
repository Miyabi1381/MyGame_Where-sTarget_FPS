/**
* @file		GamePlayScene.h
* 
* @brief	�Q�[���V�[���Ɋւ���w�b�_�[�t�@�C��
* 
* @autor	Frira
* 
* @date		2025/07/02
*/


// ���d�C���N���[�h�̖h�~ =====================================================
#pragma once



// �w�b�_�t�@�C���̓ǂݍ��� ===================================================
#include "Game/Screen.h"
#include "Game/GameMath.h"

#include "Target.h"
#include "AIM.h"


// �N���X�̑O���錾
class Game;

class GamePlayScene
{
	// �񋓌^�̐錾 -------------------------------------------------
private:

	// �Q�[���̏��
	enum class GameState
	{
		NONE = -1,		// �G���[
		GAMEPLAY,		// �Q�[���v���C��
		GAMEOVER,		// �Q�[���I�[�o�[
		GAMECLEAR,		// �Q�[���N���A
	};


	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �t�H���g�T�C�Y
	static constexpr int FONT_SIZE = 50;

	// �Q�[���I�[�o�[�̕�����
	static constexpr wchar_t GAMEOVER[] = L"Game Over";

	// �Q�[���N���A�̕�����
	static constexpr wchar_t GAMECLEAR[] = L"Game Clear";


	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �G�̃O���t�B�b�N�n���h��
	int m_ghWheresTarget;

	// �Ə�
	AIM m_AIM;

	// �^�[�Q�b�g
	Target m_target;

	// ���̃V�[�����܂ރQ�[���I�u�W�F�N�g�ւ̃|�C���^
	Game* m_pGame;

	// �Q�[���̏��
	GameState m_gameState;


	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	GamePlayScene(Game* pGame);

	// �f�X�g���N�^
	~GamePlayScene();

	// ����������
	void Initialize();

	// �X�V����
	void Update(int keyCondition, int keyTrigger);

	// �`�揈��
	void Render();

	// �I������
	void Finalize();


private:

	// �Q�[���N���A�����ׂ�֐�
	bool IsGameClear();

	// �Q�[���I�[�o�[�����ׂ�֐�
	bool IsGameOver();

};