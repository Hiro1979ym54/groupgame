#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

// �Q�[���v���C������
void ScenePlay::InitPlay() {
	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// �Q�[���v���C�ʏ폈��
void ScenePlay::StepPlay() {
	g_CurrentSceneId = SCENE_ID_FIN_PLAY;

}

// �Q�[���v���C�`�揈��
void ScenePlay::DrawPlay() {

}

//�Q�[���v���C�I������
void ScenePlay::FinPlay() {
	g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
}
