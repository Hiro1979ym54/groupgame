#pragma once

class ScenePlay {
private:
	//�摜�p�ϐ�
	int BackHan = 0;
	int GroundHan = 0;
	int ReadyHan = 0;
	int PlayerHan = 0;

	//�v���C���[���W
	float PlayerX = 620.0f;
	float PlayerY = 300.0f;

	//�摜�̉��̃T�C�Y�A�c�̃T�C�Y
	int plsize_W; //��
	int plsize_H; //�c

	//�v���C���[�̐����t���O
	bool PlyerisAlive = false;

	//�v���C���[�̓����蔻��̃t���O
	bool isHit = false;

	//�v���C���[�㉺�����p
	int Player_sw = 0;

	//�v���C���[�̉�]�ʕύX�p�ϐ�
	int PlayerRota = 0;

	//�X�y�[�X�������ꂽ���m�F����t���O
	bool SpacePush = false;

	//�W�����v�����m�F����t���O
	bool isJump = false;

	float Yspeed = 0.0f;

	//�v���C���[���㏸�������ׂ�t���O
	bool isUp = false;

	//�W�����v��
	float jump_power = 7.0f;

	//�N���A���I�[�o�[����ʑJ�ڎ��Ɋm�F����t���O
	bool isClear = false;

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
