#pragma once

//�^�C�g���N���X
class SceneTitle {
private:
	//�摜�p�ϐ�
	int BackHan   = 0;
	int GroundHan = 0;
	int titleHan  = 0;
	int enterHan  = 0;

	int PlayerHan = 0;

	float PlayerX = 620;
	float PlayerY = 300;

	int Player_sw = 0;

	//BGM
	int TitleBGMHan = 0;

	//�n�ʂ̃X���C�h�����p�ϐ�
	int GroundPosX  = 0;
	int GroundPosX2 = 1280;

	//�G���^�[�̃`�J�`�J�p�ϐ�
	int entertouka_sw = 0;
	int entertouka    = 0;
public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();		// �^�C�g��������

	void StepTitle();		// �^�C�g���ʏ폈��

	void DrawTitle();		// �^�C�g���`�揈��

	void FinTitle();		// �^�C�g���I������
};