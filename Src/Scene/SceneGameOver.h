#pragma once

class SceneGameOver {
private:
	//�摜�p�ϐ�
	int GameoverHan = 0;
	int GroundHan	= 0;
	int PlayerHan	= 0;

	//BGM
	int GameoverBGMHan = 0;

	//�v���C���[���W
	float PlayerX = 620.0f;
	float PlayerY = 300.0f;

	//�v���C���[�㉺�����p
	int Player_sw = 0;

	//�n�ʂ̃X���C�h�����p�ϐ�
	int GroundPosX	= 0;
	int GroundPosX2	= 1280;
	
public:
	SceneGameOver();
	~SceneGameOver();

	void InitGameOver();		// �Q�[���I�[�o�[������

	void StepGameOver();		// �Q�[���I�[�o�[�ʏ폈��

	void DrawGameOver();		// �Q�[���I�[�o�[�`�揈��

	void FinGameOver();		    // �Q�[���I�[�o�[�I������
};