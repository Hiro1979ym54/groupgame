#include "DxLib.h"
#include <DxLib.h>
#include "map.h"



#define MAP_CHIP_X_NUM	(12)	//�}�b�v�`�b�v���̐�
#define MAP_CHIP_Y_NUM	(10)	//�}�b�v�`�b�v�c�̐�


//�}�b�v�`�b�v�摜�t�@�C���p�X
#define MAP_CHIP_IMG_PATH "Data/Play/Dokan.png"


//�}�b�v�`�b�v�̎��
enum MAP_CHIP_TYPE
{
	MP_CHIP_CLAY_PIPE_TIP,  //�y�ǐ�[
	MP_CHIP_CLAY_PIPE_ROOT, //�y�Ǎ��{

};


//�}�b�v�`�b�v�\����
struct  MapChip
{
	int handle;  //�摜�n���h��
	int x, y;    //���W
	bool isDraw; //�`��t���O
};


//�}�b�v�`�b�v[�c�̐�][���̐�]
MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };


//�}�b�v�`�b�v�̔z�u�f�[�^
const int mapChipData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] =
{
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},

};


//�}�b�v�`�b�v��1�̃T�C�Y
const int MAP_CHIP_SIZE_X = (32);
const int MAP_CHIP_SIZE_Y = (64);


//�}�b�v�`�b�v�摜�ǂݍ���
void LoaMap()
{
	//���摜��ǂݍ���
	int src_handle = LoadGraph(MAP_CHIP_IMG_PATH);

	//���s�Ȃ�I��
	if (src_handle == -1)
		return;

	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//�}�b�v�`�b�v�̎�ނɂ���āA
			//�摜�̂ǂ̈ʒu��؂��邩���߂�
			int start_x = 0;
			int start_y = 0;

			//�y�ǐ�[�̃}�b�v�`�b�v
			if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_TIP)
			{
				//�y�ǐ�[�̐؂蔲���J�n�ʒu��ݒ肷��
				start_x = 0;
				start_y = 0;
			}
			//�y�Ǎ��{
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_ROOT)
			{
				//�y�Ǎ��{�̐؂蔲���J�n�ʒu��ݒ肷��
				start_x = 0;
				start_y = 0;
			}

			MapChip* map_chip = &mapChip[y_index][x_index];

			//���摜����e�}�b�v�`�b�v�摜�̃n���h�����쐬
			map_chip->handle = DerivationGraph(start_x, start_y,
				MAP_CHIP_SIZE_X,
				MAP_CHIP_SIZE_Y,
				src_handle);

			//���W�����߂�
			map_chip->x = x_index * MAP_CHIP_SIZE_X;
			map_chip->y = y_index * MAP_CHIP_SIZE_Y;

			//�`��t���O��ON
			map_chip->isDraw = true;

		}
	}

	//���摜������
	DeleteGraph(src_handle);

}

//�}�b�v������
void InitMap()
{
	//�}�b�v�`�b�v��S��0�ŏ�����
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			mapChip[y_index][x_index].handle = 0;
			mapChip[y_index][x_index].x = 0;
			mapChip[y_index][x_index].y = 0;
			mapChip[y_index][x_index].isDraw = false;
		}
	}
}

//�}�b�v�ʏ폈��
void StepMap()
{

}

//�}�b�v�`�揈��
void DrawMap()
{
	//�}�b�v�`�b�v��`��
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//�`��t���O��ON�̃`�b�v�̂�
			if (mapChip[y_index][x_index].isDraw)
			{

			}
		}
	}
}

//�}�b�v�㏈��
void FinMap()
{
	//���ׂẴ}�b�v�`�b�v�摜����������
	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//����
			if (mapChip[y_index][x_index].handle != 0)
			{
				DeleteGraph(mapChip[y_index][x_index].handle);
			}
		}
	}

}