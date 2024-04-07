//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "Scene/Scene.h"
#include "Scene/SceneTitle.h"
#include "Scene/ScenePlay.h"
#include "Scene/SceneClear.h"
#include "Scene/SceneGameOver.h"
#include "Input/Input.h"
#include "map/map.h"

// define
#define	SCREEN_SIZE_X	1280	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	720		// Y�����̉�ʃT�C�Y���w��

// ���݂̃V�[��ID
SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//���͐��䏉����
	InitInput();

	SceneTitle  Title;			// �N���X�錾
	ScenePlay   Play;
	SceneClear clear;
	SceneGameOver gameover;
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���

	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//�G�X�P�[�v�L�[�������ꂽ��I��
			break;
		}

		//��ʂɕ\�����ꂽ���̂�������
		ClearDrawScreen();

		StepInput();				//���͐���X�e�b�v

		//-----------------------------------------
		//��������Q�[���̖{�̂��������ƂɂȂ�
		//-----------------------------------------
		
		switch (g_CurrentSceneId)
		{
		case SCENE_ID_INIT_TITLE:
		{
			// �^�C�g���̏�����
			Title.InitTitle();
		}
		break;
		case SCENE_ID_LOOP_TITLE:
		{
			// �^�C�g���̒ʏ폈��
			Title.StepTitle();

			// �^�C�g���̕`�揈��
			Title.DrawTitle();
		}
		break;
		case SCENE_ID_FIN_TITLE:
		{
			// �^�C�g���̏�����
			Title.FinTitle();
		}
		break;
		case SCENE_ID_INIT_PLAY:
		{
			// �v���C��ʏ�����
			Play.InitPlay();
			
			//�}�b�v������
			InitMap();
			//�}�b�v�`�b�v�摜�ǂݍ���
			LoadMap();
			
		}
		break;
		case SCENE_ID_LOOP_PLAY:
		{
			// �v���C�̒ʏ폈��
			Play.StepPlay();

			// �v���C�̕`�揈��
			Play.DrawPlay();
			//�}�b�v�`�揈��
			DrawMap();
		}
		break;
		case SCENE_ID_FIN_PLAY:
		{
			// �v���C�I��
			Play.FinPlay();
			//�}�b�v�㏈��
			FinMap();
		}
		break;
		case SCENE_ID_INIT_CLEAR:
		{
			// �N���A��ʏ�����
			clear.InitClear();
		}
		break;
		case SCENE_ID_LOOP_CLEAR:
		{
			// �N���A��ʒʏ폈��
			clear.StepClear();

			// �N���A��ʂ̕`��
			clear.DrawClear();
		}
		break;
		case SCENE_ID_FIN_CLEAR:
		{
			// �v���C�I��
			clear.FinClear();
		}
		break;
		case SCENE_ID_INIT_GAMEOVER:
		{
			// �Q�[���I�[�o�[��ʏ�����
			gameover.InitGameOver();
		}
		break;
		case SCENE_ID_LOOP_GAMEOVER:
		{
			// �Q�[���I�[�o�[��ʒʏ폈��
			gameover.StepGameOver();

			// �Q�[���I�[�o�[��ʂ̕`��
			gameover.DrawGameOver();
		}
		break;
		case SCENE_ID_FIN_GAMEOVER:
		{
			// �v���C�I��
			gameover.FinGameOver();
		}
		break;
		default:
			break;
		}

		//-----------------------------------------
		//���[�v�̏I����
		//�t���b�v�֐�
		ScreenFlip();

	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

