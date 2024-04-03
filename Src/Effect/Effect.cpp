
#include <DxLib.h>
#include "Effect.h"
#include "Common.h"

/*
  �i�߂�菇
  1�F�G�t�F�N�g���\���̂�����������
  2�FInitEffect�֐�����������
  3�FLoadEffect�֐�����������
  4�FPlayEffect�֐�����������
  5�FDrawEffect�֐�����������@�������܂Ŏ����ł���Ώ����Ȃ��G�t�F�N�g����������
  6�FStepEffect�֐�����������
  7�FFinEffect�֐�����������

  ��������͎����̃Q�[���Ƀ\�[�X�t�@�C�����R�s�[���G�t�F�N�g���������Ă݂܂��傤!!
*/

//��x�ɕ\���ł���G�t�F�N�g�ő吔
#define EFFECT_MAX_NUM		(20)

//�G�t�F�N�g�̃A�j���ő吔
#define EFFECT_ANIME_MAX_NUM	(4)	

//�G�t�F�N�g���
struct EffectInfo
{
	EFFECT_TYPE effectType;								//�G�t�F�N�g�̎��

	int handle[EFFECT_ANIME_MAX_NUM];					//�摜�n���h��

	int x, y;											//���W
	bool isUse;											//�g�p�t���O

	int animeNum;										//�A�j����
	int currentAnimeIndex;								//���݂̃A�j���ԍ�

	float changeTime;									//�P��������̕\������
	float currentAnimeTime;								//���݂̃A�j������
};

//�G�t�F�N�g���
EffectInfo effectInfo[EFFECT_MAX_NUM];

//�G�t�F�N�g�̃t�@�C���p�X
const char effectFilePath[EFFECT_TYPE_NUM][256] =
{
	"Data/Effect/EffectExplosion.png",
	"Data/Effect/EffectRecovery.png",
};

//�e�G�t�F�N�g�̃A�j����
const int effectAnimeImgNum[EFFECT_TYPE_NUM] =
{
	4,	//EFFECT_TYPE_EXPLOSION
	3,	//EFFECT_TYPE_RECOVERY
};

//�e�G�t�F�N�g�̉摜������ [0] = x, [1] = y
const int effectImageSplitNum[EFFECT_TYPE_NUM][2] =
{
	{ 2, 2,},	//EFFECT_TYPE_EXPLOSION
	{ 2, 2,},	//EFFECT_TYPE_RECOVERY
};

//�G�t�F�N�g�̉摜�T�C�Y
const int effectImageSize[EFFECT_TYPE_NUM] =
{
	64,	//EFFECT_TYPE_EXPLOSION
	32,	//EFFECT_TYPE_RECOVERY
};

//�e�G�t�F�N�g�̃A�j���摜�؂�ւ�����
const float effectChageTime[EFFECT_TYPE_NUM] =
{
	0.05f,	//EFFECT_TYPE_EXPLOSION
	0.1f,	//EFFECT_TYPE_RECOVERY
};

//�G�t�F�N�g�̓ǂݍ���
//����	�F�G�t�F�N�g�̎�ށA�쐬��
void LoadEffect(EFFECT_TYPE type, int create_num)
{
	//�G�t�F�N�g�̍쐬��for������
	for (int createNum_index = 0; createNum_index < create_num; createNum_index++)
	{
		//�G�t�F�N�g�̏��\���̔z��for������
		for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
		{
			//�ǂݍ��݂��Ă��Ȃ��G�t�F�N�g����������
			//�i�ЂƂڂ̉摜�n���h�����[���Ȃ�ǂݍ��݂���ĂȂ��j
			if (effectInfo[effect_index].handle[0] == 0)
			{

				int animeImagenum = effectAnimeImgNum[type];

				int ImageSplitNumX = effectImageSplitNum[type][0];
				int ImageSplitNumY = effectImageSplitNum[type][1];

				int ImageSize = effectImageSize[type];

				//�摜�𕪊��ǂݍ���
				int success_flg = LoadDivGraph(effectFilePath[type], animeImagenum, ImageSplitNumX, ImageSplitNumY, ImageSize, ImageSize, effectInfo[effect_index].handle);

				//��������
				if (success_flg == 0)
				{
					//�A�j�������i�[
					effectInfo[effect_index].animeNum = animeImagenum;

					//1��������̕\�����Ԃ�ݒ�
					effectInfo[effect_index].changeTime = effectChageTime[type];

					//�G�t�F�N�g�̎�ނ�ݒ�
					effectInfo[effect_index].effectType = type;
				}

				//���ۂɂ�����炸������
				break;
			}
		}
	}

}

