#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"

#define	SCREEN_SIZE_X	1280	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	720		// Y�����̉�ʃT�C�Y���w��

//�摜
#define BACK_PATH	"Data/Play/back.png"
#define GROUND_PATH	"Data/Play/ground.png"
#define READY_PATH	"Data/Play/ready.png"

#define PLAYER_PATH	"Data/Play/playeranime1.png"

#define PI    3.1415926535897932384626433832795f


#define GRAVITY (0.5f)	// �d�͉����x
#define SIZE	(50)	// �L�����N�^�[�̃T�C�Y

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

// �Q�[���v���C������
void ScenePlay::InitPlay() {
	// �v���C�摜�̓Ǎ�
	BackHan = LoadGraph(BACK_PATH);
	GroundHan = LoadGraph(GROUND_PATH);
	PlayerHan = LoadGraph(PLAYER_PATH);
	ReadyHan = LoadGraph(READY_PATH);

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// �Q�[���v���C�ʏ폈��
void ScenePlay::StepPlay() {
	//�n�ʂ̃X�N���[������
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
	}

	//�v���C��ʂɑJ�ڂ�����v���C���[�����ֈړ�
	if (PlayerX >= 440) {
		PlayerX -= 4;
	}

	//�v���C���[�̏㉺����
	//��x�ł��W�����v������㉺�ړ����I��
	if (!SpacePush) {
		switch (Player_sw) {
		case 0:
			PlayerY += 0.5f;
			if (PlayerY >= 305) {
				Player_sw = 1;
			}
			break;
		case 1:
			PlayerY -= 0.5f;
			if (PlayerY <= 295) {
				Player_sw = 0;
			}
			break;
		}
	}

	//�W�����v�p�̃L�[�������ꂽ��W�����v
	if (IsKeyPush(KEY_INPUT_SPACE)){
		isUp = true;
		Yspeed = -jump_power;
		//��x�ł�������Ă�����X�y�[�X�t���O��true��
		SpacePush = true;
	}

	//�d�͂�^����
	if (SpacePush) {
		isUp = false;
		Yspeed += GRAVITY;
		PlayerY += Yspeed;
	}

	//������
	if (PlayerY >= 547) {
		PlayerY = 547;
		isJump = false;
	}

	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// �Q�[���v���C�`�揈��
void ScenePlay::DrawPlay() {
	//�摜�`��
	DrawGraph(0, 0, BackHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(PlayerX, PlayerY, PlayerHan, true);

	//��Ńv���C���[�̉�]�ʂ�ύX
	/*if (!isUp) {
		DrawRotaGraph(PlayerX, PlayerY, 1.0, PI / 0.52, PlayerHan, true);
	}

	if (isUp) {
		DrawRotaGraph(PlayerX, PlayerY, 1.0, PI / 0.1, PlayerHan, true);
	}*/

	//ready�摜�̓W�����v�J�n������\�����Ȃ�
	if (PlayerX <= 440 && SpacePush == false) {
		DrawGraph(0, 0, ReadyHan, true);
	}
}

//�Q�[���v���C�I������
void ScenePlay::FinPlay() {
	g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
}
