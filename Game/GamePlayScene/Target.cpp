#include "Target.h"
#include "Game/Screen.h"
#include <cstdlib>
#include <ctime>




// �R���X�g���N�^
Target::Target()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
	, m_angle{ 0.0f }
{
}



// �f�X�g���N�^
Target::~Target()
{
}



// �������֐�
void Target::Initialize(Vector2D position)
{
	// �A�N�e�B�u�ɂ���
	m_isActive = true;

	// �o���ʒu��ݒ肷��
	m_position = position;

	// �����_���ɏ����p�x��ݒ�
	m_angle = static_cast<float>(rand()) / RAND_MAX * 2.0f * 3.1415926f;

	// �����x�N�g��
	m_velocity.x = std::cosf(m_angle) * Target::SPEED;
	m_velocity.y = std::sinf(m_angle) * Target::SPEED;
}



// �X�V�֐�
void Target::Update()
{
	// �^�[�Q�b�g����A�N�e�B�u�Ȃ�X�V���Ȃ�
	if (!m_isActive) return;

	// �ɂ₩�ɕ�����ς���
	float deltaAngle = ((rand() / (float)RAND_MAX) - 0.5f) * 0.6f;	// -0.3 �` 0.3f Rad
	m_angle += deltaAngle;

	// ���x���p�x����Čv�Z����
	m_velocity.x = std::cosf(m_angle) * Target::SPEED;
	m_velocity.y = std::sinf(m_angle) * Target::SPEED;

	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

		// X������ʊO�Ȃ�
	if ((m_position.x < 0) ||
		(m_position.x + Target::SIZE > Screen::WIDTH))
	{
		m_angle = 3.1415926f - m_angle;	// �p�x�𔽓]������
	}

	// Y������ʊO�Ȃ�
	if ((m_position.y < 0) ||
		(m_position.y + Target::SIZE > Screen::HEIGHT))
	{
		m_angle = -m_angle;	// �p�x�𔽓]������
	}
	
}



// �`��֐�
void Target::Render(int ghShootingGame)
{
	// �^�[�Q�b�g�����񂾂�
	if (!m_isActive)
	{
		// �f�b�h�^�[�Q�b�g�̕`��
		DrawRectExtendGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y),
			static_cast<int>(m_position.x) + Target::SIZE, static_cast<int>(m_position.y) + Target::SIZE / 2,
			0, 80, 64, 24,
			ghShootingGame, TRUE);
	}
	else
	{
		// �^�[�Q�b�g�̕`��
		DrawRectExtendGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y),
			static_cast<int>(m_position.x) + Target::SIZE / 2, static_cast<int>(m_position.y) + Target::SIZE,
			80, 0, 32, 64,
			ghShootingGame, TRUE);
	}
}



// �I������
void Target::Finalize()
{
}

// ���̃^�[�Q�b�g���o��������֐�
void Target::Spawn(Vector2D position)
{
	// �A�N�e�B�u�ɂ���
	m_isActive = true;

	// �^�[�Q�b�g������������
	Initialize(position);
}



// ���E�{�b�N�X���擾����֐�
RECT Target::GetBoundingBox() const
{
	return RECT{
	static_cast<LONG>(m_position.x),
	static_cast<LONG>(m_position.y),
	static_cast<LONG>(m_position.x + SIZE),
	static_cast<LONG>(m_position.y + SIZE)
	};
}
