#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneClear.h"
#include "../Input/Input.h"

//�摜
#define GAMECLEAR_PATH	"Data/Play/gameclear.png"
#define GROUND_PATH		"Data/Play/ground.png"
#define PLAYER_PATH		"Data/Play/clearplayer.png"

//BGM
#define GAMECLEAR_BACKGROUND		"Data/Sound/ClearBGM.mp3"

SceneClear::SceneClear() {}

SceneClear::~SceneClear() {}

// �Q�[���N���A������
void SceneClear::InitClear() {
	// �Q�[���I�[�o�[�摜�̓Ǎ�
	GameclearHan = LoadGraph(GAMECLEAR_PATH);
	GroundHan = LoadGraph(GROUND_PATH);
	PlayerHan = LoadGraph(PLAYER_PATH);

	//BGM�Ǎ�
	GameclearBGMHan = LoadSoundMem(GAMECLEAR_BACKGROUND);

	//BGM�Đ�
	PlaySoundMem(GameclearBGMHan, DX_PLAYTYPE_LOOP, true);

	g_CurrentSceneId = SCENE_ID_LOOP_CLEAR;
}

// �Q�[���N���A�ʏ폈��
void SceneClear::StepClear() {
	//�n�ʂ̃X�N���[������
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
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
	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneId = SCENE_ID_FIN_CLEAR;
	}

}

// �Q�[���N���A�`�揈��
void SceneClear::DrawClear() {
	//�摜�`��
	DrawGraph(0, 0, GameclearHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(PlayerX, PlayerY, PlayerHan, true);
}

//�Q�[���N���A�I������
void SceneClear::FinClear() {
	//BGM�㏈��
	DeleteSoundMem(GameclearBGMHan);

	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}
