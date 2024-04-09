#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//�摜�Ǎ�
#define BACK_PATH	"Data/Play/back.png"
#define GROUND_PATH	"Data/Play/ground.png"
#define TITLE_PATH	"Data/Play/title.png"
#define ENTER_PATH	"Data/Play/enter.png"

#define PLAYER_PATH	"Data/Play/player.png"

//BGM
#define TITLE_BACKGROUND		"Data/Sound/TitleBGM.mp3"

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// �^�C�g��������
void SceneTitle::InitTitle() {
	// �^�C�g���摜�̓Ǎ�
	BackHan   = LoadGraph(BACK_PATH);
	GroundHan = LoadGraph(GROUND_PATH);
	titleHan  = LoadGraph(TITLE_PATH);
	enterHan  = LoadGraph(ENTER_PATH);

	PlayerHan = LoadGraph(PLAYER_PATH);

	//BGM�Ǎ�
	TitleBGMHan = LoadSoundMem(TITLE_BACKGROUND);

	//BGM�Đ�
	PlaySoundMem(TitleBGMHan, DX_PLAYTYPE_LOOP, true);

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle() {
	//�n�ʂ̃X�N���[������
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
	}

	//�G���^�[�̃`�J�`�J����
	switch (entertouka_sw) {
	case 0:
		entertouka += 9;
		if (entertouka >= 255) {
			entertouka_sw = 1;
		}
		break;
	case 1:
		entertouka -= 9;
		if (entertouka <= 0) {
			entertouka_sw = 0;
		}
		break;
	}

	//�v���C���[�̏㉺����
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

	//�G���^�[�L�[�Ńv���C��ʂ֑J��
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle() {
	//�摜�`��
	DrawGraph(0, 0, BackHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(0, -50, titleHan, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, entertouka);
	DrawGraph(0, 0, enterHan, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawGraph(PlayerX, PlayerY, PlayerHan, true);
}

//�^�C�g���I������
void SceneTitle::FinTitle() {
	//BGM�㏈��
	DeleteSoundMem(TitleBGMHan);

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
