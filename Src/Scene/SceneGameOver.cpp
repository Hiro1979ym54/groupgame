#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneGameOver.h"
#include "../Input/Input.h"

//�摜
#define GAMEOVER_PATH	"Data/Play/gameover.png"
#define GROUND_PATH		"Data/Play/ground.png"
#define PLAYER_PATH		"Data/Play/gameoverplayer.png"

//BGM
#define GAMEOVER_BACKGROUND		"Data/Sound/GameOverBGM.mp3"

SceneGameOver::SceneGameOver() {}

SceneGameOver::~SceneGameOver() {}

// �Q�[���I�[�o�[������
void SceneGameOver::InitGameOver() {
	// �Q�[���I�[�o�[�摜�̓Ǎ�
	GameoverHan = LoadGraph(GAMEOVER_PATH);
	GroundHan	= LoadGraph(GROUND_PATH);
	PlayerHan	= LoadGraph(PLAYER_PATH);

	//BGM�Ǎ�
	GameoverBGMHan = LoadSoundMem(GAMEOVER_BACKGROUND);

	//BGM�Đ�
	PlaySoundMem(GameoverBGMHan, DX_PLAYTYPE_LOOP, true);

	g_CurrentSceneId = SCENE_ID_LOOP_GAMEOVER;
}

// �Q�[���I�[�o�[�ʏ폈��
void SceneGameOver::StepGameOver() {
	//�n�ʂ̃X�N���[������
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
	}

	if (IsKeyPush(KEY_INPUT_RETURN)) {
		g_CurrentSceneId = SCENE_ID_FIN_GAMEOVER;
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

}

// �Q�[���I�[�o�[�`�揈��
void SceneGameOver::DrawGameOver() {
	//�摜�`��
	DrawGraph(0, 0, GameoverHan, true);
	DrawGraph(GroundPosX, 597, GroundHan, true);
	DrawGraph(GroundPosX2, 597, GroundHan, true);
	DrawGraph(PlayerX, PlayerY, PlayerHan, true);
}

//�Q�[���I�[�o�[�I������
void SceneGameOver::FinGameOver() {
	//BGM�㏈��
	DeleteSoundMem(GameoverBGMHan);

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
