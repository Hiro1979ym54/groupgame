#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"
#include "../map/map.h"
#include "../Collison/Collison.h"

#define	SCREEN_SIZE_X	1280	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	720		// Y�����̉�ʃT�C�Y���w��

//�摜
#define BACK_PATH	"Data/Play/back.png"
#define GROUND_PATH	"Data/Play/ground.png"
#define READY_PATH	"Data/Play/ready.png"
#define PLAYER_PATH	"Data/Play/player.png"

//�摜�̉��̃T�C�Y�A�c�̃T�C�Y
#define PLAYER_WIDTH (50)	//���T�C�Y
#define PLAYER_WIDTH (50)	//�c�T�C�Y

//BGM
#define PLAY_BACKGROUND		"Data/Sound/PlayBGM.mp3"

//��]�ʗp�~����
#define PI    3.1415926535897932384626433832795f

#define GRAVITY (0.5f)	// �d�͉����x
#define SIZE	(50)	// �L�����N�^�[�̃T�C�Y

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

//Map�̍\���̐錾
MapChip map;

// �Q�[���v���C������
void ScenePlay::InitPlay() {
	// �v���C�摜�̓Ǎ�
	BackHan		= LoadGraph(BACK_PATH);
	GroundHan	= LoadGraph(GROUND_PATH);
	PlayerHan	= LoadGraph(PLAYER_PATH);
	ReadyHan	= LoadGraph(READY_PATH);
	src_handle	= LoadGraph(MAP_CHIP_IMG_PATH_UP);
	src_handle2 = LoadGraph(MAP_CHIP_IMG_PATH_DOWN);
	src_handle3 = LoadGraph(MAP_CHIP_IMG_PATH_UP);
	src_handle4 = LoadGraph(MAP_CHIP_IMG_PATH_DOWN);

	//�v���C���[�̉��Əc�̃T�C�Y
	plsize_W = PLAYER_WIDTH;
	plsize_H = PLAYER_WIDTH;

	//�v���C���[�̐����t���O
	PlyerisAlive = true;

	//�v���C���[�̓����蔻��̃t���O
	bool isHit = true;

	//�}�b�v�̉��Əc�̃T�C�Y
	map.Mapsize_W = DOKAN_WIDTH;
	map.Mapsize_H = DOKAN_HEIGHT;

	//�e�ϐ�������
	PlayerX		= 620.0f;
	PlayerY		= 300.0f;
	SpacePush	= false;
	isJump		= false;
		
	//BGM�Ǎ�
	PlayBGMHan = LoadSoundMem(PLAY_BACKGROUND);

	//BGM�Đ�
	PlaySoundMem(PlayBGMHan, DX_PLAYTYPE_LOOP, true);

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

	//�X�y�[�X�L�[�ŃW�����v�J�n������v���C���[��i�߂�
	if (SpacePush) {
		PlayerX += 10;
	}

	//�W�����v�p�̃L�[�������ꂽ��W�����v

	if (IsKeyPush(KEY_INPUT_SPACE)) {
		isUp = true;
		Yspeed = -jump_power;
		//��x�ł�������Ă�����X�y�[�X�t���O��true��
		SpacePush = true;
	}

	//�y�ǂ̓����蔻��
	if (isHit == true) {
		//IsHitRect�̒�`
		if (IsHitRect(PlayerX, PlayerY, plsize_W, plsize_H
			, map.x, map.y,
			map.Mapsize_W, map.Mapsize_H == -1)) {
			PlyerisAlive = false;
		}
	}

	//�d�͂�^����
	if (SpacePush) {
		isUp = false;
		Yspeed += GRAVITY;
		PlayerY += Yspeed;
	}

	//������
	if (PlayerY >= 547) {
		isJump  = false;
		isClear = false;
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}

	//�v���C���[����ʊO�ւ����Ȃ��悤��
	if (PlayerY <= 0) {
		PlayerY = 0;
	}

	//�N���A����
	/*if (PlayerX >= 1500) {
		isClear = true;
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}*/
}

// �Q�[���v���C�`�揈��
void ScenePlay::DrawPlay() {
	//�摜�`��
	DrawGraph(0, 0, BackHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(PlayerX - ScreenX, PlayerY, PlayerHan, true);

	//�}�b�v�̏c�̐������J��Ԃ�
	for (int y_index = 0; y_index < MAP_CHIP_X_NUM; y_index++) {

		//�}�b�v�̉��̐������J��Ԃ�
		for (int x_index = 0; x_index < MAP_CHIP_Y_NUM; x_index++) {

			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle, true);
			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle2, true);
			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle , true);
			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle2, true);
			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle3, true);
			DrawGraph(mapChip[x_index][y_index].x, mapChip[x_index][y_index].y, src_handle4, true);
		}
	}

	//ready�摜�̓W�����v�J�n������\�����Ȃ�
	if (SpacePush == false) {
		DrawGraph(0, 0, ReadyHan, true);
	}

	//�f�o�b�O
	DrawFormatString(150, 10, GetColor(255, 0, 0), "%f", PlayerX);
}

//�Q�[���v���C�I������
void ScenePlay::FinPlay() {
	//BGM�㏈��
	DeleteSoundMem(PlayBGMHan);

	//�N���A�t���O���m�F���đJ�ڐ������
	if (!isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
	}
}

void ScenePlay::InitScreen()
{
	ScreenX = PlayerX - SCREEN_SIZE_X / 2;
}

//�X�N���[���̃��[���h���W
void ScenePlay::StepScreen()
{
	ScreenX = PlayerX + 200 - SCREEN_SIZE_X / 2;
}