#pragma once

class SceneClear {
private:
	//�摜�p�ϐ�
	int GameclearHan = 0;
	int GroundHan = 0;
	int PlayerHan = 0;

	//BGM
	int GameclearBGMHan = 0;

	//�v���C���[���W
	float PlayerX = 620.0f;
	float PlayerY = 300.0f;

	//�v���C���[�㉺�����p
	int Player_sw = 0;

	//�n�ʂ̃X���C�h�����p�ϐ�
	int GroundPosX = 0;
	int GroundPosX2 = 1280;
public:
	SceneClear();
	~SceneClear();

	void InitClear();		// �N���A������

	void StepClear();		// �N���A�ʏ폈��

	void DrawClear();		// �N���A�`�揈��

	void FinClear();		//�N���A�I������

};
