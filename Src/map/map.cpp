#include "DxLib.h"
#include <DxLib.h>
#include "map.h"


int src_handle = 0;
int src_handle2 = 0;

//�}�b�v�`�b�v[�c�̐�][���̐�]
MapChip mapChip[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] = { 0 };

//�}�b�v�`�b�v�̔z�u�f�[�^
const int mapChipData[MAP_CHIP_Y_NUM][MAP_CHIP_X_NUM] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

};

//�}�b�v�`�b�v�摜�ǂݍ���
void LoaMap()
{

	//���s�Ȃ�I��
	if (src_handle == -1)
		return;

	if (src_handle2 == -1)
		return;

	for (int y_index = 0; y_index < MAP_CHIP_Y_NUM; y_index++)
	{
		for (int x_index = 0; x_index < MAP_CHIP_X_NUM; x_index++)
		{
			//�}�b�v�`�b�v�̎�ނɂ���āA
			//�摜�̂ǂ̈ʒu��؂��邩���߂�
			int start_x = 0;
			int start_y = 0;

			//��ɂ���y�ǂ̃}�b�v�`�b�v
			if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_UP)
			{
				//��ɂ���y�ǂ̐؂蔲���J�n�ʒu��ݒ肷��
				start_x = 32;
				start_y = 32;
			}
			//���ɂ���y�ǂ̃}�b�v�`�b�v
			else if (mapChipData[y_index][x_index] == MP_CHIP_CLAY_PIPE_DOWN)
			{
				//���ɂ���y�ǂ̐؂蔲���J�n�ʒu��ݒ肷��
				start_x = 32;
				start_y = 32;
			}

			MapChip* map_chip = &mapChip[y_index][x_index];

			//���摜����e�}�b�v�`�b�v�摜�̃n���h�����쐬(�y�Ǐ�)
			map_chip->handle = DerivationGraph(start_x, start_y,
				MAP_CHIP_SIZE_X,
				MAP_CHIP_SIZE_Y,
				src_handle);

			//���摜����e�}�b�v�`�b�v�摜�̃n���h�����쐬(�y�ǉ�)
			map_chip->handle = DerivationGraph(start_x, start_y,
				MAP_CHIP_SIZE_X,
				MAP_CHIP_SIZE_Y,
				src_handle2);

			//���W�����߂�
			map_chip->x = x_index * MAP_CHIP_SIZE_X;
			map_chip->y = y_index * MAP_CHIP_SIZE_Y;

			//�`��t���O��ON
			map_chip->isDraw = true;

			//�^�C�v���L�^
			map_chip->type = (MAP_CHIP_TYPE)mapChipData[y_index][x_index];

		}
	}

	//���摜������
	DeleteGraph(src_handle);
	DeleteGraph(src_handle2);

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
				int map_x = (int)(mapChip[y_index][x_index].x);
				int map_y = (int)(mapChip[y_index][x_index].y);
				DrawGraph(map_x, map_y, mapChip[y_index][x_index].handle, true);
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

//�}�b�v�`�b�v�f�[�^�̎擾
MapChip* GetMapChip(int y_index)
{
	return mapChip[y_index];
}