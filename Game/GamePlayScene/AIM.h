/**
* @file AIM.h
* 
* @brief �Ə��Ɋւ���w�b�_�[�t�@�C��
* 
* @autor Frira
* 
* @date 2025/07/08
*/


// ���d�C���N���[�h�̖h�~ ===========================================
#pragma once



// �w�b�_�t�@�C���̓ǂݍ���
#include "Game/GameMath.h"



// �N���X�̒�`
class AIM
{
	// �N���X�萔�̐錾 ---------------------------------------------
public:

	// ���˂������ǂ���
	bool m_shot;

	// �傫��
	static constexpr float SIZE = 32.0f;


	// �f�[�^�����o�̐錾 -------------------------------------------
private:

	// �ʒu
	Vector2D m_position;
	
	// �����o�֐��̐錾 ---------------------------------------------
public:

	// �R���X�g���N�^
	AIM();

	// �f�X�g���N�^
	~AIM();

	// ����������
	void Initialize(Vector2D position);

	// �X�V����
	void Update(int keyCondition, int keyTrigger);

	// �`��֐�
	void Render(int ghWheresTarget);

	// �I������
	void Finalize();

	// �v���C���[�̒��S�̈ʒu���擾����֐�
	Vector2D GetCenterPosition();
};