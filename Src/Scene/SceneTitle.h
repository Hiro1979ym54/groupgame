#pragma once

//�^�C�g���N���X
class SceneTitle {
private:
	//�摜�p�ϐ�
	int BackHan = 0;
	int GroundHan = 0;
public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();		// �^�C�g��������

	void StepTitle();		// �^�C�g���ʏ폈��

	void DrawTitle();		// �^�C�g���`�揈��

	void FinTitle();		// �^�C�g���I������
};