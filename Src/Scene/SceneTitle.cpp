#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//�摜�Ǎ�
#define BACK_PATH	"Data/Play/back.png"
#define GROUND_PATH	"Data/Play/ground.png"
#define TITLE_PATH	"Data/Play/title.png"

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// �^�C�g��������
void SceneTitle::InitTitle() {
	// �^�C�g���摜�̓Ǎ�
	BackHan   = LoadGraph(BACK_PATH);
	GroundHan = LoadGraph(GROUND_PATH);
	titleHan  = LoadGraph(TITLE_PATH);

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
	DrawGraph(GroundPosX, 0, GroundHan, true);
	DrawGraph(GroundPosX2, 0, GroundHan, true);
	DrawGraph(0, 0, titleHan, true);
}

//�^�C�g���I������
void SceneTitle::FinTitle() {
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