//�G�t�F�N�g�̏�����
void InitEffect()
{
	//���ׂẴG�t�F�N�g���̕ϐ����N���A����i�[���ɂ���j
	for (int index = 0; index < EFFECT_MAX_NUM; index++) {
		effectInfo[index].x = 0;
		effectInfo[index].y = 0;
		effectInfo[index].isUse = false;
		effectInfo[index].animeNum = 0;
		effectInfo[index].currentAnimeIndex = 0;
		effectInfo[index].changeTime = 0.0f;
		effectInfo[index].currentAnimeTime = 0.0f;
		for (int maxnum_index = 0; maxnum_index < EFFECT_ANIME_MAX_NUM; maxnum_index++) {
			effectInfo[index].handle[maxnum_index] = 0;
		}
	}
}

//�G�t�F�N�g�ʏ폈��
void StepEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//�g�p���Ȃ�A�j�����Ԃ��o�߂����āA�A�j���ԍ����X�V����
		if (effectInfo[effect_index].isUse == true)
		{
			//���ԍX�V
			effectInfo[effect_index].currentAnimeTime += 1.0f / FRAME_RATE;

			//�摜�؂�ւ��ɕK�v�Ȏ��Ԍo�߂�����
			if (effectInfo[effect_index].currentAnimeTime >= effectInfo[effect_index].changeTime)
			{
				//���̉摜��
				effectInfo[effect_index].currentAnimeIndex++;

				//�v�����ԃ��Z�b�g
				effectInfo[effect_index].currentAnimeTime = 0.0f;

				//���̉摜�����������Ȃ�
				if (effectInfo[effect_index].currentAnimeIndex >= EFFECT_ANIME_MAX_NUM)
				{
					//�g�p���t���O��OFF��
					effectInfo[effect_index].isUse = false;

					//�ȉ��̏����͕s�v
					break;
				}

			}


		}
	}
}

//�G�t�F�N�g�`�揈��
void DrawEffect()
{
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//�g�p���Ȃ猻�݂̃A�j���ԍ��ŕ`�悷��
		if (effectInfo[effect_index].isUse)
		{
			DrawRotaGraph(effectInfo[effect_index].x, effectInfo[effect_index].y, 1.0f, 0.0f,
				effectInfo[effect_index].handle[effectInfo[effect_index].currentAnimeIndex], true);
		}
	}
}

//�G�t�F�N�g�̌㏈��
void FinEffect()
{
	//���ׂẴG�t�F�N�g���폜����
	for (int effct_index = 0; effct_index < EFFECT_ANIME_MAX_NUM; effct_index++)
	{
		//���ׂč폜����
		for (int index = 0; index < EFFECT_MAX_NUM; index++)
		{
			//���[���ȊO�Ȃ�폜����


			//�摜�폜������ݒ肷��
			DeleteGraph(effectInfo[index].handle[index]);

			//���폜������[�������Ă���
			effectInfo[index].currentAnimeIndex = 0;
		}

	}
}

//�G�t�F�N�g�̍Đ�
//����	�F�G�t�F�N�g�̎��, �w���W, �x���W, �P��������̕\������
void PlayEffect(EFFECT_TYPE type, int x, int y)
{
	//���g�p�G�t�F�N�g��T���čĐ�
	for (int effect_index = 0; effect_index < EFFECT_MAX_NUM; effect_index++)
	{
		//�g�p���Ȃ�ȉ��s��Ȃ�
		if (!effectInfo[effect_index].isUse)
		{
			//�^�C�v����v����
			if (effectInfo[effect_index].effectType == type)
			{
				//���W�ݒ�
				effectInfo[effect_index].x = x;
				effectInfo[effect_index].y = y;

				//�v���p�̕ϐ����N���A
				effectInfo[effect_index].currentAnimeIndex = 0;
				effectInfo[effect_index].currentAnimeTime = 0.0f;

				//�g�p���ɂ���
				effectInfo[effect_index].isUse = true;

				//������
				break;
			}
		}
	}
}
