#include "AIM.h"
#include "Game/Screen.h"


// �R���X�g���N�^
AIM::AIM()
	: m_position{ 0}
{
}


// �f�X�g���N�^
AIM::~AIM()
{
}


// ����������
void AIM::Initialize(Vector2D position)
{
	// �ʒu�̏�����
	m_position = position;
}


// �X�V����
void AIM::Update(int keyCondition, int keyTrigger)
{
	// �}�E�X�̍��W���擾����
	int mouseX{}, mouseY{};
	GetMousePoint(&mouseX, &mouseY);

	// �}�E�X�̈ʒu�ɉ摜��\������
	m_position.x = static_cast<float>(mouseX) - AIM::SIZE / 2;
	m_position.y = static_cast<float>(mouseY) - AIM::SIZE / 2;

	// ���N���b�N���ꂽ��
	if (keyCondition & MOUSE_INPUT_LEFT)
	{

	}
}


// �`�揈��
void AIM::Render(int ghWheresTarget)
{
	// �J�[�\���̕`��
	DrawRectExtendGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y), 
						static_cast<int>(m_position.x + AIM::SIZE), static_cast<int>(m_position.y + AIM::SIZE),
					    0, 0, 64, 64,
					    ghWheresTarget, TRUE);

}


// �I������
void AIM::Finalize()
{
}


// �v���C���[�̒��S�̈ʒu���擾����֐�
Vector2D AIM::GetCenterPosition()
{
	return Vector2D
	{
		m_position.x + AIM::SIZE / 2,
		m_position.y + AIM::SIZE / 2
	};
}
