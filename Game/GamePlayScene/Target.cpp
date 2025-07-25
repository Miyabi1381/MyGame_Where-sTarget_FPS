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
	// �^�[�Q�b�g�̕`��
	DrawRectExtendGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y), 
						static_cast<int>(m_position.x) + Target::SIZE, static_cast<int>(m_position.y) + Target::SIZE,
						64, 0, 64, 64,
						ghShootingGame, TRUE);
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
	RECT rect{};

	rect.left = static_cast<int>(m_position.x);
	rect.right = static_cast<int>(m_position.x) + Target::SIZE;
	rect.top = static_cast<int>(m_position.y);
	rect.bottom = static_cast<int>(m_position.y) + Target::SIZE;

	return rect;
}
