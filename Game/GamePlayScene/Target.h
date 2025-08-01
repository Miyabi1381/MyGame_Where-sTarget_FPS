#pragma once
#include "Game/GameMath.h"


// �G�N���X
class Target
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �c���Ɖ���
	static constexpr int SIZE = 64;

	// �ړ��̑���
	static constexpr int SPEED = 2;


	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �A�N�e�B�u�Ȃ�true��ݒ�
	bool m_isActive;

	// �ʒu
	Vector2D m_position;

	// ���x
	Vector2D m_velocity;

	// ����(Rad)
	float m_angle;


	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Target();

	// �f�X�g���N�^
	~Target();

	// �������֐�
	void Initialize(Vector2D position);

	// �X�V�֐�
	void Update();

	// �`��֐�
	void Render(int ghWheresTarget);

	// �I������
	void Finalize();

	// �^�[�Q�b�g���A�N�e�B�u�����ׂ�֐�
	bool IsActive() const { return m_isActive; }

	// ���̃^�[�Q�b�g���o��������֐�
	void Spawn(Vector2D position);

	// ���E�{�b�N�X���擾����֐�
	RECT GetBoundingBox() const;

	// ���W���擾����֐�
	Vector2D GetPosition() const { return m_position; }

	// �Փ˂�����Ăяo�����֐�
	void OnHit() { m_isActive = false; }

};
