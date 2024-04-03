#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//�摜�Ǎ�
#define TITLE_BACK_PATH		"Data/Play/back.png"
#define TITLE_GROUND_PATH	"Data/Play/ground.png"

//�n�ʂ̃X���C�h�����p�ϐ�
int GroundPosX = 0;
int GroundPosX2 = 1280;

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// �^�C�g��������
void SceneTitle::InitTitle() {
	// �^�C�g���摜�̓Ǎ�
	BackHan = LoadGraph(TITLE_BACK_PATH);
	GroundHan = LoadGraph(TITLE_GROUND_PATH);

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle() {
	GroundPosX -= 5;
	GroundPosX2 -= 5;
	if (GroundPosX <= -1280) {
		GroundPosX = 1280;
	}
	if (GroundPosX2 <= -1280) {
		GroundPosX2 = 1280;
	}

	//�G���^�[�L�[�Ńv���C��ʂ֑J��
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle() {
	DrawGraph(0, 0, BackHan, true);
	DrawGraph(GroundPosX, 0, GroundHan, true);
	DrawGraph(GroundPosX2, 0, GroundHan, true);
}

//�^�C�g���I������
void SceneTitle::FinTitle() {
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
