#pragma once

class ScenePlay {
private:
	//�摜�p�ϐ�
	int BackHan = 0;
	int GroundHan = 0;
	int ReadyHan = 0;

	int PlayerHan = 0;

	float PlayerX = 620;
	float PlayerY = 300;

	int Player_sw = 0;

	//�n�ʂ̃X���C�h�����p�ϐ�
	int GroundPosX = 0;
	int GroundPosX2 = 1280;
public:
	ScenePlay();
	~ScenePlay();

	void InitPlay();		// �N���A������

	void StepPlay();		// �N���A�ʏ폈��

	void DrawPlay();		// �N���A�`�揈��

	void FinPlay();			//�v���C�I������
};
